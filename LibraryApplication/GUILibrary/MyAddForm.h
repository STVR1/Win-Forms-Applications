#pragma once
#include<regex>
#include"LibraryForm.h"
#include<msclr/marshal_cppstd.h>

namespace GUILibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyAddForm : public System::Windows::Forms::Form
	{
	private:

		Library<Info>* list = nullptr;

	public:

		void SetList(Library<Info>* list)
		{
			this->list = list;
		}

		Library<Info>* GetList()
		{
			return this->list;
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
	private: System::Windows::Forms::RichTextBox^ AddMemoBox;
	private: System::Windows::Forms::Button^ AddButton;
	protected:

	protected:


	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->AddMemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// AddMemoBox
			// 
			this->AddMemoBox->Location = System::Drawing::Point(79, 39);
			this->AddMemoBox->Name = L"AddMemoBox";
			this->AddMemoBox->Size = System::Drawing::Size(196, 191);
			this->AddMemoBox->TabIndex = 0;
			this->AddMemoBox->Text = L"";

			this->AddButton->Location = System::Drawing::Point(141, 277);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 23);
			this->AddButton->TabIndex = 1;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyAddForm::AddButton_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(351, 344);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->AddMemoBox);
			this->Name = L"MyAddForm";
			this->Text = L"MyAddForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::regex num("^[0-9]+$");

		Info info;

		if (this->AddMemoBox->Lines->Length == 6 
			&& regex_match(msclr::interop::marshal_as<std::string>(this->AddMemoBox->Lines[3]->ToString()), num)
			&& regex_match(msclr::interop::marshal_as<std::string>(this->AddMemoBox->Lines[0]->ToString()), num)
			&& regex_match(msclr::interop::marshal_as<std::string>(this->AddMemoBox->Lines[5]->ToString()), num))
		{

			if (list == nullptr)list = new Library<Info>;
			
			info.SetRegnum(Convert::ToInt32(this->AddMemoBox->Lines[0]->ToString()));
			info.SetAuthor(msclr::interop::marshal_as<std::string>(this->AddMemoBox->Lines[1]->ToString()));
			info.SetName(msclr::interop::marshal_as<std::string>(this->AddMemoBox->Lines[2]->ToString()));
			info.SetDate(Convert::ToInt32(this->AddMemoBox->Lines[3]->ToString()));
			info.SetOffice(msclr::interop::marshal_as<std::string>(this->AddMemoBox->Lines[4]->ToString()));
			info.SetAmount(Convert::ToInt32(this->AddMemoBox->Lines[5]->ToString()));
			list->push_back(info);

			MessageBox::Show(this, "Success", "Successfully added", MessageBoxButtons::OK, MessageBoxIcon::Information);

			Close();

		}
		else MessageBox::Show(this, "Incorrect pattern", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	};
}