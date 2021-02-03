#include "qrDecoder.h"


void qrDecoder::findThePattern(bool**bitMap, unsigned width, unsigned height)
{
    findLeftFinder (bitMap, width, height); //looks at full bitmap
    createModuleMap (bitMap, width, height);
    findLeftFinder (moduleMap, moduleCols, moduleRows); //looks at the module map
    findRightFinder (moduleMap, moduleCols, moduleRows); //looks at the module map
    findLeftCenter (moduleMap, leftCol, leftRow);
    findRightCenter(moduleMap, rightCol, rightRow);
    finderPattern1 = findPattern1(moduleMap,moduleCols,moduleRows);
}

void qrDecoder::findLeftFinder (bool**bitMap, unsigned width, unsigned height)
{
    int counterOfStates[6]={0};
    int currentState;
    bool currentBitValue;
    bool finderFound = false;

    for (unsigned y = 0; y<height && finderFound==false; y++)
    {
        counterOfStates[0] = 0; //Starting color
        counterOfStates[1] = 0; //first shift to new color
        counterOfStates[2] = 0; //second set of starting color
        counterOfStates[3] = 0; //second of shift color
        counterOfStates[4] = 0; //third starting color
        counterOfStates[5] = 0; //third set of shift color
        currentState = 0;
        currentBitValue = bitMap[y][0];

        for(unsigned x = 0; x < width && finderFound == false; x++)
        {
            if (bitMap[y][x]== currentBitValue)
                counterOfStates[currentState]++;
            
            else
            {
                if (currentBitValue == true)
                    currentBitValue = false;
                else
                    currentBitValue = true;

                if (currentState < 5)
                    currentState++;
                else
                    break;

                if (currentState == 3)
                {
                    leftCol = x;
                    leftRow =y;
                }

                counterOfStates[currentState]++;
            }

            finderFound = ratioChecker(counterOfStates); 
        }
    }
}

void qrDecoder::findRightFinder (bool**bitMap, unsigned width, unsigned height)
{
    int counterOfStates[6]={0};
    int currentState;
    bool currentBitValue;
    bool finderFound = false;

    for (unsigned y = 0; y<height && finderFound==false; y++)
    {
        counterOfStates[0] = 0; //Starting color
        counterOfStates[1] = 0; //first shift to new color
        counterOfStates[2] = 0; //second set of starting color
        counterOfStates[3] = 0; //second of shift color
        counterOfStates[4] = 0; //third starting color
        counterOfStates[5] = 0; //third set of shift color
        currentState = 0;
        currentBitValue = bitMap[y][width];

        for(unsigned x = width; x > 0 && finderFound == false; x--)
        {
            if (bitMap[y][x]== currentBitValue)
                counterOfStates[currentState]++;
            
            else
            {
                if (currentBitValue == true)
                    currentBitValue = false;
                else
                    currentBitValue = true;

                if (currentState < 5)
                    currentState++;
                else
                    break;

                if (currentState == 3)
                {
                    rightCol = x;
                    rightRow =y;
                }

                counterOfStates[currentState]++;
            }

            finderFound = ratioChecker(counterOfStates); 
        }
    }
}

bool qrDecoder::ratioChecker (int counter[])
{
    int totalFinderSize = 0;

    for (int i=1; i < 6; i++)
    {
        int count = counter[i];
        totalFinderSize += count;
        if (count == 0)
            return false;
    }

    if (totalFinderSize < 7)
        return false;
    
    moduleSize = ceil (totalFinderSize / 7.0);
    maxVariance = moduleSize/2; 

    if (((moduleSize - counter[1])<=maxVariance) &&
        (moduleSize - (counter[2]) <= maxVariance) && 
        (3*moduleSize - (counter[3]) <= maxVariance) &&
        (moduleSize - (counter[4]) <= maxVariance) && 
        (moduleSize - (counter[5]) <= maxVariance))

        return true;
    else
    {
        return false;
    }
}

