﻿#include "stdafx.h"

#include "func.h"
#include "schedule.h"
class schedule_inputs; 

bool sched_string::operator <(const sched_string& str) const 
{
	if (day1.id == str.day1.id)
	{
		if (tim1.begin_time == str.tim1.begin_time)
			return aud1.id < str.aud1.id;
		else
			return tim1.begin_time < str.tim1.begin_time;
	} else 
		return day1.id < str.day1.id;
}

bool adt_string::operator <(const adt_string& str) const 
{
	return aud.groups_max > str.aud.groups_max;
}

void SCHEDULE::Show_All_List(char* out)
{
	//выводит расписание в out

	slist.sort();
	cout << '\n';
	int iiicnt=1;
	char tmpstr[65000]="";
	char thisis[]="This is automatically generated schedule\n\n";
	char header1[]="N\tDay\t\tStart\tL_name\t\t\tL_type\tAud\t\tFree\tGroup N\n";
	char header2[]="-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	int header_length=strlen(header1);
	strcat(tmpstr,thisis);
	strcat(tmpstr,header1);
	strcat(tmpstr,header2);
	
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		/*cout << setw(6) << iiicnt << "|	"; iiicnt++; 
		cout << setw(8) << (*it).day1.name << '|' << setw(7) << (*it).tim1.begin_time << '|' << setw(8);
		cout << (*it).les1.name << '|' << setw(7) << (*it).les1.type << '|' << setw(7); 
		cout << (*it).aud1.id << '|' << setw(7) << (*it).aud1.groups_available << '|' << setw(7) << (*it).gr1.name << "|" ;
		cout << "\n";*/
		
		char iiicnt_char[10];
		_itoa_s(iiicnt,iiicnt_char,sizeof(iiicnt_char),10);

		strcat(tmpstr, iiicnt_char);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).day1.name);
		if (strlen((*it).day1.name)<10)
			strcat(tmpstr, "\t");
		strcat(tmpstr, "\t");

		char bt_char[10];
		_itoa_s((*it).tim1.begin_time,bt_char,sizeof(bt_char),10);
		strcat(tmpstr, bt_char);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).les1.name);

		if (strlen((*it).les1.name)<10)
			strcat(tmpstr, "\t\t\t");
		else if (strlen((*it).les1.name)<=15)
			strcat(tmpstr, "\t\t");
		else if (strlen((*it).les1.name)<=20)
			strcat(tmpstr, "\t");
		else if (strlen((*it).les1.name)>20)
			strcat(tmpstr, "\t");

		//strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).les1.type);
		strcat(tmpstr, "\t");

		//char audid_char[10];
		//itoa((*it).aud1.id,audid_char,10);
		//strcat(tmpstr, audid_char);
		strcat(tmpstr, (*it).aud1.name);
		if (strlen((*it).aud1.name)<8)
			strcat(tmpstr, "\t");
		strcat(tmpstr, "\t");

		char grav_char[10];
		_itoa_s((*it).aud1.groups_available,grav_char,sizeof(grav_char),10);
		strcat(tmpstr, grav_char);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).gr1.name);
		strcat(tmpstr, "\n");

		iiicnt++; 

	}
	strcpy(out,tmpstr);
	return;
};

void SCHEDULE::AddNewStr(schedule_inputs* inputs)
{
	// TODO: сделать случайный выбор аудитории в пределах высших вместимостей

	sched_string current;	// добавляемая строка
	
	bool bo=1;
	bool flag=1;
	int les=0;
	int cnt=0;  
	int gr=0;
	int day=0;
	int tim=0;
	
	list<lesson_struct> lessons_list = inputs->inputs.lessons;

	lessons_list.sort();
	bool SchedOk = false;
	bool BadSched = false;
	// отсортировать список по максимальному количеству групп в занятиях
	while (!SchedOk)
	{
		for (list<lesson_struct>::iterator it_l=lessons_list.begin(); it_l!=lessons_list.end(); it_l++)
		{
			current.les1=*it_l;
			bool ResOfFillOneLesson = true;
			if (!strcmp(current.les1.type,"лекция")) 
			{
				ResOfFillOneLesson = Fill_One_Lesson(&lec_list,&current,inputs);
			}
			else if (!strcmp(current.les1.type,"семинар")) 
			{
				ResOfFillOneLesson = Fill_One_Lesson(&sem_list,&current,inputs);
			}
			else if (!strcmp(current.les1.type,"лаб")) 
			{
				ResOfFillOneLesson = Fill_One_Lesson(&lab_list,&current,inputs);
			}
			if (ResOfFillOneLesson == false)
			{
				BadSched = true;
				break;
			}
		}
		if (!BadSched)
		{
			SchedOk = true;
		}
		else
		{
			slist.clear(); // обнуление расписания
		}
	}

}

