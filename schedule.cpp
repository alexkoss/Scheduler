#include "stdafx.h"

#include "func.h"
#include "schedule.h"
class schedule_inputs; 
/*auditory aarr[] =
{
	
	{1, LECTION, 2, 2},
	{2, SEMINAR, 1, 1},
	{3, SEMINAR, 1, 1},
	{4, LAB,	 1, 1}
};

groups garr[] =
{
	{1, "I", I},
	{2, "II", II},
	{3, "III", III},
	{4, "IV", IV}
};

days darr[] =
{
	{1, "Monday"},
	{2, "Tuesday"}
};

lessons larr[] =
{
	{1, "Math",		"lec", 2},
	{2, "Physics",	"lec", 2},
	{3, "Math",		"upr", 2},
	{4, "Physics",	"upr", 2},
	{5, "Physics",	"lab", 2}
};

times tarr[] =
{
	{1, 10},
	{2, 12},
	{3, 14}
};*/

bool sched_string::operator <(const sched_string& str) const 
{
	//if (day1.n < str.day1.n)
	//	return day1.n < str.day1.n;
	if (day1.id == str.day1.id)
	{
		//if (tim1.T < str.tim1.T)
		//	return tim1.T < str.tim1.T;
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
	slist.sort();
	cout << '\n';
	int iiicnt=1;
	char tmpstr[65000]="";
	strcat(tmpstr,"This is automatically generated schedule\n\n");
	strcat(tmpstr, "N\tDay\tStart\tL_name\tL_type\tAud\tFree\tGroup N\n");
	strcat(tmpstr,"----------------------------------------------------------------------------------------------------------------------------------------------\n");
	
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
		strcat(tmpstr, "\t");

		char bt_char[10];
		itoa((*it).tim1.begin_time,bt_char,10);
		strcat(tmpstr, bt_char);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).les1.name);
		strcat(tmpstr, "\t");
		strcat(tmpstr, (*it).les1.type);
		strcat(tmpstr, "\t");

		char audid_char[10];
		itoa((*it).aud1.id,audid_char,10);
		strcat(tmpstr, audid_char);
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

/*void SCHEDULE::Sort_List (void)
{
	slist.sort();
	return;
}*/


/*void SCHEDULE::Add(const sched_string &sc)
{
	sched_string *temp, *cur;
	temp = new sched_string;
	if (!temp)
	{
		cout << "\nNot added to 1 list!\n";
		exit(1);
	}
	temp->aud1=sc.aud1;
	temp->day1=sc.day1;
	temp->gr1 =sc.gr1;
	temp->les1=sc.les1;
	temp->tim1=sc.tim1;
	temp->next=NULL;
	//temp->next=sc.next;
	if (!start) start=temp;
	else
	{
		cur=start;
		while (cur->next)
			cur=cur->next;
		cur->next=temp;
	}
	return;
};*/

/*void SCHEDULE::Del_start(void)
{
	if (!start)
	{
		cout << "\nNothing to destroy\n";
		return;
	}
	sched_string *del;
	del=start;
	start=del->next;
	delete del;
	return;
}*/

/*void SCHEDULE::Del_all(void)
{
	if (!start)
	{
		cout << "\nNothing to destroy\n";
		return;
	}
	while (start)
	{
	//	sched_string *del;
	//	del=start;
	//	start=del->next;
	//	delete del;
		
		this->Del_start();
	}
	//slist->clear();
	return;
};

*/
/*void SCHEDULE::Show_All(void)
{
	sched_string * prn;
	int iiicnt=1;
	int iiicnt1=0;
	int iiicnt2=0;
	int aud_cnt=0;

	if (!start)
	{
		cout << "\nNothing to show out\n";
		return;
	}
	prn=start;
	//cout << "\n";	!!	вывод всех записей
	cout << "\n#     |Lesson  |Mode   |Aud.   |Free   |Group  |Day    |Time\n";
	cout <<   "------|--------|-------|-------|-------|-------|-------|----\n";
	while (prn)
	{
		cout << iiicnt << "	"; iiicnt++;
		cout << prn->les1.name  << "	" << prn->les1.mode << "	"; 
		cout << prn->aud1.n << "	" << prn->aud1.free << "	" << prn->gr1.name << "	" ;
		cout << prn->day1.name << "	" << prn->tim1.T << "\n";
		prn=prn->next;
	}
	

//cout << "\nPRINTING SIZEOF tarr->n\n" << sizeof(tarr->n) << '\n';
	

	return;

}*/

