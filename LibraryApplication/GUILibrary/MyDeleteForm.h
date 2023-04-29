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

	public ref class MyDeleteForm : public System::Windows::Forms::Form
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
	private: System::Windows::Forms::Button^ DeleteButton;
	protected:


	private: System::Windows::Forms::RichTextBox^ DeleteMemoBox;


	protected:

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->DeleteComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->DeleteMemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// DeleteComboBox
			// 
			this->DeleteComboBox->FormattingEnabled = true;
			this->DeleteComboBox->Location = System::Drawing::Point(95, 42);
			this->DeleteComboBox->Name = L"DeleteComboBox";
			this->DeleteComboBox->Size = System::Drawing::Size(163, 24);
			this->DeleteComboBox->TabIndex = 0;
			this->DeleteComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyDeleteForm::DeleteComboBox_SelectedIndexChanged);
			this->DeleteComboBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyDeleteForm::DeleteComboBox_MouseClick);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(138, 266);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(75, 23);
			this->DeleteButton->TabIndex = 1;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MyDeleteForm::DeleteButton_Click);
			// 
			// DeleteMemoBox
			// 
			this->DeleteMemoBox->Location = System::Drawing::Point(95, 87);
			this->DeleteMemoBox->Name = L"DeleteMemoBox";
			this->DeleteMemoBox->ReadOnly = true;
			this->DeleteMemoBox->Size = System::Drawing::Size(163, 164);
			this->DeleteMemoBox->TabIndex = 2;
			this->DeleteMemoBox->Text = L"";
			// 
			// MyDeleteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(336, 301);
			this->Controls->Add(this->DeleteMemoBox);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->DeleteComboBox);
			this->Name = L"MyDeleteForm";
			this->Text = L"MyDeleteForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	
	private: System::Void DeleteComboBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		this->DeleteComboBox->Items->Clear();

		for (int i = 0; i < list->GetSize(); i++)
		{
			this->DeleteComboBox->Items->Add(Convert::ToString((*list)[i].GetRegnum()));
		}

	}
private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show(this, "Are you sure?", "Attention", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
	{
		for (int i = 0; i < list->GetSize(); i++)
		{

			if (this->DeleteComboBox->SelectedIndex == i)
			{

				int size = list->GetSize() - ++i;
				Info* extra = new Info[size];

				for (int j = 0; j < size; j++, i++)extra[j] = (*list)[i];

				for (int j = 0; j <= size; j++)list->pop_back();

				if (this->DeleteComboBox->SelectedIndex == 0)delete list,list=nullptr, list = new Library<Info>;

				for (int j = 0; j < size; j++)list->push_back(extra[j]);

				delete[] extra, extra=nullptr;

			}

		}

		MessageBox::Show(this, "Successfully deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		Close();

	}

}

	   // Done

private: System::Void DeleteComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	this->DeleteMemoBox->Clear();

	for (int i = 0; i < list->GetSize(); i++)
	{
		if (this->DeleteComboBox->SelectedIndex == i)
		{
			this->DeleteMemoBox->AppendText(Convert::ToString((*list)[i].GetRegnum()) + "\n");
			this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[i].GetAuthor()) + "\n");
			this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[i].GetName()) + "\n");
			this->DeleteMemoBox->AppendText(Convert::ToString((*list)[i].GetDate()) + "\n");
			this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[i].GetOffice()) + "\n");
			this->DeleteMemoBox->AppendText(Convert::ToString((*list)[i].GetAmount()));
			this->DeleteMemoBox->Show();
			break;
		}
	}

}

};
}