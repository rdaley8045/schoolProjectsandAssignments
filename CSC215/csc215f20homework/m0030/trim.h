#ifndef __TRIM__H__
#define __TRIM__H__

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <cctype>

using namespace std;


enum trimType {BOTH, FRONT, END};

// add your prototype for you cTrim function here
void cTrim(char theString[], trimType type);

// add your prototype for your sTrim function here

void sTrim(string& theString, trimType type);

#endif
