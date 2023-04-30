#pragma once

#include<msclr/marshal_cppstd.h>

#include"..\ClassATS\ClassATS.h"
#include"..\ClassATS\ClassInfo.h"

#include"MyAddForm.h"
#include"MyDeleteForm.h"
#include"MySortForm.h"
#include"MySearchForm.h"

namespace GUIATS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class ATSForm : public System::Windows::Forms::Form
	{
	private:

		ATS<Info>* list = new ATS<Info>();

	public:

		ATSForm(void)
		{
			InitializeComponent();
		}

	protected:

		~ATSForm()
		{
			list->clear();
			delete list;
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ SaveFileDialog;
	protected:

	protected:

	private: System::Windows::Forms::Button^ ReadButton;
	private: System::Windows::Forms::ListView^ MainListView;
	private: System::Windows::Forms::Button^ ShowAllButton;
	private: System::Windows::Forms::Button^ SortButton;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::RichTextBox^ PatternMemoBox;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->ReadButton = (gcnew System::Windows::Forms::Button());
			this->MainListView = (gcnew System::Windows::Forms::ListView());
			this->ShowAllButton = (gcnew System::Windows::Forms::Button());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->PatternMemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// ReadButton
			// 
			this->ReadButton->Location = System::Drawing::Point(214, 26);
			this->ReadButton->Name = L"ReadButton";
			this->ReadButton->Size = System::Drawing::Size(75, 23);
			this->ReadButton->TabIndex = 0;
			this->ReadButton->Text = L"Read";
			this->ReadButton->UseVisualStyleBackColor = true;
			this->ReadButton->Click += gcnew System::EventHandler(this, &ATSForm::ReadButton_Click);
			// 
			// MainListView
			// 
			this->MainListView->HideSelection = false;
			this->MainListView->Location = System::Drawing::Point(12, 12);
			this->MainListView->Name = L"MainListView";
			this->MainListView->Size = System::Drawing::Size(177, 385);
			this->MainListView->TabIndex = 1;
			this->MainListView->UseCompatibleStateImageBehavior = false;
			// 
			// ShowAllButton
			// 
			this->ShowAllButton->Location = System::Drawing::Point(322, 26);
			this->ShowAllButton->Name = L"ShowAllButton";
			this->ShowAllButton->Size = System::Drawing::Size(75, 23);
			this->ShowAllButton->TabIndex = 2;
			this->ShowAllButton->Text = L"Show all";
			this->ShowAllButton->UseVisualStyleBackColor = true;
			this->ShowAllButton->Click += gcnew System::EventHandler(this, &ATSForm::ShowAllButton_Click);
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(214, 64);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(75, 23);
			this->SortButton->TabIndex = 3;
			this->SortButton->Text = L"Sort";
			this->SortButton->UseVisualStyleBackColor = true;
			this->SortButton->Click += gcnew System::EventHandler(this, &ATSForm::SortButton_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(322, 64);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(75, 23);
			this->SearchButton->TabIndex = 4;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &ATSForm::SearchButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(214, 104);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 23);
			this->AddButton->TabIndex = 5;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &ATSForm::AddButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(322, 104);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(75, 23);
			this->DeleteButton->TabIndex = 6;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &ATSForm::DeleteButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(214, 148);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(183, 23);
			this->SaveButton->TabIndex = 7;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &ATSForm::SaveButton_Click);
			// 
			// PatternMemoBox
			// 
			this->PatternMemoBox->Location = System::Drawing::Point(214, 272);
			this->PatternMemoBox->Name = L"PatternMemoBox";
			this->PatternMemoBox->ReadOnly = true;
			this->PatternMemoBox->Size = System::Drawing::Size(183, 125);
			this->PatternMemoBox->TabIndex = 8;
			this->PatternMemoBox->Text = L"Date\nCode\nCity\nTime in sceonds\nRate\nCity number\nCustom number";
			// 
			// ATSForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 409);
			this->Controls->Add(this->PatternMemoBox);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->SortButton);
			this->Controls->Add(this->ShowAllButton);
			this->Controls->Add(this->MainListView);
			this->Controls->Add(this->ReadButton);
			this->Name = L"ATSForm";
			this->Text = L"ATSForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	// Done

	private: System::Void ReadButton_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ filename = "";
		String^ line = "";
		Info info;
		int i = 0;

		if (OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			filename = OpenFileDialog->FileName;

			try
			{

				StreamReader^ file=gcnew StreamReader(filename);

				while (file->Peek() >= 0)
				{

					line=file->ReadLine();
					while (line == "")line = file->ReadLine();

					switch (i)
					{
					case 0:
					{
						info.SetDate(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 1:
					{
						info.SetCode(Convert::ToInt32(line)), i++;
						break;
					}
					case 2:
					{
						info.SetCity(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 3:
					{
						info.SetTime(Convert::ToInt32(line)), i++;
						break;
					}
					case 4:
					{
						info.SetRate(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 5:
					{
						info.SetCitynumber(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 6:
					{
						info.SetCustomnumber(msclr::interop::marshal_as<std::string>(line)), i++;
						list->push_back(info), i=0;
						break;
					}
					}

				}

				file->Close();

				if (list->Size() != 0)MessageBox::Show(this, "Successfully read", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch(Exception^ e)
			{
				MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}

	}

	// Done

    private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (list->Size() == 0)
		{
			MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ filename = "";

		if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			filename = SaveFileDialog->FileName;
			try
			{

				StreamWriter^ file = gcnew StreamWriter(filename);

				for (int i = 0; i < list->Size(); i++)
				{
					file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetDate()));
					file->WriteLine(Convert::ToString((*list)[i].GetCode()));
					file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetCity()));
					file->WriteLine(Convert::ToString((*list)[i].GetTime()));
					file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetRate()));
					file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetCitynumber()));
					file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetCustomnumber())+"\n");
				}

				file->Close();

				MessageBox::Show(this, "Successfully saved", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			}
			catch (Exception^ e)
			{
				MessageBox::Show(this, "", "", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

    }

    // Done

    private: System::Void ShowAllButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MainListView->Clear();

		if (list->Size() == 0)
		{
			MessageBox::Show(this, "Empty list", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		ColumnHeader^ col = gcnew ColumnHeader();
		this->MainListView->Columns->Add(col);
		this->MainListView->Scrollable = true;
		this->MainListView->HeaderStyle = ColumnHeaderStyle::None;

		for (int i = 0; i < list->Size(); i++)
		{
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetDate()));
			this->MainListView->Items->Add(Convert::ToString((*list)[i].GetCode()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetCity()));
			this->MainListView->Items->Add(Convert::ToString((*list)[i].GetTime()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetRate()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetCitynumber()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*list)[i].GetCustomnumber()));
			this->MainListView->Items->Add("");
		}

		this->MainListView->View = View::Details;
		this->MainListView->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

    }

	// Done

    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (list->Size() == 0)
		{
			MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		MyDeleteForm newform;

		newform.SetList(list);

		newform.ShowDialog();

		list=newform.GetList();

		if (list->Size() == 0)MessageBox::Show(this, "Your list is empty", "Attention", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    
	}

	// Done

    private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MainListView->Clear();

		if (list->Size() == 0)
		{
			MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		MySearchForm newform;

		newform.SetList(list);

		newform.ShowDialog();

		ColumnHeader^ col = gcnew ColumnHeader();

		this->MainListView->Columns->Add(col);
		this->MainListView->Scrollable = true;
		this->MainListView->HeaderStyle = ColumnHeaderStyle::None;

		for (int i = 0; i < newform.GetList()->Size(); i++)
		{
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*newform.GetList())[i].GetDate()));
			this->MainListView->Items->Add(Convert::ToString((*newform.GetList())[i].GetCode()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*newform.GetList())[i].GetCity()));
			this->MainListView->Items->Add(Convert::ToString((*newform.GetList())[i].GetTime()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*newform.GetList())[i].GetRate()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*newform.GetList())[i].GetCitynumber()));
			this->MainListView->Items->Add(msclr::interop::marshal_as<String^>((*newform.GetList())[i].GetCustomnumber()));
			this->MainListView->Items->Add("");
		}

		this->MainListView->View = View::Details;
		this->MainListView->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

		newform.GetList()->clear();
		delete newform.GetList();

    }

	// Done

    private: System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e) {

	if (list->Size() == 0)
	{
		MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	MySortForm newform;

	newform.SetList(list);

	newform.ShowDialog();

	list=newform.GetList();

    }

	// Done

    private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		MyAddForm newform;

		newform.SetList(list);

		newform.ShowDialog();

		list=newform.GetList();

    }
};
}