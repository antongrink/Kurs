#include "Tree.h"

int COUNTER_ROOMS = 0;
Three* single_left_rotate(Three*& element)
{
	Three* help = element->right;
	element->right = help->left;
	help->left = element;
	element->height = max(height(element->left), height(element->right)) + 1;
	help->height = max(height(element->left), element->height) + 1;
	return help;
}

Three* single_right_rotate(Three*& element)
{
	Three* help = element->left;
	element->left = help->right;
	help->right = element;
	element->height = max(height(element->left), height(element->right)) + 1;
	help->height = max(height(help->left), element->height) + 1;
	return help;
}

Three* big_left_rotate(Three*& element)
{
	element->right = single_right_rotate(element->right);
	return single_left_rotate(element);
}

Three* big_right_rotate(Three*& element)
{
	element->left = single_left_rotate(element->left);
	return single_right_rotate(element);
}

string generate_hotelroom()
{
	string key = "";
	int k;
	cout << "��� ������ ������\n==========================\n"
		<< "1. � - ����\n"
		<< "2. � - ��������\n"
		<< "3. � - �����������\n"
		<< "4. � - ������������\n";
	cout << "==========================\n�������� ��������:  ";
	isDigit(k);
	// A
	switch (k)
	{
	case 1:
		key.append("�");
		break;
	case 2:
		key.append("�");
		break;
	case 3:
		key.append("�");
		break;
	case 4:
		key.append("�");
		break;
	}
	// NNN
	if (COUNTER_ROOMS < 10)
	{
		key += "00";
		key += to_string(COUNTER_ROOMS);
	}
	else if (COUNTER_ROOMS >= 10 && COUNTER_ROOMS < 100)
	{
		key += "0";
		key += to_string(COUNTER_ROOMS);
	}
	else
	{
		key += to_string(COUNTER_ROOMS);
	}
	return key;
}

void add_hotelroom(Three*& element, string value)
{
	if (element == NULL)
	{
		Room* r = new Room;
		r->room_number = value;
		// ���� ����� �����������
		if (r->room_number[0] == '�')
		{
			r->all_places = 1;
		}
		else
		{
			cout << "������� ���������� ���� � ������: ";
			isDigit(r->all_places);
		}
		r->place_ready = r->all_places;
		cout << "������� ���������� ������ � ������: ";
		isDigit(r->all_rooms);
		r->isBathroom = bathroomIS();
		cout << "������� ������������ � ������: ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		string temp;
		
		getline(cin, r->equipment);
		
		
		element = new Three;
		element->height = 0;
		element->room = r;
		COUNTER_ROOMS++;
	}
	else
	{
		if (value < element->room->room_number)
		{
			add_hotelroom(element->left, value);
			
			if (height(element->left) - height(element->right) == 2)
			{
				if (value < element->left->room->room_number)
				{
					element = single_right_rotate(element);
				}
				else
				{
					element = big_right_rotate(element);
				}
			}
		}
		else if (value > element->room->room_number)
		{
			add_hotelroom(element->right, value);
			if (height(element->right) - height(element->left) == 2)
			{
				if (value > element->right->room->room_number)
				{
					element = single_left_rotate(element);
				}
				else
				{
					element = big_left_rotate(element);
				}
			}
		}
	}
	element->height = max(height(element->left), height(element->right)) + 1;
}

Room* deletemin(Three*& element)
{
	Room* a;
	if (element->left == NULL)
	{
		a = element->room;
		element = element->right;
		return a;
	}
	else
	{
		a = deletemin(element->left);
		return a;
	}
}

void show_hotelrooms(const Three* element)
{
	if (element == NULL)
	{
		return;
	}
	
	cout << "� �������: " << element->room->room_number << endl;
	cout << "����� ����: " << element->room->all_places << endl;
	cout << "��������� ����: " << element->room->place_ready << endl;
	cout << "���-�� ������: " << element->room->all_rooms << endl;
	cout << "������������: " << element->room->equipment << endl;
	cout << "====================================\n";
	show_hotelrooms(element->left); // ������ ����� ��������� 
	show_hotelrooms(element->right); // ������ ������ ���������   
}

void del_hotelroom(Three*& element, string value, Data*& start, Data*& end)
{
	if (check_room_with_guest(start, end, value))
	{
		cout << "�������� ������ ����������, � �� ����� ���������\n";
		cout << "===========================================================" << endl;
		return;
	}
	if (element == NULL)
	{
		cout << "��������, �� ������ ������ ����" << endl;
		cout << "======================================" << endl;
	}
	else if (value < element->room->room_number)
	{
		del_hotelroom(element->left, value, start, end);
	}
	else if (value > element->room->room_number)
	{
		del_hotelroom(element->right, value, start, end);
	}
	else if ((element->left == NULL) && (element->right == NULL))
	{
		
		delete element->room;
		element->room = nullptr;
		delete element;
		element = nullptr;
		cout << "������� �������" << endl;
		cout << "======================================" << endl;
	}
	else if (element->left == NULL)
	{
		Three* help = element->right;
		delete element->room;
		element->room = nullptr;
		delete element;
		element = help;
		cout << "������� �������" << endl;
		cout << "======================================" << endl;
	}
	else if (element->right == NULL)
	{
		Three* help = element->left;
		delete element->room;
		element->room = nullptr;
		delete element;
		element = help;
		cout << "������� �������" << endl;
		cout << "======================================" << endl;
	}
	else
	{
		delete element->room;
		element->room = deletemin(element->right);
		cout << "������� �������" << endl;
		cout << "======================================" << endl;
	}
}





