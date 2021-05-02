#ifndef __QUADTREE_H_
#define __QUADTREE_H_

//include files
#include <iostream>
#include <math.h>
#include "alloc2d.h"

typedef unsigned char byte;
struct Node
{
  int minX = 0, minY = 0, maxX = 0, maxY = 0;
  byte color = 0;
  bool leaf = false;
  Node *topl = nullptr;
  Node *topr = nullptr;
  Node *botr = nullptr;
  Node *botl = nullptr;

  //recursively delete the tree
  ~Node(){ delete topl; delete topr; delete botr; delete botl;}
};

class quadTree
{
private:
  byte **image;
  byte **imageCopy;
  int threshold = 0;
  int leafcount = 0;

public:
  Node *root;
  quadTree();
  ~quadTree();
  byte **constructTree(byte **inImage, int height = 0, int width = 0, int thresh = 0);
  void divide(Node *&root);
  void changeColor(Node *&quadrant);
  byte findAvgColor(Node *&quadrant);
  int getCount() const;
  int getLeafs() const;
  void compressImage(Node *root);
  void whiteLines(Node *root);
  byte** decrement(byte** inImage, int height, int width);
  byte** increment(byte** inImage, int height, int width);
};

#endif