bool SCHEDULE::Fill_One_Lesson(list<adt_string> *inlist, sched_string *current, schedule_inputs* inputs) 
{
	list<adt_string>::iterator ptr_to_erase;	// для памяти указателя на удаляемую строку
	bool need_to_change=true;
	int num_of_inserted=0;
	bool first_time=true;
	bool noptr=true;
	bool retval=false;	// возвращаемое значение - если тру - добавили строку
	// выбираем из списка соответсвующих аудиторий, после использования нужно удалить использованную строку из списка ***_list
	
	// нужно добавить проверку на максимальное количество групп для занятия
	
	for (list<string>::iterator it_s=current->les1.for_groups.begin(); it_s!=current->les1.for_groups.end(); it_s++)
	{

		// тут есть группа в формате string. находим её из списка групп, добавляем в current, добавляем в расписание
		for (list<group_struct>::iterator it_t=inputs->inputs.groups.begin(); it_t!=inputs->inputs.groups.end(); it_t++)
		{
			// сравниваем название группы из списка целевых групп занятия и общего списка групп
			if (!strcmp((*it_t).name,(*it_s).c_str()))
			{
				(*current).gr1=*it_t;

				// выбираем группу, если это необходимо
				// каждую группу необходимо проверять на допустимость заполнения
				if (!noptr)
				{
					if (!is_not_in_restricted_list_and_not_full((*current).gr1,(*ptr_to_erase)))
						need_to_change = true;
				}

				if (need_to_change) {
					bool ResOfSelectNewGroup = Select_New_Group(inputs,current,inlist,&need_to_change,&ptr_to_erase);
					if (ResOfSelectNewGroup == false)
					{
						return false; // неудачное расписание - нужно создать заново
					}
					noptr=false;
				}
				else  {
					(*ptr_to_erase).aud.groups_available--;
					(*current).aud1.groups_available--;
				}
				
				// на самом деле выбирать строку из ***_list нужно тут с проверкой группы на наличие в restrict-листе

				slist.push_back(*current);	// добавление строки в расписание
				num_of_inserted++;
				if (num_of_inserted==(*current).les1.groups_max || (*current).aud1.groups_available==0)
				{
					// тут нужно удалить заполненную аудиторию из списка аудитория-день-время
					// 
					(*inlist).erase(ptr_to_erase);
					noptr=true;
					need_to_change=true;
				}

				// тут нужно в оставшиеся 3 списка занести информацию, что группа в данное день-время занята
				Fill_Restricted(&lec_list,*it_s,*current);
				Fill_Restricted(&sem_list,*it_s,*current);
				Fill_Restricted(&lab_list,*it_s,*current);
			}
		}
	}

	// проверяем списки на наличие в них запрещённых групп
	int cnt=Check_Restricted_Count(lec_list);
	cnt=Check_Restricted_Count(sem_list);
	cnt=Check_Restricted_Count(lab_list);

	// убираем связку аудитория-дата-время из списка		!!! не правильно! нужно удалять тот элемент, который использовался!
	if (!need_to_change)
	{
		(*inlist).erase(ptr_to_erase);
	}
	
	return true; // расписание создано удачно
}

bool SCHEDULE::Select_New_Group(schedule_inputs* inputs, sched_string* current,
								list<adt_string>* inlist, bool* need_to_change, 
								list<adt_string>::iterator *ptr_to_erase)
{
	// сортировка списка аудитория-день-время по вместимости
	// выбор максимальной вместимости по первой аудитории из списка
	// создание массива указателей на подходящие аудитории (число свободных = числу максимальной вместимости)
	// случайный выбор аудитории из массива
	// ОК

	(*inlist).sort();
	list<adt_string>::iterator itr = (*inlist).begin();
	int max_groups = (*itr).aud.groups_max;
	list<adt_string>::iterator * mas = new list<adt_string>::iterator [500]();
	
	int cntr=0;
	for (list<adt_string>::iterator it_adt=(*inlist).begin(); it_adt!=(*inlist).end(); it_adt++)
	{
		if ((*it_adt).aud.groups_available==(*it_adt).aud.groups_max && (*it_adt).aud.groups_available==max_groups)
		{
			if (is_not_in_restricted_list_and_not_full((*current).gr1,(*it_adt)))	// если не в запретном списке - добавляем текущие параметры строки в массив
			{
				// проверка нахождения группы в списке разрешённых занятий
				for (list<string>::iterator it_for=(*it_adt).aud.for_lessons.begin(); it_for!=(*it_adt).aud.for_lessons.end(); it_for++)
				{
					if (!strcmp((*it_for).c_str(),(*current).les1.name))
					{
						*(mas+cntr)=it_adt;
						cntr++;
					}
				}
			}
		}
	}
	if (cntr==0)
	{
		for (list<adt_string>::iterator it_adt=(*inlist).begin(); it_adt!=(*inlist).end(); it_adt++)
		{
			if ((*it_adt).aud.groups_available==(*it_adt).aud.groups_max)
			{
				if (is_not_in_restricted_list_and_not_full((*current).gr1,(*it_adt)))	// если не в запретном списке - добавляем текущие параметры строки в массив
				{
					// проверка нахождения группы в списке разрешённых занятий
					for (list<string>::iterator it_for=(*it_adt).aud.for_lessons.begin(); it_for!=(*it_adt).aud.for_lessons.end(); it_for++)
					{
						if (!strcmp((*it_for).c_str(),(*current).les1.name))
						{
							*(mas+cntr)=it_adt;
							cntr++;
						}
					}
				}
			}
		}
	}
	if (cntr==0)
	{
		int sizeofslist=slist.size();
		delete[] mas;
		return false;
	}
	// выбираем случайно из массива
	itr = mas[rand() %(cntr)];
	(*itr).aud.groups_available--;
	(*current).aud1=(*itr).aud;
	(*current).day1=(*itr).day;
	(*current).tim1=(*itr).time;
	*ptr_to_erase=itr;

	if ((*(*ptr_to_erase)).aud.groups_available>0)
		*need_to_change=false;
	else
		*need_to_change=true;
	delete[] mas;
	return true;
}

