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
			 SCHEDULE* s;

			 static int selected_index;

	private: System::Windows::Forms::ComboBox^  comboBox1;

			 
	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TabControl^  tabControl3;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Button^  button8;
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
			this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl3->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(894, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить учебный план";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(871, 528);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(902, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 63);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Составить расписание!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox2->Location = System::Drawing::Point(3, 3);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(873, 524);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1028, 592);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tabControl3);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1020, 566);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Учебный план";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabControl3
			// 
			this->tabControl3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl3->Controls->Add(this->tabPage5);
			this->tabControl3->Controls->Add(this->tabPage6);
			this->tabControl3->Location = System::Drawing::Point(6, 6);
			this->tabControl3->Name = L"tabControl3";
			this->tabControl3->SelectedIndex = 0;
			this->tabControl3->Size = System::Drawing::Size(882, 557);
			this->tabControl3->TabIndex = 17;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->richTextBox1);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(874, 531);
			this->tabPage5->TabIndex = 0;
			this->tabPage5->Text = L"Текст";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->label1);
			this->tabPage6->Controls->Add(this->comboBox1);
			this->tabPage6->Controls->Add(this->panel1);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(874, 531);
			this->tabPage6->TabIndex = 1;
			this->tabPage6->Text = L"Таблица";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Выберите категорию";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(135, 9);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(6, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(864, 489);
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
				155)));
			this->tableLayoutPanel1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(258, 48);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button7->Location = System::Drawing::Point(894, 71);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(111, 34);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Сохранить учебный план";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button8);
			this->tabPage2->Controls->Add(this->tabControl2);
			this->tabPage2->Controls->Add(this->button9);
			this->tabPage2->Controls->Add(this->button6);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1020, 566);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Расписание";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button8->Location = System::Drawing::Point(903, 159);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(110, 34);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Обновить";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// tabControl2
			// 
			this->tabControl2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl2->Controls->Add(this->tabPage3);
			this->tabControl2->Controls->Add(this->tabPage4);
			this->tabControl2->Location = System::Drawing::Point(6, 6);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(890, 556);
			this->tabControl2->TabIndex = 9;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->richTextBox2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(882, 530);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Текст";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->panel2);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(882, 530);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Таблица";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->AutoScroll = true;
			this->panel2->Controls->Add(this->tableLayoutPanel2);
			this->panel2->Location = System::Drawing::Point(6, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(873, 522);
			this->panel2->TabIndex = 6;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->AutoSize = true;
			this->tableLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				151)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(254, 48);
			this->tableLayoutPanel2->TabIndex = 5;
			// 
			// button9
			// 
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button9->Location = System::Drawing::Point(902, 199);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(111, 37);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Добавить столбец";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click_1);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button6->Location = System::Drawing::Point(902, 117);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 36);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Загрузить шаблон";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 593);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Составитель расписания";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResizeBegin += gcnew System::EventHandler(this, &Form1::Form1_ResizeBegin);
			this->ResizeEnd += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabControl3->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				 openFileDialog1->InitialDirectory = "../";
				 openFileDialog1->Filter = "xml files (*.xml)|*.xml|txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex = 1;
				 openFileDialog1->RestoreDirectory = true;

				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 richTextBox1->Text=out_text(inp,openFileDialog1->FileName);
				 }

				 comboBox1_SelectedIndexChanged(sender,e);
			 }
	
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 inp = new schedule_inputs;
				 s = new SCHEDULE;
				 srand(unsigned(time(NULL)));
				 
				 comboBox1->Items->Add("Аудитории");
				 comboBox1->Items->Add("Группы");
				 comboBox1->Items->Add("Дни недели");
				 comboBox1->Items->Add("Занятия");
				 comboBox1->Items->Add("Время начала");
				 
				 selected_ind = new selected_indexes;

				 int i=0;
				 for (i=0; i<5; i++)
				 {
					 selected_ind->aud[i]=i;
				 }
				 for (i=0; i<2; i++)
				 {
					 selected_ind->gr[i]=i;
				 }
				 for (i=0; i<2; i++)
				 {
					 selected_ind->day[i]=i;
				 }
				 for (i=0; i<4; i++)
				 {
					 selected_ind->les[i]=i;
				 }
				 for (i=0; i<2; i++)
				 {
					 selected_ind->tim[i]=i;
				 }

				 comboBox1->SelectedIndex=0;
				 selected_index=-1;

				 Form1::DoubleBuffered = true;
				 //panel1->DoubleBuffered = true;
			 }

	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 delete inp;
				 delete selected_ind;
				 delete s;
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
//			 richTextBox2->Text=out_struct(inp);
/*			 int n=2;
			 for (list<auditory_struct>::iterator it=inp->inputs.auditories.begin(); it!=inp->inputs.auditories.end(); it++)
			 {
				 if ((*it).id==n)
					MessageBox::Show(String::Concat("Id = ",(*it).id,", Name = ",String((*it).name).ToString(),", Groups maximum = ",(*it).groups_max,", Groups available = ",(*it).groups_available,"\n"));
			 }*/

			 delete s;
			 s = new SCHEDULE;
