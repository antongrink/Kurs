#pragma once
#pragma once
#include<iostream>
#include <string>
using namespace std;
// Постоялец
struct Guest
{
	string pasport; // «NNNN-NNNNNN» N - цифры
	string all_name; // ФИО
	int year_of_birth; // Год рождения
	string address; // Адрес
	string destination_of_arrival; // Цель прибытия
};

// Гостиничный номер
struct Room
{
	string room_number; // № гостиничного номера «ANNN» где A – буква, обозначающая тип номера (Л – люкс, П – полулюкс, О – одноместный, М – многоместный), N - цифры
	int all_places; // Всего мест
	int place_ready; // Свободных мест
	int all_rooms; // кол-во комнат
	bool isBathroom; // наличие санузла
	string equipment; // оборудование
};




//Структрура для хранения клиентов в хэш-таблице
struct Hash
{

	
	Guest* guest = NULL; 
	Hash* next = NULL; 


};


// Структура дерева
struct Three
{
	int height; // Высота поддерева
	Room* room = NULL; // Данные о гостиничном номере
	Three* left = NULL; // Левый элемент поддерева
	Three* right = NULL; // Правый элемент поддерева
};

//Список с информацией о заселении и выселении
struct Data
{
	string pasport; // Паспорт постояльца
	string room_number; // Номер комнаты
	string checkin_date; // Дата заселения
	string checkout_date; // Дата выселения
	Data* next = NULL; // Следующий элемент линейного списка
};