// добавление группы в списки
void SCHEDULE::Fill_Restricted(list<adt_string> *inlist, string adt_str, sched_string current)
{
	for (list<adt_string>::iterator it_adt=(*inlist).begin(); it_adt!=(*inlist).end(); it_adt++)
	{
		if ((*it_adt).day.id==current.day1.id && (*it_adt).time.id==current.tim1.id)
		{
			(*it_adt).restricted.push_back(adt_str);
		}
	}
}

int SCHEDULE::Check_Restricted_Count(list<adt_string> inlist)
{	// опеределение количества групп невозможных к добавлению
	int num=0;
	for (list<adt_string>::iterator it=inlist.begin(); it!=inlist.end(); it++)
	{
		num+=(*it).restricted.size();
	}
	return num;
}

bool SCHEDULE::is_not_in_restricted_list_and_not_full(group_struct gr, adt_string adt_str)
{	// функция определения допустимости добавления группы в данную комбинацию - аудитория-день-время
	
	// проверяем, если группа уже занята в это время

	
	if (adt_str.aud.groups_available>0)
	{
		bool is_in=false;
		for (list<string>::iterator it=adt_str.restricted.begin();it!=adt_str.restricted.end();it++)
		{
			if (!strcmp((*it).c_str(),gr.name))
			{
				is_in=true;
			}
		}
		return !is_in;
	}
	else 
		return false;
}

void SCHEDULE::Create(schedule_inputs* inputs)
{
	// создание расписания - добавление всех строк
	AddNewStr(inputs);

	return;
}

int SCHEDULE::stats(schedule_inputs* inputs)
{
	// вычисление статистики по группам - возможно ненужная функция


	int res=0;
	const int lessons_size = 24;//(const int*)(inputs->inputs.lessons.size());
	const int groups_size = 4;//(const int*)(inputs->inputs.groups.size());
	//	list<sched_string> slist2;
	int mas[groups_size][lessons_size]; 
	//string grps[4]={"I","II","III","IV"};
	//grouplist grps2;
	//cout << '\n';
	lesson_struct current_lesson;
	group_struct  current_group;
	for (int j=0; j<groups_size; j++)
	{	
		for (int i=0; i<lessons_size; i++)
		{
			//mas[j][i]=larr[i].leng/2;
			// тут нужно прогнать список по lessons
			for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
			{	// выбор аудитории из списка аудиторий
				if ((*it).id==i+1)
				{
					current_lesson=(*it);
				}
			}
			mas[j][i]=current_lesson.hours/2;
		}
	}
	
	for (int j=0; j<groups_size; j++)
	{
		for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
		{
			for (list<group_struct>::iterator it3=inputs->inputs.groups.begin(); it3!=inputs->inputs.groups.end(); it3++)
			{	// выбор случайной группы из списка
				if ((*it3).id==j+1)
					current_group=(*it3);
			}
			if ((*it).gr1.name==current_group.name)
			{
				for (int i=0;i<lessons_size;i++)
				{
					for (list<lesson_struct>::iterator it2=inputs->inputs.lessons.begin(); it2!=inputs->inputs.lessons.end(); it2++)
					{	// выбор аудитории из списка аудиторий
						if ((*it2).id==i+1)
						{
							current_lesson=(*it2);
						}
					}
					if (((*it).les1.type == current_lesson.type) && ((*it).les1.type == current_lesson.type))
						mas[j][i]--;
				}
			}
		}
	}

	for (int j=0; j<groups_size; j++)
	{	
		for (int i=0; i<lessons_size; i++)
		{
			res=res+mas[j][i];
		}
	}

	int retVal=res+RateWindowsGroups(inputs);
	retVal+=RateWindowsTeachers(inputs);
	//return res;
	return retVal;
}

void SCHEDULE::modify(schedule_inputs* inputs,int num)
{
	for (int i=1;i<num;i++)
		slist.pop_back();
	for (int i=1;i<num;i++)
		this->AddNewStr(inputs);

	return;
}

bool SCHEDULE::search(const sched_string &current)
{
	// поиск по текущему расписанию, есть ли занятие в то же время в тот же день, как и current
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).tim1.id==current.tim1.id && (*it).day1.id==current.day1.id)
		{return 1;}
	}
	return 0;
}

bool SCHEDULE::search2(const sched_string &current)
{
	// поиск по текущему расписанию, есть ли занятие у той же группы то же занятие, как и current
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).gr1.id==current.gr1.id && (*it).les1.id==current.les1.id)
		{return 1;}
	}
	return 0;
}

