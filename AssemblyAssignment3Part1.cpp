//Computer Science 240
//Project Number 3 (division, multiplication, and making decisions)
//Students: Abrahams, Thomas; Krochman, Max
// Part 1
// Due Feb 16th 2017
//
#include<iostream>


using namespace std;

short drinkNum = 0;
short drinkType = (short)'W';
short sandwichNum;
short sandwichSize = 10;
short total = 0;

void menu() {
	char myDrinkType;
	cout << "---------------7-11 Convenient Store ---------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(S)..............................$2" << endl;
	cout << "\tWater(W).............................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inches............................$3" << endl;
	cout << "\t12 inches............................$5" << endl;
	//This is how many drinks...
	cout << "How many drinks? ";
	cin >> drinkNum;


	//This is what type of drink
	cout << "\tWhat kind of drink (S=Soda, W=Water)? ";
	cin >> myDrinkType;
	//This is how many sandwiches;

	cout << "How many sandwiches?";
	cin >> sandwichNum;
	cout << endl << "\tWhat size of sandwich (10/12 inches)? ";
	cin >> sandwichSize;
	myDrinkType = toupper(myDrinkType);
	//cout << "Get ready" << endl;
	drinkType = (short)myDrinkType;
}
void thankYou()
{
	cout << "Your total bill is " << total << endl;
	system("Pause");
}


int main() {


	__asm {
		call menu;
		mov ax, drinkNum;		//ax = num of drinks
		mov bx, sandwichNum;	//bx = num of sandwiches
		mov cx, drinkType;		//cx = types of drinks		
		cmp cx, 'W';
		je true1;
	false1:
		cmp cx, 'S'; //Check if soda
		jmp true2;
	true1:
		//Drinks multiplied by 1		
		mov total, ax; //total = 1*drinks
		jmp testSandwich;
	true2:
		mov bx, 2; //bx = 2
		cwd; //Ready multiplication.
		imul ax, bx; //ax = 2*soda
		mov total, ax; //total = 2*soda
	testSandwich:
		mov ax, sandwichNum; //Num of sandwiches
							 //Get sandwich type.
		mov cx, sandwichSize; //Get the size
							  //See if it is 10 inches
		cmp cx, 10;
		je sandTen;
	sandTwelve:
		mov ax, sandwichNum; //Num of Sandwiches
		cwd; //prepare 12 inches * 5
		imul ax, 5; //sand*12
		add total, ax; //Gets total.
		jmp finish;
	sandTen:
		mov ax, sandwichNum; //Num of Sandwiches
		cwd; //prepare 12 inches * 5
		imul ax, 3; //sand*3
		add total, ax; //Gets total.
		jmp finish;
	finish:
		call thankYou;

	}


}