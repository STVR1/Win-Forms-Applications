#pragma once

#include"..\BinaryTree\TreeClass.h"

namespace GUITree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MySearchForm : public System::Windows::Forms::Form
	{

	private:

		Tree<int, std::string>* tree=nullptr;
		Pair<int, std::string>* temp = nullptr;
		Pair<int, std::string>* searched = nullptr;

	public:

		void SetTree(Tree<int, std::string>* tree)
		{
			this->tree = tree;
		}

		Pair<int, std::string>* GetPair()
		{
			return this->searched;
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

	private: System::Windows::Forms::TextBox^ SearchTextBox;
	protected:
	private: System::Windows::Forms::Label^ SearchLabel;
	private: System::Windows::Forms::Button^ SearchButton;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->SearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchLabel = (gcnew System::Windows::Forms::Label());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SearchTextBox
			// 
			this->SearchTextBox->Location = System::Drawing::Point(32, 104);
			this->SearchTextBox->Name = L"SearchTextBox";
			this->SearchTextBox->Size = System::Drawing::Size(177, 22);
			this->SearchTextBox->TabIndex = 0;
			// 
			// SearchLabel
			// 
			this->SearchLabel->AutoSize = true;
			this->SearchLabel->Location = System::Drawing::Point(29, 70);
			this->SearchLabel->Name = L"SearchLabel";
			this->SearchLabel->Size = System::Drawing::Size(180, 16);
			this->SearchLabel->TabIndex = 1;
			this->SearchLabel->Text = L"Input the number of password";
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(58, 151);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(119, 46);
			this->SearchButton->TabIndex = 2;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MySearchForm::SearchButton_Click);
			// 
			// MySearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 241);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->SearchLabel);
			this->Controls->Add(this->SearchTextBox);
			this->Name = L"MySearchForm";
			this->Text = L"MySearchForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		int value = 0;

		if (!int::TryParse(this->SearchTextBox->Text->ToString(), value))
		{
			MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		value = int::Parse(this->SearchTextBox->Text->ToString());
		
		if (1000000 < value || value < 99999)
		{
			MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		searched = tree->Find(value);

		if (searched == nullptr) MessageBox::Show(this, "Unsuccessfully found", "Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::None);
		else {
			MessageBox::Show(this, "Successfully found", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Close();
		}

	}
	
};
}