void SCHEDULE::skr(schedule_inputs* inputs,SCHEDULE & sch1, SCHEDULE & sch2)
{
	// реализация алгоритма скрещивания

	sch1.slist.sort();
	sch2.slist.sort();
	int num1=0,num2=0;
	int cnt1=0,cnt2=0;
	int cntmax1=0,cntmax2=0;
	int day,tim;
	const int maxnumofpairs=5;	//??
	sched_string cur[2][maxnumofpairs][2];
	//SCHEDULE tmp;
	for (list<sched_string>::iterator it=sch1.slist.begin(); it!=sch1.slist.end(); it++)
	{
		if ((*it).aud1.groups_max==2 && (*it).aud1.groups_available==0) 
		{
			num1++;
			cur[0][cnt1][0].aud1=(*it).aud1;
			cur[0][cnt1][0].gr1=(*it).gr1;
			cur[0][cnt1][0].les1=(*it).les1;
			it--;
			cur[0][cnt1][1].aud1=(*it).aud1;
			cur[0][cnt1][1].gr1=(*it).gr1;
			cur[0][cnt1][1].les1=(*it).les1;
			it++;
			cnt1++;
		} 
	}
	for (list<sched_string>::iterator it=sch2.slist.begin(); it!=sch2.slist.end(); it++)
	{
		if ((*it).aud1.groups_max==2 && (*it).aud1.groups_available==0) 
		{
			num2++;
			cur[1][cnt2][0].aud1=(*it).aud1;
			cur[1][cnt2][0].gr1=(*it).gr1;
			cur[1][cnt2][0].les1=(*it).les1;
			it--;
			cur[1][cnt2][1].aud1=(*it).aud1;
			cur[1][cnt2][1].gr1=(*it).gr1;
			cur[1][cnt2][1].les1=(*it).les1;
			it++;
			cnt2++;
		} 
	}
	
	if (num1>num2)
	{
		for (int i=0;i<cnt1;i++)
		{
			
			day=rand() %(inputs->inputs.days.size());
			tim=rand() %(inputs->inputs.times.size());

			for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
			{
				if ((*it).id==day+1)
					current_parameters.day1=(*it);
			}
			for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
			{
				if ((*it).id==tim+1)
					current_parameters.tim1=(*it);
			}

			cur[0][i][0].day1=current_parameters.day1;
			cur[0][i][1].day1=current_parameters.day1;
			cur[0][i][0].tim1=current_parameters.tim1;
			cur[0][i][1].tim1=current_parameters.tim1;
			if (search(cur[0][i][0])!=0)// && cntmax1<20)
			{	/*goto m1;*/}//cntmax1++;}

			//	cout << "\nerr1 " << search(cur[0][i][0]) << '\n';
/*			while ((this->search(cur[0][i][0]))!=0)
			{
				day=rand() %2; tim=rand() %3;
				cur[0][i][0].day1=darr[day];
				cur[0][i][1].day1=darr[day];
				cur[0][i][0].tim1=tarr[tim];
				cur[0][i][1].tim1=tarr[tim];
			}
*/			slist.push_back(cur[0][i][1]);
			slist.push_back(cur[0][i][0]);
		}
/*		for (int j=0;j<cnt2;j++)
		{
m3:			day=rand() %2;
			tim=rand() %3;
			cur[1][j][0].day1=darr[day];
			cur[1][j][1].day1=darr[day];
			cur[1][j][0].tim1=tarr[tim];
			cur[1][j][1].tim1=tarr[tim];
			if (search(cur[1][j][0])!=0)
				goto m3;
			if (search2(cur[1][j][0])==0)
			{
				slist.push_back(cur[1][j][1]);
				slist.push_back(cur[1][j][0]);
			}
		}
*/	} else {
		for (int i=0;i<cnt2;i++)
		{
			
			day=rand() %(inputs->inputs.days.size());
			tim=rand() %(inputs->inputs.times.size());

			for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
			{
				if ((*it).id==day+1)
					current_parameters.day1=(*it);
			}
			for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
			{
				if ((*it).id==tim+1)
					current_parameters.tim1=(*it);
			}

			cur[1][i][0].day1=current_parameters.day1;
			cur[1][i][1].day1=current_parameters.day1;
			cur[1][i][0].tim1=current_parameters.tim1;
			cur[1][i][1].tim1=current_parameters.tim1;

			if (search(cur[1][i][0])!=0 )//&& cntmax2<20)
			{	/*goto m2;*/}//cntmax2++;}
	//			cout << "\nerr2 " << search(cur[1][i][0]) << '\n';
/*			while ((this->search(cur[1][i][0]))!=0)
			{
				day=rand() %2; tim=rand() %3;
				cur[1][i][0].day1=darr[day];
				cur[1][i][1].day1=darr[day];
				cur[1][i][0].tim1=tarr[tim];
				cur[1][i][1].tim1=tarr[tim];
			}
*/			slist.push_back(cur[1][i][1]);
			slist.push_back(cur[1][i][0]);
		}
/*		for (int j=0;j<cnt1;j++)
		{
m4:			day=rand() %2;
			tim=rand() %3;
			cur[0][j][0].day1=darr[day];
			cur[0][j][1].day1=darr[day];
			cur[0][j][0].tim1=tarr[tim];
			cur[0][j][1].tim1=tarr[tim];
			if (search(cur[0][j][0])!=0)
				goto m4;
			if (search2(cur[0][j][0])==0)
			{
				slist.push_back(cur[0][j][1]);
				slist.push_back(cur[0][j][0]);
			}
		}
*/	}
	cntmax1=0;
	cntmax2=0;
	//cout << "\nNumber of double groupped pair in 1st schedule is " << num1 << "\nNumber of double groupped pair in 2nd schedule is " << num2 << '\n';
	
	//ЗДЕСЬ НУЖНО СДЕЛАТЬ ПРОВЕРКУ НА ВОЗМОЖНОСТЬ ДОБАВЛЕНИЯ - ok
	// for (int i=0;i<max_num_of_strings;i++)
	int cnt=0;
	while (cnt<100)// && CanAdd(inputs))
	{
		this->AddNewStr(inputs);
		cnt++;
	}
	return;
}

