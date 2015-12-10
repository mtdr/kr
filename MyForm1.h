#pragma once
#include "BT.cpp"
#include <string>
namespace GF4 {

	using namespace BT1;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PaintEventArgs^ e;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(45, 429);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 129);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Поиск";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 367);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(258, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->Tag = L"char";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 303);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(236, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите элемент для поиска";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Location = System::Drawing::Point(310, 27);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1258, 671);
			this->panel1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button2->Location = System::Drawing::Point(13, 71);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(272, 129);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Построить дерево";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1878, 944);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximumSize = System::Drawing::Size(1900, 1000);
			this->MinimumSize = System::Drawing::Size(1900, 1000);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Search in BinaryTree";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion

		inline void displayBT (binTree b, int theX, int theY,int n, int theX1, int theY1)
	{	// n - уровень узла
		
		Graphics ^panelGraphics = panel1->CreateGraphics();
		if (b!=NULL) 
		{
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font("verdana",11);
			label->Width = 20;
			
			label->BackColor = Color::Gold;
			
			label->Location = Point(theX1, theY1);
			label->Text = Convert::ToString((wchar_t)RootBT(b));
			panel1->Controls->Add(label);
			
			if(theX !=theX1 && theY !=theY1){
			 // Draw line to screen.
				panelGraphics->DrawLine( gcnew Pen(Color::Violet, 2), Point(theX+10,theY+10), Point(theX1+10,theY1+10));}
			n++;
			if(!isNull(Right1(b))) 
			{
				displayBT (Right1(b),theX1,theY1,n,theX1+150/n,theY1+50);
			}
			
 			if(!isNull(Left1(b))) 
			{
				displayBT (Left1(b),theX1,theY1,n,theX1-150/n,theY1+50);
			}
		}

	}
		
		inline void copydisplayBT (binTree b, int theX, int theY,int n, int theX1, int theY1,const base x)
	{	// n - уровень узла
		
		Graphics ^panelGraphics = panel1->CreateGraphics();
		
		if (b!=NULL) 
		{
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font("verdana",11);
			label->Width = 20;
			if (b->data != x)
			label->BackColor = Color::Gold;
			else
			label->BackColor = Color::Green;
			label->Location = Point(theX1, theY1);
			label->Text = Convert::ToString((wchar_t)RootBT(b));
			panel1->Controls->Add(label);
			
			if(theX !=theX1 && theY !=theY1){
			 // Draw line to screen.
				panelGraphics->DrawLine( gcnew Pen(Color::Violet, 2), Point(theX+10,theY+10), Point(theX1+10,theY1+10));}
			n++;
			if(!isNull(Right1(b))) 
			{
				copydisplayBT (Right1(b),theX1,theY1,n,theX1+150/n,theY1+50,x);
			}
			
 			if(!isNull(Left1(b))) 
			{
				copydisplayBT (Left1(b),theX1,theY1,n,theX1-150/n,theY1+50,x);
			}
		}

	}
		
			inline bool check1()           // на последние //
		{
			ifstream in("input.txt");
			char str[100];
			int i = -1;
			while (!in.eof())
			{
				i++;
				in >> str[i];
			}
			if ((str[i-2] != '/') || (str[i-1] != '/')) return 0;
			else return 1;
				
			in.close();
		}
		
		inline bool check2()      // количество слэшей всегда превышает кол-во символов на 1
		{
			ifstream in("input.txt");
			ifstream in1("input.txt");
			char str[100];
			char t[100];
			int k = 0, s = 0;
			int i = -1; //k - number of elements, s-slash
			int j = -1;
			while (!in1.eof())
				{
					j++;
					in1 >> t[j];
				}
			
			while (i < j-1)
			{
				i++;
				in >> str[i];
				if (str[i] == '/') s++;
				else k++;
			}
			if (k+1==s) return 1;
			else return 0;
			in.close();
			
		}
		
		inline bool check3()          // чтобы не было первого слэша
		{
			ifstream in("input.txt");
			char str[100];
			int j = -1;
			while (!in.eof())
				{
					j++;
					in >> str[j];
				}
			if (str[0] == '/') return 0;
			else return 1;
			in.close();
		}
		
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			
				//Graphics ^panelGraphics = panel1->CreateGraphics();
				
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				int k=0;
				ifstream in("input.txt");
				binTree b;
				b=enterBT(in);
				
				if(textBox1->Text->Length != 0)
					{
						if(textBox1->Text->Length == 1)
						{
							base x = Convert::ToChar(textBox1->Text[0]);
							search(x,b,k);
						
							if (k > 0)
							{   
							
								panel1->Controls->Clear();							
								copydisplayBT(b,400,20,0,400,20,x);
								MessageBox::Show("Элемент '" + textBox1->Text[0] + "' найден " + k +  " раз(а)");
							}
								else MessageBox::Show("Элемент не найден");
						}
						else
						MessageBox::Show("Осуществляется поиск только одного элемента");
					}
					else
					MessageBox::Show("Введите элемент для поиска!");
				}
				
	
			 
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				ifstream in("input.txt");
				in.seekg(0 , ios::end);
				int length = in.tellg();
				if (!in || length == 0 )
				{
					MessageBox::Show("Файл не был создан или он пуст");
					
				}
				else
				{
					if (check1()==0)
					MessageBox::Show("Входная последовательность неправильна, возможно в конце строки не хватает /");
					else
					{
						if (check3()==0)
						MessageBox::Show("/ не может являться первым знаком");
						else
						{
							if (check2()==0)
							MessageBox::Show("Входная последовательность неправильна, возможно где то пропущен /");
							else 
							{
								
										in.seekg(0,ios::beg);
										binTree b;
										b=enterBT(in);
										displayBT(b,400,20,0,400,20);
										destroy(b);
								
							}
						}
					}
				}
			 }				 
};
}

