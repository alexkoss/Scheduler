#pragma once
#include "stdafx.h"



struct uni_input
{
	int num;
	char name[100];
	int gnum;
	int free;
	char type[100];
	int hours;
	int begin_time;
	bool operator <(const uni_input& inp) const;  
};

struct auditory_struct
{
	int id;					// ���������� �����
	char name[100];			// �������� ���������
	char type[100];			// ��� ���������
	int groups_max;			// ����������� ���������
	int groups_available;	// ���������� ����������� (������� ����� ��� ����� ���������� � ������ ���������)
	int priority;			// ��������� ��������� (���� - ������������)
	list<string> for_lessons;	// ������� ������� ������ ���������
	bool operator <(const auditory_struct& aud) const; // �����, ����������� ��� ���������� ���������� ��� ������ ���������
};

struct group_struct
{
	int id;					// ���������� �����
	char name[100];			// �������� ������
	bool operator <(const group_struct& gr) const; // �����, ����������� ��� ���������� ���������� ��� ������ �����
};

struct day_struct
{
	int id;					// ���������� �����
	char name[100];			// �������� ��� ������
	bool operator <(const day_struct& day) const; // �����, ����������� ��� ���������� ���������� ��� ������ �����
};

struct lesson_struct
{
	int id;					// ���������� �����
	char name[100];			// �������� �������
	char type[100];			// ��� �������
	int hours;				// ���������� ������������� �����
	list<string> for_groups;	// ������� ������ ������� �������
	int groups_max;			// ������������ ���������� ����� ��� ������ �������
	int groups_available;		// ���������� ��������� ����� 
	bool in_sch;				// �������� ������� ������� � ����������
	bool operator <(const lesson_struct& les) const; // �����, ����������� ��� ���������� ���������� ��� ������ �����
};

struct time_struct
{
	int id;					// ���������� �����
	int begin_time;			// ����� ������ �������
	bool operator <(const time_struct& tim) const; // �����, ����������� ��� ���������� ���������� ��� ������ �����
};

struct schedule_inputs_all	// �������� �������� �����
{
	list<auditory_struct> auditories;
	list<group_struct> groups;
	list<day_struct> days;
	list<lesson_struct> lessons;
	list<time_struct> times;
};

class schedule_inputs
{
//protected:

public:
	schedule_inputs_all inputs;

public:
	schedule_inputs(void)
	{

	}
	~schedule_inputs()
	{
		inputs.auditories.clear();
		inputs.groups.clear();
		inputs.days.clear();
		inputs.lessons.clear();
		inputs.times.clear();
	}
};

struct selected_indexes 
{
	int aud[5];
	int gr[2];
	int day[2];
	int les[4];
	int tim[2];
};

String^ out_text(schedule_inputs* inputs, String^ filename_in);	// ������ �������� xml-����� + ���������� �������� �������� �����
String^ out_struct(schedule_inputs* inputs);					// ����� �������� ����� � ��������� ����