// проверка на возможность добавления новой строки в расписание
int SCHEDULE::CanAdd(sched_string current)
{
	int cnt = 0;
	//тут нужно проверить на список на возможность добавления current в список - ok
	for (list<sched_string>::iterator it=slist.begin();it!=slist.end();it++)
	{
		if ((*it).gr1.id==current.gr1.id && (*it).day1.id==current.day1.id && (*it).tim1.id==current.tim1.id)
		{
			return 4;
		}

		if ((*it).aud1.id==current.aud1.id && (*it).day1.id==current.day1.id && (*it).tim1.id==current.tim1.id)
		{
			if ((*it).les1.id==current.les1.id)
			{
				cnt++;
				if ((*it).gr1.id==current.gr1.id)
				{
					return 3; // такая группа уже в расписании
				}
				if (cnt<=current.aud1.groups_max)
				{
					//ok, nothing to do
				}
				else
				{
					return 2; // избыточная группа в аудитории
				}
			}
			else
				return 1;
		}
	}

	return 0;
}

// проверка на возможность добавления новой строки в расписание
int SCHEDULE::CanDelete(sched_string current)
{
	bool cnt = false;
	list<sched_string>::iterator ptrToDelete;
	//тут нужно проверить на список на возможность удаления current из списка
	for (list<sched_string>::iterator it=slist.begin();it!=slist.end();it++)
	{
		if ((*it).aud1.id==current.aud1.id && (*it).day1.id==current.day1.id && (*it).tim1.id==current.tim1.id && (*it).gr1.id==current.gr1.id && (*it).les1.id==current.les1.id)
		{
			cnt=true; // есть в расписании, надо удалять
			ptrToDelete = it;
		}
	}
	if (!cnt)
	{
		return 0;
	}
	else
	{
		slist.erase(ptrToDelete);
		RemoveFromRestricted(current);
		return 1;
	}
	
}
void SCHEDULE::RemoveFromRestricted(sched_string current)
{
	RemoveOneFromRestricted(current,&lec_list);
	RemoveOneFromRestricted(current,&sem_list);
	RemoveOneFromRestricted(current,&lab_list);
}
void SCHEDULE::RemoveOneFromRestricted(sched_string current,list<adt_string> *adt_list)
{
	for (list<adt_string>::iterator it=(*adt_list).begin(); it!=(*adt_list).end(); it++)
	{
		if (current.aud1.id==(*it).aud.id && current.day1.id==(*it).day.id && current.tim1.id==(*it).time.id) // нашли ауд-день-время
		{
			list<string>::iterator ptrToDelete;
			bool ok_to_del=false;
			for (list<string>::iterator it2=(*it).restricted.begin(); it2!=(*it).restricted.end(); it2++)
			{
				if (!strcmp((*it2).c_str(),current.gr1.name))	// отметили положение в списке для удаления
				{
					ptrToDelete = it2;
					ok_to_del = true;
				}
			}
			if (ok_to_del)
			{
				(*it).restricted.erase(ptrToDelete);
			}
		}
	}
}

// создание одного расписания
int SCHEDULE::Cycle2(schedule_inputs* inputs)
{
	Create(inputs);
	slist.sort();
	return Get_Stat();
}

