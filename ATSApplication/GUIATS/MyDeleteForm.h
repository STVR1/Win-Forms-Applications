#pragma once

#include"ATSForm.h"
#include<msclr/marshal_cppstd.h>

namespace GUIATS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MyDeleteForm : public System::Windows::Forms::Form
	{
	private:

		ATS<Info>* list = nullptr;

		ATS<int>* arr = new ATS<int>;

	public:

		void SetList(ATS<Info>* list)
		{
			this->list = list;
		}

		ATS<Info>* GetList()
		{
			return this->list;
		}

		MyDeleteForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyDeleteForm()
		{

			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ComboBox^ DeleteComboBox;
	protected:
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::ComboBox^ DateComboBox;
	private: System::Windows::Forms::RichTextBox^ DeleteMemoBox;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->DeleteComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->DateComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteMemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// DeleteComboBox
			// 
			this->DeleteComboBox->FormattingEnabled = true;
			this->DeleteComboBox->Location = System::Drawing::Point(78, 12);
			this->DeleteComboBox->Name = L"DeleteComboBox";
			this->DeleteComboBox->Size = System::Drawing::Size(175, 24);
			this->DeleteComboBox->TabIndex = 0;
			this->DeleteComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyDeleteForm::DeleteComboBox_SelectedIndexChanged);
			this->DeleteComboBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyDeleteForm::DeleteComboBox_MouseClick);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(122, 282);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(75, 23);
			this->DeleteButton->TabIndex = 1;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MyDeleteForm::DeleteButton_Click);
			// 
			// DateComboBox
			// 
			this->DateComboBox->FormattingEnabled = true;
			this->DateComboBox->Location = System::Drawing::Point(78, 65);
			this->DateComboBox->Name = L"DateComboBox";
			this->DateComboBox->Size = System::Drawing::Size(175, 24);
			this->DateComboBox->TabIndex = 2;
			this->DateComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyDeleteForm::DateComboBox_SelectedIndexChanged);
			// 
			// DeleteMemoBox
			// 
			this->DeleteMemoBox->Location = System::Drawing::Point(78, 116);
			this->DeleteMemoBox->Name = L"DeleteMemoBox";
			this->DeleteMemoBox->ReadOnly = true;
			this->DeleteMemoBox->Size = System::Drawing::Size(175, 150);
			this->DeleteMemoBox->TabIndex = 3;
			this->DeleteMemoBox->Text = L"";
			// 
			// MyDeleteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 328);
			this->Controls->Add(this->DeleteMemoBox);
			this->Controls->Add(this->DateComboBox);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->DeleteComboBox);
			this->Name = L"MyDeleteForm";
			this->Text = L"MyDeleteForm";
			this->ResumeLayout(false);

		}

#pragma endregion

    // Done

	private: System::Void DeleteComboBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		this->DeleteMemoBox->Clear();

		this->DeleteComboBox->Items->Clear();

		for (int i = 0; i < list->Size(); i++)
			for (int j = 0; j <= i; j++)
			{
				if(i==j)this->DeleteComboBox->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetCustomnumber()));
				if((*list)[i].GetCustomnumber()==(*list)[j].GetCustomnumber())break;
			}

	}

    // Done

	private: System::Void DeleteComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->DateComboBox->Items->Clear();

		for (int i = 0; i < list->Size(); i++)
		{
			if (this->DeleteComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>((*list)[i].GetCustomnumber()))
				this->DateComboBox->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetDate())), arr->push_back(i);
		}

	}

	// Done

    private: System::Void DateComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		int index = (*arr)[this->DateComboBox->SelectedIndex];

		this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[index].GetDate()) + "\n");
		this->DeleteMemoBox->AppendText(Convert::ToString((*list)[index].GetCode()) + "\n");
		this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[index].GetDate()) + "\n");
		this->DeleteMemoBox->AppendText(Convert::ToString((*list)[index].GetTime()) + "\n");
		this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[index].GetRate()) + "\n");
		this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[index].GetCitynumber()) + "\n");
		this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[index].GetCustomnumber()) + "\n");

    }

    // Done

    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->DateComboBox->SelectedItem == nullptr || this->DeleteComboBox->SelectedItem == nullptr)
		{
			MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		ATS<Info> newlist=ATS<Info>();

		for (int i = (*arr)[this->DateComboBox->SelectedIndex]+1; i < list->Size(); i++) newlist.push_back((*list)[i]);

		for (int i = list->Size() - 1; i >= (*arr)[this->DateComboBox->SelectedIndex]; i--)list->pop_back();

		for (int i = 0; i < newlist.Size(); i++)list->push_back(newlist[i]);

		MessageBox::Show(this, "Successfully deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		while (arr->Size() != 0)arr->pop_back();

		delete arr;

		Close();

    }
};
}