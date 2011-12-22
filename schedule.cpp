#include "stdafx.h"

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

inline void SCHEDULE::AddNewStr_List (const sched_string &current)
{
	slist.push_back(current);
	return;
};

void SCHEDULE::Show_All_List(char* out)
{
	//выводит расписание в out

	slist.sort();
	cout << '\n';
	int iiicnt=1;
	char tmpstr[65000]="";
	strcat(tmpstr,"This is automatically generated schedule\n\n");
	strcat(tmpstr, "N\tDay\t\tStart\tL_name\t\t\tL_type\tAud\t\tFree\tGroup N\n");
	strcat(tmpstr,"-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		/*cout << setw(6) << iiicnt << "|	"; iiicnt++; 
		cout << setw(8) << (*it).day1.name << '|' << setw(7) << (*it).tim1.begin_time << '|' << setw(8);
		cout << (*it).les1.name << '|' << setw(7) << (*it).les1.type << '|' << setw(7); 
		cout << (*it).aud1.id << '|' << setw(7) << (*it).aud1.groups_available << '|' << setw(7) << (*it).gr1.name << "|" ;
		cout << "\n";*/
		
		char iiicnt_char[10];
		itoa(iiicnt,iiicnt_char,10);

		strcat(tmpstr, iiicnt_char);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).day1.name);
		if (strlen((*it).day1.name)<10)
			strcat(tmpstr, "\t");
		strcat(tmpstr, "\t");

		char bt_char[10];
		itoa((*it).tim1.begin_time,bt_char,10);
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

		char audid_char[10];
		//itoa((*it).aud1.id,audid_char,10);
		//strcat(tmpstr, audid_char);
		strcat(tmpstr, (*it).aud1.name);
		if (strlen((*it).aud1.name)<8)
			strcat(tmpstr, "\t");
		strcat(tmpstr, "\t");

		char grav_char[10];
		itoa((*it).aud1.groups_available,grav_char,10);
		strcat(tmpstr, grav_char);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).gr1.name);
		strcat(tmpstr, "\n");

		iiicnt++; 

	}
	strcpy (out,tmpstr);
	return;
};

