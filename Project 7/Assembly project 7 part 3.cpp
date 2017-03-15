// Assembly project 7 part 3.cpp : Defines the entry point for the console application.
//
//Project 7 part 3
// Students Tom Abrahams, Max Krochman

#include <iostream>

using namespace std;


float numDrink = 0;
float numSand = 0;
float tenPrice = 3.45;
float twelvePrice = 5.25;
char Soda = 'S';
char Water = 'W';
char drinkType = ' ';
int sandSize = 0;
float totalBill = 0;
float sodaPrice = 2.25;
float waterPrice = 1.75;

void menuDisplay()
{
	cout << "------------------------------7-11 Convenient Store ------------------------------" << endl;
	cout << "Drinks" << endl;
	cout << "    Soda(S)..................................................................$2.25" << endl;
	cout << "    Water (W)................................................................$1.75" << endl;
	cout << "Sandwiches" << endl;
	cout << "    10 inches................................................................$3.45" << endl;
	cout << "    12 inches................................................................$5.25" << endl;
	cout << endl << "How many drinks?";
	cin >> numDrink;
	cout << endl << "What kind of drink (S=Soda, W=Water)?";
	cin >> drinkType;
	cout << endl << "How many Sanwiches?";
	cin >> numSand;
	cout << endl << "What size of sandwhich (10/12 inches)?";
	cin >> sandSize;
}
void resultOutput()
{
	cout << "Your total bill = " << totalBill << endl;
	cout << "Enter Q to quit";
	cin >> totalBill;
}


int main()
{
	__asm {
		call menuDisplay;	//Display menu output
		mov eax, numDrink;	//place number of drinks entered into EAX reg
		mov bl, drinkType;	//place drink type cahr in BL reg
		cmp bl, Soda;		//compare BL reg to 'S' char 
		je true1;			//if compare equals true jump to true1
	false1:
		cmp bl, 's';		//compare BL reg to 's' char
		je true2;			//if compare equals true jump to true2
	false2:
		cmp bl, Water;		//compare BL reg to 'W' char
		je true3;			//if compare equals true jump to true3
	false3:
		cmp bl, 'w';		//compare BL reg to 'w' char
		je true4;			//if compare equals true jump tp true 4
	false4:
		jmp End;			//if all is false jump to End

	true4:
	true3:
		fninit;				//clear stack
		fld numDrink;		//convert numDrink to tbyte and push to stack
		fmul waterPrice;	//convert waterPrice to tbyte and multiply with top of stack
		fstp totalBill;		//convert top of stack to real(float) and pop to totalBill
		jmp Calc2;			//jump tp calc 2
	
	true2:
	true1:
		fninit;				//clear stack
		fld numDrink;		//convert numDrink to tbyte and push to stack
		fmul sodaPrice;		//convert sodaPrice to tbyte and multiply with top of stack
		fstp totalBill;		//convert top of stack to real(float) and pop to totalBill

	Calc2:
		mov ebx, sandSize;	//move sandSize to EBX reg
		cmp ebx, 10;		//compare EBX to the value 10
		je true5;			//if compare equals true jump to true5
	false5:
		cmp ebx, 12;		//compare EBX to the value 12
		je true6;			//if compare equals true jump to true6
	false6:
		jmp End;			//if all is false jump to End
	true6:
		fninit;				//clear stack
		fld numSand;		//convert numSand to tbyte and push to top of stack
		fmul twelvePrice;	//convert twelvePrice to tbyte and multiply with top of stack
		fadd totalBill;		//add totalBill to top of stack
		fstp totalBill;		//convert top of stack to real(float) and pop to totalBill
		jmp result;
	
	true5:
		fninit;				//clear stack
		fld numSand;		//convert numSand to tbyte and push to top of stack
		fmul tenPrice;		//convert tenPrice to tbyte and multiply with top of stack
		fadd totalBill;		//add totalBill to top of stack
		fstp totalBill;		//convert top of stack to real(float) and pop to totalBill
	result:
		call resultOutput;	//run resultOutput function

	End:
	}
    return 0;
}

