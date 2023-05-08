#pragma once

#include"..\BinaryTree\TreeClass.h"

#include<msclr/marshal_cppstd.h>

namespace GUITree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyAddForm : public System::Windows::Forms::Form
	{
	private:

		Tree<int, std::string>* tree = nullptr;



	public:

		void SetTree(Tree<int, std::string>* tree)
		{
			this->tree = tree;
		}

		Tree<int, std::string>* GetTree()
		{
			return this->tree;
		}

		MyAddForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyAddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ PassportLabel;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::Button^ AddButton;


	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->PassportLabel = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 132);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(135, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(153, 132);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 22);
			this->textBox2->TabIndex = 1;
			// 
			// PassportLabel
			// 
			this->PassportLabel->AutoSize = true;
			this->PassportLabel->Location = System::Drawing::Point(25, 109);
			this->PassportLabel->Name = L"PassportLabel";
			this->PassportLabel->Size = System::Drawing::Size(109, 16);
			this->PassportLabel->TabIndex = 2;
			this->PassportLabel->Text = L"Passport number";
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Location = System::Drawing::Point(215, 109);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(65, 16);
			this->NameLabel->TabIndex = 3;
			this->NameLabel->Text = L"Full name";
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(89, 234);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(126, 45);
			this->AddButton->TabIndex = 4;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyAddForm::AddButton_Click);
			// 
			// MyAddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(332, 314);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->PassportLabel);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyAddForm";
			this->Text = L"MyAddForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		Pair<int, std::string> temp;
		int value = 0;
		int prevsize = tree->Size();

		if (int::TryParse(this->textBox1->Text->ToString(), value) && this->textBox2->Text->ToString()!="")
		{

			value = Convert::ToInt32(this->textBox1->Text->ToString());
			
			if (1000000 < value || value < 99999)
			{
				MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			temp.first = value;
			temp.second = msclr::interop::marshal_as<std::string>(this->textBox2->Text->ToString());

			tree->Add(temp);

			if (this->tree->Size() - prevsize > 0)
			{
				MessageBox::Show(this, "Successfully added", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				Close();
			}
			else MessageBox::Show(this, "Unsuccessfully added","Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
		else MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}
};
}
