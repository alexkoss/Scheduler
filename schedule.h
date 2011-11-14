#pragma once
#include "stdafx.h"

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

class SCHEDULE
{
protected:
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
	inline void AddNewStr_List	(const sched_string &current);
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
	int  num_free_groups		();
};