void qrDecoder::createModuleMap(bool** bitmap,unsigned width, unsigned height)
{
    moduleRows = ceil(height/moduleSize);
    moduleCols = ceil(width/moduleSize);
    
    moduleMap = alloc2D_bool(moduleRows,moduleCols);

    for (unsigned i=0; i <moduleRows;i++)
    {
        for(unsigned j=0;j<moduleCols;j++)
        {
            moduleMap[i][j]=bitmap[i*moduleSize][j*moduleSize];
        }
    }
}

bool qrDecoder::findPattern1(bool**map, unsigned mapCols, unsigned mapRows)
{
    unsigned differenceBetweenLeftAndRight = rightCol -leftCol;
    int counterOfStates[6]={0};
    int currentState= 1;
    bool finderFound = false;

    finder1Row = leftRow + differenceBetweenLeftAndRight;
    finder1Col = leftCol;

    finder2Row = leftRow;
    finder2Col = leftCol;

    finder3Row = rightRow;
    finder3Col = rightCol;

    bool currentColor = map[finder1Row][finder1Col-3];

       counterOfStates[0] = 0; //Starting color
        counterOfStates[1] = 0; //first shift to new color
        counterOfStates[2] = 0; //second set of starting color
        counterOfStates[3] = 0; //second of shift color
        counterOfStates[4] = 0; //third starting color
        counterOfStates[5] = 0; //third set of shift color

    for (unsigned x= finder1Col-3; x < finder1Col+4 && finderFound == false; x++)
    {   
        if (map[finder1Row][x]== currentColor)
            counterOfStates[currentState]++;
            
        else
        {
            if (currentColor == true)
                currentColor = false;
            else
                currentColor = true;

            if (currentState < 5)
                currentState++;

            counterOfStates[currentState]++;
        }

        finderFound = ratioChecker(counterOfStates); 
    }
    return finderFound;
}

void qrDecoder::findLeftCenter(bool** map, unsigned startCol, unsigned startRow)
{
    bool currentColor = map[startRow][startCol];
    unsigned y=0;

    leftCol +=1;
    
    while (currentColor == map[startRow+y][startCol])
    {
        y++;
    }

    if (y == 1)
    {
        leftRow -=1;
    }
    else if (y == 3)
    {
        leftRow +=1;
    }
    else
    {
        leftRow = leftRow;
    }
}

void qrDecoder::findRightCenter(bool** map, unsigned startCol, unsigned startRow)
{
    bool currentColor = map[startRow][startCol];
    unsigned y=0;

    rightCol -=1;
    
    while (currentColor == map[startRow+y][startCol])
    {
        y++;
    }

    if (y == 1)
    {
        rightRow -=1;
    }
    else if (y == 3)
    {
        rightRow +=1;
    }
    else
    {
        rightRow = leftRow;
    }   
}

int qrDecoder::calculateTheVersion()
{
    unsigned startPointCol = finder2Col + 4;
    unsigned startPointRow = finder2Row + 3;
    unsigned endPointCol = finder3Col-4;
    unsigned endPointRow = finder3Row+3;
    int counterOfStates[2] ={0};
    int currentState = 0;
    int version;
    bool currentColor = moduleMap[startPointRow][startPointCol];

    for (unsigned x= startPointCol; x <=endPointCol; x++)
    {
        if (currentColor == moduleMap[startPointRow][x])
        {
            counterOfStates[currentState] ++;
        }
        else
        {
            if(currentColor == true)
                currentColor = false; 
            else
                currentColor = true;

            if (currentState == 0)
                currentState = 1;
            else 
                currentState = 0;
            
            counterOfStates[currentState]++;
        }   
    }
    version = (counterOfStates[0] - 2) / 2;
    return version;
}

