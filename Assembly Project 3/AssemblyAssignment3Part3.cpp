//Computer Science 240
//Project Number 3 (division, multiplication, and making decisions)
//Students: Abrahams, Thomas; Krochman, Max
// Part 3
// Due Feb 16th 2017
//
#include<iostream>
#include<cstdio>

using namespace std;
short adultMalePrice = 100;
short teenMalePrice = 75;
short adultFemPrice = 80;
short teenFemPrice = 85;
short age = 0;
char gender = 'M';
short total = 0;
char male = 'M';
char female = 'F';

void menu()
{
	cout << "--------------------ACE CLUB--------------------" << endl;
	cout << "Male" << endl;
	cout << "\tAdult( age > 19 ).......................$100" << endl;
	cout << "\tTeenager( age 13-19 )....................$75" << endl;
	cout << "Female" << endl;
	cout << "\tAdult( age > 19 ).......................$80" << endl;
	cout << "\tTeenager( age 13-19 )...................$85" << endl;
	cout << "How old are you? ";
	cin >> age;
	cout << "What is your gender (M/F)? ";
	char myGender;
	cin >> myGender;
	//Convert
	gender = myGender;
	


}
void thankyou()
{
	cout << "Your membership is $" << total << endl;

}
void kidWarn()
{
	cout << "You are a kid. No membership for you" << endl;

}
void theEnd()
{
	cout << "Thank you for your time." << endl;
	system("Pause");
}

int main()
{
	__asm {
		//gender, age,
		//Determine gender
	menu:
		call menu; //Menu gets variables.
		mov al, gender; //al = gender
		cmp al, male;
		je male1;
		cmp al, 'm';
		je male1;
		//Check for female.
		mov al, female;
		cmp al, female;
		je female1;
		//Check for female lowercase
		mov al, female;
		cmp al, 'f';
		je female1;
		jmp menu;
	female1:
		mov ax, age; //ax = age
		cmp ax, 20; //
		jge femaleTwenty;
		cmp ax, 13;
		jge female13to19;
		jmp kid;
	femaleTwenty:
		//20 years old female.
		mov total, 80;
		jmp finish;
	female13to19:
		mov ax, age;
		mov total, 85;
		jmp finish;
	male1:
		mov ax, age; //ax = age
		cmp ax, 20; //
		jge maleTwenty;
		cmp ax, 13;
		jge male13to19;
		jmp kid;
	maleTwenty:
		//20 years old female.
		mov total, 100;
		jmp finish;
	male13to19:
		mov ax, age;
		mov total, 75;
		jmp finish;
	kid:
		call kidWarn;
		jmp endgame;

	finish:
		call thankyou;

	endgame:
		call theEnd;
	}
	return 0;
}