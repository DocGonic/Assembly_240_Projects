// AssemblyAssignment3Part4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

short a = 0, b = 0, c = 0;
short d = 0, e = 0, f = 0;
short x = 0, y = 0;

short temp1 = 0, temp2 = 0;
short upperHalf = 0, lowerHalf = 0;
short zero = 0, negitiveOne = -1;


void mainMessage()
{
	cout << "This program solves the system" << endl << "aX + bY =c" << endl;
	cout << "dX + eY = f" << endl;
	cout << "ENter the values of a,b, and c:";
	cin >> a >> b >> c;
	cout << endl;
	cout << "Enter the values of d,e, and f:";
	cin >> d >> e >> f;
	cout << endl;
}

void endMessage()
{
	cout << "X =" << x << "      " << "Y =" << y;
	cin >> x;// to pause program
}

int main()
{
	__asm {
		call mainMessage;
		//First calculating Y
		//Firstly the Upper half of the equation
		//(a*f - c*d)
		mov ax, a;
		mov bx, f;
		mul bx;
		mov temp1, ax;

		mov ax, c;
		mov bx, d;
		mul bx;
		mov temp2, ax;

		mov ax, temp1;
		mov bx, temp2;
		sub ax, bx;
		mov upperHalf, ax;
		//Then the lower half
		//(a*e - b*d)
		mov ax, a;
		mov bx, e;
		mul bx;
		mov temp1, ax;

		mov ax, b;
		mov bx, d;
		mul bx;
		mov temp2, ax;

		mov ax, temp1;
		mov bx, temp2;
		sub ax, bx;
		mov lowerHalf, ax;
			//final Y calc
		mov ax, upperHalf;
		mov bx, lowerHalf;
		idiv bx;
		mov y, ax;
		//Lastly calculate X
		//Top Half
		//(c*e - b*f)
		mov ax, c;
		mov bx, e;
		mul bx;
		mov temp1, ax;

		mov ax, b;
		mov bx, f;
		mul bx;
		mov temp2, ax;

		mov ax, temp1;
		mov bx, temp2;
		sub ax, bx;
		mov upperHalf, ax;
		
		//Lower half
		//(a*e - b*d)
		mov ax, a;
		mov bx, e;
		mul bx;
		mov temp1, ax;

		mov ax, b;
		mov bx, d;
		mul bx;
		mov temp2, ax;

		mov ax, temp1;
		mov bx, temp2;
		sub ax, bx;
		mov lowerHalf, ax;
			//final X calc
		mov ax, upperHalf;
		mov bx, lowerHalf;
		imul negitiveOne;
		idiv bx;
		imul negitiveOne;
		mov x, ax;
		call endMessage;
	}

    return 0;
}

