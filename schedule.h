#pragma once
#include "stdafx.h" // test commit

#include "func.h"			

struct sched_string
{
	auditory_struct aud1;
	group_struct gr1;
	day_struct day1;
	lesson_struct les1;
	time_struct tim1;
	bool operator <(const sched_string& str) const;
};

struct lesson_string
{
	int id;					// порядковый номер
	char lesson_name[100];	// название занятия
	char lesson_type[100];	// тип занятия
	int hours;				// количество академических часов
	string group;			// название группы
	bool used;				// использован ли предмет в расписании
	int max_groups;			// максимальное количество групп для занятия
	int from_lessons_id;	// номер в списке всех занятий
};

struct adt_string
{
	auditory_struct aud;	// аудитория
	day_struct day;			// день
	time_struct time;		// время
	list<string> restricted;// список занятых групп
	bool operator <(const adt_string& str) const;
};

class SCHEDULE
{
protected:
	sched_string current_parameters;

public: 
	unsigned int max_num_of_strings;
	list<sched_string> slist;
	list<lesson_string> llist;
	list<adt_string> lec_list;
	list<adt_string> sem_list;
	list<adt_string> lab_list;
	//методы

public:
	SCHEDULE(void)
	{
		max_num_of_strings = 0;
	}

	~SCHEDULE(void)
	{
		slist.clear();
	}
	void remax(schedule_inputs* inputs)
	{
		max_num_of_strings = inputs->inputs.groups.size() * inputs->inputs.lessons.size();
	}
	void clear(void)
	{
		slist.clear();
	}
	void Show_All_List			(char* out);
	void Create					(schedule_inputs* inputs);
	void AddNewStr				(schedule_inputs* inputs);
	int  stats					(schedule_inputs* inputs);
	void modify					(schedule_inputs* inputs,int num);
	void skr					(schedule_inputs* inputs,SCHEDULE & sch1, SCHEDULE & sch2);
	bool search					(const sched_string &current);
	bool search2				(const sched_string &current);
	bool CanAdd					(schedule_inputs* inputs);
	void Cycle					(schedule_inputs* inputs);  
	void Cycle2					(schedule_inputs* inputs);
	int  num_free_groups		();
	void Make_Lesson_List		(schedule_inputs* inputs);
	String^ Show_Lesson_List	();
	int Get_Lesson_Number		(schedule_inputs* inputs);
	lesson_struct Get_Lesson_From			(schedule_inputs* inputs);
	time_struct Get_Time_From				(schedule_inputs* inputs);
	day_struct Get_Day_From					(schedule_inputs* inputs);
	auditory_struct Get_Aud_From			(schedule_inputs* inputs, lesson_struct ls);
	bool Fill_Les_into						(schedule_inputs* inputs, lesson_struct ls, auditory_struct as);
	bool is_not_in_restricted_list_and_not_full			(group_struct gr, adt_string adt_str);
	void Fill_Restricted					(list<adt_string> *inlist, string adt_str, sched_string current);
	int Check_Restricted_Count				(list<adt_string> inlist);
	void Fill_One_Lesson					(list<adt_string> *inlist, sched_string *current, schedule_inputs* inputs);
};

