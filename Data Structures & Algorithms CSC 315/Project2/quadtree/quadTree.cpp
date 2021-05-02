#include "quadTree.h"

using namespace std;

/*
    The constructor doesn't do much besides allow us to call functions
    within the class.
*/
quadTree::quadTree()
{

}

/*
    This the function that actually constructs the tree
*/
byte** quadTree::constructTree(byte **inImage, int height, int width, int thresh)
{
    //Get fresh variables
    threshold = thresh;
    leafcount = 0;
    root = new Node;
    root->minX = 0;
    root->minY = 0;
    root->maxX = height;
    root->maxY = width;

    //Allocate the new image
    image = alloc2D_byte(width, height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy the original image
            image[i][j] = inImage[i][j];
        }
    }
    imageCopy = image;
    //traverse and build the tree
    changeColor(root);
    //add the compression
    compressImage(root);

    //output info
    cout << "Leaves = " << leafcount << " mem: " << leafcount * 2
        << " bytes: " << " compressed size: "
        << ceil(((float)(leafcount * 2) / (float)(height * width)) * 100)
        << "% : Quality Factor [" << threshold << "]" << endl;

    return image;
}

quadTree::~quadTree()
{
    delete root;
}

/*
    This divides current leaf if called
*/
void quadTree::divide(Node *&root)
{
    root->topr = new Node;
    root->topl = new Node;
    root->botr = new Node;
    root->botl = new Node;
    // top left node
    root->topr->minX = root->minX;
    root->topr->maxX = ((root->maxX + root->minX) / 2);
    root->topr->minY = root->minY;
    root->topr->maxY = ((root->maxY + root->minY) / 2);
    // top right node
    root->topl->minX = ((root->maxX + root->minX) / 2);
    root->topl->maxX = root->maxX;
    root->topl->minY = root->minY;
    root->topl->maxY = ((root->maxY + root->minY) / 2);
    // bottom left node
    root->botl->minX = ((root->maxX + root->minX) / 2);
    root->botl->maxX = root->maxX;
    root->botl->minY = ((root->maxY + root->minY) / 2);
    root->botl->maxY = root->maxY;
    // bottom right node
    root->botr->minX = root->minX;
    root->botr->maxX = ((root->maxX + root->minX) / 2);
    root->botr->minY = ((root->maxY + root->minY) / 2);
    root->botr->maxY = root->maxY;
}

/*
    finds the average color in the quadrant
*/
byte quadTree::findAvgColor(Node *&quadrant)
{
    double avg = 0;
    //starts at the current quadrants top left corner and traverses down to
    //bottom right of the quadrant
    for (int i = quadrant->minY; i < quadrant->maxY; i++)
    {
        for (int j = quadrant->minX; j < quadrant->maxX; j++)
        {
            avg += image[j][i];
        }
    }

    //calculate the average
    avg = avg / (double)((quadrant->maxX - quadrant->minX) * (quadrant->maxY - quadrant->minY));
    return ceil(avg);
}

/*
    traverse through the tree 
*/
void quadTree::changeColor(Node *&quadrant)
{
    //gets the average color
    int avg = findAvgColor(quadrant);
    //starting from the top left and moving to the bottom right
    for (int y = quadrant->minY; y < quadrant->maxY; y++)
    {
        for (int x = quadrant->minX; x < quadrant->maxX; x++)
        {
            //checks to see if the value of the pixel is greater than the threshold
            if (abs(image[x][y] - avg) > threshold)
            {
                //divides the quadrant even further and traverses farther down the tree.
                divide(quadrant);
                changeColor(quadrant->topr);
                changeColor(quadrant->topl);
                changeColor(quadrant->botl);
                changeColor(quadrant->botr);
                return;
            }
        }
    }
    quadrant->leaf = true;
    leafcount++;
    quadrant->color = avg;
}

/*
    get the leaf count
*/
int quadTree::getLeafs() const
{
    return leafcount;
}

/*
    Compresses the image with the color of the current node
*/
void quadTree::compressImage(Node *root)
{
    if (root->leaf == true)
    {
        for (int y = root->minY; y < root->maxY; y++)
        {
            for (int x = root->minX; x < root->maxX; x++)
            {
                image[x][y] = root->color;
            }
        }
    }
    else
    {
        compressImage(root->topr);
        compressImage(root->topl);
        compressImage(root->botl);
        compressImage(root->botr);
    }
}

/*
    Draws the white lines
*/
void quadTree::whiteLines(Node *tree)
{

    if (tree->leaf == true)
    {
        //takes the points from the current node and makes the line to be drawn
        for (int x = tree->minX; x < tree->maxX; x++)
        {
            image[x][tree->minY] = 255;
            if (tree->maxY != root->maxY)
                image[x][tree->maxY] = 255;
            else
                image[x][tree->maxY - 1] = 255;
        }
        for (int y = tree->minY; y < tree->maxY; y++)
        {
            image[tree->minX][y] = 255;
            if (tree->maxX != root->maxX)
                image[tree->maxX][y] = 255;
            else
                image[tree->maxX - 1][y] = 255;
        }
    }
    else
    {
        whiteLines(tree->topr);
        whiteLines(tree->topl);
        whiteLines(tree->botl);
        whiteLines(tree->botr);
    }
}

/*
* Decrease the image compression
*/
byte** quadTree::decrement(byte** inImage, int height, int width)
{

    if(threshold == 255)
    {
        return inImage;
    }
    delete root;
    threshold++;
    leafcount = 0;
    root = new Node;
    root->minX = 0;
    root->minY = 0;
    root->maxX = height;
    root->maxY = width;

    //Allocate the new image
    image = alloc2D_byte(width, height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy the original image
            image[i][j] = inImage[i][j];
        }
    }

    //traverse and build the tree
    changeColor(root);
    //add the compression
    compressImage(root);

    //output info
    cout << "Leaves = " << leafcount << " mem: " << leafcount * 2
        << " bytes: " << " compressed size: "
        << ceil(((float)(leafcount * 2) / (float)(height * width)) * 100)
        << "% : Quality Factor [" << threshold << "]" << endl;

    return image;
}

/*
* Increase the image compression
*/
byte** quadTree::increment(byte** inImage, int height, int width)
{

    if(threshold == 0)
    {
        return inImage;
    }
    delete root;
    threshold--;
    leafcount = 0;
    root = new Node;
    root->minX = 0;
    root->minY = 0;
    root->maxX = height;
    root->maxY = width;

    //Allocate the new image
    image = alloc2D_byte(width, height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy the original image
            image[i][j] = inImage[i][j];
        }
    }
    //traverse and build the tree
    changeColor(root);
    //add the compression
    compressImage(root);

    //output info
    cout << "Leaves = " << leafcount << " mem: " << leafcount * 2
        << " bytes: " << " compressed size: "
        << ceil(((float)(leafcount * 2) / (float)(height * width)) * 100)
        << "% : Quality Factor [" << threshold << "]" << endl;

    return image;
}