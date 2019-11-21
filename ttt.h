#ifndef _TTT_H
#define _TTT_H

#include <iostream>
#include <bitset>
#include <stdio.h>
#include <cstdlib>
#include <ctime> 
#define w1 0b100100100
#define w2 0b010010010
#define w3 0b001001001
#define w4 0b111000000
#define w5 0b000111000
#define w6 0b000000111
#define w7 0b100010001
#define w8 0b001010100

using namespace std;

class TTT
{
public:
	TTT();
	void print(int a, int b);
	void In2(int* a, int* b);
	void In3(int* b, int input);
	void In(int* a, int* b);
	int vic(int* a, int* b);
	int argo1(int* a, int* b);
	int argo2(int* a, int* b);
	int argo0(int* a);
	void menu(void);
	void m1(void);
	void m2(void);
	void m3(void);
private:
	int a;
	int b;
};
#else
#endif
