#pragma once
#include<iostream>
#include <string>
using namespace std;
// ???????? ????
void menu_main()
{
	cout << "????\n"
		<< "1. ?????????\n"
		<< "2. ??????????? ?????\n"
		<< "3. ???????? ? ????????? ???????????\n"
		<< "0. ?????????? ??????\n";
	cout << "=====================\n???????? ????????:  ";
}

// ???? ??????????
void menu_guests()
{
	cout << "?????????\n"
		<< "1. ??????????? ??????????\n"
		<< "2. ???????? ??????????\n"
		<< "3. ???????? ???????????\n"
		<< "4. ????? ?????????? ?? ????????\n"
		<< "5. ????? ?????????? ?? ???\n"
		<< "6. ???????? ???? ???????????\n"
		<< "0. ??????? ? ????\n";
	cout << "=======================================\n???????? ????????:  ";
}

// ???? ???????????? ??????
void menu_hotelroom()
{
	cout << "??????????? ?????\n"
		<< "1. ?????????? ??????\n"
		<< "2. ???????? ??????\n"
		<< "3. ???????? ???? ???????\n"
		<< "4. ????? ?????? ?? ??????\n"
		<< "5. ????? ?????? ?? ????????????\n"
		<< "6. ???????? ???? ???????\n"
		<< "0. ??????? ? ????\n";
	cout << "==============================\n???????? ????????:  ";
}

// ???? ??? ????????? ? ?????????
void menu_checkin_and_checkout()
{
	cout << "???????? ? ?????????\n"
		<< "1. ?????????\n"
		<< "2. ?????????\n"
		<< "0. ??????? ? ????\n";
	cout << "=============================\n???????? ????????:  ";
}