void SCHEDULE::AddNewStr(schedule_inputs* inputs)
/*
   for (lesson in lessonList) // Уроки
   {
      int roomNum = getRoomNum(lesson);
      int compatibleNum = 0;  // Число допустимых
      for (elem in roomList)  // Комната-интервал
      {
         if (isCompatible(lesson, elem))
            compatibleNum++;
      }
      for (int r=0; r<roomNum; r++)
      {
         int index = rand() % compatibleNum;
         for (elem in roomList)
         {
            if (isCompatible(lesson, elem))
            {
               index--;
               if (index==0)
               {
                  timeTable.put(lesson, r, elem);
                  break;
               }
            }
         }
      }
   }
*/
{
	//

	sched_string current;	// добавляемая строка
	bool bo=1;
	bool flag=1;
	int les=0;
	int cnt=0;
	int gr=0;
	int day=0;
	int tim=0;
	
	//итерация по добавлению
	//while (bo==1 && CanAdd(inputs) /*&& cnt<100*/)	
		// 100, потому что CanAdd проверяет на количество строк в расписании 
		// по отношению к количеству строк с полностью распределённым расписанием.
		// В версии с реальными входными данными нужно проверить без cnt<100

	//les = Get_Lesson_Number(inputs);
	//lesson_struct current_lesson = Get_Lesson_From(inputs);
	
	//не правильно, потому что будем вытаскивать из списка групп 
	current.les1 = Get_Lesson_From(inputs);

	if (current.les1.for_groups.size()!=0)
	{
		
		String^ outstr = "";
		//outstr+=String(current.les1.name).ToString()+"; "+String(current.les1.type).ToString()+"; "+String(current.day1.name).ToString();
		//MessageBox::Show(outstr);

		//тут нужно определить, сколько нужно аудиторий для заполнения данного занятия
		int num_of_auds = current.les1.for_groups.size() / current.les1.groups_max;
		
		//по количеству занимаемых аудиторий заполняем группы занятиями
		for (int i=0; i<num_of_auds; i++)
		{
			current.aud1 = Get_Aud_From(inputs, current.les1);

			if (Fill_Les_into(inputs, current.les1, current.aud1)) 
			{
				for (list<auditory_struct>::iterator it=inputs->inputs.auditories.begin(); it!=inputs->inputs.auditories.end(); it++)
				{
					//inputs->inputs.auditories
					if ((*it).name == current.aud1.name) {
						(*it).groups_available = 0;
					}
				}
				//MessageBox::Show("sum groups added to schedule ", String::Concat(i));
			}
		}
		

		//сопоставить время



		//les=rand() %(inputs->inputs.lessons.size());
		
		/*
		lesson_string current_lesson_string;
		for (list<lesson_string>::iterator it=llist.begin(); it!=llist.end(); it++)
		{
			if ((*it).id==les)
			{
				current_lesson_string=*it;
			}
		}

		for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
		{	// выбор аудитории из списка аудиторий
			//if ((*it).id==les+1)
			if ((*it).id==current_lesson_string.from_lessons_id)
			{
				current_parameters.les1=(*it);
			}
		}*/
		/*int some_size_of_auditories=inputs->inputs.auditories.size();
		for (int i=0;i<some_size_of_auditories;i++)
		{	
			// проверка аудитории на занятость
			bool free_groups=false; // по какой ветке пойдём
			bool get_out=false;		// выйти из ветки
			int const max_free_groups=5555;

			if (num_free_groups()>max_free_groups)
			{
				free_groups=true;
			}

			// прогон строки по аудиториям
			for (list<auditory_struct>::iterator it2=inputs->inputs.auditories.begin(); it2!=inputs->inputs.auditories.end(); it2++)
			{
				if ((*it2).id==i+1)
				{
					current_parameters.aud1=(*it2);
					if (free_groups)
					{
						//if (current_parameters.aud1.priority==0)
						if (num_free_groups()+current_parameters.aud1.groups_available>max_free_groups)
						{
							get_out=true;
						}
					}
					
				}
			}
			if (!get_out)
			{
				if ((!strcmp(current_parameters.aud1.type,"лекция") && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"лекция")) || 
					(!strcmp(current_parameters.aud1.type,"семинар") && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"семинар")) || 
					(!strcmp(current_parameters.aud1.type,"лаб")	 && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"лаб")) )
				{
					gr=rand() %(inputs->inputs.groups.size());
					day=rand() %(inputs->inputs.days.size());
					tim=rand() %(inputs->inputs.times.size());

					for (list<group_struct>::iterator it=inputs->inputs.groups.begin(); it!=inputs->inputs.groups.end(); it++)
					{	// выбор случайной группы из списка
						if ((*it).id==gr+1)
							current_parameters.gr1=(*it);
					}
					for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
					{	// выбор случайного дня недели из списка
						if ((*it).id==day+1)
							current_parameters.day1=(*it);
					}
					for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
					{	// выбор случайного времени начала из списка 
						if ((*it).id==tim+1)
							current_parameters.tim1=(*it);
					}


					//	создание текущей строки
					current.aud1=current_parameters.aud1;
					current.day1=current_parameters.day1;
					current.gr1 =current_parameters.gr1;
					current.les1=current_parameters.les1;
					current.tim1=current_parameters.tim1;

					for (list<sched_string>::iterator it1=slist.begin(); it1!=slist.end(); it1++)
					{
						// проверка на конфликты
						if ( ((*it1).gr1.id == current.gr1.id  &&  (*it1).les1.id==current.les1.id) ||
							( ((*it1).gr1.id == current.gr1.id  || ((*it1).aud1.id==current.aud1.id && 
							(*it1).les1.id!= current.les1.id)) && 
							(*it1).day1.id== current.day1.id &&  (*it1).tim1.id==current.tim1.id) ) 
						{flag=0;} 
						else if ((*it1).gr1.id!=current.gr1.id   && (*it1).day1.id==current.day1.id && 
							(*it1).tim1.id==current.tim1.id && (*it1).aud1.id==current.aud1.id)
						{
							if ((*it1).aud1.groups_available==0)
							{flag=0;} else current.aud1.groups_available--;
						}
					}

					if (flag==1)
					{
						current.aud1.groups_available--;	

						
						for (list<lesson_string>::iterator itq=llist.begin(); itq!=llist.end(); itq++)
						{
							//if ((*itq).id==les && strcmp(current.gr1.name,(*itq).group.c_str()))
							if (strcmp(current.les1.name,(*itq).lesson_name) && 
								strcmp(current.les1.type,(*itq).lesson_type) && 
								strcmp(current.gr1.name,(*itq).group.c_str()) &&
								(current.les1.id==(*itq).from_lessons_id))
								//current.les1.
							{
								(*itq).used=true;
							}
						}

						// добавление в расписание
						this->AddNewStr_List(current);

						bo=0;
						i=4;
					}
					flag=1;
				}
			}
			
		}  
		cnt+=1;*/
	}
}

