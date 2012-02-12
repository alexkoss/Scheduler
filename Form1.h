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
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;

			 static schedule_inputs* inp;
			 static schedule_inputs* inp_original;
			 SCHEDULE* s;
			 SCHEDULE* s_template;
			 static int selected_index;
			 static bool NeedToWork;
			 static bool NeedToUpdate;
			 
			 // Текущие значения предмета для добавления
			 /*public lesson_struct TemplLes;
			 group_struct  TemplGr;
			 auditory_struct TemplAud;
			 day_struct    TemplDay;
			 time_struct   TemplTime;*/

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;

	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::DataGridView^  TTable;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button6;






			 static selected_indexes* selected_ind;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->TTable = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TTable))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->panel2->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 28);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1030, 540);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1022, 514);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Учебный план";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Выберите категорию";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(135, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(6, 41);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1010, 470);
			this->panel1->TabIndex = 18;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 5);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(3, 2);
			this->tableLayoutPanel1->TabIndex = 2;
			this->tableLayoutPanel1->Visible = false;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->groupBox2);
			this->tabPage3->Controls->Add(this->groupBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1022, 514);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Шаблон";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(341, 7);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(26, 211);
			this->button6->TabIndex = 5;
			this->button6->Text = L"<<<<<<";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->TTable);
			this->groupBox2->Location = System::Drawing::Point(373, 7);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(641, 504);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Просмотр шаблона";
			// 
			// TTable
			// 
			this->TTable->AllowUserToAddRows = false;
			this->TTable->AllowUserToDeleteRows = false;
			this->TTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->TTable->Location = System::Drawing::Point(6, 17);
			this->TTable->Name = L"TTable";
			this->TTable->ReadOnly = true;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->TTable->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->TTable->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->TTable->Size = System::Drawing::Size(629, 481);
			this->TTable->TabIndex = 1;
			this->TTable->CellPainting += gcnew System::Windows::Forms::DataGridViewCellPaintingEventHandler(this, &Form1::TTable_CellPainting);
			this->TTable->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::TTable_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->comboBox6);
			this->groupBox1->Controls->Add(this->comboBox5);
			this->groupBox1->Controls->Add(this->comboBox4);
			this->groupBox1->Controls->Add(this->comboBox3);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(9, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(331, 211);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Редактирование";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(250, 183);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(133, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 35);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Выбрать занятие";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 183);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox6
			// 
			this->comboBox6->Enabled = false;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(111, 125);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(214, 21);
			this->comboBox6->TabIndex = 5;
			// 
			// comboBox5
			// 
			this->comboBox5->Enabled = false;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(111, 98);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(214, 21);
			this->comboBox5->TabIndex = 5;
			// 
			// comboBox4
			// 
			this->comboBox4->Enabled = false;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(111, 71);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(214, 21);
			this->comboBox4->TabIndex = 5;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox4_SelectedIndexChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->Enabled = false;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(111, 44);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(214, 21);
			this->comboBox3->TabIndex = 5;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox3_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(111, 17);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(214, 21);
			this->comboBox2->TabIndex = 5;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 47);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Группа:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Время:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"День:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Аудитория:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Предмет:";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->panel2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1022, 514);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Расписание";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->AutoScroll = true;
			this->panel2->Controls->Add(this->tableLayoutPanel2);
			this->panel2->Location = System::Drawing::Point(3, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1013, 505);
			this->panel2->TabIndex = 12;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->AutoSize = true;
			this->tableLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->Size = System::Drawing::Size(3, 28);
			this->tableLayoutPanel2->TabIndex = 5;
			this->tableLayoutPanel2->Visible = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolStripButton1, 
				this->toolStripSeparator1, this->toolStripButton4, this->toolStripSeparator2, this->toolStripButton2, this->toolStripButton3});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1030, 25);
			this->toolStrip1->TabIndex = 6;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"Загрузить учебный план";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"Изменить шаблон расписания";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButton4_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"Составить расписание";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"Составить расписание с использованием генетического алгоритма";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 571);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1030, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(29, 17);
			this->toolStripStatusLabel1->Text = L"Text";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 593);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->tabControl1);
			this->MinimumSize = System::Drawing::Size(800, 350);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Составитель расписания";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResizeBegin += gcnew System::EventHandler(this, &Form1::Form1_ResizeBegin);
			this->ResizeEnd += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TTable))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// инициализация при загрузке формы
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		inp = new schedule_inputs;
		inp_original = new schedule_inputs;
		s = new SCHEDULE;
		s_template = new SCHEDULE;
		

		selected_ind = new selected_indexes;

		srand(unsigned(time(NULL)));
				 
		comboBox1->Items->Add("Аудитории");
		comboBox1->Items->Add("Группы");
		comboBox1->Items->Add("Дни недели");
		comboBox1->Items->Add("Занятия");
		comboBox1->Items->Add("Время начала");
				 
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
		NeedToWork = false;
		NeedToUpdate = false;

		toolStripStatusLabel1->Text="Приложение запущено";

		Form1::DoubleBuffered = true;
		MakeTemplate();
		AddColumn();
		AddColumn();
	}

	// освобождение памяти при закрытии формы
	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		delete inp;
		delete inp_original;
		delete s;
		delete s_template;
		delete selected_ind;
	}

	// создание шаблона для таблицы расписания
	private: System::Void MakeTemplate() {
		tableLayoutPanel2->SuspendLayout();

		while (tableLayoutPanel2->ColumnCount<6)
		{
			tableLayoutPanel2->ColumnCount+=1;
			tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 140));
		}
		while (tableLayoutPanel2->RowCount < 1)
		{
			tableLayoutPanel2->RowCount+=1;
			tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
		}
		for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
		{
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

		}
		for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
		{
			Label^ l0 = gcnew Label;
			l0->AutoSize=true;
			tableLayoutPanel2->Controls->Add(l0,i,1);
		}

		tableLayoutPanel2->ResumeLayout();
	}

	// изменение таблицы входных данных
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
				new_col_count=4;
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
				new_col_count=7;
				break;
			case 4:
				new_row_count=inp->inputs.times.size();
				new_col_count=2;
				break;
			default:
				break;
			}
			for (int i=tableLayoutPanel1->RowCount;i>=0;i--)
			{
				for (int j=tableLayoutPanel1->ColumnCount;j>=0;j--)
				{
					tableLayoutPanel1->Controls->Remove(tableLayoutPanel1->GetControlFromPosition(j,i)); 
				}
			}
			for (int i=tableLayoutPanel1->ColumnCount-1;i>=new_col_count;i--)
			{
				tableLayoutPanel1->ColumnStyles->RemoveAt(i);
				tableLayoutPanel1->ColumnCount--;
			}
			for (int i=tableLayoutPanel1->RowCount-1;i>=new_row_count;i--)
			{
				tableLayoutPanel1->RowStyles->RemoveAt(i);
				tableLayoutPanel1->RowCount--;
			}
			int current_row=1;
			switch (comboBox1->SelectedIndex)
			{
			case 0:
				while (tableLayoutPanel1->ColumnCount<new_col_count)
				{
					tableLayoutPanel1->ColumnCount+=1;
					tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
				}
				while (tableLayoutPanel1->RowCount < (int)(inp->inputs.auditories.size()))
				{
					tableLayoutPanel1->RowCount+=1;
					tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
				}

				for (int columnCount=0;columnCount<new_col_count;columnCount++)
				{
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
					/*case 4:
						l0->Text="Время начала";
						break;
					case 5:
						l0->Text="Приоритет";
						break;*/
					default:
						break;
					}
					tableLayoutPanel1->Controls->Add(l0,columnCount,0);
				}

					 
				for (list<auditory_struct>::iterator it=inp->inputs.auditories.begin(); it!=inp->inputs.auditories.end(); it++)
				{
					for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					{
						Label^ l1 = gcnew Label;
						l1->AutoSize=true;
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
						} /*else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Время начала")
						{
							l1->Text=String::Concat((*it).groups_available);
						} else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Приоритет")
						{
							l1->Text=String::Concat((*it).priority);
						} */


						tableLayoutPanel1->Controls->Add(l1,i,current_row);
					}
					current_row++;
				}
				break;
			case 1:
				while (tableLayoutPanel1->ColumnCount<new_col_count)
				{
					tableLayoutPanel1->ColumnCount+=1;
					tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
				}
				while (tableLayoutPanel1->RowCount < (int)(inp->inputs.groups.size()))
				{
					tableLayoutPanel1->RowCount+=1;
					tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
				}
				for (int columnCount=0;columnCount<new_col_count;columnCount++)
				{
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
					for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					{
						Label^ l1 = gcnew Label;
						l1->AutoSize=true;
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
				}
				break;
			case 2:
				while (tableLayoutPanel1->ColumnCount<new_col_count)
				{
					tableLayoutPanel1->ColumnCount+=1;
					tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
				}
				while (tableLayoutPanel1->RowCount < (int)(inp->inputs.days.size()))
				{
					tableLayoutPanel1->RowCount+=1;
					//tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 25));
					tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
				}
				for (int columnCount=0;columnCount<new_col_count;columnCount++)
				{
					Label^ l0 = gcnew Label;
					//l0->AutoSize=true;
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
					for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					{
						Label^ l1 = gcnew Label;
						l1->AutoSize=true;
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
				}
				break;
			case 3:
					 
				while (tableLayoutPanel1->ColumnCount<new_col_count)
				{
					tableLayoutPanel1->ColumnCount+=1;
					float column_width=100;
					tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
				}
				tableLayoutPanel1->ColumnStyles[4]->Width = 200;
				while (tableLayoutPanel1->RowCount < (int)(inp->inputs.lessons.size()))
				{
					tableLayoutPanel1->RowCount+=1;
					tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
				}
				for (int columnCount=0;columnCount<new_col_count;columnCount++)
				{
					Label^ l0 = gcnew Label;
					//l0->AutoSize=true;
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
					case 4:
						l0->Text="Группы";
						break;
					case 5:
						l0->Text="Макс. групп";
						break;
					case 6:
						l0->Text="Преподаватель";
						break;
					default:
						break;
					}
					tableLayoutPanel1->Controls->Add(l0,columnCount,0);
				}
				for (list<lesson_struct>::iterator it=inp->inputs.lessons.begin(); it!=inp->inputs.lessons.end(); it++)
				{
					for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					{
						Label^ l1 = gcnew Label;
						l1->AutoSize=true;
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
						} else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Преподаватель")
						{
							l1->Text=String::Concat(String((*it).teacher).ToString());
						} else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Группы")
						{
							String^ groups_all = "";
							for (list<string>::iterator it12=(*it).for_groups.begin(); it12!=(*it).for_groups.end(); it12++)
							{
								if (groups_all!="")
									groups_all+=",";
								groups_all+=String((*it12).c_str()).ToString();
								//MessageBox::Show(String::Concat(String(it->c_str()).ToString()));
							}
							l1->Text=groups_all;

						} else if (tableLayoutPanel1->GetControlFromPosition(i,0)->Text=="Макс. групп")
						{
							l1->Text=String::Concat((*it).groups_max);
						} 


						tableLayoutPanel1->Controls->Add(l1,i,current_row);
					}
					current_row++;
				}
				break;
			case 4:
				while (tableLayoutPanel1->ColumnCount<new_col_count)
				{
					tableLayoutPanel1->ColumnCount+=1;
					tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::AutoSize));
				}
				while (tableLayoutPanel1->RowCount < (int)(inp->inputs.times.size()))
				{
					tableLayoutPanel1->RowCount+=1;
					tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
				}
				for (int columnCount=0;columnCount<new_col_count;columnCount++)
				{
					Label^ l0 = gcnew Label;
					//l0->AutoSize=true;
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
					for (int i=0;i<tableLayoutPanel1->ColumnCount;i++)
					{
						Label^ l1 = gcnew Label;
						l1->AutoSize=true;
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
				}
				break;
			default:
				break;
			}
			selected_index=comboBox1->SelectedIndex;
		}
		tableLayoutPanel1->ResumeLayout();
			 
	}

	// добавление столбца
	private: System::Void AddColumn() {
		tableLayoutPanel2->SuspendLayout();

		if (tableLayoutPanel2->ColumnCount<9)
		{
			tableLayoutPanel2->ColumnCount+=1;
			tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 140));
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
				l0->AutoSize=true;
				tableLayoutPanel2->Controls->Add(l0,i,j);
			}
		}

		tableLayoutPanel2->ResumeLayout();
		TableUpdate();
	}
	
	// обновление таблицы расписания
	private: System::Void TableUpdate() {
		tableLayoutPanel2->SuspendLayout();

		int cnt=1;
		int Cur_Row=1;
 		for (list<sched_string>::iterator it=s->slist.begin(); it!=s->slist.end(); it++)
		{
			for (int i=0;i<tableLayoutPanel2->ColumnCount;i++)
			{
				String^ Cur_Control_Text = gcnew String("123");
				Cur_Control_Text = tableLayoutPanel2->GetControlFromPosition(i,0)->Text;
				if (Cur_Control_Text=="Номер строки")
				{
					if (Cur_Row==tableLayoutPanel2->RowCount)
					{
						tableLayoutPanel2->RowCount+=1;
						//tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
						tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
						for (int k=0;k<tableLayoutPanel2->ColumnCount;k++)
						{
							Label^ L0 = gcnew Label;
							L0->AutoSize=true;
							tableLayoutPanel2->Controls->Add(L0,k,Cur_Row);
						}
					}

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

		tableLayoutPanel2->ResumeLayout();
	}

	// обработка начала изменения размера формы
	private: System::Void Form1_ResizeBegin(System::Object^  sender, System::EventArgs^  e) {
		tableLayoutPanel1->Hide();
		tableLayoutPanel2->Hide();
	}

	// обработка завершения изменения размера формы
	private: System::Void Form1_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
		tableLayoutPanel1->Show();
		tableLayoutPanel2->Show();
	}
		
// открытие файла с учебным планом
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

			 String^ app_path=Application::StartupPath;
			 openFileDialog1->InitialDirectory = app_path;
			 openFileDialog1->Filter = "xml files (*.xml)|*.xml|txt files (*.txt)|*.txt|All files (*.*)|*.*";
			 openFileDialog1->FilterIndex = 1;
			 openFileDialog1->RestoreDirectory = true;

			 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			 {
				 InitInputs(inp,openFileDialog1->FileName);
				 s_template->Make_Lesson_List(inp);
				 InitInputs(inp_original,openFileDialog1->FileName);
			 }
			 else
				 return;
			 comboBox1_SelectedIndexChanged(sender,e);
			 tableLayoutPanel1->Visible = true;
			 FillFirstCombo();

			 int newColIndex = 0;

			 NumOfDays = inp_original->inputs.days.size();
			 NumOfTimes = inp_original->inputs.times.size();
			 days = gcnew array<String^> (400);

			 newColIndex = TTable->Columns->Add("Groups","Группа");
			 TTable->Columns[newColIndex]->Frozen = true;

			 int dayCnt=0;
			 for (list<day_struct>::iterator it_d=inp_original->inputs.days.begin();it_d!=inp_original->inputs.days.end();it_d++)
			 {
				 String^ curDay = gcnew String((*it_d).name);
				 days[dayCnt++] = curDay;
				 for (list<time_struct>::iterator it_t=inp_original->inputs.times.begin();it_t!=inp_original->inputs.times.end();it_t++)
				 {
					 String^ curTime((*it_t).begin_time.ToString());
					 newColIndex = TTable->Columns->Add("Col"+(newColIndex+1).ToString(),curTime);
				 }
			 }

			 for (int i=0;i<TTable->ColumnCount;i++)
			 {
				 TTable->Columns[i]->Width = 150;
			 }

			 TTable->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::EnableResizing;
			 TTable->ColumnHeadersHeight = TTable->ColumnHeadersHeight*2;
			 TTable->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::BottomCenter;

			 // заносим шаблон группы
			 for (list<group_struct>::iterator it=inp_original->inputs.groups.begin();it!=inp_original->inputs.groups.end();it++)
			 {
				 String^ curGroup = gcnew String((*it).name);
				 TTable->Rows->Add(curGroup);
			 }
			 tabControl1->SelectedIndex = 0;
		 }

// заполнение предметов для выбора в шаблоне
private: System::Void FillFirstCombo() {
			 comboBox2->Text = "Выберите предмет";
			 comboBox3->Text = "Выберите группу";
			 comboBox4->Text = "Выберите аудиторию";
			 comboBox5->Text = "Выберите день";
			 comboBox6->Text = "Выберите время";

			 for (list<lesson_struct>::iterator it=(inp_original->inputs).lessons.begin();it!=(inp_original->inputs).lessons.end();it++)
			 {
				 String^ str1 = gcnew String((*it).name);
				 String^ str2 = gcnew String((*it).type);
				 String^ str3 = (*it).id.ToString()+" "+str1+" "+str2;
				 comboBox2->Items->Add(str3);
			 }
			 comboBox3->Enabled=false;
			 comboBox4->Enabled=false;
			 comboBox5->Enabled=false;
			 comboBox6->Enabled=false;
		 }

// запуск расчёта расписания
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			 s->clear();
			 s->CopySched(*s_template);
			 int num_of_8_am_pairs = s->Cycle2(inp);
			 //char str[65000]="";
			 //s->Show_All_List(str);
			 MessageBox::Show(String::Concat("Number of 8 am pairs: ", num_of_8_am_pairs));
			 TableUpdate();
			 tableLayoutPanel2->Visible = true;
			 tabControl1->SelectedIndex = 2;
		 }

