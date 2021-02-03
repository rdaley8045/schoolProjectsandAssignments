#ifndef QRDECODER_H
#define QRDECODER_H
#include <cmath>
#include "alloc2d.h"
#include <string>

using namespace std;

class qrDecoder
{
    public:

    void findThePattern(bool **, unsigned, unsigned);
    int calculateTheVersion();
    char findErrorCorrectionCode();
    unsigned findMaskingPattern();
    string findEncodeType(int);
    private:

    bool finderPattern1;
    bool uppperLeft =false, uppperRight=false, lowerLeft=false, lowerRight =false;
    bool **moduleMap , **qrMap;

    unsigned leftRow =0, leftCol =0, rightRow =0, rightCol =0; 
    unsigned moduleSize, maxVariance, moduleRows, moduleCols;
    unsigned finder1Row, finder1Col, finder2Row, finder2Col, finder3Row;
    unsigned finder3Col;

    void findLeftFinder(bool**, unsigned, unsigned);

    void findRightFinder(bool**, unsigned, unsigned);
  
    bool ratioChecker (int counter[]);

    void createModuleMap(bool** ,unsigned , unsigned);

    bool findPattern1(bool**, unsigned, unsigned);

    void findLeftCenter(bool**, unsigned, unsigned);

    void findRightCenter(bool**, unsigned, unsigned);

    char applyMask(int, bool, unsigned, unsigned); 

    void createQRMap ();


};


#endif