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

	public ref class MyDeleteForm : public System::Windows::Forms::Form
	{

	private:

		Tree<int, std::string>* tree=nullptr;
	private: System::Windows::Forms::ComboBox^ ChoiceComboBox;
		   Pair<int, std::string>* temp = nullptr;

	public:

		void SetTree(Tree<int, std::string>* tree)
		{
			this->tree = tree;
		}

		Tree<int, std::string>* GetTree()
		{
			return this->tree;
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
	private: System::Windows::Forms::RichTextBox^ DeleteMemoBox;
	private: System::Windows::Forms::Button^ DeleteButton;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->DeleteComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteMemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->ChoiceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// DeleteComboBox
			// 
			this->DeleteComboBox->FormattingEnabled = true;
			this->DeleteComboBox->Location = System::Drawing::Point(82, 75);
			this->DeleteComboBox->Name = L"DeleteComboBox";
			this->DeleteComboBox->Size = System::Drawing::Size(177, 24);
			this->DeleteComboBox->TabIndex = 0;
			this->DeleteComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyDeleteForm::DeleteComboBox_SelectedIndexChanged);
			// 
			// DeleteMemoBox
			// 
			this->DeleteMemoBox->Enabled = false;
			this->DeleteMemoBox->Location = System::Drawing::Point(82, 138);
			this->DeleteMemoBox->Name = L"DeleteMemoBox";
			this->DeleteMemoBox->ReadOnly = true;
			this->DeleteMemoBox->Size = System::Drawing::Size(177, 63);
			this->DeleteMemoBox->TabIndex = 1;
			this->DeleteMemoBox->Text = L"";
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(115, 259);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(98, 43);
			this->DeleteButton->TabIndex = 2;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MyDeleteForm::DeleteButton_Click);
			// 
			// ChoiceComboBox
			// 
			this->ChoiceComboBox->FormattingEnabled = true;
			this->ChoiceComboBox->Location = System::Drawing::Point(82, 24);
			this->ChoiceComboBox->Name = L"ChoiceComboBox";
			this->ChoiceComboBox->Size = System::Drawing::Size(178, 24);
			this->ChoiceComboBox->TabIndex = 3;
			this->ChoiceComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyDeleteForm::ChoiceComboBox_SelectedIndexChanged);
			// 
			// MyDeleteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 331);
			this->Controls->Add(this->ChoiceComboBox);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->DeleteMemoBox);
			this->Controls->Add(this->DeleteComboBox);
			this->Name = L"MyDeleteForm";
			this->Text = L"MyDeleteForm";
			this->Load += gcnew System::EventHandler(this, &MyDeleteForm::MyDeleteForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyDeleteForm_Load(System::Object^ sender, System::EventArgs^ e) {

		temp = tree->Inorder();

		for (int i = 0; i < tree->Size(); i++) this->DeleteComboBox->Items->Add(Convert::ToString(temp[i].first)); 

		this->ChoiceComboBox->Items->Add("Node");
		this->ChoiceComboBox->Items->Add("Tree");
		
		this->DeleteMemoBox->Hide();
		this->DeleteComboBox->Hide();

		this->DeleteComboBox->DropDownStyle = ComboBoxStyle::DropDownList;
		this->ChoiceComboBox->DropDownStyle = ComboBoxStyle::DropDownList;

	}

	private: System::Void ChoiceComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->DeleteMemoBox->Hide();
		this->DeleteComboBox->Hide();

		if (this->ChoiceComboBox->SelectedIndex == 0) this->DeleteComboBox->Show();

	}

	private: System::Void DeleteComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		this->DeleteMemoBox->Clear();
		this->DeleteMemoBox->Show();
		this->DeleteMemoBox->AppendText(this->DeleteComboBox->SelectedItem->ToString() + "\n");
		this->DeleteMemoBox->AppendText(msclr::interop::marshal_as<String^>(temp[this->DeleteComboBox->SelectedIndex].second));

	}
	
    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->ChoiceComboBox->SelectedItem==nullptr)
		{
			MessageBox::Show(this,"Incorrect choice","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (this->ChoiceComboBox->SelectedIndex == 0 && this->DeleteComboBox->SelectedItem == nullptr)
		{
			MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (MessageBox::Show(this, "Are you sure?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		{

			if (this->ChoiceComboBox->SelectedIndex == 0) tree->Delete(Convert::ToInt32(this->DeleteComboBox->SelectedItem->ToString()));
			else tree->Clear();

			MessageBox::Show(this, "Successfully deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			
			delete[] temp, temp = nullptr;

			Close();
		}

    }

};
}