// запуск расчёта расписания с использованием генетического алгоритма
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
			 NeedToWork = true;
			 backgroundWorker1->RunWorkerAsync();
		 }

private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 s->clear();
			 s->CopySched(*s_template);
			 int num_of_8_am_pairs = s->Cycle(inp);
			 char str[65000]="";
			 s->Show_All_List(str);
			 MessageBox::Show(String::Concat("Number of 8 am pairs: ", num_of_8_am_pairs));
			 NeedToWork=false;
		 }

private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 TableUpdate();
			 tableLayoutPanel2->Visible = true;
			 tabControl1->SelectedIndex = 2;
		 }

		 // смена значения комбо занятия
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 int SelectedLes = comboBox2->SelectedIndex;

			 lesson_struct current_lesson;
			 
			 int cnt=0;
			 for (list<lesson_struct>::iterator it=(inp_original->inputs).lessons.begin();it!=(inp_original->inputs).lessons.end();it++)
			 {
				 String^ str1 = gcnew String((*it).name);
				 String^ str2 = gcnew String((*it).type);
				 String^ str3 = (*it).id.ToString()+" "+str1+" "+str2;
				 if (str3==comboBox2->Text && cnt==SelectedLes)
				 {
					 current_lesson=(*it);
					 break;
				 }
				 cnt++;
			 }
			 
			 comboBox3->Items->Clear();
			 for (list<string>::iterator it2=current_lesson.for_groups.begin();it2!=current_lesson.for_groups.end();it2++)
			 {
				 String^ str = gcnew String((*it2).c_str());
				 comboBox3->Items->Add(str);
			 }
			 
			 comboBox4->Items->Clear();
			 for (list<auditory_struct>::iterator it2=inp_original->inputs.auditories.begin(); it2!=inp_original->inputs.auditories.end(); it2++)
			 {
				 if (/*(*it2).groups_max>=current_lesson.groups_max &&*/ !strcmp((*it2).type,current_lesson.type) && (*it2).groups_available>0)
				 {
					 for (list<string>::iterator it3=(*it2).for_lessons.begin(); it3!=(*it2).for_lessons.end(); it3++)
					 {
						 //добавление данной аудитории в список возможных
						 if (!strcmp((*it3).c_str(),current_lesson.name))
						 {
							 String^ str = gcnew String((*it2).name);
							 comboBox4->Items->Add(str);
						 }
					 }
				 }
			 }

			 //TemplLes = current_lesson;
			 comboBox3->Text = "Выберите группу";
			 comboBox4->Text = "Выберите аудиторию";
			 comboBox5->Text = "Выберите день";
			 comboBox6->Text = "Выберите время";

			 comboBox3->Enabled=true;
			 comboBox4->Enabled=false;
			 comboBox5->Enabled=false;
			 comboBox6->Enabled=false;
		 }
		 
		 // смена значения комбо группы
