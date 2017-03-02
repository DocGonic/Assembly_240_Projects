//
//Assembly 240 Project 5 Part 1
//Students Max Krochman, Tom Abrahams
//

#include "stdafx.h"
#include <iostream>

using namespace std;

short maxBits = 16, counter = 0, numOfPrinters = 0, numOfFloopy = 0;
int numOfMemory = 0;




void displayOutput()
{
	cout << "Number of Printers: " << numOfPrinters
		<< endl << "Number of Floppy: " << numOfFloopy
		<< endl << "Number of Memory: " << numOfMemory << "K" << endl;
	cin >> numOfPrinters;
}


int main()
{
	__asm {
	Printer:
		inc counter;//counter from 0 to 1
		mov ax, 1100111010011100b; // starts off the program with the proper value in the AX register
		shr ax, 14;// shift ax right 14 positions
		and ax, 1;// find value of 15th bit
		imul ax, counter;//Converts vaule from base 2 to 10
		add numOfPrinters, ax;// add the first part of the number of printers to the final value

		inc counter;//counter from 1 to 2
		mov ax, 1100111010011100b; // starts off the program with the proper value in the AX register
		shr ax, 15;// shift ax right 15 positions
		and ax, 1;// find value of 16th bit
		imul ax, counter;//Converts vaule from base 2 to 10
		add numOfPrinters, ax;// add the second part of the number of printers to the final value

		mov counter, 0;//Reset counter for later use
////////////////////////////////////////////////////////////////
	Floopy:
		inc counter;//counter from 0 to 1
		mov ax, 1100111010011100b; // starts off the program with the proper value in the AX register
		shr ax, 6;// shift ax right 6 positions
		and ax, 1;// find value of 6th bit
		imul ax, counter;//Converts vaule from base 2 to 10
		add numOfFloopy, ax;// add the first part of the number of floppies to final value 

		inc counter;//counter from 1 to 2
		mov ax, 1100111010011100b; // starts off the program with the proper value in the AX register
		shr ax, 7;// shift ax right 7 positions
		and ax, 1;// find value of 7th bit
		imul ax, counter;//Converts vaule from base 2 to 10
		add numOfFloopy, ax;// add the second part of the number of floopies to the final value
		inc numOfFloopy;// floopy value is 1+ reg value, adding one to normalize
	
		mov counter, 0;//Reset counter for later use
////////////////////////////////////////////////////////////////
	Memory:
		inc counter;
		mov ax, 1100111010011100b; // starts off the program with the proper value in the AX register
		shr ax, 2;
		and eax, 1;
		imul ax, counter;//Converts vaule from base 2 to 10
		add numOfMemory, eax;

		inc counter;
		mov ax, 1100111010011100b; // starts off the program with the proper value in the AX register
		shr ax, 3;
		and eax, 1;
		imul ax, counter;//Converts vaule from base 2 to 10
		add numOfMemory, eax;

		cmp numOfMemory, 0;
		je SixteenK;
		cmp numOfMemory, 1;
		je ThirtyTwoK;
		cmp numOfMemory, 2;
		je FourtyEightK;
		cmp numOfMemory, 3;
		je SixtyFourK;
		jmp Exit;
////////////////////////////////////////////////////////////////////
	SixteenK:
		mov numOfMemory, 16;
		jmp Exit;
////////////////////////////////////////////////////////////////////	
	ThirtyTwoK:
		mov numOfMemory, 32;
		jmp Exit;
////////////////////////////////////////////////////////////////////	
	FourtyEightK:
		mov numOfMemory, 48;
		jmp Exit;
////////////////////////////////////////////////////////////////////	
	SixtyFourK:
		mov numOfMemory, 64;
		jmp Exit;
////////////////////////////////////////////////////////////////////
		Exit:
	
		call displayOutput;
	}
    return 0;
}

