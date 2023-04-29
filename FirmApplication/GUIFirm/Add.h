#pragma once
#include"..\ClassFirm\Firm.h"
#include<msclr/marshal_cppstd.h>
#include<regex>

namespace GUIFirm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Add : public System::Windows::Forms::Form
	{
	private:

		Firm* List = NULL;
		int size = 0;

	public:

		void SetList(Firm* List)
		{
			this->List = List;
		}

		void SetSize(int size)
		{
			this->size = size;
		}

		Firm* GetList()
		{
			return List;
		}

		int GetSize()
		{
			return size;
		}

		Add(void)
		{
			InitializeComponent();
		}

	protected:

		~Add()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ AddRichTextBox;
	private: System::Windows::Forms::Button^ SaveButton;
	protected:

	protected:


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->AddRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// AddRichTextBox
			// 
			this->AddRichTextBox->Location = System::Drawing::Point(80, 29);
			this->AddRichTextBox->Name = L"AddRichTextBox";
			this->AddRichTextBox->Size = System::Drawing::Size(248, 267);
			this->AddRichTextBox->TabIndex = 0;
			this->AddRichTextBox->Text = L"";
			this->AddRichTextBox->TextChanged += gcnew System::EventHandler(this, &Add::AddRichTextBox_TextChanged);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(165, 329);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 1;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &Add::SaveButton_Click);
			// 
			// Add
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 427);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->AddRichTextBox);
			this->Name = L"Add";
			this->Text = L"AddForm";
			this->ResumeLayout(false);

		}
#pragma endregion

    // Done

	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (MessageBox::Show(this, "Are you sure?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
		{
			if (this->AddRichTextBox->Lines->Length == 7)
			{
				std::regex date("^([0-9]{2}[.]{1}){2}([0-9]{4}){1}$");

				if (std::regex_match(msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[5]->ToString()), date) && std::regex_match(msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[6]->ToString()), date))
				{

					Firm* newlist = new Firm[++size];
					for (int i = 0; i < size - 1; i++)newlist[i] = List[i];
					delete[]List, List = nullptr;

					std::string info[7];
					info[0] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[0]->ToString());
					info[1] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[1]->ToString());
					info[2] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[2]->ToString());
					info[3] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[3]->ToString());
					info[4] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[4]->ToString());
					info[5] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[5]->ToString());
					info[6] = msclr::interop::marshal_as<std::string>(this->AddRichTextBox->Lines[6]->ToString());

					newlist[size - 1].SetInfo(info);
					List = newlist;

					MessageBox::Show(this, "Successfully added", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

					Close();

				}
				else MessageBox::Show(this, "Incorrect lines", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else MessageBox::Show(this, "Incorrect amount of lines", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	private: System::Void AddRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }

	};
}