private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 int SelectedLes = comboBox2->SelectedIndex;
			 
			 /*lesson_struct current_lesson;
			 
			 int cnt=0;
			 for (list<lesson_struct>::iterator it=(inp->inputs).lessons.begin();it!=(inp->inputs).lessons.end();it++)
			 {
				 String^ str1 = gcnew String((*it).name);
				 String^ str2 = gcnew String((*it).type);
				 String^ str3 = (*it).id.ToString()+" "+str1+" "+str2;
				 if (str3==comboBox2->Text && cnt==SelectedLes)
				 {
					 current_lesson=(*it);
					 break;
				 }
				 cnt++;
			 }*/
			 
			 /*comboBox4->Items->Clear();
			 for (list<auditory_struct>::iterator it2=inp->inputs.auditories.begin(); it2!=inp->inputs.auditories.end(); it2++)
			 {
				 if (/ *(*it2).groups_max>=current_lesson.groups_max &&* / !strcmp((*it2).type,current_lesson.type) && (*it2).groups_available>0)
				 {
					 for (list<string>::iterator it3=(*it2).for_lessons.begin(); it3!=(*it2).for_lessons.end(); it3++)
					 {
						 //добавление данной аудитории в список возможных
						 if (!strcmp((*it3).c_str(),current_lesson.name))
						 {
							 String^ str = gcnew String((*it2).name);
							 comboBox4->Items->Add(str);
						 }
					 }
				 }
			 }*/

