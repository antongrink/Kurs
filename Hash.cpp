#include "Hash.h"

static const int SIZE_TABLE = 50; // ������ �������


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
	
	cout << "������� ����� �������� NNNN-NNNNNN (��� N - �����): ";
	checkPasport(g->pasport); // �������� �������� �� ������������
	if (SPasportInHash(Table,g->pasport))
	{
		cout << "������� � ����� ��������� ��� ����������!" << endl;
		cout << "��������� ���� " << endl;
		checkPasport(g->pasport); // �������� �������� �� ������������

	}
	cout << "������� ��� ������ ���������� (������: Phamiliya Imya Otchestvo): ";
	
	isName(g->all_name);
	cout << "������� ��� �������� ������ ����������: ";
	isDigit(g->year_of_birth);
	cout << "������� ����� ����������: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	inputArress(g->address);
	cout << "������� ���� ��������: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	inputArress( g->destination_of_arrival);
	system("cls");
	int hash = hash_position(g->pasport); // ���������� ������� � �������
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
				cout << "���������: " << Temp->guest->all_name << endl;
				cout << "�������: " << Temp->guest->pasport << endl;
				cout << "���� ��������: " << Temp->guest->year_of_birth << endl;
				cout << "================================" << endl;
				Temp = Temp->next;
			}
			
		}
		
	}
	if (!count)
	{
		cout << "����������� ����\n";
		cout << "================================" << endl;
	}
	system("pause");
}

void del_guest(Hash**& Table, Data*& start, Data*& end)
{
	string pass; // ��� ������ �������
	cout << "������� ����� �������� NNNN-NNNNNN (��� N - �����): ";
	checkPasport(pass); // ������ ������� ���������
	// ���������, ��������� �� �� ��� ���
	if (CheckPassportInList(start, end, pass))
	{
		cout << "===========================================================" << endl;
		cout << "�������� ���������� ����������, �� ��� �� ���������\n";
		cout << "===========================================================" << endl;
		system("pause");
		return;
	}
	int count = 0; // ��� �������� ������� ���������� � ������
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
				cout << "��������� �����\n";
				cout << "======================================" << endl;
				system("pause");
				return;
			}
			else if(Temp->guest->pasport == pass) {
				count++;
				Table[position] = Temp->next;
				delete Temp;
				cout << "======================================" << endl;
				cout << "��������� �����\n";
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
		cout << "�� ������� ���������� � ����� ���������\n";
		cout << "======================================" << endl;
	}
	system("pause");
}




