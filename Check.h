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

// ��� �������� ����� �����
void isDigit(int& digit);

// �������� �� ���� ��������
void checkPasport(string& pass);


// ��������, ���� �� � ������������ ����� �� �����
bool CheckPassportInList(Data*& start, Data*& end, string pass);


// �������� �� ���� ������
void checkRoom(string& value);


//��� �������� ������
int height(Three*& element);

bool bathroomIS();


// ��������, ����� �� ���-�� � ������
bool check_room_with_guest(Data*& start, Data*& end, string room);


// �������� �� ������� ������ �������
void SNomerInTree(Three*& element, string room, int& check);


// ���������� ���������
void bubble_sort(Data*& head);

void distribution(Data*& head, Data*&  end_list);

Data* Search4Number(Data*& head,const string &str);