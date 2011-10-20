#include "stdafx.h"
#include "func.h"


bool uni_input::operator <(const uni_input& inp) const
{
	return 1 > 2;
}

bool auditory_struct::operator <(const auditory_struct& aud) const
{
	return id < aud.id;
}

bool group_struct::operator <(const group_struct& gr) const
{
	return id < gr.id;
}

bool day_struct::operator <(const day_struct& day) const
{
	return id < day.id;
}

bool lesson_struct::operator <(const lesson_struct& les) const
{
	return id < les.id;
}

bool time_struct::operator <(const time_struct& tim) const
{
	return id < tim.id;
}

String^ out_text(schedule_inputs* inputs, String^ filename_in)
{
	String^ text="";
	XmlTextReader^ reader = gcnew XmlTextReader(filename_in);
	while (reader->Read())
	{
		auditory_struct one_auditory;
		group_struct one_group;
		day_struct one_day;
		lesson_struct one_lesson;
		time_struct one_time;

		
		switch (reader->NodeType)
		{
		case XmlNodeType::Element:
			text+="\n";
				
			if (reader->Name=="auditories" || reader->Name=="auditory")
			{
				if (reader->Name=="auditories")
					text+="Вот это параметры для аудиторий:";
				else
				{
					while (reader->MoveToNextAttribute()) // Read the attributes.
					{
						text+=(reader->Value)+" ";

						//здесь проверяем на название атрибутов и записываем в
						//определённую группу

						char* readerValue = (char*)(void*)Marshal::StringToHGlobalAnsi(reader->Value);
						if (reader->Name=="id")
						{
							one_auditory.id=atoi(readerValue);
						}
						else if (reader->Name=="name")
						{
							strcpy(one_auditory.name,readerValue);
						}
						else if (reader->Name=="type")
						{
							strcpy(one_auditory.type,readerValue);
						}
						else if (reader->Name=="groups_max")
						{
							one_auditory.groups_max=atoi(readerValue);
						}
						else if (reader->Name=="groups_available")
						{
							one_auditory.groups_available=atoi(readerValue);
						}
						else 
						{}

						Marshal::FreeHGlobal((IntPtr)(readerValue));
					}

					inputs->inputs.auditories.push_back(one_auditory);

				}
			}
			else if (reader->Name=="groups" || reader->Name=="group")
			{
				if (reader->Name=="groups")
					text+="Вот это параметры для групп:";
				else
				{
					while (reader->MoveToNextAttribute()) // Read the attributes.
					{
						text+=(reader->Value)+" ";

						//здесь проверяем на название атрибутов и записываем в
						//определённую группу

						char* readerValue = (char*)(void*)Marshal::StringToHGlobalAnsi(reader->Value);
						if (reader->Name=="id")
						{
							one_group.id=atoi(readerValue);
						}
						else if (reader->Name=="name")
						{
							strcpy(one_group.name,readerValue);
						}
						else 
						{}

						Marshal::FreeHGlobal((IntPtr)(readerValue));
					}

					inputs->inputs.groups.push_back(one_group);
				}
			}
			else if (reader->Name=="days" || reader->Name=="day")
			{
				if (reader->Name=="days")
					text+="Вот это параметры для дней:";
				else
				{
					while (reader->MoveToNextAttribute()) // Read the attributes.
					{
						text+=(reader->Value)+" ";

						//здесь проверяем на название атрибутов и записываем в
						//определённую группу

						char* readerValue = (char*)(void*)Marshal::StringToHGlobalAnsi(reader->Value);
						if (reader->Name=="id")
						{
							one_day.id=atoi(readerValue);
						}
						else if (reader->Name=="name")
						{
							strcpy(one_day.name,readerValue);
						}
						else 
						{}

						Marshal::FreeHGlobal((IntPtr)(readerValue));
					}

					inputs->inputs.days.push_back(one_day);
				}
			}
			else if (reader->Name=="lessons" || reader->Name=="lesson")
			{
				if (reader->Name=="lessons")
					text+="Вот это параметры для занятий:";
				else
				{
					while (reader->MoveToNextAttribute()) // Read the attributes.
					{
						text+=(reader->Value)+" ";

						//здесь проверяем на название атрибутов и записываем в
						//определённую группу

						char* readerValue = (char*)(void*)Marshal::StringToHGlobalAnsi(reader->Value);
						if (reader->Name=="id")
						{
							one_lesson.id=atoi(readerValue);
						}
						else if (reader->Name=="name")
						{
							strcpy(one_lesson.name,readerValue);
						}
						else if (reader->Name=="type")
						{
							strcpy(one_lesson.type,readerValue);
						}
						else if (reader->Name=="hours")
						{
							one_lesson.hours=atoi(readerValue);
						}
						else 
						{}

						Marshal::FreeHGlobal((IntPtr)(readerValue));
					}

					inputs->inputs.lessons.push_back(one_lesson);
				}
			}
			else if (reader->Name=="times" || reader->Name=="time")
			{
				if (reader->Name=="times")
					text+="Вот это параметры для времён начала занятий:";
				else
				{
					while (reader->MoveToNextAttribute()) // Read the attributes.
					{
						text+=(reader->Value)+" ";

						//здесь проверяем на название атрибутов и записываем в
						//определённую группу

						char* readerValue = (char*)(void*)Marshal::StringToHGlobalAnsi(reader->Value);
						if (reader->Name=="id")
						{
							one_time.id=atoi(readerValue);
						}
						else if (reader->Name=="begin_time")
						{
							one_time.begin_time=atoi(readerValue);
						}
						else 
						{}

						Marshal::FreeHGlobal((IntPtr)(readerValue));
					}

					inputs->inputs.times.push_back(one_time);
				}
			}
			
			

			break;
		case XmlNodeType::Text: // Вывести текст в каждом элементе.
			text+=(reader->Value)+" ";
			break;
		case XmlNodeType::Attribute:
			break;
		case XmlNodeType::EndElement:
			
			break;
		default:
			break;
		}
	}
	return text;
}

String^ out_struct(schedule_inputs* inputs)
{
	String^ text="", ^ ret_text="";

	for (list<auditory_struct>::iterator it=inputs->inputs.auditories.begin(); it!=inputs->inputs.auditories.end(); it++)
	{
		text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
	}
	ret_text+=text;
	ret_text+="\n";
	text="";
	for (list<group_struct>::iterator it=inputs->inputs.groups.begin(); it!=inputs->inputs.groups.end(); it++)
	{
		text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),"\n"));
	}
	ret_text+=text;
	ret_text+="\n";
	text="";
	for (list<day_struct>::iterator it=inputs->inputs.days.begin(); it!=inputs->inputs.days.end(); it++)
	{
		text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),"\n"));
	}
	ret_text+=text;
	ret_text+="\n";
	text="";
	for (list<lesson_struct>::iterator it=inputs->inputs.lessons.begin(); it!=inputs->inputs.lessons.end(); it++)
	{
		text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Hours = ",(*it).hours,"\n"));
	}
	ret_text+=text;
	ret_text+="\n";
	text="";
	for (list<time_struct>::iterator it=inputs->inputs.times.begin(); it!=inputs->inputs.times.end(); it++)
	{
		text+=(String::Concat("Id = ",(*it).id,", Begin times = ",(*it).begin_time,"\n"));
	}
	ret_text+=text;
	text="";


	return ret_text;
}