void delete_all_rooms(Three*& element, Data*& start, Data*& end)
{
	if (start != NULL)
	{
		cout << "������ ������� ��� ������, ���� � ��� ���-�� �����\n";
		cout << "======================================================" << endl;
		return;
	}
	if (element == NULL)
	{
		return;
	}
	delete_all_rooms(element->left, start, end); // ������ ����� ��������� 
	delete_all_rooms(element->right, start, end); // ������ ������ ���������  
	delete element->room;
	element->room = nullptr;
	delete element;
	element = nullptr;
}



// �������� ������ ��

bool BMsearch(string str, string substr)
{
	int length_sub = substr.length(); // ����� ���������
	int length_str = str.length(); // ����� ������
	if (length_str == 0 || length_sub == 0 || length_sub == 1 || length_str == 1)
	{
		return false;
	}
	else
	{
		int* arr = new int[256];
		for (int i = 0; i < 256; i++)
		{
			arr[i] = length_sub;
		}
		for (int i = length_sub - 1; i >= 0; i--)
		{
			if (arr[(int((unsigned char)(substr[i])))] == length_sub)
			{
				arr[(int((unsigned char)(substr[i])))] = length_sub - i - 1;
			}
		}
		int position = length_sub - 1;
		while (position < length_str)
		{
			if (substr[length_sub - 1] != str[position])
			{
				position = position + arr[(int((unsigned char)(str[position])))];
			}
			else
			{
				for (int i = length_sub - 2; i >= 0; i--)
				{
					if (substr[i] != str[position - length_sub + i + 1])
					{
						position += arr[(int((unsigned char)(str[position - length_sub + i + 1])))] - 1;
						break;
					}
					else
					{
						if (i == 0)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}







// ����� �� ������������
void equipment_search(const Three* element, string equ)
{
	if (element == NULL)
	{
		return;
	}
	
	if (BMsearch(element->room->equipment, equ))
	{
		cout << "� �������: " << element->room->room_number << endl;
		cout << "����� ����: " << element->room->all_places << endl;
		cout << "��������� ����: " << element->room->place_ready << endl;
		cout << "���-�� ������: " << element->room->all_rooms << endl;
		cout << "������������: " << element->room->equipment << endl;
		cout << "====================================\n";
	}
	else {
		cout << "�� ������� ����� ����������� �� �����" << endl;
	}
	equipment_search(element->left, equ); // ������ ����� ��������� 
	equipment_search(element->right, equ); // ������ ������ ���������
}






// ����� ������� �� � ������
void search_to_hotelroom(const Three* element, Data*& start, Data*& end, Hash**& Table, string room)
{
	if (element == NULL)
	{
		return;
	}
	
	if (element->room->room_number == room)
	{
		cout << "� �������: " << element->room->room_number << endl;
		cout << "����� ����: " << element->room->all_places << endl;
		cout << "��������� ����: " << element->room->place_ready << endl;
		cout << "���-�� ������: " << element->room->all_rooms << endl;
		cout << "������������: " << element->room->equipment << endl;
		cout << "====================================\n";
		H1(start, end, Table, room);
	}
	search_to_hotelroom(element->left, start, end, Table, room); // ������ ����� ��������� 
	search_to_hotelroom(element->right, start, end, Table, room); // ������ ������ ���������   
}






// ����� ������� �� ������ ��� ���������
void SRoomAndMinusPlace(Three*& element, string room, int& count, Data*& append)
{
	if (element == NULL)
	{
		return;
	}

	
	if (element->room->room_number == room)
	{
		count++; 
		if (element->room->place_ready > 0)
		{
			element->room->place_ready--;
			cout << "��������� ����������������\n";
			cout << "======================================================" << endl;
			return;
		}
		else
		{
			delete append;
			append = nullptr;
			cout << "���� � ������� ����\n";
			cout << "======================================================" << endl;
			return;
		}
	}
	SRoomAndMinusPlace(element->left, room, count, append); // ������ ����� ��������� 
	SRoomAndMinusPlace(element->right, room, count, append); // ������ ������ ���������   
}




// ����� ������ ��� ����������
void AddPlaceInTree(Three*& element, string room)
{
	if (element == NULL)
	{
		return;
	}

	AddPlaceInTree(element->left, room); // ������ ����� ��������� 
	if (element->room->room_number == room)
	{
		element->room->place_ready++;
		return;
	}
	AddPlaceInTree(element->right, room); // ������ ������ ���������   
}