// применение ГА для построения расписания
int SCHEDULE::Cycle(schedule_inputs* inputs)
{
	const int number_of_schedules=10;
	SCHEDULE mas[number_of_schedules],mas2[number_of_schedules],mas3[number_of_schedules];
	int stats[number_of_schedules];
	
	for (int i=0;i<number_of_schedules;i++)		// - создание начальной популяции
	{
		mas[i].CopySched(*this);
		mas[i].Create(inputs);
	}
	// создали начальную популяцию
	
	// скрестить
	// мутация каждого
	// выбор лучших
	// формирование нового поколения (добавление )
	// достигнут результат? нет - на мутацию; да - результирующая популяция

	int iterations=5;
	SCHEDULE ret_sch;
	int min=0;
	int min_index=0;
	bool finished = false;	// условие останова
	for (int i=0; i<iterations; i++)
	{
		// мутация, статистика
		for (int j=0; j<number_of_schedules;j++)
		{
			mas[j].Mutate(inputs);
			stats[j]=mas[j].Get_Stat();
			if (min==0)
			{
				min=stats[j];
			}
			if (stats[j]<min)
			{
				min=stats[j];	// вычисляем наименьшее количество пар в 8 утра
			}
		}
		int min_plus=min+3; // вычисляем допустимую погрешность для лучших расписаний
		int cntr=0;
		for (int j=0;j<number_of_schedules;j++)	// заполняем новую генерацию лучшими особями
		{
			if (stats[j]<min_plus)
			{
				mas3[cntr].CopySched(mas[j]);
				cntr++;
			}
		}

		for (cntr;cntr<number_of_schedules;cntr++)	// дополняем новую генерацию новыми расписаниями
		{
			SCHEDULE new_s;
			new_s.CopySched(*this);
			new_s.Create(inputs);
			mas3[cntr]=new_s;
		}
		// получили новую популяцию, возвращаем её в mas для следующего шага

		for (int j=0;j<number_of_schedules;j++)
		{
			mas[j].CopySched(mas3[j]);
			stats[j]=mas[j].Get_Stat();
			if (j==0)
			{
				min=stats[j];
				min_index=j;
			}
			if (stats[j]<min)
			{
				min=stats[j];
				min_index=j;
			}
		}
		// новая популяция

		// выбор лучших

		if (finished)
		{
			break;
		}
	}

	ret_sch=mas[min_index];
	// выбираем лучшее расписание, выводим ret_sch
	slist=ret_sch.slist;
	slist.sort();
	return min;
}

int SCHEDULE::RateWindowsGroups(schedule_inputs* inputs)
{
	int retVal=0;
	bool groupStarts = false;
	bool switcher = false; // изменение состояния подряд идущих пар
	sched_string memLes;

	for (list<group_struct>::iterator it_gr=inputs->inputs.groups.begin();it_gr!=inputs->inputs.groups.end();it_gr++)
	{
		for (list<sched_string>::iterator it=slist.begin();it!=slist.end();it++)
		{
			if (!groupStarts)
			{
				if ((*it).gr1.id==(*it_gr).id)
				{
					groupStarts=true;
					memLes = (*it);
					retVal+=1;
				}
			}
			if ((*it).day1.id!=(memLes.day1.id))
			{
				if ((*it).gr1.id==(*it_gr).id)
				{
					groupStarts=true;
					memLes = (*it);
					retVal+=1;
				}
			}
			if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id)) // 
			{
				//ok - ничего не делаем
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+1) && (*it).gr1.id==memLes.gr1.id) 
			{
				switcher = false; // если у группы два занятия подряд - нет переключения
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+2) && (*it).gr1.id==memLes.gr1.id)
			{
				// занятия идут через одно - два переключения
				retVal+=2;
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+3) && (*it).gr1.id==memLes.gr1.id)
			{
				// занятия идут через одно - два переключения
				retVal+=2;
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+4) && (*it).gr1.id==memLes.gr1.id)
			{
				// занятия идут через одно - два переключения
				retVal+=2;
			}

			if ((*it).gr1.id==(*it_gr).id)
			{
				memLes = (*it);
			}
		}
	}

	return retVal;
}

int SCHEDULE::RateWindowsTeachers(schedule_inputs* inputs)
{
	int retVal=0;
	bool groupStarts = false;
	bool switcher = false; // изменение состояния подряд идущих пар
	sched_string memLes;

	//groups -> teachers
	//for (list<group_struct>::iterator it_gr=inputs->inputs.groups.begin();it_gr!=inputs->inputs.groups.end();it_gr++)
	for (list<string>::iterator it_t=teachers_list.begin();it_t!=teachers_list.end();it_t++)
	{
		for (list<sched_string>::iterator it=slist.begin();it!=slist.end();it++)
		{
			if (!groupStarts)
			{
				if ((*it).les1.teacher==(*it_t))
				{
					groupStarts=true;
					memLes = (*it);
					retVal+=1;
				}
			}
			if ((*it).day1.id!=(memLes.day1.id))
			{
				if ((*it).les1.teacher==(*it_t))
				{
					groupStarts=true;
					memLes = (*it);
					retVal+=1;
				}
			}
			if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id)) // 
			{
				//ok - ничего не делаем
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+1) && (*it).les1.teacher==(*it_t)) 
			{
				switcher = false; // если у группы два занятия подряд - нет переключения
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+2) && (*it).les1.teacher==(*it_t))
			{
				// занятия идут через одно - два переключения
				retVal+=2;
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+3) && (*it).les1.teacher==(*it_t))
			{
				// занятия идут через одно - два переключения
				retVal+=2;
			}
			else if ((*it).day1.id==(memLes.day1.id) && (*it).tim1.id==(memLes.tim1.id+4) && (*it).les1.teacher==(*it_t))
			{
				// занятия идут через одно - два переключения
				retVal+=2;
			}

			if ((*it).les1.teacher==(*it_t))
			{
				memLes = (*it);
			}
		}
	}

	return retVal;
}

