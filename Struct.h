#pragma once
#pragma once
#include<iostream>
#include <string>
using namespace std;
// ���������
struct Guest
{
	string pasport; // �NNNN-NNNNNN� N - �����
	string all_name; // ���
	int year_of_birth; // ��� ��������
	string address; // �����
	string destination_of_arrival; // ���� ��������
};

// ����������� �����
struct Room
{
	string room_number; // � ������������ ������ �ANNN� ��� A � �����, ������������ ��� ������ (� � ����, � � ��������, � � �����������, � � ������������), N - �����
	int all_places; // ����� ����
	int place_ready; // ��������� ����
	int all_rooms; // ���-�� ������
	bool isBathroom; // ������� �������
	string equipment; // ������������
};




//���������� ��� �������� �������� � ���-�������
struct Hash
{

	
	Guest* guest = NULL; 
	Hash* next = NULL; 


};


// ��������� ������
struct Three
{
	int height; // ������ ���������
	Room* room = NULL; // ������ � ����������� ������
	Three* left = NULL; // ����� ������� ���������
	Three* right = NULL; // ������ ������� ���������
};

//������ � ����������� � ��������� � ���������
struct Data
{
	string pasport; // ������� ����������
	string room_number; // ����� �������
	string checkin_date; // ���� ���������
	string checkout_date; // ���� ���������
	Data* next = NULL; // ��������� ������� ��������� ������
};