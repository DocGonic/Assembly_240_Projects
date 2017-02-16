//Computer Science 240
//Project Number 3 (division, multiplication, and making decisions)
//Students: Abrahams, Thomas; Krochman, Max
// Part 2
// Due Feb 16th 2017
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int intergerInput = 0;
int negitiveOne = -1;
int average = 0;
int counter = 0;
int one = 1;
int emptyInt = 0;
int decPlace = 0;

void mainMessage() {
	cout << "Let's compute your score's average:" << endl;
}

void loopMessage()
{
	cout << "Enter your score(-1 to stop): ";
	cin >> intergerInput;
}
void endMessage()
{
	cout << endl << "Your Average is " << average << endl;
	cin >> average;// just to pause the program for user input before closing so results can be seen.
}

int main() {
	__asm {
		call mainMessage;
		mov ebx, negitiveOne;// place the -1 value in the ebx reg
	LoopBack:
		call loopMessage;
		mov eax, intergerInput;
		cmp negitiveOne, eax;// Flag EAX and the Negitive ONe value for INput
		je True;// Test if the User input equals -1
	False://If input does not equal -1
		add average, eax;
		mov ecx, counter;
		add ecx, 1;
		mov counter, ecx;
		jmp LoopBack;

	True://If input equals -1
		mov eax, average;
		mov ecx, counter;
		cdq;
		idiv ecx;
		mov average, eax;//Moving averge calc from EAX to average Int Var for cout later
		call endMessage;
	}
	return 0;
}