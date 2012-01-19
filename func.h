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
	int id;					// порядковый номер
	char name[100];			// название аудитории
	char type[100];			// тип аудитории
	int groups_max;			// вместимость аудитории
	int groups_available;	// остаточная вместимость (сколько групп ещё может заниматься в данной аудитории)
	int priority;			// приоритет аудитории (выше - приоритетнее)
	list<string> for_lessons;	// целевые занятия данной аудитории
	bool operator <(const auditory_struct& aud) const; // метод, необходимый для применения сортировки для списка аудиторий
};

struct group_struct
{
	int id;					// порядковый номер
	char name[100];			// название группы
	bool operator <(const group_struct& gr) const; // метод, необходимый для применения сортировки для списка групп
};

struct day_struct
{
	int id;					// порядковый номер
	char name[100];			// название дня недели
	bool operator <(const day_struct& day) const; // метод, необходимый для применения сортировки для списка групп
};

struct lesson_struct
{
	int id;					// порядковый номер
	char name[100];			// название занятия
	char type[100];			// тип занятия
	int hours;				// количество академических часов
	list<string> for_groups;	// целевые группы данного занятия
	int groups_max;			// максимальное количество групп для одного занятия
	int groups_available;		// количество свободных групп 
	bool in_sch;				// отражает наличие занятия в расписании
	bool operator <(const lesson_struct& les) const; // метод, необходимый для применения сортировки для списка групп
};

struct time_struct
{
	int id;					// порядковый номер
	int begin_time;			// время начала занятия
	bool operator <(const time_struct& tim) const; // метод, необходимый для применения сортировки для списка групп
};

struct schedule_inputs_all	// описание учебного плана
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

String^ out_text(schedule_inputs* inputs, String^ filename_in);	// чтение входного xml-файла + заполнение стрктуры учебного плана
String^ out_struct(schedule_inputs* inputs);					// вывод учебного плана в текстовом виде