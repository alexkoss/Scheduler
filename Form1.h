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
			 static schedule_inputs* inp;
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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(334, 452);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"read input data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(13, 13);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(421, 431);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(441, 452);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"make schedule!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(441, 13);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(439, 431);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(892, 484);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
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

				 //richTextBox1->Text=out_text(inp);
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 inp = new schedule_inputs;
				 srand(unsigned(time(NULL)));

			 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 delete inp;
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
			 s.Cycle(inp);
			 char str[65000]="";
			 s.Show_All_List(str);
		 	 richTextBox2->Text=String(str).ToString();

	
	

		 }
};
}