/*void SCHEDULE::Show(void)
{
	sched_string * prn;
	int iiicnt=1;
	int iiicnt1=0;
	int iiicnt2=0;
	int aud_cnt=0;

	if (!start)
	{
		cout << "\nNothing to show out\n";
		return;
	}
	prn=start;
	//cout << "\n";	!!	вывод всех записей
	
	while (iiicnt1<(2)) // !! см ниже // sizeof(darr->n)/2))	//(iiicnt1<2)//(darr[iiicnt1].n)
	{
		cout << "\n#     |Day	|Time	|Lesson  |Mode   |Aud    |Free   |Group  |\n";
		cout <<   "------|---------|-------|--------|-------|-------|-------|-------|\n";
			
		while (iiicnt2<(3)) // !! тут должно быть нормальное 
							// определение количества записей sizeof(tarr->n)/2))
		{
			while (aud_cnt<4)
			{
				while (prn)
				{
					if ((prn->day1.n==darr[iiicnt1].n) && 
						(prn->tim1.n==tarr[iiicnt2].n) &&
						(prn->aud1.n==aarr[aud_cnt].n))
					{
							

						cout << setw(6) << iiicnt << "|	"; iiicnt++; 
						cout << setw(8) << prn->day1.name << '|' << setw(7) << prn->tim1.T << '|' << setw(8);
						cout << prn->les1.name << '|' << setw(7) << prn->les1.mode << '|' << setw(7); 
						cout << prn->aud1.n << '|' << setw(7) << prn->aud1.free << '|' << setw(7) << prn->gr1.name << "|" ;
						cout << "\n";
					
					}
					prn=prn->next;
				}
				//iiicnt=1;
			
				aud_cnt++;
				prn=start;
			}
			iiicnt2++;
			aud_cnt=0;
			//prn=start;
		}
		iiicnt=1;
		iiicnt1++;
		iiicnt2=0;
		//prn=start;
		
	}

//cout << "\nPRINTING SIZEOF tarr->n\n" << sizeof(tarr->n) << '\n';
	

	return;

}*/






