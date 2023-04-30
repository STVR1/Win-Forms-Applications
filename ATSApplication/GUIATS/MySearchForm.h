#pragma once

#include<msclr/marshal_cppstd.h>

#include"ATSForm.h"

namespace GUIATS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MySearchForm : public System::Windows::Forms::Form
	{

	private:

		ATS<Info>* list = nullptr;
		ATS<Info>* result=new ATS<Info>();

	public:

		void SetList(ATS<Info>* list)
		{
			this->list = list;
		}

		ATS<Info>* GetList()
		{
			return result;
		}

		MySearchForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MySearchForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ComboBox^ SearchComboBox;
	protected:
	private: System::Windows::Forms::Label^ SearchLabel;
	private: System::Windows::Forms::TextBox^ SearchTextBox;
	private: System::Windows::Forms::Button^ SearchButton;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->SearchComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SearchLabel = (gcnew System::Windows::Forms::Label());
			this->SearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SearchComboBox
			// 
			this->SearchComboBox->FormattingEnabled = true;
			this->SearchComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"City", L"Custom number" });
			this->SearchComboBox->Location = System::Drawing::Point(72, 84);
			this->SearchComboBox->Name = L"SearchComboBox";
			this->SearchComboBox->Size = System::Drawing::Size(190, 24);
			this->SearchComboBox->TabIndex = 0;
			this->SearchComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MySearchForm::SearchComboBox_SelectedIndexChanged);
			// 
			// SearchLabel
			// 
			this->SearchLabel->AutoSize = true;
			this->SearchLabel->Location = System::Drawing::Point(12, 166);
			this->SearchLabel->Name = L"SearchLabel";
			this->SearchLabel->Size = System::Drawing::Size(44, 16);
			this->SearchLabel->TabIndex = 1;
			this->SearchLabel->Text = L"label1";
			this->SearchLabel->Hide();
			// 
			// SearchTextBox
			// 
			this->SearchTextBox->Location = System::Drawing::Point(88, 166);
			this->SearchTextBox->Name = L"SearchTextBox";
			this->SearchTextBox->Size = System::Drawing::Size(155, 22);
			this->SearchTextBox->TabIndex = 3;
			this->SearchTextBox->Hide();
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(112, 251);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(75, 23);
			this->SearchButton->TabIndex = 4;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MySearchForm::SearchButton_Click);
			// 
			// MySearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 340);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->SearchTextBox);
			this->Controls->Add(this->SearchLabel);
			this->Controls->Add(this->SearchComboBox);
			this->Name = L"MySearchForm";
			this->Text = L"MySearchForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    // Done

	 private: System::Void SearchComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		 this->SearchTextBox->AutoCompleteCustomSource->Clear();
		 this->SearchTextBox->AutoCompleteSource = AutoCompleteSource::CustomSource;
		 this->SearchTextBox->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
		 array<String^>^ arr = gcnew array<String^>(0);
		 int size = 0;

		 if (this->SearchComboBox->SelectedIndex == 0)
		 {
			 this->SearchLabel->Text = "City";

			 for (int i = 0; i < list->Size(); i++)
				 for (int j = 0; j <= i; j++)
				 {
					 if (i == j)
					 {
						 arr->Resize(arr, size + 1);
						 arr[size++] = msclr::interop::marshal_as<String^>((*list)[i].GetCity());
					 }
					 if ((*list)[i].GetCity() == (*list)[j].GetCity())break;
				 }



		 }
		 else
		 {
			 this->SearchLabel->Text = "Number";

			 for (int i = 0; i < list->Size(); i++)
				 for (int j = 0; j <= i; j++)
				 {
					 if (i == j)
					 {
						 arr->Resize(arr, size + 1);
						 arr[size++] = msclr::interop::marshal_as<String^>((*list)[i].GetCustomnumber());
					 }
					 if ((*list)[i].GetCustomnumber() == (*list)[j].GetCustomnumber())break;
				 }

		 }

		 this->SearchTextBox->AutoCompleteCustomSource->AddRange(arr);
		 this->SearchTextBox->Show();
		 this->SearchLabel->Show();

	 }

	// Done

	 private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		 if (this->SearchComboBox->SelectedItem == nullptr)
		 {
			 MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 return;
		 }

		 if (this->SearchTextBox->SelectedText == nullptr)
		 {
			 MessageBox::Show(this, "Empty text", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 return;
		 }

		 if (this->SearchComboBox->SelectedIndex == 0)
		 {
			 for (int i = 0; i < list->Size(); i++)
				 if (this->SearchTextBox->Text->ToString() == msclr::interop::marshal_as<String^>((*list)[i].GetCity())) result->push_back((*list)[i]);
		 }
		 else
		 {
			 for (int i = 0; i < list->Size(); i++)
				 if (this->SearchTextBox->Text->ToString() == msclr::interop::marshal_as<String^>((*list)[i].GetCustomnumber())) result->push_back((*list)[i]);
		 }

		 if (result->Size() == 0)MessageBox::Show(this, "Nothing found", "Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 else MessageBox::Show(this, "Successfully found", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		 Close();

     }
};
}