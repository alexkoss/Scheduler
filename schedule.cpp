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
	//������� ���������� � out

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
{
	//

	sched_string current;	// ����������� ������
	bool bo=1;
	bool flag=1;
	int les=0;
	int cnt=0;
	int gr=0;
	int day=0;
	int tim=0;
	
	//��������� �� ����������
	while (bo==1 && CanAdd(inputs) && cnt<100)	
		// 100, ������ ��� CanAdd ��������� �� ���������� ����� � ���������� 
		// �� ��������� � ���������� ����� � ��������� ������������� �����������.
		// � ������ � ��������� �������� ������� ����� ��������� ��� cnt<100
	{
		les=rand() %(inputs->inputs.lessons.size());
		
		for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
		{	// ����� ��������� �� ������ ���������
			if ((*it).id==les+1)
			{
				current_parameters.les1=(*it);
			}
		}
		int some_size_of_auditories=inputs->inputs.auditories.size();
		for (int i=0;i<some_size_of_auditories;i++)
		{	// ������ ������ �� ����������
			for (list<auditory_struct>::iterator it2=inputs->inputs.auditories.begin(); it2!=inputs->inputs.auditories.end(); it2++)
			{
				if ((*it2).id==i+1)
				{
					current_parameters.aud1=(*it2);
				}
			}
			if ((!strcmp(current_parameters.aud1.type,"lection") && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"lection")) || 
				(!strcmp(current_parameters.aud1.type,"seminar") && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"seminar")) || 
				(!strcmp(current_parameters.aud1.type,"lab")	 && 
					(current_parameters.aud1.groups_available>0) && 
					!strcmp(current_parameters.les1.type,"lab")) )
			{
				gr=rand() %(inputs->inputs.groups.size());
				day=rand() %(inputs->inputs.days.size());
				tim=rand() %(inputs->inputs.times.size());

				for (list<group_struct>::iterator it=inputs->inputs.groups.begin(); it!=inputs->inputs.groups.end(); it++)
				{	// ����� ��������� ������ �� ������
					if ((*it).id==gr+1)
						current_parameters.gr1=(*it);
				}
				for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
				{	// ����� ���������� ��� ������ �� ������
					if ((*it).id==day+1)
						current_parameters.day1=(*it);
				}
				for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
				{	// ����� ���������� ������� ������ �� ������ 
					if ((*it).id==tim+1)
						current_parameters.tim1=(*it);
				}


				//	�������� ������� ������
				current.aud1=current_parameters.aud1;
				current.day1=current_parameters.day1;
				current.gr1 =current_parameters.gr1;
				current.les1=current_parameters.les1;
				current.tim1=current_parameters.tim1;
				
				for (list<sched_string>::iterator it1=slist.begin(); it1!=slist.end(); it1++)
				{
					// �������� �� ���������
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
					
					// ���������� � ����������
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
	// �������� ���������� - ���������� ����������� ���������� ���������� �����
	for (unsigned int i=0;i<max_num_of_strings;i++)
	{
		this->AddNewStr(inputs);
	}

	return;
}

int SCHEDULE::stats(schedule_inputs* inputs)
{
	// ���������� ���������� �� ������� - �������� �������� �������


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
			// ��� ����� �������� ������ �� lessons
			for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
			{	// ����� ��������� �� ������ ���������
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
			{	// ����� ��������� ������ �� ������
				if ((*it3).id==j+1)
					current_group=(*it3);
			}
			if ((*it).gr1.name==current_group.name)
			{
				for (int i=0;i<lessons_size;i++)
				{
					for (list<lesson_struct>::iterator it2=inputs->inputs.lessons.begin(); it2!=inputs->inputs.lessons.end(); it2++)
					{	// ����� ��������� �� ������ ���������
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
	
	//�����
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
	// ����� �� �������� ����������, ���� �� ������� � �� �� ����� � ��� �� ����, ��� � current
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).tim1.id==current.tim1.id && (*it).day1.id==current.day1.id)
		{return 1;}
	}
	return 0;
}

bool SCHEDULE::search2(const sched_string &current)
{
	// ����� �� �������� ����������, ���� �� ������� � ��� �� ������ �� �� �������, ��� � current
	for (list<sched_string>::iterator it=slist.begin(); it!=slist.end(); it++)
	{
		if ((*it).gr1.id==current.gr1.id && (*it).les1.id==current.les1.id)
		{return 1;}
	}
	return 0;
}

void SCHEDULE::skr(schedule_inputs* inputs,SCHEDULE & sch1, SCHEDULE & sch2)
{
	// ���������� ��������� �����������

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
	
	//����� ����� ������� �������� �� ����������� ���������� - ok
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
	//��� ����� ��������� �� ������ �� ����������� ���������� - ok

	if (slist.size()<max_num_of_strings)
		return 1;
	return 0;
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
	for (int i=0;i<number_of_schedules;i++)		// - �������� ������� ���������
	{
		mas[i].Create(inputs);
		stats[i]=mas[i].stats(inputs);
	}

	max=stats[0];
	nmax=1;

//mm11:
	for (int i=1;i<number_of_schedules;i++)		// - ���2 - ������ �� ������� 
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
		mas3[i].skr(inputs,mas2[i],mas2[i+1]); // - ���������� ������ �������
	for (int i=nmax-1;i<number_of_schedules;i++)
		mas3[i]=mas[i];				// - ��������� �������� - ����������
	for (int i=0;i<10;i++)
	{
		mas3[i].modify(inputs,5);
		mas[i]=mas3[i];
		stats[i]=mas[i].stats(inputs);
	}
	max=stats[0];
	nmax=1;

	
	iter+=1;
//	if (iter<10) goto mm11;

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