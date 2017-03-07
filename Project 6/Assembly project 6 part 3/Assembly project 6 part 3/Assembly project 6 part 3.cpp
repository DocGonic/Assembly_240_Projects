// Assembly project 6 part 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

short a[3][3][2] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
short x = 0;
short n = 0;
short totalSum=0;
short totalMed = 0;
short totalShort = 0;
short totalRed = 0;

void display1()
{
	cout << "Total number of shirts: " << totalSum << endl;
	cout << "Total number of Med shirts: " << totalMed << endl;
	cout << "Total number of Short Sleeve shirts: " << totalShort << endl;
	cout << "Total number of Red shirts: " << totalRed << endl;
	cin >> x;
}

int main()
{
	__asm {
/////////////////////////////////////////
		//Total number of all shirts
		mov ax, 0;
		mov ebx, 0;
	loop1:
		cmp n, 18;
		je done1;
		inc n;
		mov ax, [a + ebx];
		add bx, 2;
		add totalSum, ax;
		jmp loop1;
	done1:
///////////////////////////////////////
		//total number of medium size shirts

		mov ecx, 0;
	loop3:
		mov ax, 0;
		mov ebx, 2;
		mov n, 0;
	loop2:
		cmp n, 3;
		je done2;
		inc n;
		mov ax, [a + ebx + ecx];
		add bx, 6;
		add totalMed, ax;
		jmp loop2;

	done2:
		cmp ecx, 18;
		je Exit1;
		mov ecx, 18;
		jmp loop3;
	Exit1:
///////////////////////////////////////////////////
		//Total number of SHort sleeves shirts
		mov ax, 0;
		mov ebx, 0;
		mov n, 0;
	loop4:
		cmp n, 9;
		je done4;
		inc n;
		mov ax, [a + ebx];
		add bx, 2;
		add totalShort, ax;
		jmp loop4;
	done4:
/////////////////////////////////////////////////////
		//Total number of RED shirts
		mov ecx, 0;
	loop6:
		mov ax, 0;
		mov ebx, 0;
		mov n, 0;
	loop5:
		cmp n, 3;
		je done5;
		inc n;
		mov ax, [a + ebx + ecx];
		add bx, 2;
		add totalRed, ax;
		jmp loop5;
	done5:
		cmp ecx, 18;
		je Exit3;
		mov ecx, 18;
		jmp loop6;

	Exit3:

		call display1;
	}
    return 0;
}