void SCHEDULE::Create(schedule_inputs* inputs)
{
	Make_Lesson_List(inputs);
	// создание расписания - добавление максимально возможного количества строк
	//for (unsigned int i=0;i<llist.size();i++)
	for (unsigned int i=0;i<(inputs->inputs.lessons).size();i++)
	//for (unsigned int i=0;i<10;i++)
	{
		this->AddNewStr(inputs);
	}

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

/*	cout << "\n Statistics: \n";
	
	//вывод
	cout << "Groups		Lessons \n";
	cout << "	1	2	3	4	5\n";
	for (int j=0; j<4; j++)
	{
		cout << garr[j].name << '\t';
		for (int i=0; i<5; i++)
		{
			cout << mas[j][i] << '\t';
		}
		cout << '\n';
	}
*/	return res;
	//return 0;
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
	while (cnt<100 && CanAdd(inputs))
	{
		this->AddNewStr(inputs);
		cnt++;
	}
	return;
}

bool SCHEDULE::CanAdd(schedule_inputs* inputs)
{
	//тут нужно проверить на список на возможность добавления - ok

	if (slist.size()<max_num_of_strings)
		return 1;
	return 0;
}

void SCHEDULE::Cycle2(schedule_inputs* inputs)
{
	SCHEDULE sch;
	sch.remax(inputs);
	sch.Create(inputs);
	slist=sch.slist;
	llist=sch.llist;
	//sch.Make_Lesson_List(inputs);
	//sch.Show_Lesson_List();
}

void SCHEDULE::Cycle(schedule_inputs* inputs)
{
	const int number_of_schedules=10;
	SCHEDULE mas[number_of_schedules],mas2[number_of_schedules],mas3[number_of_schedules];
	for (int i=0;i<number_of_schedules;i++)
	{
		mas[i].remax(inputs);
		mas2[i].remax(inputs);
		mas3[i].remax(inputs);
	}

	int stats[number_of_schedules],max,nmax,iter;
	iter=0;
	for (int i=0;i<number_of_schedules;i++)		// - создание массива статистик
	{
		mas[i].Create(inputs);
		stats[i]=mas[i].stats(inputs);
	}

	max=stats[0];
	nmax=1;

	do

	{
		for (int i=1;i<number_of_schedules;i++)		// - мас2 - лучшие из выборки 
		{
			if (stats[i]<max) 
			{
				max=stats[i];
				nmax=1;
				mas2[nmax-1]=mas[i];
			} else if (stats[i]==max)
			{
				nmax+=1;
				mas2[nmax-1]=mas[i];
			}
		}
		for (int i=0;i<nmax-1;i++)
			mas3[i].skr(inputs,mas2[i],mas2[i+1]); // - скрещенный массив списков
		for (int i=nmax-1;i<number_of_schedules;i++)
			mas3[i]=mas[i];				// - дополняем списками - родителями
		for (int i=0;i<10;i++)
		{
			mas3[i].modify(inputs,5);
			mas[i]=mas3[i];
			stats[i]=mas[i].stats(inputs);
		}
		max=stats[0];
		nmax=1;

	
		iter+=1;
	} while (iter<1);

	for (int i=0;i<number_of_schedules;i++)
	{
		if (stats[i]<=max)
		{
			max=stats[i];
			nmax=i;
			slist=mas[i].slist;
		} //else if (stats[i]==max)
			//slist=mas[i].slist;

	}

	return;
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
	int id = 1;
	for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
	{
		for (list<string>::iterator it2=(*it).for_groups.begin(); it2!=(*it).for_groups.end(); it2++)
		{
			lesson_string new_lesson_string;
			new_lesson_string.group=(*it2);
			new_lesson_string.hours=(*it).hours;
			new_lesson_string.id=id;
			id++;
			strcpy(new_lesson_string.lesson_name,(*it).name);
			strcpy(new_lesson_string.lesson_type,(*it).type);
			new_lesson_string.used=false;
			new_lesson_string.max_groups=(*it).groups_max;
			new_lesson_string.from_lessons_id=(*it).id;
			llist.push_back(new_lesson_string);
		}
	}
	//MessageBox::Show(String::Concat(llist.size()));
}

