// Assembly project 6 part 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int a[5] = {9,3,22,8,1};
int n = 0;
int x =0, y = 0;

void test()
{
	cout << a[0] <<", " << a[1] << ", " << a[2] << ", " << a[3] << ", " << a[4] << endl;
}
int main()
{
	__asm {
	call test;
	loop2:
		mov eax, 0;//place to store values
		mov ebx, 0;//start position modifer
		mov ecx, 0;//place to store values
		mov n, 0;
		cmp x, 4;
		je done2;
		inc x;
	loop1:
		cmp n, 4;
		je done1;
		inc n;
		mov eax, [a + ecx];
		mov ebx, [a + ecx + 4];

		cmp eax, ebx;
		jg true1;
	false1:
		add ecx, 4;
		jmp loop1;

	true1:
		mov [a + ecx + 4], eax;
		mov [a + ecx], ebx;
		add ecx, 4;
		jmp loop1;
	
	done1:
		jmp loop2;
	done2:
		call test;
	}
	cin >> x;

    return 0;
}

