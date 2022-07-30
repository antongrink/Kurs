#pragma once
#include<iostream>
#include <string>
#include "Check.h"
#include "Struct.h"
#include "Tree.h"
using namespace std;



// Получения хэша
int hash_position(string r);

// Добавление постояльца
void add_guest(Hash**& Table);

// Вывод постояльцев
void show_guests(Hash**& Table);

// Удаление постояльца
void del_guest(Hash**& Table, Data*& start, Data*& end);

// Удаление всех постоялцев
void delete_all_guests(Hash**& Table, Data*& start, Data*& end);





///////////////////////////
// Заселение
void check_in(Data*& start, Data*& end, Three*& element, Hash**& Table);

// Выселение
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