String^ SCHEDULE::Show_Lesson_List	()
{
	String^ output_str="";
	for (list<lesson_string>::iterator it=llist.begin(); it!=llist.end(); it++)
	{
		output_str+=String::Concat((*it).id,"\t",String((*it).group.c_str()).ToString(),"\t",(*it).hours,"\t",
			String((*it).lesson_name).ToString(),"\t",String((*it).lesson_type).ToString(),"\t",(*it).max_groups,"\t",
			(*it).used,"\t",(*it).from_lessons_id,"\n");
	}
	return output_str;
}

// Показывает все занятия с максимальным количеством групп
// inputs - учебный план
// результат - индекс одного из этих занятий 
int SCHEDULE::Get_Lesson_Number (schedule_inputs* inputs)
{
	int string_id=0;
	int max_for_groups=0;
	string cur_group="";
	char cur_lesson_name[100];
	char cur_lesson_type[100];
	int counter=0;
	int* mas = new int[llist.size()];

	for (list<lesson_string>::iterator it=llist.begin(); it!=llist.end(); it++)
	{
		if ((*it).id==1)
		{
			cur_group=(*it).group;
			strcpy(cur_lesson_name,"");//(*it).lesson_name);
			strcpy(cur_lesson_type,"");//(*it).lesson_type);
		}
		if ((*it).max_groups>=max_for_groups)
		{
			if ((*it).max_groups==max_for_groups)
			{
				if (((strcmp((*it).lesson_name,cur_lesson_name)) || (strcmp((*it).lesson_type,cur_lesson_type))) && !((*it).used))
				{
					max_for_groups=(*it).max_groups;
					string_id=(*it).id;
					strcpy(cur_lesson_name,(*it).lesson_name);
					strcpy(cur_lesson_type,(*it).lesson_type);
					mas[counter++]=string_id;
				}
			}
			else
			{
				counter=0;			
				max_for_groups=(*it).max_groups;
				string_id=(*it).id;
				strcpy(cur_lesson_name,(*it).lesson_name);
				strcpy(cur_lesson_type,(*it).lesson_type);
				mas[counter++]=string_id;
			}
		}
	}
	//MessageBox::Show(String::Concat("Max for groups = ",max_for_groups));
	//MessageBox::Show(String::Concat("String id in lessons table = ",string_id));
	String^ str_mas="";
	for (int i=0; i< counter; i++)
	{
		if (i!=0)
		{
			str_mas+=",";
		}
		str_mas+=mas[i];
	}
	int randnum=0;
	if (counter == 0)
	{
		randnum=0;
	}
	else
		randnum=mas[rand()%counter];
	//MessageBox::Show(String::Concat("Massiv = "+str_mas));
	//MessageBox::Show(String::Concat("Random number from mas = "+randnum));
	delete [] mas;
	return randnum;
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
	//MessageBox::Show(outstr);
	return ls;
}

time_struct SCHEDULE::Get_Time_From (schedule_inputs* inputs)
{
	int randnum = rand() %(inputs->inputs.times.size());
	int cnt = 0;
	time_struct ts;
	for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
	{
		if (cnt==randnum) {return *it;}
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
		if (cnt==randnum) {return *it;}
		cnt++;
	}
	return ds;
}

