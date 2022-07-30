#include "Check.h"
#include <limits>
#include <regex>
#include <vector>
string trimValue(const string& str) {
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}




void isName(string& temp)
{
		getline(cin, temp);
		
	
		regex regFIO("([�-�])([�-�]{0,45})([\\s])(([�-�])[�-�]{0,45})([\\s])(([�-�])[�-�]{0,45})");
		temp = trimValue(temp);
		while (cin.fail() || ((regex_match(temp, regFIO) == false))) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			cout << " �������!" << endl;
			cout << " ������� ��� ������:" << endl;
			getline(cin, temp);
			temp = trimValue(temp);
		}
		
	

}



void isString(string & temp)
{
	getline(cin, temp);
	regex regString("(([�-�])[�-�]{0,45})");
	temp = trimValue(temp);
	while (cin.fail() || ((regex_match(temp, regString) == false))) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
		cout << " �������!" << endl;
		cout << " ������� ������:" << endl;
		getline(cin, temp);
		temp = trimValue(temp);
	}
	
}

string inputArress(string& temp) {
	
	
	getline(cin, temp);
	temp = trimValue(temp);
	return temp;
}


void InputFullDate(string & birthdayDate) {
	// ���������� ��������� ��� ����
	regex regDATA("([0-9]{1,2})(\\.)([0-9]{1,2})(\\.)([0-9]{1,4})");

	
	cmatch result;
	cout << "\n ������� ���� � ������� (dd.mm.yy): ";
	getline(cin, birthdayDate);
	regex_match(birthdayDate.c_str(), result, regDATA);

	while (!regex_match(birthdayDate.c_str(), result, regDATA) || (stoi(result[1]) > 31 && stoi(result[3]) == 12) ||
		(stoi(result[1]) > 30 && stoi(result[3]) == 11) || (stoi(result[1]) > 31 && stoi(result[3]) == 10) ||
		(stoi(result[1]) > 30 && stoi(result[3]) == 9) || (stoi(result[1]) > 31 && stoi(result[3]) == 8) ||
		(stoi(result[1]) > 31 && stoi(result[3]) == 7) || (stoi(result[1])
> 30 && stoi(result[3]) == 6) ||
(stoi(result[1]) > 31 && stoi(result[3]) == 5) || (stoi(result[1]) > 30 && stoi(result[3]) == 4) ||
(stoi(result[1]) > 31 && stoi(result[3]) == 3) || (stoi(result[1]) > 31 && stoi(result[3]) == 1) ||
stoi(result[1]) == 0 || stoi(result[3]) > 12 || stoi(result[3]) == 0 || (((stoi(result[5]) % 4 == 0) ||
	(stoi(result[5]) % 100 == 0 && stoi(result[5]) % 400)) && stoi(result[3]) == 2 && stoi(result[1]) > 29) ||
		(!((stoi(result[5]) % 4 == 0) || (stoi(result[5]) % 100 == 0 && stoi(result[5]) % 400)) && stoi(result[3]) == 2 && stoi(result[1]) > 28)) {
		cout << " �������� ����. ���������� ������ ������ ���� � ������� (dd.mm.yy): ";
		getline(cin, birthdayDate);
	}
	
}





void isDigit(int& digit)
{
	cin >> digit; // ���� �����
	while (cin.fail() || (cin.rdbuf()->in_avail() > 1))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������� ����� ��������: ";
		cin >> digit;
	}
}

void checkPasport(string& pass)
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, pass);
	while (true)
	{
		// �NNNN-NNNNNN� N - �����
		if ((int)pass[0] >= 48 && (int)pass[0] <= 57 && (int)pass[1] >= 48 && (int)pass[1] <= 57 && (int)pass[2] >= 48 && (int)pass[2] <= 57
			&& (int)pass[3] >= 48 && (int)pass[3] <= 57 && (int)pass[4] == 45 && (int)pass[5] >= 48 && (int)pass[5] <= 57
			&& (int)pass[6] >= 48 && (int)pass[6] <= 57 && (int)pass[7] >= 48 && (int)pass[7] <= 57 && (int)pass[8] >= 48 && (int)pass[8] <= 57
			&& (int)pass[9] >= 48 && (int)pass[9] <= 57 && (int)pass[10] >= 48 && (int)pass[10] <= 57 && pass.size() == 11)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������� ����� �������� �������� NNNN-NNNNNN (��� N - �����): ";
			getline(cin, pass);
		}
	}
}

