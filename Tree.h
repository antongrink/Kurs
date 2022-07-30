#pragma once
#include<iostream>
#include <string>
#include "Struct.h"
#include "Check.h"
#include "Hash.h"
using namespace std;

//малый левый поворот
Three* single_left_rotate(Three*& element);

//малый правый поворот
Three* single_right_rotate(Three*& element);

//большой левый поворот
Three* big_left_rotate(Three*& element);

//большой правый поворот
Three* big_right_rotate(Three*& element);

// Генерация № гостиничного номера (ANNN)
string generate_hotelroom();

// Добавление элементов в дерево
void add_hotelroom(Three*& element, string value);

// Удаление минимального значения
Room* deletemin(Three*& element);

// Вывод номеров
void show_hotelrooms(const Three* element);

// Удаление элемента из дерева
void del_hotelroom(Three*& element, string value, Data*& start, Data*& end);

// Удаление всех номеров
void delete_all_rooms(Three*& element, Data*& start, Data*& end);

bool BMsearch(string str, string substr);

void equipment_search(const Three* element, string equ);

void search_to_hotelroom(const Three* element, Data*& start, Data*& end, Hash**& Table, string room);

void SRoomAndMinusPlace(Three*& element, string room, int& count, Data*& append);

void AddPlaceInTree(Three*& element, string room);
















#pragma once