void delete_all_guests(Hash**& Table, Data*& start, Data*& end)
{
	if (start != nullptr)
	{
		cout << "������ ������� ���� �����������, ���� ��� ��������� � �������\n";
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
		cout << "����������� ����\n";
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
	cout << "���������� ������\n";
	cout << "======================================" << endl;
	system("pause");
}





void check_in(Data*& start, Data*& end, Three*& element, Hash**& Table)
{
	Data* append = new Data;
	
		
	// ������ ������� � � ������ � ��������� � ������
	cout << "������� ����� �������� NNNN-NNNNNN (��� N - �����): ";
	checkPasport(append->pasport); // ���� ��������
	
	// ���� ������� ���� � ����
	if (SPasportInHash(Table, append->pasport))
	{
		int count = 0; // ��� �������� �� ������� ������
		cout << "������� ����� ������� �ANNN� ��� A � ��� ������, N - �����: ";
		checkRoom(append->room_number); // ���� ������ �������
		SRoomAndMinusPlace(element, append->room_number, count, append); // ����� ������ � ��������� �����
		if (count == 0)
		{
			cout << "������� ������ �� ����������\n";
			cout << "======================================================" << endl;
			delete append;
			append = nullptr;
			return;
		}
		// ������ ���� ��������� � ���������
		cout << "������� ���� ��������� (��.��.����): ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		InputFullDate (append->checkin_date);
		cout << "������� ���� ��������� (��.��.����): ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		InputFullDate(append->checkout_date);
		
		
	}
	else
	{
		cout << "������� �������� ��� � ����\n";
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
	// ������ ������� � ����� ��� �������� ������
	string pasport;
	string room_number;
	cout << "������� ����� �������� NNNN-NNNNNN (��� N - �����): ";
	checkPasport(pasport); // ���� ��������
	cout << "������� ����� ������� �ANNN� ��� A � ��� ������, N - �����: ";
	checkRoom(room_number); // ���� ������ �������
	int check = 0;
	SNomerInTree(element, room_number, check); // ���� �� ����� ������� � ������
	if (!SPasportInHash(Table, pasport) && !check) // ���� �� ������������ � ��� �������
	{
		cout << "������� ��� ����� ������� �� ���� �������!\n";
		cout << "======================================================" << endl;
		return;
	}
	Data* help = start;
	// ����� � �������� �� ������ ������
	while (help != nullptr)
	{
		if (help->room_number == room_number && help->pasport == pasport)
		{
			// ���� ����� 1 �������
			if (start == end)
			{
				delete start;
				start = nullptr;
				end = nullptr;
				AddPlaceInTree(element, room_number);
				cout << "����� � ������� ���������, ��������� �������\n";
				cout << "======================================================" << endl;
				return;
			}
			// ���� ������� ������ �������
			else if (help == start)
			{
				start = help->next;
				delete help;
				help = start;
				AddPlaceInTree(element, room_number);
				cout << "����� � ������� ���������, ��������� �������\n";
				cout << "======================================================" << endl;
				return;
			}
			// ���� ������� ��������� �������
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
				cout << "����� � ������� ���������, ��������� �������\n";
				cout << "======================================================" << endl;
				return;
			}
			// ���� ������� ������� ������-�� �� ������
			else
			{
				Data* del_element = help; // ���������� ��������� �������
				Data* next_element = help->next; // ���������� ��������� ������� �� ���������
				help = start;
				while (help != nullptr)
				{
					if (help->next == del_element)
					{
						help->next = next_element; //�������������
						delete del_element;
						del_element = nullptr;
						break;
					}
					help = help->next;
				}
				AddPlaceInTree(element, room_number);
				cout << "����� � ������� ���������, ��������� �������\n";
				cout << "======================================================" << endl;
				return;
			}
		}
		help = help->next;
	}
	cout << "������ ����� �� ���������� � ������!\n";
	cout << "======================================================" << endl;
}








// ����� ����������� �� ���
void search_to_FUO_guests(Hash**& Table)
{
	
	string Name; // ������ ��� ���
	cout << "������� ��� ����������: ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	isName(Name);
	
	int count = 0; // ��� �������� ������� ���������� � ������

	for (int i = 0; i < SIZE_TABLE; i++)
	{
		if (Table[i]) {
			Hash* Temp = Table[i];
			while (Temp) {
				if (Temp->guest->all_name == Name) {
					cout << "�������: " << Temp->guest->pasport << endl;
					cout << "���������: " << Temp->guest->all_name << endl;
					cout << "================================" << endl;
					count++;
				}
				Temp = Temp->next;
			}
		}
	
	}
	
	if (!count)
	{
		cout << "���������� � ����� ��� ����\n";
		cout << "================================" << endl;
	}
	system("pause");
}




// ����� �� �������� � ������ ��������� � ���������
void sPasportInData(Data*& start, Data*& end, string pasport_from_Hashing)
{
	int check = 0;
	Data* help = start;
	while (help != nullptr)
	{
		if (help->pasport == pasport_from_Hashing)
		{
			check++;
			cout << "�����: " << help->room_number << endl;
			cout << "���� ���������: " << help->checkin_date << endl;
			cout << "���� ���������: " << help->checkout_date << endl;
			cout << "======================================" << endl;
			return;
		}
		help = help->next;
	}
	if (check == 0)
	{
		cout << "� ���������� ��� ������\n";
		cout << "======================================" << endl;
	}
}






// ����� ����������� �� ������ ��������
void search_to_pasport(Hash**& Table, Data*& start, Data*& end)
{
	
	
	int count = 0; // ��� �������� �� ������� ����������
	string pasport;
	cout << "������� ����� �������� NNNN-NNNNNN (��� N - �����): ";
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
				cout << "���������: " << Temp->guest->all_name << endl;
				cout << "�������: " << Temp->guest->pasport << endl;
				cout << "���� ��������: " << Temp->guest->year_of_birth << endl;
				cout << "================================" << endl;
				sPasportInData(start, end, Temp->guest->pasport);
				system("pause");
				return;
			}
			Temp = Temp->next;
		}
	}
	
	
	
	cout << "���������� ����\n";
	cout << "======================================" << endl;
	system("pause");
}






void H2(Hash**& Table, string pasport) ///(��������������� ������� ��� search_to_hotelroom �� ������ ���)
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
					cout << "���������: " << Temp->guest->all_name << endl;
					cout << "================================" << endl;
					return;
				}
				Temp = Temp->next;



			}
		}

	}
	
}

// ����� �������� �� ������(��������������� ������� ��� ������ ������������ ������ �� ������ search_to_hotelroom)
void H1(Data*& start, Data*& end, Hash**& Table, string hotelroom)
{
	int check = 0; // ��� ��������, ��� ����� ���-�� ����
	Data* help = start;
	while (help != nullptr)
	{
		if (help->room_number == hotelroom)
		{
			check++;
			cout << "�������: " << help->pasport << endl;
			H2(Table, help->pasport);
		}
		help = help->next;
	}
	if (check == 0)
	{
		cout << "������� � ������� " << hotelroom << " ��� �����������\n";
		cout << "=======================================================" << endl;
	}
}




// ��������, ���� �� ����� ��������� � ����(�� ��������)
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
