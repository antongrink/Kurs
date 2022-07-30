#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include "Menu.h"
#include "Struct.h"
#include "Check.h"
#include "Tree.h"
#include "Hash.h"

using namespace std;


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	Hash** Table = nullptr;
	Three* start = nullptr; // Создаём указатель на дерево
	Data* start_list = nullptr; // указатель на начало списка
	Data* end_list = nullptr; // указатель на конец списка
	while (true)
	{
		menu_main();
		int k;
		isDigit(k);
		cout << k;
		switch (k)
		{
		case 1:
			while (true)
			{
				system("cls");
				menu_guests();
				int k1;
				isDigit(k1);
				int l = 0;
				switch (k1)
				{
				case 1:
					system("cls");
					add_guest(Table);
					break;
				case 2:
					system("cls");
					del_guest(Table, start_list, end_list);
					break;
				case 3:
					system("cls");
					show_guests(Table);
					break;
				case 4:
					system("cls");
					search_to_pasport(Table, start_list, end_list);
					break;
				case 5:
					system("cls");
					search_to_FUO_guests(Table);
					break;
				case 6:
					system("cls");
					delete_all_guests(Table, start_list, end_list);
					break;
				case 0:
					l++;
					break;
				}
				if (l == 1)
				{
					system("cls");
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				system("cls");
				menu_hotelroom();
				int k2;
				isDigit(k2);
				int l = 0;
				switch (k2)
				{
				case 1:
				{
					system("cls");
					string room = generate_hotelroom();
					add_hotelroom(start, room);
					system("pause");
					break;
				}
				case 2:
				{
					system("cls");
					string value;
					cout << "Введите номер комнаты «ANNN», где A – тип номера, N - цифры: ";
					checkRoom(value);
					del_hotelroom(start, value, start_list, end_list);
					system("pause");
					break;
				}
				case 3:
					system("cls");
					show_hotelrooms(start);
					system("pause");
					break;
				case 4:
				{
					system("cls");
					string value;
					cout << "Введите номер комнаты «ANNN» где A – тип номера, N - цифры: ";
					checkRoom(value);
					search_to_hotelroom(start, start_list, end_list, Table, value); //Поиск в дереве номера по имени номера
					system("pause");
					break;
				}
				case 5:
				{
					system("cls");
					string value;
					cout << "Введите оборудование: ";
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, value);
					system("cls");
					equipment_search(start, value);
					system("pause");
					break;
				}
				case 6:
					system("cls");
					delete_all_rooms(start, start_list, end_list);
					system("pause");
					break;
				case 0:
					l++;
					break;
				}
				if (l == 1)
				{
					system("cls");
					break;
				}
			}
			break;
		case 3:
			while (true)
			{
				system("cls");
				menu_checkin_and_checkout();
				int k3;
				isDigit(k3);
				int l = 0;
				switch (k3)
				{
				case 1:
					system("cls");
					check_in(start_list, end_list, start, Table);
					distribution(start_list, end_list);
					
					system("pause");
					break;
				case 2:
					system("cls");
					check_out(start_list, end_list, start, Table);
					distribution(start_list, end_list);
					
					system("pause");
					break;
				case 0:
					l++;
					break;
				}
				if (l == 1)
				{
					system("cls");
					break;
				}
			}
			break;
		case 0:
			return 0;
		}
	}
}