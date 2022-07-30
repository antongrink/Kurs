#pragma once
#include<iostream>
#include <string>
#include "Struct.h"
#include "Check.h"
#include "Hash.h"
using namespace std;

//����� ����� �������
Three* single_left_rotate(Three*& element);

//����� ������ �������
Three* single_right_rotate(Three*& element);

//������� ����� �������
Three* big_left_rotate(Three*& element);

//������� ������ �������
Three* big_right_rotate(Three*& element);

// ��������� � ������������ ������ (ANNN)
string generate_hotelroom();

// ���������� ��������� � ������
void add_hotelroom(Three*& element, string value);

// �������� ������������ ��������
Room* deletemin(Three*& element);

// ����� �������
void show_hotelrooms(const Three* element);

// �������� �������� �� ������
void del_hotelroom(Three*& element, string value, Data*& start, Data*& end);

// �������� ���� �������
void delete_all_rooms(Three*& element, Data*& start, Data*& end);

bool BMsearch(string str, string substr);

void equipment_search(const Three* element, string equ);

void search_to_hotelroom(const Three* element, Data*& start, Data*& end, Hash**& Table, string room);

void SRoomAndMinusPlace(Three*& element, string room, int& count, Data*& append);

void AddPlaceInTree(Three*& element, string room);
















#pragma once
