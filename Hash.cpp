#include "Hash.h"

static const int SIZE_TABLE = 50; // размер таблицы


void add_guest(Hash **& Table)
{
	if (!Table) {
		Table = new Hash * [50];
		for (int i = 0; i < SIZE_TABLE; i++)
 		{
			Table[i] = nullptr;
	
		}
	}
	Guest* g = new Guest;
	
	cout << "Введите номер паспорта NNNN-NNNNNN (где N - цифра): ";
	checkPasport(g->pasport); // проверка паспорта на корректность
	if (SPasportInHash(Table,g->pasport))
	{
		cout << "Человек с таким паспортом уже существует!" << endl;
		cout << "Повторите ввод " << endl;
		checkPasport(g->pasport); // проверка паспорта на корректность

	}
	cout << "Введите ФИО нового постояльца (Формат: Phamiliya Imya Otchestvo): ";
	
	isName(g->all_name);
	cout << "Введите год рождения нового постояльца: ";
	isDigit(g->year_of_birth);
	cout << "Введите адрес проживания: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	inputArress(g->address);
	cout << "Введите цель прибытия: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	inputArress( g->destination_of_arrival);
	system("cls");
	int hash = hash_position(g->pasport); // Вычисление позиции в таблице
	Hash* temp = new Hash;
	temp->guest = g;
	temp->next = Table[hash];
	Table[hash] = temp;

}




int hash_position(string r)
{
	int hash;
	hash = 13 * (int(r[0]) + int(r[1]) + int(r[2])) + 18 * (int(r[3]) + int(r[5]) + int(r[6])) + 3 * (int(r[7]) + int(r[8]) + int(r[9]) + int(r[10]));
	return hash % SIZE_TABLE;
}







void show_guests(Hash**& Table)
{
	
	int count = 0;
	for (int i = 0; i < SIZE_TABLE; i++)
	{
		
		if (Table[i] != nullptr)
		{
			Hash* Temp = Table[i];
			while (Temp) 
			{
				count++;
				cout << "Постоялец: " << Temp->guest->all_name << endl;
				cout << "Паспорт: " << Temp->guest->pasport << endl;
				cout << "Дата рождения: " << Temp->guest->year_of_birth << endl;
				cout << "================================" << endl;
				Temp = Temp->next;
			}
			
		}
		
	}
	if (!count)
	{
		cout << "Постояльцев нету\n";
		cout << "================================" << endl;
	}
	system("pause");
}

void del_guest(Hash**& Table, Data*& start, Data*& end)
{
	string pass; // тут храним паспорт
	cout << "Введите номер паспорта NNNN-NNNNNN (где N - цифра): ";
	checkPasport(pass); // вводим паспорт корректно
	// проверяем, выселился ли он или нет
	if (CheckPassportInList(start, end, pass))
	{
		cout << "===========================================================" << endl;
		cout << "Удаление постояльца невозможно, он еще не выселился\n";
		cout << "===========================================================" << endl;
		system("pause");
		return;
	}
	int count = 0; // для проверки наличия постояльца в списке
	int position = hash_position(pass);
	Hash* Prev = nullptr;
	if (Table[position]) {
		Hash* Temp = Table[position];
		while (Temp) {
			if (Temp->guest->pasport == pass && Prev != nullptr) {
				count++;
				Prev->next = Temp->next;
				delete Temp;
				Temp = nullptr;
				cout << "======================================" << endl;
				cout << "Постоялец удалён\n";
				cout << "======================================" << endl;
				system("pause");
				return;
			}
			else if(Temp->guest->pasport == pass) {
				count++;
				Table[position] = Temp->next;
				delete Temp;
				cout << "======================================" << endl;
				cout << "Постоялец удалён\n";
				cout << "======================================" << endl;
				system("pause");
				return;
			}
			Prev = Temp;
			Temp = Temp->next;
		}
		
	}

	if (!count)
	{
		cout << "======================================" << endl;
		cout << "Не найдено постояльца с таким поспортом\n";
		cout << "======================================" << endl;
	}
	system("pause");
}




void delete_all_guests(Hash**& Table, Data*& start, Data*& end)
{
	if (start != nullptr)
	{
		cout << "Нельзя удалить всех постояльцев, если они проживают в номерах\n";
		cout << "======================================================" << endl;
		system("pause");
		return;
	}
	bool temp = true;
	for (int i = 0; i < SIZE_TABLE; i++) {
		if (Table[i])
			temp = false;
	}
	if (temp)
	{
		cout << "======================================" << endl;
		cout << "Постояльцев нету\n";
		cout << "======================================" << endl;
		system("pause");
		return;
	}
	Hash* Temp;
	Hash* Next;
	for (int i = 0; i < SIZE_TABLE; i++)
	{
		Temp = Table[i];
		while (Temp) {
			Next = Temp->next;
			delete Temp;
			Temp = Next;

		}
	}
	cout << "Постояльцы удаены\n";
	cout << "======================================" << endl;
	system("pause");
}