bool CheckPassportInList(Data*& start, Data*& end, string pass)
{
	Data* help = start;
	while (help != NULL)
	{
		if (help->pasport == pass)
		{
			return 1;
		}
		help = help->next;
	}
	return 0;
}
void checkRoom(string& value)
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, value);
	while (true)
	{
		if ((value[0] == '�' || value[0] == '�' || value[0] == '�' || value[0] == '�')
			&& ((int)value[1] >= 48 && (int)value[1] <= 57 && (int)value[2] >= 48 && (int)value[2] <= 57
				&& (int)value[3] >= 48 && (int)value[3] <= 57))
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������� ����� ������� �������� �ANNN� ��� A � ��� ������, N - �����: ";
			getline(cin, value);
		}
	}
}

int height(Three*& element)
{
	if (element == NULL)
	{
		return -1;
	}
	else
	{
		return element->height;
	}
}

bool bathroomIS()
{
	int k; // ��� ������ ������������ � ������� �������
	cout << "������� �������\n==========================\n"
		<< "1. ����\n"
		<< "2. ����\n";
	cout << "==========================\n�������� ��������:  ";
	while (true)
	{
		isDigit(k);
		switch (k)
		{
		case 1:
			return true;
		case 2:
			return false;
		}
	}
}

bool check_room_with_guest(Data*& start, Data*& end, string room)
{
	Data* help = start;
	while (help != NULL)
	{
		if (help->room_number == room)
		{
			return 1;
		}
		help = help->next;
	}
	return 0;
}





void bubble_sort(Data*& head)
{

	for (Data* i = head; i != NULL; i = i->next)
	{
		for (Data* j = i->next; j != NULL; j = j->next)
		{
			if (i->room_number < j->room_number)
			{
				swap(i->room_number, j->room_number);
			}
		}
	}
}

// �������� �� ������� ������ �������
void  SNomerInTree(Three*& element, string room, int& check)
{
	if (element == NULL)
	{
		return;
	}
	
	if (element->room->room_number == room)
	{
		check++;
	}
	SNomerInTree(element->left, room, check); // ������ ����� ��������� 
	SNomerInTree(element->right, room, check); // ������ ������ ���������  
}


void distribution(Data*& head,Data*& end)
{
	int max;
	Data* temp = head;
	if (head)
		max = 0;
	else
		return;

	for (Data* i = head; i != NULL; i = i->next)
	{
		if (stoi(i->room_number.substr(1)) > max)               //���������� ������������� ������ ��� �������� �������
		{
			max = stoi(i->room_number.substr(1));
		}
	}
	vector<int> arr( max + 1);                          //�������� �������
	
	for (Data* i = head; i != NULL; i = i->next)
	{
		arr[stoi(i->room_number.substr(1))]++;             
	}
	bool first_init = true;
	bool second_init = true;
	Data* new_head = nullptr;
	Data* new_list = nullptr;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i < 10 && arr[i] != 0)
		{	
			if (first_init) {
				new_head = Search4Number(head, "00" + std::to_string(i));
				new_list = new_head;
				first_init = false;
			}
			else if(second_init) {
				new_list = Search4Number(head, "00" + std::to_string(i));
				new_head->next = new_list;
				second_init = false;
			}
			else {
				new_list->next = Search4Number(head, "00" + std::to_string(i));
				
				new_list = new_list->next;
			}
		}
		else if (i < 100 && arr[i] != 0)
		{
			if (first_init) {
				new_head = Search4Number(head, "0" + std::to_string(i));
				new_list = new_head;
				first_init = false;
			}
			else if (second_init) {
				new_list = Search4Number(head, "0" + std::to_string(i));
				new_head->next = new_list;
				second_init = false;
			}
			else {
				new_list->next = Search4Number(head, "0" + std::to_string(i));
				
				new_list = new_list->next;
			}
		}
	}
	head = new_head;
	new_list->next = nullptr;
	end = new_list;
}

Data* Search4Number(Data*& head,const string& str)
{
	Data* temp = head;
	while (temp->room_number.substr(1) != str && temp != nullptr)
	{
		temp = temp->next;
	}
	return temp;
}