int SCHEDULE::Get_Stat()	// функция расчёта количества пар в 8 утра
{
	int retval = 0;
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).tim1.begin_time==8)
		{
			retval++;
		}
	}
	return retval;
} 

void SCHEDULE::Mutate(schedule_inputs* inputs)		// мутирование расписание - перемещение пар с 8 утра
{	// функция мутации
	list<sched_string>::iterator ptrmas[100];//mas [10];// = new list<sched_string>::iterator []();
	int cntr = 0, cntr2 = 0;
	int dayId = 0;
	int audId = 0;
	int lesId = 0;
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).tim1.begin_time==8)
		{
			if (dayId==0)
				dayId=(*it).day1.id;
			if (audId==0)
				audId=(*it).aud1.id;
			if (lesId==0)
				lesId=(*it).les1.id;
			if (((*it).aud1.id!=audId || (*it).day1.id!=dayId || (*it).les1.id!=lesId))	// && cntr2>1)
			{
				audId = (*it).aud1.id;
				dayId = (*it).day1.id;
				lesId = (*it).les1.id;
				if (cntr==1)
				{
					ptrmas[cntr2]=it;
					cntr2++;
				}
				cntr=1;
			}
			else {
				// то есть в 8 больше одной группы на одном занятии
				cntr++;
			}
		}
	}
	slist.sort();
	int num = Get_Stat();
	for (int i=0;i<cntr2;i++)
	{
		if (ReplaceSchedStr(&(*ptrmas[i]),inputs))
		{
			slist.erase(ptrmas[i]);
		}
		num = Get_Stat();
	}
	slist.sort();
	num = Get_Stat();
	int o=0;
}

bool SCHEDULE::ReplaceSchedStr (sched_string *current, schedule_inputs* inputs)
{	// функция замены строки в расписании
	(*current).les1.for_groups.clear();
	(*current).les1.for_groups.push_back((*current).gr1.name);
	bool retval=false;
	if (!strcmp((*current).les1.type,"лекция")) 
		retval = Fill_One_Lesson(&lec_list,current,inputs);
	else if (!strcmp((*current).les1.type,"семинар")) 
		retval = Fill_One_Lesson(&sem_list,current,inputs);
	else if (!strcmp((*current).les1.type,"лаб")) 
		retval = Fill_One_Lesson(&lab_list,current,inputs);
	return retval;
}

int SCHEDULE::num_free_groups ()
{
	int sum_num_free=0;
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		sum_num_free+=(*it).aud1.groups_available;
	}
	return sum_num_free;
}

// Создает массив из всех занатий
void SCHEDULE::Make_Lesson_List	(schedule_inputs* inputs)
{
	// тут создаём 3 списка аудитория - день - время для лекций, семинаров, лабораторных

	adt_string new_adt_string; // строка для заполнения
	for (list<auditory_struct>::iterator it_a=inputs->inputs.auditories.begin(); it_a!=inputs->inputs.auditories.end(); it_a++)
	{
		new_adt_string.aud=(*it_a);
		for (list<day_struct>::iterator it_d=inputs->inputs.days.begin(); it_d!=inputs->inputs.days.end(); it_d++)
		{
			new_adt_string.day=(*it_d);
			for (list<time_struct>::iterator it_t=inputs->inputs.times.begin(); it_t!=inputs->inputs.times.end(); it_t++)
			{
				new_adt_string.time=(*it_t);
				char cur_aud_type[100];
				strcpy(cur_aud_type,new_adt_string.aud.type);
				if (!strcmp(cur_aud_type,"лекция"))
				{
					lec_list.push_back(new_adt_string);
				}
				else if (!strcmp(cur_aud_type,"семинар"))
				{
					sem_list.push_back(new_adt_string);
				}
				else if (!strcmp(cur_aud_type,"лаб"))
				{
					lab_list.push_back(new_adt_string);
				}
			}
		}
	}

	// тут нужно отсортировать аудитории из списков по вместимости; аудитории с максимальной вместимостью - в начале

	lec_list.sort();
	sem_list.sort();
	lab_list.sort();
	
	// создаём список преподавателей

	//teachers_list = new list<string>();
	for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin();it!=inputs->inputs.lessons.end();it++)
	{
		string str((*it).teacher); // новый учитель 
		bool isInTList = false;
		if (teachers_list.size()>0)
		{
			for (list<string>::iterator it_s=teachers_list.begin(); it_s!=teachers_list.end(); it_s++)
			{
				if ((*it_s)==str)
					isInTList = true;
			}
		}
		if (!isInTList)
		{
			teachers_list.push_back(str);
		}
	}

	int a = teachers_list.size();
	// теперь из отсортированных списков аудиторий нужно создавать строки расписания
}