void SCHEDULE::AddNewStr(schedule_inputs* inputs)
{

	
	
	sched_string current;//, *prn;
//	prn=start;
	bool bo=1;
	bool flag=1;
	int les=0;
	int cnt=0;
	int gr=0;
	int day=0;
	int tim=0;
	//while (bo==1 && cnt<10000)
	
	
	//ПОЧЕМУ 100?
	while (bo==1 && CanAdd(inputs) && cnt<100)
	{
		les=rand() %(inputs->inputs.lessons.size());
		//lesson_struct one_lesson;
		//list<lesson_struct> slist;
		//schedule_inputs_all slist;
		//slist.lessons=(schedule_inputs::inputs.lessons);
		//for (list<lesson_struct>::iterator it=((schedule_inputs::inputs).lessons.begin()); it!=(schedule_inputs::inputs).lessons.end(); it++)
		for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
		{
			if ((*it).id==les+1)
			{
				//one_lesson=(*it);
				current_parameters.les1=(*it);
			}
		}
		int some_size_of_auditories=inputs->inputs.auditories.size();
		for (int i=0;i<some_size_of_auditories;i++)
		{
			//auditory_struct one_auditory;
			for (list<auditory_struct>::iterator it2=inputs->inputs.auditories.begin(); it2!=inputs->inputs.auditories.end(); it2++)
			{
				if ((*it2).id==i+1)
			//		MessageBox::Show(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
				{
					//one_auditory=(*it);
					current_parameters.aud1=(*it2);
				}
			}
			/*if ((aarr[i].name==0 && aarr[i].free>0 && larr[les].mode=="lec") || 
				(aarr[i].name==1 && aarr[i].free>0 && larr[les].mode=="upr") || 
				(aarr[i].name==2 && aarr[i].free>0 && larr[les].mode=="lab") )*/
/*					if (((*it).name=="lection" && (*it).groups_available>0 && larr[les].mode=="lec") || 
						(aarr[i].name==1 && aarr[i].free>0 && larr[les].mode=="upr") || 
						(aarr[i].name==2 && aarr[i].free>0 && larr[les].mode=="lab") )*/
			/*if (((current_parameters.aud1.name=="lection") && (current_parameters.aud1.groups_available>0) && (current_parameters.les1.type=="lection")) || 
				((current_parameters.aud1.name=="seminar") && (current_parameters.aud1.groups_available>0) && (current_parameters.les1.type=="seminar")) || 
				((current_parameters.aud1.name=="lab") && (current_parameters.aud1.groups_available>0) && (current_parameters.les1.type=="lab")) )*/
			if ((!strcmp(current_parameters.aud1.name,"lection") && (current_parameters.aud1.groups_available>0) && !strcmp(current_parameters.les1.type,"lection")) || 
				(!strcmp(current_parameters.aud1.name,"seminar") && (current_parameters.aud1.groups_available>0) && !strcmp(current_parameters.les1.type,"seminar")) || 
				(!strcmp(current_parameters.aud1.name,"lab") && (current_parameters.aud1.groups_available>0) && !strcmp(current_parameters.les1.type,"lab")) )
			{
				gr=rand() %(inputs->inputs.groups.size());
				day=rand() %(inputs->inputs.days.size());
				tim=rand() %(inputs->inputs.times.size());

				//group_struct one_group;
				for (list<group_struct>::iterator it=inputs->inputs.groups.begin(); it!=inputs->inputs.groups.end(); it++)
				{
					if ((*it).id==gr+1)
						current_parameters.gr1=(*it);
				}
				//day_struct one_day;
				for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
				{
					if ((*it).id==day+1)
						current_parameters.day1=(*it);
				}
				//time_struct one_time;
				for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
				{
					if ((*it).id==tim+1)
						current_parameters.tim1=(*it);
				}


				//	создание текущей строки
				current.aud1=current_parameters.aud1;//one_auditory;//aarr[i];
				current.day1=current_parameters.day1;//one_day;//darr[day];
				current.gr1 =current_parameters.gr1;//garr[gr];
				current.les1=current_parameters.les1;//larr[les];
				current.tim1=current_parameters.tim1;//tarr[tim];
				
				for (list<sched_string>::iterator it1=slist.begin(); it1!=slist.end(); it1++)
				{
								
					if ( ((*it1).gr1.id==current.gr1.id && (*it1).les1.id==current.les1.id) ||
						(((*it1).gr1.id==current.gr1.id || ((*it1).aud1.id==current.aud1.id && (*it1).les1.id!=current.les1.id)) && 
						(*it1).day1.id==current.day1.id && (*it1).tim1.id==current.tim1.id) ) 
					{flag=0;} 
					else if ((*it1).gr1.id!=current.gr1.id && (*it1).day1.id==current.day1.id && (*it1).tim1.id==current.tim1.id && (*it1).aud1.id==current.aud1.id)
					{
						if ((*it1).aud1.groups_available==0)
						{flag=0;} else current.aud1.groups_available--;
					}
				}
				
				if (flag==1)
				{
					current.aud1.groups_available--;	
					// добавление в объект
					//this->Add(current);	//это вызывает ошибки при копировании
					this->AddNewStr_List(current);

					bo=0;
					i=4;
				}
				flag=1;
						
			}
		}  

		cnt+=1;
	}
	return;
}

