#pragma once
#include"..\ClassFirm\Firm.h"
#include"FirmForm.h"
#include<msclr/marshal_cppstd.h>
#include<regex>

namespace GUIFirm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class EditForm : public System::Windows::Forms::Form
	{
	private: 

		Firm* List = NULL;
		int size = 0;

	public:


		void SetSize(int size)
		{
			this->size = size;
		}

		void SetList(Firm* List)
		{
			this->List = List;
		}
		

		EditForm(void)
		{
			InitializeComponent();
		}

	protected:
	
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::ComboBox^ ProjectComboBox;
	protected:
	private: System::Windows::Forms::RichTextBox^ InfoRichTextBox;
	private: System::Windows::Forms::ComboBox^ PersonComboBox;
	private: System::Windows::Forms::Button^ SaveChangesButton;

	protected:

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->ProjectComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->InfoRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->PersonComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SaveChangesButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ProjectComboBox
			// 
			this->ProjectComboBox->FormattingEnabled = true;
			this->ProjectComboBox->Location = System::Drawing::Point(126, 48);
			this->ProjectComboBox->Name = L"ProjectComboBox";
			this->ProjectComboBox->Size = System::Drawing::Size(182, 24);
			this->ProjectComboBox->TabIndex = 0;
			this->ProjectComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EditForm::ProjectComboBox_SelectedIndexChanged);
			// 
			// InfoRichTextBox
			// 
			this->InfoRichTextBox->Location = System::Drawing::Point(126, 157);
			this->InfoRichTextBox->Name = L"InfoRichTextBox";
			this->InfoRichTextBox->Size = System::Drawing::Size(182, 202);
			this->InfoRichTextBox->TabIndex = 1;
			this->InfoRichTextBox->Text = L"";
			this->InfoRichTextBox->TextChanged += gcnew System::EventHandler(this, &EditForm::InfoRichTextBox_TextChanged);
			this->InfoRichTextBox->ReadOnly = true;
			// 
			// PersonComboBox
			// 
			this->PersonComboBox->FormattingEnabled = true;
			this->PersonComboBox->Location = System::Drawing::Point(126, 98);
			this->PersonComboBox->Name = L"PersonComboBox";
			this->PersonComboBox->Size = System::Drawing::Size(182, 24);
			this->PersonComboBox->TabIndex = 2;
			this->PersonComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EditForm::PersonComboBox_SelectedIndexChanged);
			// 
			// SaveChangesButton
			// 
			this->SaveChangesButton->Location = System::Drawing::Point(176, 394);
			this->SaveChangesButton->Name = L"SaveChangesButton";
			this->SaveChangesButton->Size = System::Drawing::Size(75, 23);
			this->SaveChangesButton->TabIndex = 3;
			this->SaveChangesButton->Text = L"Save";
			this->SaveChangesButton->UseVisualStyleBackColor = true;
			this->SaveChangesButton->Click += gcnew System::EventHandler(this, &EditForm::SaveChangesButton_Click);
			// 
			// ReizeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(440, 438);
			this->Controls->Add(this->SaveChangesButton);
			this->Controls->Add(this->PersonComboBox);
			this->Controls->Add(this->InfoRichTextBox);
			this->Controls->Add(this->ProjectComboBox);
			this->Name = L"EditForm";
			this->Text = L"EditForm";
			this->ResumeLayout(false);
			
		}
#pragma endregion

		// Done

	private: System::Void ProjectComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		this->PersonComboBox->Items->Clear();
		this->InfoRichTextBox->Clear();

		for (int i = 0; i < this->ProjectComboBox->Items->Count; i++)
		{
			if (this->ProjectComboBox->SelectedIndex == i)
			{
				for (int j = 0; j < size; j++)
					if (this->ProjectComboBox->Items[i]->ToString() == msclr::interop::marshal_as<String^>(List[j].GetProjectName()))
						this->PersonComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[j].GetExecutor()));
				break;
			}
		}

	}

	    // Done

	private: System::Void PersonComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->InfoRichTextBox->Clear();

		for (int i = 0; i < this->PersonComboBox->Items->Count; i++)
		{
			if (this->PersonComboBox->SelectedIndex == i)
			{
				for(int j=0;j<size;j++)
					if (this->PersonComboBox->Items[i]->ToString() == msclr::interop::marshal_as<String^>(List[j].GetExecutor()))
					{
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetProjectName()) + "\n");
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetTask()) + "\n");
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetExecutor()) + "\n");
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetSupervisor()) + "\n");
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetDateOfIssue()) + "\n");
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetDeadLine()) + "\n");
						this->InfoRichTextBox->AppendText(msclr::interop::marshal_as<String^>(List[j].GetDateOfDelivery()));
						break;
					}
				break;
			}
		}
		this->InfoRichTextBox->ReadOnly = false;
	}

	   // Done

    private: System::Void SaveChangesButton_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show(this, "Are you sure?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning)== System::Windows::Forms::DialogResult::Yes)
	{
		if (this->InfoRichTextBox->Lines->Length == 7)
		{
			bool empty = false;

			for (int i = 0; i < 7; i++)if (this->InfoRichTextBox->Lines[i]->ToString()=="")
			{
				empty = true;
				break;
			}

			if (empty == false)
			{
				std::regex date("([0-9]{2}[.]{1}){2}([0-9]{4}){1}");

				if (std::regex_match(msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[5]->ToString()), date) && std::regex_match(msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[6]->ToString()), date))
				{

					for (int i = 0; i < this->ProjectComboBox->Items->Count; i++)
						for (int j = 0; j < size; j++)
							if (this->ProjectComboBox->Items[i]->ToString() == msclr::interop::marshal_as<String^>(List[j].GetProjectName()))
							{
								for (int k = 0; k < this->PersonComboBox->Items->Count; k++)
									if (this->PersonComboBox->Items[k]->ToString() == msclr::interop::marshal_as<String^>(List[j].GetExecutor()))
									{
										std::string info[7];
										info[0] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[0]->ToString());
										info[1] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[1]->ToString());
										info[2] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[2]->ToString());
										info[3] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[3]->ToString());
										info[4] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[4]->ToString());
										info[5] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[5]->ToString());
										info[6] = msclr::interop::marshal_as<std::string>(this->InfoRichTextBox->Lines[6]->ToString());
										List[j].SetInfo(info);

										break;
									}
								i = this->ProjectComboBox->Items->Count;
								break;
							}

					this->PersonComboBox->Items->Clear();
					this->ProjectComboBox->Items->Clear();
					this->InfoRichTextBox->Clear();
					this->InfoRichTextBox->ReadOnly = true;

					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j <= i; j++)
						{
							if (i == j)this->ProjectComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
							if (List[i].GetProjectName() == List[j].GetProjectName())break;
						}
					}

					MessageBox::Show(this, "Successfully edited", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				}
				else MessageBox::Show(this, "Incorrect editing", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else MessageBox::Show(this, "Empty lines", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else MessageBox::Show(this, "Incorrect amount of lines", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

}

	private: System::Void InfoRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

};
}