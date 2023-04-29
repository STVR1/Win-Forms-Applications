#pragma once

#include"LibraryForm.h"
#include<msclr/marshal_cppstd.h>

namespace GUILibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyShowForm : public System::Windows::Forms::Form
	{

	private:

		Library<Info>* list = nullptr;
		Library<Info>* Result = nullptr;

	public:
	
		void SetList(Library<Info>* list)
		{
			this->list = list;
		}

		Library<Info>* GetRes()
		{
			return this->Result;
		}

		MyShowForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyShowForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::ComboBox^ ShowChoiceComboBox;
	private: System::Windows::Forms::TextBox^ TextBox1;
	private: System::Windows::Forms::Button^ SearchButton;



	private: System::Windows::Forms::TextBox^ TextBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;




	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->ShowChoiceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->TextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->TextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ShowChoiceComboBox
			// 
			this->ShowChoiceComboBox->FormattingEnabled = true;
			this->ShowChoiceComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Author", L"Name and date", L"Register number" });
			this->ShowChoiceComboBox->Location = System::Drawing::Point(93, 45);
			this->ShowChoiceComboBox->Name = L"ShowChoiceComboBox";
			this->ShowChoiceComboBox->Size = System::Drawing::Size(172, 24);
			this->ShowChoiceComboBox->TabIndex = 2;
			this->ShowChoiceComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyShowForm::ShowChoiceComboBox_SelectedIndexChanged);
			// 
			// TextBox1
			// 
			this->TextBox1->Location = System::Drawing::Point(93, 95);
			this->TextBox1->Name = L"TextBox1";
			this->TextBox1->Size = System::Drawing::Size(172, 22);
			this->TextBox1->TabIndex = 3;
			this->TextBox1->Hide();
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(133, 191);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(71, 23);
			this->SearchButton->TabIndex = 4;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyShowForm::SearchButton_Click);
			// 
			// TextBox2
			// 
			this->TextBox2->Location = System::Drawing::Point(93, 140);
			this->TextBox2->Name = L"TextBox2";
			this->TextBox2->Size = System::Drawing::Size(172, 22);
			this->TextBox2->TabIndex = 5;
			this->TextBox2->Hide();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			this->label1->Hide();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			this->label2->Hide();
			// 
			// MyShowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(374, 290);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TextBox2);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->TextBox1);
			this->Controls->Add(this->ShowChoiceComboBox);
			this->Name = L"MyShowForm";
			this->Text = L"MyShowForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    // Done

	private: System::Void ShowChoiceComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->TextBox1->Hide();
		this->TextBox2->Hide();
		this->label1->Hide();
		this->label2->Hide();
		this->TextBox1->AutoCompleteCustomSource->Clear();
		this->TextBox2->AutoCompleteCustomSource->Clear();

		switch (this->ShowChoiceComboBox->SelectedIndex)
		{
		case 0:
		{
			this->TextBox1->Show();
			this->label1->Show();
			this->label1->Text = "Author";
			this->TextBox1->AutoCompleteSource = AutoCompleteSource::CustomSource;
			this->TextBox1->AutoCompleteMode = AutoCompleteMode::SuggestAppend;

			array<String^>^ arr = gcnew array<String^>  (list->GetSize());

			for (int i = 0; i < list->GetSize(); i++) arr[i]=msclr::interop::marshal_as<String^>((*list)[i].GetAuthor());
			
			this->TextBox1->AutoCompleteCustomSource->AddRange(arr);

			break;
		}
		case 1:
		{
			this->TextBox1->Show();
			this->TextBox2->Show();
			this->label1->Show();
			this->label1->Text = "Name";
			this->label2->Show();
			this->label2->Text = "Date";
			this->TextBox1->AutoCompleteSource = AutoCompleteSource::CustomSource;
			this->TextBox1->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
			this->TextBox2->AutoCompleteSource = AutoCompleteSource::CustomSource;
			this->TextBox2->AutoCompleteMode = AutoCompleteMode::SuggestAppend;

			array<String^>^ arr1 = gcnew array<String^>(list->GetSize());
			array<String^>^ arr2 = gcnew array<String^>(list->GetSize());

			for (int i = 0; i < list->GetSize(); i++)
			{
				arr1[i] = msclr::interop::marshal_as<String^>((*list)[i].GetName());
				arr2[i] = Convert::ToString((*list)[i].GetDate());
			}

			this->TextBox1->AutoCompleteCustomSource->AddRange(arr1);
			this->TextBox2->AutoCompleteCustomSource->AddRange(arr2);

			break;
		}
		case 2:
		{

			this->TextBox1->Show();
			this->label1->Show();
			this->label1->Text = "Reg num";
			this->TextBox1->AutoCompleteSource = AutoCompleteSource::CustomSource;
			this->TextBox1->AutoCompleteMode = AutoCompleteMode::SuggestAppend;

			array<String^>^ arr = gcnew array<String^>(list->GetSize());

			for (int i = 0; i < list->GetSize(); i++)arr[i] = Convert::ToString((*list)[i].GetRegnum());
			
			this->TextBox1->AutoCompleteCustomSource->AddRange(arr);

			break;
		}
		}
	}

	// Done

    private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {

	switch (this->ShowChoiceComboBox->SelectedIndex)
	{
	case 0:
	{
		for (int i = 0; i < list->GetSize(); i++)
		{
			if (this->TextBox1->Text->ToString() == msclr::interop::marshal_as<String^>((*list)[i].GetAuthor()))
			{
				if (Result == nullptr)Result = new Library<Info>;
				Result->push_back((*list)[i]);
			}
		}
		break;
	}
	case 1:
	{
		for (int i = 0; i < list->GetSize(); i++)
		{
			if (this->TextBox1->Text->ToString() == msclr::interop::marshal_as<String^>((*list)[i].GetName()) && this->TextBox2->Text->ToString() == Convert::ToString((*list)[i].GetDate()))
			{
				if (Result == nullptr)Result = new Library<Info>;
				Result->push_back((*list)[i]);
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < list->GetSize(); i++)
		{
			if (this->TextBox1->Text->ToString() == Convert::ToString((*list)[i].GetRegnum()))
			{
				if (Result == nullptr)Result = new Library<Info>;
				Result->push_back((*list)[i]);
			}
		}
		break;
	}
	}

	if (Result == nullptr)MessageBox::Show(this, "Nothing found", "Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Information);
	else MessageBox::Show(this, "Successfully found", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	Close();

}

};
}