void SCHEDULE::Create(schedule_inputs* inputs)
{
	//НЕ 20!!!
	for (int i=0;i<20;i++)
//	for (int i=0;i<25;i++)
	{
		this->AddNewStr(inputs);
	}

	return;
}

int SCHEDULE::stats(void)
{
	/*int res=0;
	//	list<sched_string> slist2;
	int mas[4][5]; 
	//string grps[4]={"I","II","III","IV"};
	//grouplist grps2;
	//cout << '\n';
	for (int j=0; j<4; j++)
	{	
		for (int i=0; i<5; i++)
		{
			mas[j][i]=larr[i].leng/2;
		}
	}
	
	for (int j=0; j<4; j++)
	{
		for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
		{
			if ((*it).gr1.name2==garr[j].name2)
			{
				for (int i=0;i<5;i++)
				{
					if (((*it).les1.name == larr[i].name) && ((*it).les1.mode == larr[i].mode))
						mas[j][i]--;
				}
			}
		}
	}

	for (int j=0; j<4; j++)
	{	
		for (int i=0; i<5; i++)
		{
			res=res+mas[j][i];
		}
	}

/ *	cout << "\n Statistics: \n";
	
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
* /	return res;*/
	return 0;
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
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).tim1.id==current.tim1.id && (*it).day1.id==current.day1.id)
		{return 1;}
	}
	return 0;
}

bool SCHEDULE::search2(const sched_string &current)
{
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).gr1.id==current.gr1.id && (*it).les1.id==current.les1.id)
		{return 1;}
	}
	return 0;
}

void SCHEDULE::skr(schedule_inputs* inputs,SCHEDULE & sch1, SCHEDULE & sch2)
{
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
			
m1:			day=rand() %(inputs->inputs.days.size());
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
			{	goto m1;}//cntmax1++;}

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
			
m2:			day=rand() %(inputs->inputs.days.size());
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
			{	goto m2;}//cntmax2++;}
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
	
	//ЗДЕСЬ НУЖНО СДЕЛАТЬ ПРОВЕРКУ НА ВОЗМОЖНОСТЬ ДОБАВЛЕНИЯ
	for (int i=0;i<25;i++)
	{
		this->AddNewStr(inputs);
	}
	return;
}

bool SCHEDULE::CanAdd(schedule_inputs* inputs)
{
	//тут нужно проверить на список на возможность добавления


	/*int cnt_list=0,cnt_groups=0,cnt_lessons=0;
	for (list<sched_string>::iterator it=this->slist.begin(); it!=this->slist.end(); it++)
	{cnt_list++;}
	while (garr[cnt_groups].name!="")
	{cnt_groups++;}
	while (larr[cnt_lessons].mode!="")
	{cnt_lessons++;}
	if (cnt_list<cnt_groups*cnt_lessons) 
		return 1;*/
	//if (slist.size()<(inputs->inputs.groups.size()*inputs->inputs.lessons.size()))
		return 1;
	//return 0;
}

void SCHEDULE::Cycle(schedule_inputs* inputs)
{
	SCHEDULE mas[10],mas2[10],mas3[10];
	int stats[10],max,nmax,iter;
	iter=0;
	for (int i=0;i<10;i++)		// - создание массива статистик
	{
		mas[i].Create(inputs);
		stats[i]=mas[i].stats();
	}

	max=stats[0];
	nmax=1;

//mm11:
	for (int i=1;i<10;i++)		// - мас2 - лучшие из выборки 
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
	for (int i=nmax-1;i<10;i++)
		mas3[i]=mas[i];				// - дополняем списками - родителями
	for (int i=0;i<10;i++)
	{
		mas3[i].modify(inputs,5);
		mas[i]=mas3[i];
		stats[i]=mas[i].stats();
	}
	max=stats[0];
	nmax=1;

	
	iter+=1;
//	if (iter<10) goto mm11;

	for (int i=0;i<10;i++)
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
