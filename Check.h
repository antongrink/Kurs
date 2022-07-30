#pragma once
#pragma once
#include<iostream>
#include <string>
#include "Struct.h"
using namespace std;


void isName(string& temp);

void isString(string& temp);

string inputArress(string& temp);

void InputFullDate(string& birthdayDate);

// Для проверки ввода числа
void isDigit(int& digit);

// Проверка на ввод паспорта
void checkPasport(string& pass);


// Проверка, есть ли у пользователя книги на руках
bool CheckPassportInList(Data*& start, Data*& end, string pass);


// Проверка на ввод номера
void checkRoom(string& value);


//для проверки высоты
int height(Three*& element);

bool bathroomIS();


// Проверка, живет ли кто-то в номере
bool check_room_with_guest(Data*& start, Data*& end, string room);


// Проверка на наличие номера комнаты
void SNomerInTree(Three*& element, string room, int& check);


// Сортировка пузырьком
void bubble_sort(Data*& head);

void distribution(Data*& head, Data*&  end_list);

Data* Search4Number(Data*& head,const string &str);