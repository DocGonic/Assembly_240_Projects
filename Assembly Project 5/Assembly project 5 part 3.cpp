// Assembly project 5 part 3.cpp : Defines the entry point for the console application.
//
//
//Assembly 240 Project 5 Part 3
//Students Max Krochman, Tom Abrahams
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int counter = 0, onSprinkelers =0;
void startOutput()
{
	cout << "AX=";
}

void outputOne()
{
	cout << "1";
}

void outputZero()
{
	cout << "0";
}
void outputOnSprinkelers()
{
	cout << endl << onSprinkelers << " sprinklers are ON" << endl;
}

void outputBroken()
{
	cout << "Defective sprinklers: ";
}

void outputDefectiveNumbers()
{
	cout << counter << " ";
}

int main()
{
	__asm {
		mov eax, 0;
		mov bx, 16;
		call startOutput;
	cloop:
		mov ax, 0x6A2F;//store proper value in AX reg
		inc counter;//Add one to counter
		dec bx;//subtract 1 from BX value
		bt ax, bx;//Test(with Bit Test) the bx'th bit in the AX register and stores it in the CF(carry flag)
		jc cone;//True if CF(carry flag is value 1/False if 0)
	zero://False section
		call outputZero;//Print out '0'
		jmp check;//jump to check for loop
	cone://True section
		call outputOne;//OUtput 1
		inc onSprinkelers;//add one to num of sprinkelers working
	check:
		cmp counter, 16;
		je on;
		jmp cloop;
	on:
		call outputOnSprinkelers;

	defective:
		mov counter, 0;
		call outputBroken;
	loop1:
		mov ax, 0x6A2F;//store proper value in AX reg
		inc counter;//Add one to counter
		dec bx;//subtract 1 from BX value
		bt ax, bx;//Test(with Bit Test) the bx'th bit in the AX register and stores it in the CF(carry flag)
		jc one1;//True if CF(carry flag is value 1/False if 0)
	zero1:
		jmp check1;
	one1:
		call outputDefectiveNumbers;
	check1:
		cmp counter, 16;
		je Exit;
		jmp loop1;
	Exit:
	}
	cin >> counter;
	return 0;
}

