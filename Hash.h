#pragma once
#include<iostream>
#include <string>
#include "Check.h"
#include "Struct.h"
#include "Tree.h"
using namespace std;



// ��������� ����
int hash_position(string r);

// ���������� ����������
void add_guest(Hash**& Table);

// ����� �����������
void show_guests(Hash**& Table);

// �������� ����������
void del_guest(Hash**& Table, Data*& start, Data*& end);

// �������� ���� ����������
void delete_all_guests(Hash**& Table, Data*& start, Data*& end);





///////////////////////////
// ���������
void check_in(Data*& start, Data*& end, Three*& element, Hash**& Table);

// ���������
void check_out(Data*& start, Data*& end, Three*& element, Hash**& Table);
/////////////////////////








void search_to_FUO_guests(Hash**& Table);

void sPasportInData (Data*& start, Data*& end, string pasport_from_Hashing);

void search_to_pasport(Hash**& Table, Data*& start, Data*& end);

////////////////////////////////////Strange thing
void H2(Hash**&Table, string pasport);
////////////////////////////////////


///////////////////////////////////
void H1(Data*& start, Data*& end, Hash**&, string hotelroom);
///////////////////////////////////


bool SPasportInHash(Hash**& Table, string pasport_from_data);

