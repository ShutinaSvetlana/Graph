#pragma once
#include "TTree.h"

namespace projectGraphs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int val;
		Point p1; //первая точка
		Point p2; //вторая точка
		int n = 1; //кол-во точек
		Node* t1;
		Node* t2;
		TTree* T;
		TTree* NewT;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
			 Adjacencies* adj;
	public:
		MyForm(void)
		{
			InitializeComponent();
			T = new TTree();
			t1 = new Node();
			t2 = new Node();
			adj = new Adjacencies();
			NewT = new TTree();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(423, 397);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(446, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Вершины";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(446, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ребра";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(446, 129);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Задание";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(429, 100);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(105, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Нарисовать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 412);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(464, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(38, 20);
			this->textBox1->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 434);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{ //вершины
		val = 1;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{ //ребра
		val = 2;
	}

private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{ //запоминание координат
	Graphics^ g = panel1->CreateGraphics();	
	switch (val)
	{
	case 1:
		p1 = e->Location;
		T->Add(p1);
		T->Draw(g);
		break;
	case 2:		
		if (n % 2)
			p1 = e->Location;
		else
			p2 = e->Location;
		n++;	
		break;
	}	
}
private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
{//отрисовка панели
	Graphics^ g = panel1->CreateGraphics();	
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
{ //нарисовать ребро
	Pen^ pen = gcnew Pen(Color::Black);
	Graphics^ g = panel1->CreateGraphics();
	if (p1.X < p2.X)
	{
		t1 = T->Hit(p1);
		t2 = T->Hit(p2);
	}
	else
	{
		t2 = T->Hit(p1);
		t1 = T->Hit(p2);
	}
	if (t1 && t2 && t1 != t2)
	{
		int val = Convert::ToInt32(textBox1->Text);
		label1->Text = "";
		adj = T->AddAdj(t1, t2, val);
		adj->Draw(g,pen);
	}
	else
	{
		label1->Text = "Не попали в вершины";
	}	
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{ //задание
	Graphics^ g = panel1->CreateGraphics();
	T->Sort();
	NewT = T->Task();
	NewT->DrawAdj(g);
}
};
}
