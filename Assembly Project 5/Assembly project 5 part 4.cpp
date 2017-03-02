// Assembly project 5 part 4.cpp : Defines the entry point for the console application.
//
//
//Assembly 240 Project 5 Part 4
//Students Max Krochman, Tom Abrahams
//

#include "stdafx.h"
#include <iostream>

using namespace std;

short var = 0;
int counter = 0;

void elevatorMsg()
{
	cout << endl << "Eleavator will stop at floors NO. ";
}
void outPutFloors()
{
	cout << counter << " ";
}

void outputOne()
{
	cout << '1';
}
void outputZero()
{
	cout << "0";
}
void outputAX()
{
	cout << "AX= ";
}

int main()
{
	__asm {

		mov bx, 16;
		call outputAX;
	Cloop1:
		mov ax, 1001000100001100b;
		inc counter;//Add one to counter
		dec bx;//subtract 1 from BX value
		bt ax, bx;//Test(with Bit Test) the bx'th bit in the AX register and stores it in the CF(carry flag)
		jc one1;//True if CF(carry flag is value 1/False if 0)
	zero0:
		call outputZero;
		jmp check1;
	one1:
		call outputOne;
		jmp check1;
	check1:
		cmp counter, 15;
		jle Cloop1;





		mov bx, 0;
		mov counter, 1;
		call elevatorMsg;
	Cloop:
		mov ax, 1001000100001100b;
		inc counter;//Add one to counter
		inc bx;//subtract 1 from BX value
		bt ax, bx;//Test(with Bit Test) the bx'th bit in the AX register and stores it in the CF(carry flag)
		jc yesStop;//True if CF(carry flag is value 1/False if 0)
	noStop:
		jmp check;
	yesStop:
		call outPutFloors;
		jmp check;
	check:
		cmp counter, 16;
		jle Cloop;
	}
	cin >> var;
    return 0;
}