//			 comboBox4->Text = "Выберите аудиторию";
//			 comboBox5->Text = "Выберите день";
//			 comboBox6->Text = "Выберите время";

			 comboBox3->Enabled=true;
			 comboBox4->Enabled=true;
//			 comboBox5->Enabled=false;
//			 comboBox6->Enabled=false;
		 }

		 // смена значения комбо аудитории
private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

//			 comboBox5->Text = "Выберите день";
//			 comboBox6->Text = "Выберите время";

			 comboBox5->Items->Clear();
			 comboBox6->Items->Clear();
			 for (list<day_struct>::iterator it=(inp->inputs).days.begin();it!=(inp->inputs).days.end();it++)
			 {
				 String^ str = gcnew String((*it).name);
				 comboBox5->Items->Add(str);
			 }

			 for (list<time_struct>::iterator it=(inp->inputs).times.begin();it!=(inp->inputs).times.end();it++)
			 {
				 String^ str = gcnew String(Convert::ToString((*it).begin_time));
				 comboBox6->Items->Add(str);
			 }

			 comboBox3->Enabled=true;
			 comboBox4->Enabled=true;
			 comboBox5->Enabled=true;
			 comboBox6->Enabled=true;
		 }

		 // обработка добавления в шаблон
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox3->SelectedIndex<0)
			{
				MessageBox::Show("Для добавления занятия в расписание требуется выбрать группу","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if (comboBox4->SelectedIndex<0)
			{
				MessageBox::Show("Для добавления занятия в расписание требуется выбрать аудиторию","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if (comboBox5->SelectedIndex<0)
			{
				MessageBox::Show("Для добавления занятия в расписание требуется выбрать день недели","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if (comboBox6->SelectedIndex<0)
			{
				MessageBox::Show("Для добавления занятия в расписание требуется выбрать время занятия","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			sched_string current;
			// места в таблице
			int row=0;
			int col=0;

			int SelectedLes = comboBox2->SelectedIndex;
			int cnt=0,cntGrps=0,dayNum=0,timeNum=0,maxOfTimes=inp->inputs.times.size();
			for (list<lesson_struct>::iterator it=(inp->inputs).lessons.begin();it!=(inp->inputs).lessons.end();it++)
			{
				String^ str1 = gcnew String((*it).name);
				String^ str2 = gcnew String((*it).type);
				String^ str3 = (*it).id.ToString()+" "+str1+" "+str2;
				if (str3==comboBox2->Text && cnt==SelectedLes)
				{
					current.les1=(*it);
					break;
				}
				cnt++;
			}

			for (list<group_struct>::iterator it=(inp->inputs).groups.begin();it!=(inp->inputs).groups.end();it++)
			{
				String^ str = gcnew String((*it).name);
				if (str==comboBox3->Text)
				{
					current.gr1=(*it);
					break;
				}
				cntGrps++;
			}
			row = cntGrps;
			for (list<auditory_struct>::iterator it=(inp->inputs).auditories.begin();it!=(inp->inputs).auditories.end();it++)
			{
				String^ str = gcnew String((*it).name);
				if (str==comboBox4->Text)
				{
					current.aud1=(*it);
					current.aud1.groups_available--;
					break;
				}
			}

			for (list<day_struct>::iterator it=(inp->inputs).days.begin();it!=(inp->inputs).days.end();it++)
			{
				String^ str = gcnew String((*it).name);
				if (str==comboBox5->Text)
				{
					current.day1=(*it);
					break;
				}
				dayNum++;
			}

			for (list<time_struct>::iterator it=(inp->inputs).times.begin();it!=(inp->inputs).times.end();it++)
			{
				if ((*it).begin_time.ToString()==comboBox6->Text)
				{
					current.tim1=(*it);
					break;
				}
				timeNum++;
			}
			
			// TODO: осуществить проверку на возможность добавления!!!!
			if (s_template->CanAdd(current)==0)
			{
				toolStripStatusLabel1->Text="В шаблон добавлена новая строка!";
			}
			else if (s_template->CanAdd(current)==1)
			{
				MessageBox::Show("Невозможно добавить занятие. В аудитории в данный день в данное время проходят другие занятия.","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (s_template->CanAdd(current)==2)
			{
				MessageBox::Show("Невозможно добавить занятие. В аудитории максимальное количество групп.","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (s_template->CanAdd(current)==3)
			{
				MessageBox::Show("Невозможно добавить занятие. Данная группа уже занята в данное время в данной аудитории.","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (s_template->CanAdd(current)==4)
			{
				MessageBox::Show("Невозможно добавить занятие. Данная группа уже занята другим занятием в данное время в данной аудитории.","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			s_template->slist.push_back(current);

			col=1+dayNum*maxOfTimes+timeNum;
			String^ stringToFill;
			String^ stringToFill1 = gcnew String(current.les1.name);
			String^ stringToFill2 = gcnew String(current.les1.type);
			String^ stringToFill3 = gcnew String(current.aud1.name);
			String^ stringToFill4 = gcnew String(current.les1.teacher);
			stringToFill=stringToFill1+"\n"+stringToFill2+"\n"+stringToFill3+"\n"+stringToFill4;
			TTable[col,row]->Value=stringToFill;


			// добавили в шаблон - удалить из исходных данных
			for (list<lesson_struct>::iterator it=(inp->inputs).lessons.begin();it!=(inp->inputs).lessons.end();it++)
			{
				if ((*it).id==current.les1.id) // если нужный предмет - удаляем добавленную группу из его списка предметов
				{
					string str(current.gr1.name);
					list<string>::iterator GroupToDelete;
					for (list<string>::iterator it2=(*it).for_groups.begin();it2!=(*it).for_groups.end();it2++)
					{
						if ((*it2)==str)
						{
							GroupToDelete = it2;
						}
					} // прошлись по всем группам, указали на удаляемую
					(*it).for_groups.erase(GroupToDelete);
					
					break;
				}
			}

			// удалили - обновить данные для занятия
			string group_name(current.gr1.name);
			s_template->Fill_Restricted(&(s_template->lec_list),group_name,current);
			s_template->Fill_Restricted(&(s_template->sem_list),group_name,current);
			s_template->Fill_Restricted(&(s_template->lab_list),group_name,current);
			
			int cnt2=s_template->Check_Restricted_Count(s_template->lec_list);
			cnt2=s_template->Check_Restricted_Count(s_template->sem_list);
			cnt2=s_template->Check_Restricted_Count(s_template->lab_list);
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 comboBox2->SelectedIndex=0;
			 comboBox3->SelectedIndex=0;
			 comboBox4->SelectedIndex=0;
			 comboBox5->SelectedIndex=0;
			 comboBox6->SelectedIndex=1;
		 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (comboBox3->SelectedIndex<0)
			 {
				 MessageBox::Show("Для удаления занятия требуется выбрать группу","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 return;
			 }
			 if (comboBox4->SelectedIndex<0)
			 {
				 MessageBox::Show("Для удаления занятия требуется выбрать аудиторию","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 return;
			 }
			 if (comboBox5->SelectedIndex<0)
			 {
				 MessageBox::Show("Для удаления занятия требуется выбрать день недели","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 return;
			 }
			 if (comboBox6->SelectedIndex<0)
			 {
				 MessageBox::Show("Для удаления занятия требуется выбрать время занятия","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 return;
			 }

			 sched_string current;
			 // места в таблице
			 int row=0;
			 int col=0;

			 int SelectedLes = comboBox2->SelectedIndex;
			 int cnt=0,dayNum=0,timeNum=0,maxOfTimes=inp->inputs.times.size();
			 for (list<lesson_struct>::iterator it=(inp->inputs).lessons.begin();it!=(inp->inputs).lessons.end();it++)
			 {
				 String^ str1 = gcnew String((*it).name);
				 String^ str2 = gcnew String((*it).type);
				 String^ str3 = (*it).id.ToString()+" "+str1+" "+str2;
				 if (str3==comboBox2->Text && cnt==SelectedLes)
				 {
					 current.les1=(*it);
					 break;
				 }
			 }

			 for (list<group_struct>::iterator it=(inp->inputs).groups.begin();it!=(inp->inputs).groups.end();it++)
			 {
				 String^ str = gcnew String((*it).name);
				 if (str==comboBox3->Text)
				 {
					 current.gr1=(*it);
					 break;
				 }
				 cnt++;
			 }
			 row=cnt;

			 for (list<auditory_struct>::iterator it=(inp->inputs).auditories.begin();it!=(inp->inputs).auditories.end();it++)
			 {
				 String^ str = gcnew String((*it).name);
				 if (str==comboBox4->Text)
				 {
					 current.aud1=(*it);
					 current.aud1.groups_available--;
					 break;
				 }
			 }

			 for (list<day_struct>::iterator it=(inp->inputs).days.begin();it!=(inp->inputs).days.end();it++)
			 {
				 String^ str = gcnew String((*it).name);
				 if (str==comboBox5->Text)
				 {
					 current.day1=(*it);
					 break;
				 }
				 dayNum++;
			 }

			 for (list<time_struct>::iterator it=(inp->inputs).times.begin();it!=(inp->inputs).times.end();it++)
			 {
				 if ((*it).begin_time.ToString()==comboBox6->Text)
				 {
					 current.tim1=(*it);
					 break;
				 }
				 timeNum++;
			 }

			 col=1+dayNum*maxOfTimes+timeNum;

			 int res=s_template->CanDelete(current);
			 if (res==0) // нету у данной группы занятия в данные ауд-день-время
			 {
				 MessageBox::Show("Невозможно удалить занятие. Не существует занятия у данной группы в данной аудитории в данный день в данное время.","Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
			 else if (res==1)
			 {
				 toolStripStatusLabel1->Text="Из шаблона удалена строка!";
				 String^ stringToFill = "";
				 
				 //stringToFill=stringToFill1+"\n"+stringToFill2+"\n"+stringToFill3;
				 TTable[col,row]->Value=stringToFill;
			 }
			 // вернуть в исходные данные

			 for (list<lesson_struct>::iterator it=(inp->inputs).lessons.begin();it!=(inp->inputs).lessons.end();it++)
			 {
				 if ((*it).id==current.les1.id) // если нужный предмет - удаляем добавленную группу из его списка предметов
				 {
					 string str(current.gr1.name);
					 (*it).for_groups.push_back(str);

					 break;
				 }
			 }
		 }

private: System::Void TTable_CellPainting(System::Object^  sender, System::Windows::Forms::DataGridViewCellPaintingEventArgs^  e) {
			 if (e->RowIndex == -1 && e->ColumnIndex > -1)
			 {
				 e->PaintBackground(e->CellBounds, false);
				 Rectangle r2 = e->CellBounds;
				 r2.Y += e->CellBounds.Height / 2;
				 r2.Height = e->CellBounds.Height / 2;
				 e->PaintContent(r2);
				 e->Handled = true;
			 }
		 }
		 private: array<String^>^days;
				  int NumOfDays;
				  int NumOfTimes;

private: System::Void TTable_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 //String^^ monthes[] = {gcnew String("January"), gcnew String("February"), gcnew String("March") };
			 //string monthes[] = { "January", "February", "March" };

			 //array<String^>^monthes = gcnew array<String^> (3) { "January", "February", "March" };
			 
			 for (int j = 0; j < NumOfDays*NumOfTimes+1;)
			 {
				 RectangleF r1 = TTable->GetCellDisplayRectangle(j+1, -1, true); //get the column header cell
				 r1.X += 1;
				 r1.Y += 1;
				 /*r1.Width = r1.Width * 2 - 2;
				 r1.Height = r1.Height / 2 - 2;*/
				 r1.Width = r1.Width * NumOfTimes - NumOfTimes;
				 r1.Height = r1.Height / 2 - 2;
				 e->Graphics->FillRectangle(/*Brushes::Transparent*/gcnew SolidBrush(TTable->ColumnHeadersDefaultCellStyle->BackColor), r1);
				 StringFormat^ format = gcnew StringFormat();
				 format->Alignment = StringAlignment::Center;
				 format->LineAlignment = StringAlignment::Center;
				 e->Graphics->DrawString(days[j/NumOfTimes],
					 TTable->ColumnHeadersDefaultCellStyle->Font,
					 gcnew SolidBrush(TTable->ColumnHeadersDefaultCellStyle->ForeColor),
					 r1,
					 format);
				 j += NumOfTimes;
			 }
		 }

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (groupBox1->Visible)
			 {
				 groupBox1->Visible=false;
				 button6->Text=">>>>>>";
				 Point^ newLoc = gcnew Point(button6->Location.X-332,button6->Location.Y);
				 button6->Location = *newLoc;
				 
				 groupBox2->Size = *(gcnew System::Drawing::Size(groupBox2->Size.Width+332, groupBox2->Size.Height));
				 newLoc = gcnew Point(groupBox2->Location.X-332,groupBox2->Location.Y);
				 groupBox2->Location = *newLoc;
			 }
			 else
			 {
				 groupBox1->Visible=true;
				 button6->Text="<<<<<<";
				 Point^ newLoc = gcnew Point(button6->Location.X+332,button6->Location.Y);
				 button6->Location = *newLoc;

				 groupBox2->Size = *(gcnew System::Drawing::Size(groupBox2->Size.Width-332, groupBox2->Size.Height));
				 newLoc = gcnew Point(groupBox2->Location.X+332,groupBox2->Location.Y);
				 groupBox2->Location = *newLoc;
			 }

			 
		 }
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e) {
			 tabControl1->SelectedIndex = 1;
		 }
};
}

