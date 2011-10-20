#pragma once
#include "stdafx.h"
#include "func.h"
#include "schedule.h"

namespace xmltest_dotnet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	public: 
		
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;



	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel1;


	private: System::Windows::Forms::Button^  button7;
			 static schedule_inputs* inp;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button8;
			 static int selected_index;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::ComboBox^  comboBox1;

			 static DataTable^ data = gcnew DataTable();
	private: System::Windows::Forms::Label^  label1;
			 static selected_indexes* selected_ind;  // = gcnew selected_indexes;
			 //SCHEDULE current_schedule;
			 //list<schedule_inputs> inplist;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 421);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить учебный план";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(6, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(339, 412);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 424);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"make schedule!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(6, 3);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(755, 417);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1000, 484);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Controls->Add(this->richTextBox1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(992, 458);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Учебный план";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(481, 11);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(762, 427);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Load data";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->Column1});
			this->dataGridView1->Location = System::Drawing::Point(871, 430);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(86, 21);
			this->dataGridView1->TabIndex = 10;
			this->dataGridView1->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Combobobox";
			this->Column1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"1", L"2", L"3", L"4"});
			this->Column1->Name = L"Column1";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(126, 421);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(110, 34);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Сохранить учебный план";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(352, 40);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(631, 375);
			this->panel1->TabIndex = 6;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				120)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(223, 48);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox2);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(992, 458);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Расписания";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(352, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Выберите категорию";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1003, 484);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 /*try 
				 {
					 char* text="";
					 StreamWriter^ file = gcnew StreamWriter("temp.xml", false, Encoding::UTF8);
					 file->Write(text);
					 file->Close();
					 XmlTextReader^ reader = gcnew XmlTextReader("temp.xml");
					 while (reader->Read())
					 {
						 switch (reader->NodeType)
						 {
						 case XmlNodeType::Element:
							 if (reader->Name=="param")
								 b_param=true;
							 while (reader->MoveToNextAttribute()) // Read the attributes.
							 {
								 if (b_param)
								 {
									 if (cnt!=0)
										 out_text += reader->Value + " ";
									 cnt++;
								 }
								 else 
									 out_text += reader->Value + " ";
							 }
							 cnt=0;
							 out_text+="\n";

							 break;
						 case XmlNodeType::Text: // Вывести текст в каждом элементе.
							 break;
						 case XmlNodeType::Attribute:
							 break;
						 case XmlNodeType::EndElement:
							 break;
						 default:
							 break;
						 }
					 }
					 reader->Close();
				 }
				 catch (...) {}*/
				 
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				 openFileDialog1->InitialDirectory = "../";
				 openFileDialog1->Filter = "xml files (*.xml)|*.xml|txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex = 1;
				 openFileDialog1->RestoreDirectory = true;

				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 //MessageBox::Show((openFileDialog1->FileName)->ToString());
					 richTextBox1->Text=out_text(inp,openFileDialog1->FileName);
				 }

				 comboBox1_SelectedIndexChanged(sender,e);
				 //richTextBox1->Text=out_text(inp);
			 }
	
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 inp = new schedule_inputs;
				 srand(unsigned(time(NULL)));
				 //int columnCount=0;

				 /*for (int columnCount=0;columnCount<5;columnCount++)
				 {
					 ComboBox^ CB1 = gcnew ComboBox;
					 CB1->Items->Add("Номер строки");
					 CB1->Items->Add("Название");
					 CB1->Items->Add("Тип");
					 CB1->Items->Add("Вместимость");
					 CB1->Items->Add("Время начала");
					 CB1->SelectedIndex=columnCount;
					 if (columnCount==tableLayoutPanel1->ColumnCount)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
					 //columnCount++;
				 }*/
				 

				 /*ComboBox^ CB2 = gcnew ComboBox;
				 CB2->Items->Add("Номер строки");
				 CB2->Items->Add("Предмет");
				 CB2->Items->Add("Тип");
				 CB2->Items->Add("День недели");
				 CB2->Items->Add("Время начала");
				 CB2->SelectedIndex=1;
				 tableLayoutPanel1->Controls->Add(CB2,1,0);

				 selected_index=2;*/

				 comboBox1->Items->Add("Аудитории");
				 comboBox1->Items->Add("Группы");
				 comboBox1->Items->Add("Дни недели");
				 comboBox1->Items->Add("Занятия");
				 comboBox1->Items->Add("Время начала");
				 

				 selected_ind = new selected_indexes;

				 /**selected_ind->aud=0;
				 selected_ind->aud[1]=1;
				 selected_ind->aud[2]=2;
				 selected_ind->aud[3]=3;*/

				 for (int i=0; i<5; i++)
				 {
					 selected_ind->aud[i]=i;
				 }
				 for (int i=0; i<2; i++)
				 {
					 selected_ind->gr[i]=i;
				 }
				 for (int i=0; i<2; i++)
				 {
					 selected_ind->day[i]=i;
				 }
				 for (int i=0; i<4; i++)
				 {
					 selected_ind->les[i]=i;
				 }
				 for (int i=0; i<2; i++)
				 {
					 selected_ind->tim[i]=i;
				 }

				 comboBox1->SelectedIndex=0;
			 }

	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 delete inp;
				 delete selected_ind;
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
//			 richTextBox2->Text=out_struct(inp);
/*			 int n=2;
			 for (list<auditory_struct>::iterator it=inp->inputs.auditories.begin(); it!=inp->inputs.auditories.end(); it++)
			 {
				 if ((*it).id==n)
					MessageBox::Show(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
			 }*/


			 SCHEDULE s;
			 s.remax(inp);
			 s.Cycle(inp);
			 char str[65000]="";
			 s.Show_All_List(str);
		 	 richTextBox2->Text=String(str).ToString();

			 //SCHEDULE s;
			 /*current_schedule.remax(inp);
			 current_schedule.Cycle(inp);
			 char str[65000]="";
			 current_schedule.Show_All_List(str);
			 richTextBox2->Text=String(str).ToString();*/
	
	

		 }

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Label^ TB1 = gcnew Label;
			 //TB1->Text="TROLOLO";
			 MessageBox::Show(String::Concat("ColumnCount=",tableLayoutPanel1->ColumnStyles->Count," RowCount=",tableLayoutPanel1->RowStyles->Count));
			 for (int i=1;i<tableLayoutPanel1->RowCount;i++)
			 {
				 for (int j=0;j<tableLayoutPanel1->ColumnCount;j++)
				 {
					 Label^ TB1 = gcnew Label;
					 TB1->Text="1";
					 //tableLayoutPanel1->Controls->Remove(TB1);
					 tableLayoutPanel1->Controls->Add(TB1,j,i);
				 }
			 }
			 
		 }

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 tableLayoutPanel1->ColumnCount+=1;
			 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));

			 ComboBox^ CB2 = gcnew ComboBox;
			 CB2->Items->Add("Номер строки");
			 CB2->Items->Add("Предмет");
			 CB2->Items->Add("Тип");
			 CB2->Items->Add("День недели");
			 CB2->Items->Add("Время начала");
			 CB2->SelectedIndex=selected_index;
			 if (selected_index<4)
				 selected_index++;
			 tableLayoutPanel1->Controls->Add(CB2,tableLayoutPanel1->ColumnCount-1,0);
		 }

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 tableLayoutPanel1->RowCount+=1;
			 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
			 System::Drawing::Size ^ ns = gcnew System::Drawing::Size((tableLayoutPanel1->Size).Width,(tableLayoutPanel1->Size).Height+20);
			 tableLayoutPanel1->Size = *ns; 
			 
			 
			 for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
			 {
				 Label^ l1 = gcnew Label;
				 tableLayoutPanel1->Controls->Add(l1,i,tableLayoutPanel1->RowCount-1);
			 }
		 }

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 tableLayoutPanel1->GetControlFromPosition(3,3)->Text="YOHOHO!!";
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

			 data->Columns->Add("ID",Type::GetType("System.Int32"));
			 //this.data.Columns.Add("ID", Type.GetType("System.Int32"));
			 data->Columns->Add("FirstName", Type::GetType("System.String"));
			 data->Columns->Add("LastName", Type::GetType("System.String"));
			 //data->Columns->Add("Combo", Datagridviewcombobox);
			 dataGridView1->DataSource = data;
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 //MessageBox::Show("Index changed!");
			 for (int i=tableLayoutPanel1->RowCount-1;i>=0;i--)
			 {
				 for (int j=tableLayoutPanel1->ColumnCount-1;j>=0;j--)
				 {
					 tableLayoutPanel1->Controls->Remove(tableLayoutPanel1->GetControlFromPosition(j,i)); 
				 }
			 }
			 for (int i=tableLayoutPanel1->ColumnCount-1;i>1;i--)
			 {
				 tableLayoutPanel1->ColumnStyles->RemoveAt(i);
			 }
			 tableLayoutPanel1->ColumnCount=2;
			 for (int i=tableLayoutPanel1->RowCount-1;i>1;i--)
			 {
				 tableLayoutPanel1->RowStyles->RemoveAt(i);
			 }
			 tableLayoutPanel1->RowCount=2;
			 int current_row=1;
			 switch (comboBox1->SelectedIndex)
			 {
			 case 0:
				 for (int columnCount=0;columnCount<5;columnCount++)
				 {
					 ComboBox^ CB1 = gcnew ComboBox;
					 CB1->Items->Add("Номер");
					 CB1->Items->Add("Название");
					 CB1->Items->Add("Тип");
					 CB1->Items->Add("Вместимость");
					 CB1->Items->Add("Время начала");
					 CB1->SelectedIndex=columnCount;//(*selected_ind).aud[columnCount];//columnCount;
					 if (columnCount==tableLayoutPanel1->ColumnCount)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
					 //columnCount++;
				 }
				 
				 for (list<auditory_struct>::iterator it=inp->inputs.auditories.begin(); it!=inp->inputs.auditories.end(); it++)
				 {
					 if (current_row==tableLayoutPanel1->RowCount)
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					 {
						 Label^ l1 = gcnew Label;
						 if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Номер")
						 {
							 l1->Text=String::Concat((*it).id);
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Название")
						 {
							 l1->Text=String::Concat(String((*it).name).ToString());
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Тип")
						 {
							 l1->Text=String::Concat(String((*it).type).ToString());
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Вместимость")
						 {
							 l1->Text=String::Concat((*it).groups_max);
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Время начала")
						 {
							 l1->Text=String::Concat((*it).groups_available);
						 } 

						 
						 tableLayoutPanel1->Controls->Add(l1,i,current_row);
					 }
					 current_row++;
					 //tableLayoutPanel1->GetControlFromPosition(0,3)->Text="YOHOHO!!";
					 //text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
				 }
				 break;
			 case 1:
				 for (int columnCount=0;columnCount<2;columnCount++)
				 {
					 ComboBox^ CB1 = gcnew ComboBox;
					 CB1->Items->Add("Номер");
					 CB1->Items->Add("Группа");
					 CB1->SelectedIndex=columnCount;
					 if (columnCount==tableLayoutPanel1->ColumnCount)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
					 //columnCount++;
				 }
				 for (list<group_struct>::iterator it=inp->inputs.groups.begin(); it!=inp->inputs.groups.end(); it++)
				 {
					 if (current_row==tableLayoutPanel1->RowCount)
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					 {
						 Label^ l1 = gcnew Label;
						 if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Номер")
						 {
							 l1->Text=String::Concat((*it).id);
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Группа")
						 {
							 l1->Text=String::Concat(String((*it).name).ToString());
						 } 

						 tableLayoutPanel1->Controls->Add(l1,i,current_row);
					 }
					 current_row++;
					 //tableLayoutPanel1->GetControlFromPosition(0,3)->Text="YOHOHO!!";
					 //text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
				 }
				 break;
			 case 2:
				 for (int columnCount=0;columnCount<2;columnCount++)
				 {
					 ComboBox^ CB1 = gcnew ComboBox;
					 CB1->Items->Add("Номер");
					 CB1->Items->Add("День");
					 CB1->SelectedIndex=columnCount;
					 if (columnCount==tableLayoutPanel1->ColumnCount)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
					 //columnCount++;
				 }
				 for (list<day_struct>::iterator it=inp->inputs.days.begin(); it!=inp->inputs.days.end(); it++)
				 {
					 if (current_row==tableLayoutPanel1->RowCount)
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					 {
						 Label^ l1 = gcnew Label;
						 if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Номер")
						 {
							 l1->Text=String::Concat((*it).id);
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="День")
						 {
							 l1->Text=String::Concat(String((*it).name).ToString());
						 } 

						 tableLayoutPanel1->Controls->Add(l1,i,current_row);
					 }
					 current_row++;
					 //tableLayoutPanel1->GetControlFromPosition(0,3)->Text="YOHOHO!!";
					 //text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
				 }
				 break;
			 case 3:
				 for (int columnCount=0;columnCount<4;columnCount++)
				 {
					 ComboBox^ CB1 = gcnew ComboBox;
					 CB1->Items->Add("Номер");
					 CB1->Items->Add("Название");
					 CB1->Items->Add("Тип");
					 CB1->Items->Add("Длительность");
					 CB1->SelectedIndex=columnCount;
					 if (columnCount==tableLayoutPanel1->ColumnCount)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
					 //columnCount++;
				 }
				 for (list<lesson_struct>::iterator it=inp->inputs.lessons.begin(); it!=inp->inputs.lessons.end(); it++)
				 {
					 if (current_row==tableLayoutPanel1->RowCount)
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					 {
						 Label^ l1 = gcnew Label;
						 if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Номер")
						 {
							 l1->Text=String::Concat((*it).id);
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Название")
						 {
							 l1->Text=String::Concat(String((*it).name).ToString());
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Тип")
						 {
							 l1->Text=String::Concat(String((*it).type).ToString());
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Длительность")
						 {
							 l1->Text=String::Concat((*it).hours);
						 } 


						 tableLayoutPanel1->Controls->Add(l1,i,current_row);
					 }
					 current_row++;
					 //tableLayoutPanel1->GetControlFromPosition(0,3)->Text="YOHOHO!!";
					 //text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
				 }
				 break;
			 case 4:
				 for (int columnCount=0;columnCount<2;columnCount++)
				 {
					 ComboBox^ CB1 = gcnew ComboBox;
					 CB1->Items->Add("Номер");
					 CB1->Items->Add("Время");
					 CB1->SelectedIndex=columnCount;
					 if (columnCount==tableLayoutPanel1->ColumnCount)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
					 //columnCount++;
				 }
				 for (list<time_struct>::iterator it=inp->inputs.times.begin(); it!=inp->inputs.times.end(); it++)
				 {
					 if (current_row==tableLayoutPanel1->RowCount)
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					 {
						 Label^ l1 = gcnew Label;
						 if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Номер")
						 {
							 l1->Text=String::Concat((*it).id);
						 } else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Время")
						 {
							 l1->Text=String::Concat((*it).begin_time);
						 } 

						 tableLayoutPanel1->Controls->Add(l1,i,current_row);
					 }
					 current_row++;
					 //tableLayoutPanel1->GetControlFromPosition(0,3)->Text="YOHOHO!!";
					 //text+=(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Type = ",String((*it).type).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
				 }
				 break;
			 default:
				 break;
			 }
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i=tableLayoutPanel1->RowCount-1;i>=0;i--)
			 {
				 for (int j=tableLayoutPanel1->ColumnCount-1;j>=0;j--)
				 {
					 tableLayoutPanel1->Controls->Remove(tableLayoutPanel1->GetControlFromPosition(j,i)); 
				 }
			 }
			 for (int i=tableLayoutPanel1->ColumnCount-1;i>1;i--)
			 {
				 tableLayoutPanel1->ColumnStyles->RemoveAt(i);
			 }
			 tableLayoutPanel1->ColumnCount=2;
			 for (int i=tableLayoutPanel1->RowCount-1;i>1;i--)
			 {
				 tableLayoutPanel1->RowStyles->RemoveAt(i);
			 }
			 tableLayoutPanel1->RowCount=2;
		 }
};
}

