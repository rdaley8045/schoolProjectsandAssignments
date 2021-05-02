#ifndef WA4_H
#define WA4_H
#include "node.h"

#define NODE_HEIGHT(n) (!n ? -1 : n->ht)

Node *insert(Node*, int);
int height(Node *);
Node *rightRotate(Node * low);
Node *leftRotate(Node * mid);

#endif

