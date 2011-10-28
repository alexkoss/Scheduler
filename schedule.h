#pragma once
#include "stdafx.h"

#include "func.h"			

/*enum lesmode
{
   LECTION,
   SEMINAR,
   LAB
};

enum grouplist
{
	I,
	II,
	III,
	IV
};

struct auditory
{
	int n;
	//string name;
	lesmode name;
	int gnum;
	int free;
};

struct groups
{
	int n;
	string name;
	grouplist name2;
};

struct days
{
	int n;
	string name;
};

struct times
{
	int n;
	int T;
};

struct lessons
{
	int n;
	string name;
	string mode;
	int leng;
};


struct sched_string
{
	auditory aud1;
	groups gr1;
	days day1;
	lessons les1;
	times tim1;
//	sched_string *next;
	bool operator <(const sched_string& str) const;
};*/

struct sched_string
{
	auditory_struct aud1;
	group_struct gr1;
	day_struct day1;
	lesson_struct les1;
	time_struct tim1;
	//	sched_string *next;
	bool operator <(const sched_string& str) const;
};


class SCHEDULE
{
protected:
//	sched_string *start;
	

	sched_string current_parameters;

public: 
	unsigned int max_num_of_strings;
	list<sched_string> slist;
	//методы

public:
	SCHEDULE(void)
	{
		max_num_of_strings = 0;
	}
	//коструктор копирования
//	SCHEDULE(SCHEDULE const& copy)
//		: slist(copy.slist) {}

	~SCHEDULE(void)
	{
		slist.clear();
		//Del_all();
	}
	void remax(schedule_inputs* inputs)
	{
		max_num_of_strings = inputs->inputs.groups.size() * inputs->inputs.lessons.size();
	}
	void clear(void)
	{
		slist.clear();
	}
	inline void AddNewStr_List	(const sched_string &current);
	void Show_All_List			(char* out);
//	void Sort_List				(void);
//	void Add					(const sched_string &sc);
//	void Del_start				(void);
//	void Del_all				(void);
//	void Show					(void);
//	void Show_All				(void);
	void Create					(schedule_inputs* inputs);
	void AddNewStr				(schedule_inputs* inputs);
	int stats					(schedule_inputs* inputs);
	void modify					(schedule_inputs* inputs,int num);
	void skr					(schedule_inputs* inputs,SCHEDULE & sch1, SCHEDULE & sch2);
	bool search					(const sched_string &current);
	bool search2				(const sched_string &current);
	bool CanAdd					(schedule_inputs* inputs);
	void Cycle					(schedule_inputs* inputs);
};

//#endif