void check_in(Data*& start, Data*& end, Three*& element, Hash**& Table)
{
	Data* append = new Data;
	
		
	// вводим паспорт и № номера и добавляем в список
	cout << "Введите номер паспорта NNNN-NNNNNN (где N - цифра): ";
	checkPasport(append->pasport); // ввод паспорта
	
	// если паспорт есть в базе
	if (SPasportInHash(Table, append->pasport))
	{
		int count = 0; // для проверки на наличие номера
		cout << "Введите номер комнаты «ANNN» где A – тип номера, N - цифры: ";
		checkRoom(append->room_number); // ввод номера комнаты
		SRoomAndMinusPlace(element, append->room_number, count, append); // Поиск номера и вычитание места
		if (count == 0)
		{
			cout << "Данного номера не существует\n";
			cout << "======================================================" << endl;
			delete append;
			append = nullptr;
			return;
		}
		// делаем дату заселения и выселения
		cout << "Введите дату заселения (ДД.ММ.ГГГГ): ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		InputFullDate (append->checkin_date);
		cout << "Введите дату выселения (ДД.ММ.ГГГГ): ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		InputFullDate(append->checkout_date);
		
		
	}
	else
	{
		cout << "Данного паспорта нет в базе\n";
		cout << "======================================================" << endl;
		return;
	}
	if (start == nullptr)
	{
		if (append != nullptr)
		{
			start = append;
			end = append;
		}
	}
	else if (append != nullptr)
	{	
		Data* help = start;
		while (true)
		{
			if (help->next == nullptr)
			{
				help->next = append;
				end = append;
				break;
			}
			help = help->next;
		}
		
	}
	
	
}
void check_out(Data*& start, Data*& end, Three*& element, Hash**& Table)
{
	// вводим паспорт и номер для удаления записи
	string pasport;
	string room_number;
	cout << "Введите номер паспорта NNNN-NNNNNN (где N - цифра): ";
	checkPasport(pasport); // ввод паспорта
	cout << "Введите номер комнаты «ANNN» где A – тип номера, N - цифры: ";
	checkRoom(room_number); // ввод номера комнаты
	int check = 0;
	SNomerInTree(element, room_number, check); // Есть ли номер комнаты в дереве
	if (!SPasportInHash(Table, pasport) && !check) // Есть ли пользователь в хэш таблице
	{
		cout << "Паспорт или номер комнаты не были найдены!\n";
		cout << "======================================================" << endl;
		return;
	}
	Data* help = start;
	// Поиск и удаление из списка записи
	while (help != nullptr)
	{
		if (help->room_number == room_number && help->pasport == pasport)
		{
			// если всего 1 элемент
			if (start == end)
			{
				delete start;
				start = nullptr;
				end = nullptr;
				AddPlaceInTree(element, room_number);
				cout << "Место в комнате добавлено, постоялец выселен\n";
				cout << "======================================================" << endl;
				return;
			}
			// если удаляем первый элемент
			else if (help == start)
			{
				start = help->next;
				delete help;
				help = start;
				AddPlaceInTree(element, room_number);
				cout << "Место в комнате добавлено, постоялец выселен\n";
				cout << "======================================================" << endl;
				return;
			}
			// если удаляем последний элемент
			else if (help == end)
			{
				
				help = start;
				while (help != nullptr)
				{
					if (help->next == end)
					{
						delete end;
						end = help;
						break;
					}
					help = help->next;
				}
				AddPlaceInTree(element, room_number);
				cout << "Место в комнате добавлено, постоялец выселен\n";
				cout << "======================================================" << endl;
				return;
			}
			// если удаляем элемент откуда-то из центра
			else
			{
				Data* del_element = help; // запоминаем удаляемый элемент
				Data* next_element = help->next; // запоминаем следующий элемент за удаляемым
				help = start;
				while (help != nullptr)
				{
					if (help->next == del_element)
					{
						help->next = next_element; //Переадресовка
						delete del_element;
						del_element = nullptr;
						break;
					}
					help = help->next;
				}
				AddPlaceInTree(element, room_number);
				cout << "Место в комнате добавлено, постоялец выселен\n";
				cout << "======================================================" << endl;
				return;
			}
		}
		help = help->next;
	}
	cout << "Данный номер не содержится в списке!\n";
	cout << "======================================================" << endl;
}