lesson_struct SCHEDULE::Get_Lesson_From (schedule_inputs* inputs)
{
	inputs->inputs.lessons.sort();
	String ^ outstr="";
	int cntr=0;
	int retindex=0;
	lesson_struct ls;
	for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
	{
		cntr++;
		if ((*it).in_sch==false)
		{	
			retindex=1;
			outstr+="GrList: ";
			for (list<string>::iterator it2=(*it).for_groups.begin(); it2!=(*it).for_groups.end(); it2++)
			{
				outstr+=String((*it2).c_str()).ToString()+",";
			}
			//outstr+=(*it).groups_max+"; Name = "+String((*it).name).ToString()+"; Type = "+String((*it).type).ToString()+"\n";
			(*it).in_sch=true;
			return *it;
		}
	}
	return ls;
}

time_struct SCHEDULE::Get_Time_From (schedule_inputs* inputs)
{
	int randnum = rand() %(inputs->inputs.times.size());
	int cnt = 0;
	time_struct ts;
	for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
	{
		if (cnt==randnum) { ts=*it; break; }
		cnt++;
	}
	return ts;
}

day_struct SCHEDULE::Get_Day_From (schedule_inputs* inputs)
{
	int randnum = rand() %(inputs->inputs.days.size());
	int cnt = 0;
	day_struct ds;
	for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
	{
		if (cnt==randnum) { ds=*it; break; }
		cnt++;
	}
	return ds;
}

auditory_struct SCHEDULE::Get_Aud_From (schedule_inputs* inputs, lesson_struct ls)
{
	//тут нужно составить список возможных аудиторий и выбрать случайную

	int audnumber=0;
	int randnum=0;
	int* mas = new int[inputs->inputs.auditories.size()];
	auditory_struct as;
	as.id=-1;
	//ищем подходящие аудитории
	for (list<auditory_struct>::iterator it=inputs->inputs.auditories.begin(); it!=inputs->inputs.auditories.end(); it++)
	{
		if (/*(*it).groups_max>=ls.groups_max &&*/ !strcmp((*it).type,ls.type) && (*it).groups_available>0)
		{
			//добавление данной аудитории в список возможных
			mas[audnumber++]=(*it).id;
		}
	}

	if (audnumber!=0)
	{
		randnum=mas[rand()%audnumber];
	}
	
	//достаём выбранную аудиторию из списка аудиторий для возвращения
	for (list<auditory_struct>::iterator it=inputs->inputs.auditories.begin(); it!=inputs->inputs.auditories.end(); it++)
	{
		if ((*it).id==randnum) { as=*it; }
	}

	delete [] mas;

	return as;
}

bool SCHEDULE::Fill_Les_into (schedule_inputs* inputs, lesson_struct ls, auditory_struct as)
{
	sched_string current;	// добавляемая строка
	
	bool Can_Add_to_sch = true;
	//выбор группы
	int cntr = 0;
	current.les1=ls;
	current.aud1=as;

	//проверка на возможность добавления
	do 
	{
		//выбираем случайное время, день
		cntr++;
		current.tim1 = Get_Time_From(inputs);
		current.day1 = Get_Day_From(inputs);
		Can_Add_to_sch=true;
		for (list<sched_string>::iterator it1=slist.begin(); it1!=slist.end(); it1++)
		{	// (*it1) - элементы расписания
			for (list<string>::iterator it=ls.for_groups.begin(); it!=ls.for_groups.end(); it++)
			{
				
				if ((!strcmp((*it).c_str(),(*it1).gr1.name) && 
					!strcmp((*it1).day1.name,current.day1.name) &&
					(*it1).tim1.begin_time==current.tim1.begin_time && as.groups_available>0 &&
					!strcmp(as.name,(*it1).aud1.name)))
				{
					//если мы нашли разногласие - флаг на обновление день-время
					Can_Add_to_sch=false;
				}
			}
		}
	} while (!Can_Add_to_sch && cntr<5000);

	//тут нужно добавить группы из списка групп
	lesson_struct TempLessonStruct = ls;

	for (int i=0; i<as.groups_max; i++)
	{
		// если в аудиторию можно добавить группу - добавляем из списка
		if (TempLessonStruct.for_groups.size()>0 && as.groups_available>0)
		{
			String^ current_group="";
			char current_group_char[10]="";
			list<string> list_to_del;
			
			for (list<string>::iterator it12=TempLessonStruct.for_groups.begin(); it12!=TempLessonStruct.for_groups.end(); it12++)
			{
				string group_string = *it12;
				list_to_del.push_back(group_string);
				current_group=String((*it12).c_str()).ToString();
				strcpy(current_group_char,(*it12).c_str());
				// прогнать по группам и сравнить с названиями
				for (list<group_struct>::iterator it123=(inputs)->inputs.groups.begin(); it123!=(inputs)->inputs.groups.end(); it123++)
				{
					if (String((*it123).name).ToString()==current_group)
					{
						current.gr1=*it123;
						current.aud1.groups_available--;
					}
				}
				// записываем строку в расписание
				slist.push_back(current);
			}
			//тут нужно вытащить группу из списка групп
			for (list<string>::iterator it12=list_to_del.begin(); it12!=list_to_del.end(); it12++)
			{
				TempLessonStruct.for_groups.remove(*it12);
			}
		}
	}
	return true; // успех
}
