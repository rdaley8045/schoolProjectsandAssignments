#include <iostream>
#include "node.h"

using namespace std;

int height(Node *);


Node *rightRotate(Node * low)
{
   Node *mid = low->left;
   Node *high = mid->right;

   mid->right = low;
   low ->left = high;

   low->ht = max(height(low->left), height(low->right))+1;
   mid->ht = max(height(mid->left), height(mid->right))+1;

   return mid;
}


Node *leftRotate(Node * mid)
{
   Node *low = mid->right;
   Node *high = low->left;

   low->left = mid;
   mid ->right = high;

   mid->ht = max(height(mid->left), height(mid->right))+1;
   low->ht = max(height(low->left), height(low->right))+1;

   return low;
}


/**************************************************************************//**
 * This function does a BST insert (no balancing).
 *
 * YOU need to implement an AVL balancing insert function
 *
 * @param[inout] root - The root of the subtree currently being processed
 * @param[in] data - The data element to add to the tree
 *
 * @return - The root of the subtree currently being processed
 *****************************************************************************/
Node *insert(Node *root, int data)
{
   
   if (root == nullptr)
      root = new Node(data);

   else if (data < root->data)
      root->left = insert(root->left, data);
   else
      root->right = insert(root->right, data);

   // Recalculate height of this node as we unwind the recursion
   int leftHeight = height(root->left);
   int rightHeight = height(root->right);
   root->ht = max(leftHeight,rightHeight) + 1;
   
   int balanceFactor = leftHeight - rightHeight;

   if (balanceFactor > 1 && data < root->left->data)
      return rightRotate(root);

   if (balanceFactor < -1 && data > root->right->data)
      return leftRotate(root);

   if (balanceFactor > 1 && data > root->left->data)
   {
      root->left = leftRotate(root->left);
      return rightRotate(root);
   }

   if (balanceFactor < -1 && data < root->right->data)
   {
      root->right = rightRotate(root->right);
      return leftRotate(root);
   }

   return root;
}

/**************************************************************************//**
 * This function returns the height of the node passed in
 *
 * @param[in] node - The node whose height we want
 *
 * @return - The height of the node passed in
 *****************************************************************************/
int height(Node *node)
{
   if (!node) return -1;
   return node->ht;
}