// Поиск постояльцев по ФИО
void search_to_FUO_guests(Hash**& Table)
{
	
	string Name; // храним тут ФИО
	cout << "Введите ФИО постояльца: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	isName(Name);
	
	int count = 0; // для проверки наличия постояльца в списке

	for (int i = 0; i < SIZE_TABLE; i++)
	{
		if (Table[i]) {
			Hash* Temp = Table[i];
			while (Temp) {
				if (Temp->guest->all_name == Name) {
					cout << "Паспорт: " << Temp->guest->pasport << endl;
					cout << "Постоялец: " << Temp->guest->all_name << endl;
					cout << "================================" << endl;
					count++;
				}
				Temp = Temp->next;
			}
		}
	
	}
	
	if (!count)
	{
		cout << "Постояльца с таким ФИО нету\n";
		cout << "================================" << endl;
	}
	system("pause");
}




// Поиск по паспорту в списке зачеления и выселения
void sPasportInData(Data*& start, Data*& end, string pasport_from_Hashing)
{
	int check = 0;
	Data* help = start;
	while (help != nullptr)
	{
		if (help->pasport == pasport_from_Hashing)
		{
			check++;
			cout << "Номер: " << help->room_number << endl;
			cout << "Дата заселения: " << help->checkin_date << endl;
			cout << "Дата выселения: " << help->checkout_date << endl;
			cout << "======================================" << endl;
			return;
		}
		help = help->next;
	}
	if (check == 0)
	{
		cout << "У постояльца нет номера\n";
		cout << "======================================" << endl;
	}
}






// Поиск постояльцев по номеру паспорта
void search_to_pasport(Hash**& Table, Data*& start, Data*& end)
{
	
	
	int count = 0; // для проверки на наличие совпадений
	string pasport;
	cout << "Введите номер паспорта NNNN-NNNNNN (где N - цифра): ";
	checkPasport(pasport);
	cout << "================================" << endl;


	
	int position = hash_position(pasport);
		
	if (Table[position])
	{
		Hash* Temp = Table[position];
		while (Temp) 
		{
			if (Temp->guest->pasport == pasport) 
			{
				cout << "Постоялец: " << Temp->guest->all_name << endl;
				cout << "Паспорт: " << Temp->guest->pasport << endl;
				cout << "Дата рождения: " << Temp->guest->year_of_birth << endl;
				cout << "================================" << endl;
				sPasportInData(start, end, Temp->guest->pasport);
				system("pause");
				return;
			}
			Temp = Temp->next;
		}
	}
	
	
	
	cout << "Совпадений нету\n";
	cout << "======================================" << endl;
	system("pause");
}






void H2(Hash**& Table, string pasport) ///(Вспомогательная функция для search_to_hotelroom по поиску ФИО)
{
	
	for (int i = 0; i < SIZE_TABLE; i++) 
	{
		int position = hash_position(pasport);
		if (Table[position]) 
		{
			Hash* Temp = Table[position];
			while (Temp) 
			{
				if (Temp->guest->pasport == pasport) 
				{
					cout << "Постоялец: " << Temp->guest->all_name << endl;
					cout << "================================" << endl;
					return;
				}
				Temp = Temp->next;



			}
		}

	}
	
}

// Поиск паспорта по номеру(вспомогательная функция для поиска гостиничного номера по номеру search_to_hotelroom)
void H1(Data*& start, Data*& end, Hash**& Table, string hotelroom)
{
	int check = 0; // для проверки, что номер кем-то снят
	Data* help = start;
	while (help != nullptr)
	{
		if (help->room_number == hotelroom)
		{
			check++;
			cout << "Паспорт: " << help->pasport << endl;
			H2(Table, help->pasport);
		}
		help = help->next;
	}
	if (check == 0)
	{
		cout << "Комната с номером " << hotelroom << " без постояльцев\n";
		cout << "=======================================================" << endl;
	}
}




// Проверка, есть ли такой постоялец в базе(по паспорту)
bool SPasportInHash(Hash**&Table, string pasport)
{
	if (!Table)
	{
		return false;
	}
	
	for (int i = 0; i < SIZE_TABLE; i++)
	{
		int position = hash_position(pasport);
		if (Table[position])
		{
			Hash* Temp = Table[position];
			while (Temp)
			{
				if (Temp->guest->pasport == pasport)
				{
					
					return true;
				}
				Temp = Temp->next;



			}
		}

	}
	return false;
}
