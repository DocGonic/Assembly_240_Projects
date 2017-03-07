// Assembly project 6 part 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

int totalShirts = 0;
int totalLargeSHirts = 0;
int totalBlackShirts = 0;
int n = 0;
int a[4][4] = { { 10,20,30,40 },{ 20,10,40,30 },{5,15,20,25},{30,25,20,15} };


void ouputResults() {
	cout << "Total number of shirts: " << totalShirts << endl;
	cout << "Total number of Large shirts: " << totalLargeSHirts << endl;
	cout << "Total number of Black shirts: " << totalBlackShirts << endl;

	cin >> totalShirts;
}

int main()
{
	__asm {
		//////////////////////////////////////////////////////////////////////////
		//Total number of shirst
		mov eax, 0; // totalShirts =0
		mov ebx, 0;
		mov n, 0; // n=0

	loop1:
		cmp n, 16;    //for (n=0; n<4; n++)
		je display1;

		add eax, [a + ebx]; // sum +=a[i]
		inc n; //n++;
		add ebx, 4; // next location(moving number of bits, in this case 4 cause INT is 4 bits)
		jmp loop1;

	display1:
		mov totalShirts, eax;
	///////////////////////////////////////////////////////////////////////////////
	// Total number of Large shirst
		mov eax, 0; // totalLargeShirts =0
		mov ebx, 12;
		mov n, 0; // n=0

	loop2:
		cmp n, 4;    //for (n=0; n<4; n++)
		je display2;

		add eax, [a + ebx]; // sum +=a[i]
		inc n; //n++;
		add ebx, 16; // next location(moving number of bits, in this case 4 cause INT is 4 bits)
		jmp loop2;

	display2:
		mov totalLargeSHirts, eax;
		////////////////////////////////////////////////////////////////////////////////
		// total of black shirts
		mov eax, 0; // totalLargeShirts =0
		mov ebx, 48;
		mov n, 0; // n=0

	loop3:
		cmp n, 4;    //for (n=0; n<4; n++)
		je display3;

		add eax, [a + ebx]; // sum +=a[i]
		inc n; //n++;
		add ebx, 4; // next location(moving number of bits, in this case 4 cause INT is 4 bits)
		jmp loop3;

	display3:
		mov totalBlackShirts, eax;


		call ouputResults;
	}

    return 0;
}