char qrDecoder::findErrorCorrectionCode()
{
    unsigned startPointRow = finder2Row + 5;
    unsigned startPointCol = finder2Col - 3;
    bool knownBlankValue = moduleMap[startPointRow-1][startPointCol];
    bool startPointValue = moduleMap[startPointRow][startPointCol];
    bool endPointValue = moduleMap[startPointRow][startPointCol+1];

    if (knownBlankValue == startPointValue && knownBlankValue == endPointValue)
        return 'H';
    else if (knownBlankValue == startPointValue && knownBlankValue != endPointValue)
        return 'Q';
    else if (knownBlankValue != startPointValue && knownBlankValue == endPointValue)
        return 'M';
    else
        return 'L';
}

unsigned qrDecoder::findMaskingPattern ()
{
    unsigned startPointRow = finder2Row + 5;
    unsigned startPointCol = finder2Col - 1;
    bool knownBlankValue = moduleMap[startPointRow-1][startPointCol];
    bool startPointValue = moduleMap[startPointRow][startPointCol];
    bool midPointValue = moduleMap[startPointRow][startPointCol +1];
    bool endPointValue = moduleMap[startPointRow][startPointCol+2];

    if (knownBlankValue == startPointValue && knownBlankValue ==midPointValue &&
         knownBlankValue == endPointValue)
        return 5;
    else if (knownBlankValue == startPointValue && knownBlankValue ==midPointValue &&
         knownBlankValue != endPointValue)
        return 4;
    else if (knownBlankValue == startPointValue && knownBlankValue !=midPointValue &&
         knownBlankValue == endPointValue)
        return 7;
    else if (knownBlankValue == startPointValue && knownBlankValue !=midPointValue &&
         knownBlankValue != endPointValue)
        return 6;
    else if (knownBlankValue != startPointValue && knownBlankValue ==midPointValue &&
         knownBlankValue == endPointValue)
        return 1;
    else if (knownBlankValue != startPointValue && knownBlankValue ==midPointValue &&
         knownBlankValue != endPointValue)
        return 0;
    else if (knownBlankValue != startPointValue && knownBlankValue !=midPointValue &&
         knownBlankValue == endPointValue)
        return 3;
    else if (knownBlankValue != startPointValue && knownBlankValue !=midPointValue &&
         knownBlankValue != endPointValue)
        return 2;
}

string qrDecoder::findEncodeType (int maskingPattern)
{
    unsigned startPointRow = finder1Row+2;
    unsigned startPointCol = finder3Col+2;
    bool startingValue = moduleMap[finder1Row][finder1Col];
    string encoder;
    char bit;
    


    for (unsigned y = startPointRow; y <= (startPointRow +1); y++)

        for (unsigned x = startPointCol; x <= (startPointCol+1); x++)
        {
            bit = applyMask(maskingPattern, moduleMap[y][x],y, x);

            encoder.push_back(bit);
        }

    for (unsigned y = 0; y < moduleRows; y++)
    {
        for (unsigned x = 0; x < moduleCols; x++)
        {
            if (y == startPointRow && x == startPointCol)
            {
                cout << "S";
            }
            else
            {
                cout << moduleMap[y][x];
            }
            
        }
        cout << endl;
    }

    return encoder;
}

char qrDecoder::applyMask(int maskingPattern,bool value, unsigned rows, unsigned cols)
{
    int newValue;
    unsigned maskValue;

    switch (maskingPattern)
    {
        case 0:
            maskValue = (rows+cols)%2;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
        case 1:
            maskValue = (rows)%2;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
        case 2:
            maskValue = (cols)%3;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
        case 3:
            maskValue = (rows+cols)%3;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
        case 4:
            maskValue = unsigned(floor(rows/2.0)+floor(cols/3.0))%2;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
        case 5:
            maskValue = ((rows*cols)%2)+((rows*cols)%3);
            if (maskValue == 0)
            {
                if (value == true)
                      newValue = '0';
                else
                    newValue = '1'; 
            }
        case 6:
            maskValue = (((rows*cols)%2)+((rows*cols)%3))%2;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
        case 7:
            maskValue = (((rows+cols)%2)+((rows*cols)%3))%2;
            if (maskValue == 0)
            {
                if (value == true)
                    newValue = '0';
                else
                    newValue = '1'; 
            }
    }

    return newValue;
}