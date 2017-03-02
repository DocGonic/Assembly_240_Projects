// Assembly project 5 part 2.cpp : Defines the entry point for the console application.
//
//
//Assembly 240 Project 5 Part 2
//Students Max Krochman, Tom Abrahams
//

#include "stdafx.h"
#include <iostream>


using namespace std;


int userPin = 0, pinSum = 0, counter = 0;
char errorAnswer = ' ';
void userInput()
{
	cout << "Enter a four digit int PIN number: ";
	cin >> userPin;
	cout << endl;
}
void errorMsg()
{
	cout << userPin << " is not a valid PIN number" << endl;
	cout << "Do you want to try again(y/n)? ";
	cin >> errorAnswer;
	cout << endl;
}
void errorMsgToBig()
{
	cout << userPin << " is greater than 4 digits" << endl;
	cout << "Do you want to try again(y/n)? ";
	cin >> errorAnswer;
	cout << endl;
}

void finaOutput()
{
	cout << userPin << " is a valid PIN number" << endl;
	cin >> userPin;
	
}

int main()
{
	__asm {
	Start:
		mov counter, 0;
		mov errorAnswer, ' ';
		mov pinSum, 0;
		call userInput;
		mov eax, userPin;
		cmp eax, 9999;
		jle under_10000;
	over_9999:
		call errorMsgToBig;
		cmp errorAnswer, 'y'
			je Start;
		cmp errorAnswer, 'Y'
			je Start;
		jmp ErrorEnd;
	under_10000:
		mov errorAnswer, ' ';
		inc counter;
		cdq;
		mov ebx, 10;
		idiv ebx;
		add pinSum, edx;
		mov ecx, counter;
		cmp counter, 4;
		je testForOdd;
		jmp under_10000;

	testForOdd:
		mov eax, pinSum;
		and eax, 1;
		cmp eax, 1;
		je oddNumb;
		jmp Exit;
	oddNumb:
		call errorMsg;
		cmp errorAnswer, 'y'
			je Start;
		cmp errorAnswer, 'Y'
			je Start;
		jmp ErrorEnd;

	Exit:
		call finaOutput;
	ErrorEnd:
	}
    return 0;
}