auditory_struct SCHEDULE::Get_Aud_From (schedule_inputs* inputs, lesson_struct ls)
{
	//тут нужно составить список возможных аудиторий и выбрать случайную
	//смотреть get_lesson_number

	int audnumber=0;
	int randnum=0;
	int* mas = new int[inputs->inputs.auditories.size()];
	auditory_struct as;
	as.id=-1;
	//ищем подходящие аудитории
	for (list<auditory_struct>::iterator it=inputs->inputs.auditories.begin(); it!=inputs->inputs.auditories.end(); it++)
	{
		if ((*it).groups_max>=ls.groups_max && !strcmp((*it).type,ls.type) && (*it).groups_available>0)
		{
			//добавление данной аудитории в список возможных
			mas[audnumber++]=(*it).id;
			
			//String^ outstr = "id of compatible aud = " + (String::Concat((*it).id));
			//MessageBox::Show(outstr);
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

	//String^ outstr = "And the winner id = " + (String::Concat(as.id));
	//MessageBox::Show(outstr);

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

					/*(!strcmp(current_parameters.aud1.type,"лекция") && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"лекция")) || 
					(!strcmp(current_parameters.aud1.type,"семинар") && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"семинар")) || 
					(!strcmp(current_parameters.aud1.type,"лаб")	 && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"лаб"))*/


				{
					//если мы нашли разногласие - флаг на обновление день-время
					Can_Add_to_sch=false;
				}
			}
			// проверка на конфликты
			/*if ( ((*it1).gr1.id == current.gr1.id  &&  (*it1).les1.id==current.les1.id) ||
				( ((*it1).gr1.id == current.gr1.id  || ((*it1).aud1.id==current.aud1.id && 
				(*it1).les1.id!= current.les1.id)) && 
				(*it1).day1.id== current.day1.id &&  (*it1).tim1.id==current.tim1.id) ) 
			{flag=0;} 
			else if ((*it1).gr1.id!=current.gr1.id   && (*it1).day1.id==current.day1.id && 
				(*it1).tim1.id==current.tim1.id && (*it1).aud1.id==current.aud1.id)
			{
				if ((*it1).aud1.groups_available==0)
				{flag=0;} else current.aud1.groups_available--;
			}*/
		}
	} while (!Can_Add_to_sch && cntr<5000);

	//тут нужно добавить группы из списка групп
	/*int min_of_groups_or_size = as.groups_max;
	if (ls.for_groups.size<min_of_groups_or_size)
	{
		min_of_groups_or_size=ls.for_groups.size;
	}*/
	//MessageBox::Show(String::Concat(String(as.name).ToString()));
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
				//MessageBox::Show(current_group);
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
				//

				//// записываем строку в расписание
				//AddNewStr_List(current);
				slist.push_back(current);
				////

//				MessageBox::Show(String::Concat("Current group = ",current_group));
				//тут нужно вытащить группу из списка групп
				if (TempLessonStruct.for_groups.size()>0)
				{
				//	TempLessonStruct.for_groups.pop_back();
				}
				//else
					//TempLessonStruct.for_groups.pop_front();
				//MessageBox::Show(String::Concat(TempLessonStruct.for_groups.size()));
			}
			for (list<string>::iterator it12=list_to_del.begin(); it12!=list_to_del.end(); it12++)
			{
				TempLessonStruct.for_groups.remove(*it12);
			}
		}
	}



	/*if (flag==1)
	{
		current.aud1.groups_available--;	


		for (list<lesson_string>::iterator itq=llist.begin(); itq!=llist.end(); itq++)
		{
			//if ((*itq).id==les && strcmp(current.gr1.name,(*itq).group.c_str()))
			if (strcmp(current.les1.name,(*itq).lesson_name) && 
				strcmp(current.les1.type,(*itq).lesson_type) && 
				strcmp(current.gr1.name,(*itq).group.c_str()) &&
				(current.les1.id==(*itq).from_lessons_id))
				//current.les1.
			{
				(*itq).used=true;
			}
		}

		// добавление в расписание
		this->AddNewStr_List(current);

		bo=0;
		i=4;
	}
	flag=1;*/


	return true; // успех
}