//			 SCHEDULE s;
			 s->remax(inp);
			 s->Cycle(inp);
			 char str[65000]="";
			 s->Show_All_List(str);
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


private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 tableLayoutPanel1->SuspendLayout();
			 if (comboBox1->SelectedIndex!=selected_index)
			 {
				 int new_row_count=0;
				 int new_col_count=0;
				 switch (comboBox1->SelectedIndex)
				 {
				 case 0:
					 new_row_count=inp->inputs.auditories.size();
					 new_col_count=5;
				 	 break;
				 case 1:
					 new_row_count=inp->inputs.groups.size();
					 new_col_count=2;
					 break;
				 case 2:
					 new_row_count=inp->inputs.days.size();
					 new_col_count=2;
					 break;
				 case 3:
					 new_row_count=inp->inputs.lessons.size();
					 new_col_count=4;
					 break;
				 case 4:
					 new_row_count=inp->inputs.times.size();
					 new_col_count=2;
					 break;
				 default:
					 break;
				 }
				 //tableLayoutPanel1->SuspendLayout();
				 for (int i=tableLayoutPanel1->RowCount;i>=0;i--)
				 {
					 for (int j=tableLayoutPanel1->ColumnCount;j>=0;j--)
					 {
						 tableLayoutPanel1->Controls->Remove(tableLayoutPanel1->GetControlFromPosition(j,i)); 
					 }
				 }
				 //tableLayoutPanel1->ResumeLayout();
				 //for (int i=tableLayoutPanel1->ColumnCount-1;i>1;i--)
				 for (int i=tableLayoutPanel1->ColumnCount-1;i>=new_col_count;i--)
				 {
					 tableLayoutPanel1->ColumnStyles->RemoveAt(i);
					 tableLayoutPanel1->ColumnCount--;
				 }
				 //tableLayoutPanel1->ColumnCount=2;
				 //for (int i=tableLayoutPanel1->RowCount-1;i>1;i--)
				 for (int i=tableLayoutPanel1->RowCount-1;i>=new_row_count;i--)
				 {
					 tableLayoutPanel1->RowStyles->RemoveAt(i);
					 tableLayoutPanel1->RowCount--;
				 }
				 //tableLayoutPanel1->RowCount=2;
				 int current_row=1;
				 switch (comboBox1->SelectedIndex)
				 {
				 case 0:
					 while (tableLayoutPanel1->ColumnCount<5)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 while (tableLayoutPanel1->RowCount<inp->inputs.auditories.size())
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }

					 for (int columnCount=0;columnCount<5;columnCount++)
					 {
						 /*ComboBox^ CB1 = gcnew ComboBox;
						 CB1->Items->Add("Номер");
						 CB1->Items->Add("Название");
						 CB1->Items->Add("Тип");
						 CB1->Items->Add("Вместимость");
						 CB1->Items->Add("Время начала");
						 CB1->SelectedIndex=(*selected_ind).aud[columnCount];//columnCount;
						 if (columnCount==tableLayoutPanel1->ColumnCount)
						 {
							 tableLayoutPanel1->ColumnCount+=1;
							 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
						 }*/
						 Label^ l0 = gcnew Label;
						 switch (columnCount)
						 {
						 case 0:
							 l0->Text="Номер";
							 break;
						 case 1:
							 l0->Text="Название";
							 break;
						 case 2:
							 l0->Text="Тип";
							 break;
						 case 3:
							 l0->Text="Вместимость";
							 break;
						 case 4:
							 l0->Text="Время начала";
							 break;
						 default:
							 break;
						 }
						 tableLayoutPanel1->Controls->Add(l0,columnCount,0);
						 //tableLayoutPanel1->Controls->Add(CB1,columnCount,0);
						 //columnCount++;
					 }

					 
					 for (list<auditory_struct>::iterator it=inp->inputs.auditories.begin(); it!=inp->inputs.auditories.end(); it++)
					 {
						 /*if (current_row==tableLayoutPanel1->RowCount)
						 {
							 tableLayoutPanel1->RowCount+=1;
							 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
						 }*/
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
					 while (tableLayoutPanel1->ColumnCount<2)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 while (tableLayoutPanel1->RowCount<inp->inputs.groups.size())
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int columnCount=0;columnCount<2;columnCount++)
					 {
						 /*ComboBox^ CB1 = gcnew ComboBox;
						 CB1->Items->Add("Номер");
						 CB1->Items->Add("Группа");
						 CB1->SelectedIndex=columnCount;
						 if (columnCount==tableLayoutPanel1->ColumnCount)
						 {
							 tableLayoutPanel1->ColumnCount+=1;
							 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
						 }
						 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);*/
						 Label^ l0 = gcnew Label;
						 switch (columnCount)
						 {
						 case 0:
							 l0->Text="Номер";
							 break;
						 case 1:
							 l0->Text="Группа";
							 break;
						 default:
							 break;
						 }
						 tableLayoutPanel1->Controls->Add(l0,columnCount,0);
					 }
					 for (list<group_struct>::iterator it=inp->inputs.groups.begin(); it!=inp->inputs.groups.end(); it++)
					 {
						 /*if (current_row==tableLayoutPanel1->RowCount)
						 {
							 tableLayoutPanel1->RowCount+=1;
							 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
						 }*/
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
					 while (tableLayoutPanel1->ColumnCount<2)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 while (tableLayoutPanel1->RowCount<inp->inputs.days.size())
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int columnCount=0;columnCount<2;columnCount++)
					 {
						 /*ComboBox^ CB1 = gcnew ComboBox;
						 CB1->Items->Add("Номер");
						 CB1->Items->Add("День");
						 CB1->SelectedIndex=columnCount;
						 if (columnCount==tableLayoutPanel1->ColumnCount)
						 {
							 tableLayoutPanel1->ColumnCount+=1;
							 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
						 }
						 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);*/
						 //columnCount++;
						 Label^ l0 = gcnew Label;
						 switch (columnCount)
						 {
						 case 0:
							 l0->Text="Номер";
							 break;
						 case 1:
							 l0->Text="День";
							 break;
						 default:
							 break;
						 }
						 tableLayoutPanel1->Controls->Add(l0,columnCount,0);
					 }
					 for (list<day_struct>::iterator it=inp->inputs.days.begin(); it!=inp->inputs.days.end(); it++)
					 {
						 /*if (current_row==tableLayoutPanel1->RowCount)
						 {
							 tableLayoutPanel1->RowCount+=1;
							 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
						 }*/
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
					 while (tableLayoutPanel1->ColumnCount<4)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 while (tableLayoutPanel1->RowCount<inp->inputs.lessons.size())
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int columnCount=0;columnCount<4;columnCount++)
					 {
						 /*ComboBox^ CB1 = gcnew ComboBox;
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
						 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);*/
						 //columnCount++;
						 Label^ l0 = gcnew Label;
						 switch (columnCount)
						 {
						 case 0:
							 l0->Text="Номер";
							 break;
						 case 1:
							 l0->Text="Название";
							 break;
						 case 2:
							 l0->Text="Тип";
							 break;
						 case 3:
							 l0->Text="Длительность";
							 break;
						 default:
							 break;
						 }
						 tableLayoutPanel1->Controls->Add(l0,columnCount,0);
					 }
					 for (list<lesson_struct>::iterator it=inp->inputs.lessons.begin(); it!=inp->inputs.lessons.end(); it++)
					 {
						 /*if (current_row==tableLayoutPanel1->RowCount)
						 {
							 tableLayoutPanel1->RowCount+=1;
							 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
						 }*/
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
					 while (tableLayoutPanel1->ColumnCount<2)
					 {
						 tableLayoutPanel1->ColumnCount+=1;
						 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
					 }
					 while (tableLayoutPanel1->RowCount<inp->inputs.times.size())
					 {
						 tableLayoutPanel1->RowCount+=1;
						 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
					 }
					 for (int columnCount=0;columnCount<2;columnCount++)
					 {
						 /*ComboBox^ CB1 = gcnew ComboBox;
						 CB1->Items->Add("Номер");
						 CB1->Items->Add("Время");
						 CB1->SelectedIndex=columnCount;
						 if (columnCount==tableLayoutPanel1->ColumnCount)
						 {
							 tableLayoutPanel1->ColumnCount+=1;
							 tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
						 }
						 tableLayoutPanel1->Controls->Add(CB1,columnCount,0);*/
						 //columnCount++;
						 Label^ l0 = gcnew Label;
						 switch (columnCount)
						 {
						 case 0:
							 l0->Text="Номер";
							 break;
						 case 1:
							 l0->Text="Время";
							 break;
						 default:
							 break;
						 }
						 tableLayoutPanel1->Controls->Add(l0,columnCount,0);
					 }
					 for (list<time_struct>::iterator it=inp->inputs.times.begin(); it!=inp->inputs.times.end(); it++)
					 {
						 /*if (current_row==tableLayoutPanel1->RowCount)
						 {
							 tableLayoutPanel1->RowCount+=1;
							 tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
						 }*/
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
				 selected_index=comboBox1->SelectedIndex;
			 }
			 tableLayoutPanel1->ResumeLayout();
			 
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



private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 tableLayoutPanel2->SuspendLayout();
			 
			 while (tableLayoutPanel2->ColumnCount<6)
			 {
				 tableLayoutPanel2->ColumnCount+=1;
				 tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
			 }
			 while (tableLayoutPanel2->RowCount < 2)
			 {
				 tableLayoutPanel2->RowCount+=1;
				 tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
			 }
			 for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
			 {
				 ComboBox^ CB = gcnew ComboBox;
				 /*CB->Items->Add("Номер");
				 CB->Items->Add("Время");
				 CB->Items->Add("Время1");
				 CB->Items->Add("Время2");
				 CB->Items->Add("Время3");
				 CB->Items->Add("Время4");
				 CB->Items->Add("Время5");*/
				 char* mas[9] = {
					 "Номер строки",
					 "День недели",
					 "Время начала",
					 "Номер группы",
					 "Название предмета",
					 "Тип предмета",
					 "Название аудитории",
					 "Вместимость аудитории",
					 "Свободно"
				 };

				 for (int j=0; j<9; j++)
				 {
					 CB->Items->Add(String(mas[j]).ToString());
				 }

				 CB->SelectedIndex=i;
				 tableLayoutPanel2->Controls->Add(CB,i,0);

			 }
			 for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
			 {
				 Label^ l0 = gcnew Label;
				 tableLayoutPanel2->Controls->Add(l0,i,1);
			 }
			 /*for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
			 {
				 for (int j=1;j<tableLayoutPanel2->RowCount;j++)
				 {
					 Label^ l0 = gcnew Label;
					 l0->Text="1";
					 tableLayoutPanel2->Controls->Add(l0,i,j);
				 }
			 }*/


			 tableLayoutPanel2->ResumeLayout();
		 }
private: System::Void button9_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 tableLayoutPanel2->SuspendLayout();
			 if (tableLayoutPanel2->ColumnCount<9)
			 {
				 tableLayoutPanel2->ColumnCount+=1;
				 tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 100));
				 int i=tableLayoutPanel2->ColumnCount-1;
				 ComboBox^ CB = gcnew ComboBox;
				 char* mas[9] = {
					 "Номер строки",
					 "День недели",
					 "Время начала",
					 "Номер группы",
					 "Название предмета",
					 "Тип предмета",
					 "Название аудитории",
					 "Вместимость аудитории",
					 "Свободно"
				 };
			 
				 for (int j=0; j<9; j++)
				 {
					 CB->Items->Add(String(mas[j]).ToString());
				 }
				 CB->SelectedIndex=i;
				 tableLayoutPanel2->Controls->Add(CB,i,0);
				 for (int j=1;j<tableLayoutPanel2->RowCount;j++)
				 {
					 Label^ l0 = gcnew Label;
					 tableLayoutPanel2->Controls->Add(l0,i,j);
				 }
			 }
			 tableLayoutPanel2->ResumeLayout();
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 tableLayoutPanel2->SuspendLayout();
			 int cnt=1;
			 int Cur_Row=1;
				 //for (int j=1;j<tableLayoutPanel2->RowCount;j++)
				 //{
					 
						 for (list<sched_string>::iterator it=s->slist.begin(); it!=s->slist.end(); it++)
						 {
							 /*for (list<sched_string>::iterator it=s->slist.begin(); it!=s->slist.end(); it++)
							 {

							 }*/
							 /*if (Cur_Control_Text==it->slist)
							 {
							 }*/
							 for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
							 {
								 String^ Cur_Control_Text = gcnew String("123");
								 Cur_Control_Text = tableLayoutPanel2->GetControlFromPosition(i,0)->Text;
								 if (Cur_Control_Text=="Номер строки")
								 {
									 if (Cur_Row==tableLayoutPanel2->RowCount)
									 {
										 tableLayoutPanel2->RowCount+=1;
										 tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
										 for (int k=0;k<tableLayoutPanel2->ColumnCount;k++)
										 {
											 Label^ L0 = gcnew Label;
											 tableLayoutPanel2->Controls->Add(L0,k,Cur_Row);
										 }
									 }

									 /*  "Номер строки",
										 "День недели",
										 "Время начала",
										 "Номер группы",
										 "Название предмета",
										 "Тип предмета",
										 "Название аудитории",
										 "Вместимость аудитории",
										 "Свободно"*/
									 //здесь добавляем элемент
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=(String^)(String::Concat(cnt));
								 } else if (Cur_Control_Text=="Номер группы") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=String((*it).gr1.name).ToString();
									 
								 } else if (Cur_Control_Text=="День недели") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=String((*it).day1.name).ToString();
								 } else if (Cur_Control_Text=="Время начала") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=(String^)(String::Concat((*it).tim1.begin_time));
								 } else if (Cur_Control_Text=="Название предмета") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=String((*it).les1.name).ToString();
								 } else if (Cur_Control_Text=="Тип предмета") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=String((*it).les1.type).ToString();
								 } else if (Cur_Control_Text=="Название аудитории") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=String((*it).aud1.name).ToString();
								 } else if (Cur_Control_Text=="Вместимость аудитории") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=(String^)(String::Concat((*it).aud1.groups_max));
								 } else if (Cur_Control_Text=="Свободно") 
								 {
									 tableLayoutPanel2->GetControlFromPosition(i,Cur_Row)->Text=(String^)(String::Concat((*it).aud1.groups_available));
								 } 



							 }

							 cnt++;
							 Cur_Row++;
						 }
					 
					 //tableLayoutPanel2->GetControlFromPosition(i,j)->Text=tableLayoutPanel2->GetControlFromPosition(i,j)->Text+"1";
				 //}
			 
			 tableLayoutPanel2->ResumeLayout();
		 }

private: System::Void Form1_ResizeBegin(System::Object^  sender, System::EventArgs^  e) {
			 /*tableLayoutPanel1->SuspendLayout();
			 tableLayoutPanel2->SuspendLayout();*/
			 //tableLayoutPanel1->Focused=false;
			 //tableLayoutPanel1->TableLayoutPanel();
		 }


private: System::Void Form1_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
			 /*tableLayoutPanel1->ResumeLayout();
			 tableLayoutPanel2->ResumeLayout();*/
			 //tableLayoutPanel1->Focused=true;   

		 }
};
}

