#pragma once

#include"..\ClassLibrary\ClassInfo.h"
#include"..\ClassLibrary\ClassLibrary.h"

#include"MyAddForm.h"
#include"MyDeleteForm.h"
#include"MyShowForm.h"
#include"MySortForm.h"

#include<msclr/marshal_cppstd.h>
namespace GUILibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class LibraryForm : public System::Windows::Forms::Form
	{
	public:

		Library<Info>* list=nullptr;

		LibraryForm(void)
		{
			InitializeComponent();
		}

	protected:

		~LibraryForm()
		{

			while (list->End() != nullptr)list->pop_back();

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ReadButton;
	protected:
	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;
	private: System::Windows::Forms::RichTextBox^ MemoBox;

	private: System::Windows::Forms::Button^ ShowAllButton;
	private: System::Windows::Forms::Button^ SearchMainButton;
	private: System::Windows::Forms::Button^ AddMainButton;
	private: System::Windows::Forms::Button^ DeleteMainButton;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::SaveFileDialog^ SaveFileDialog;
	private: System::Windows::Forms::Button^ SortButtons;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->ReadButton = (gcnew System::Windows::Forms::Button());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->MemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->ShowAllButton = (gcnew System::Windows::Forms::Button());
			this->SearchMainButton = (gcnew System::Windows::Forms::Button());
			this->AddMainButton = (gcnew System::Windows::Forms::Button());
			this->DeleteMainButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SortButtons = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ReadButton
			// 
			this->ReadButton->Location = System::Drawing::Point(119, 266);
			this->ReadButton->Name = L"ReadButton";
			this->ReadButton->Size = System::Drawing::Size(75, 23);
			this->ReadButton->TabIndex = 0;
			this->ReadButton->Text = L"Read";
			this->ReadButton->UseVisualStyleBackColor = true;
			this->ReadButton->Click += gcnew System::EventHandler(this, &LibraryForm::ReadButton_Click);
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->FileName = L"OpenFileDialog";
			// 
			// MemoBox
			// 
			this->MemoBox->Location = System::Drawing::Point(98, 22);
			this->MemoBox->Name = L"MemoBox";
			this->MemoBox->ReadOnly = true;
			this->MemoBox->Size = System::Drawing::Size(214, 197);
			this->MemoBox->TabIndex = 1;
			this->MemoBox->Text = L"";
			// 
			// ShowAllButton
			// 
			this->ShowAllButton->Location = System::Drawing::Point(215, 266);
			this->ShowAllButton->Name = L"ShowAllButton";
			this->ShowAllButton->Size = System::Drawing::Size(75, 23);
			this->ShowAllButton->TabIndex = 2;
			this->ShowAllButton->Text = L"Show all";
			this->ShowAllButton->UseVisualStyleBackColor = true;
			this->ShowAllButton->Click += gcnew System::EventHandler(this, &LibraryForm::ShowAllButton_Click);
			// 
			// SearchMainButton
			// 
			this->SearchMainButton->Location = System::Drawing::Point(119, 315);
			this->SearchMainButton->Name = L"SearchMainButton";
			this->SearchMainButton->Size = System::Drawing::Size(75, 23);
			this->SearchMainButton->TabIndex = 3;
			this->SearchMainButton->Text = L"Search";
			this->SearchMainButton->UseVisualStyleBackColor = true;
			this->SearchMainButton->Click += gcnew System::EventHandler(this, &LibraryForm::SearchMainButton_Click);
			// 
			// AddMainButton
			// 
			this->AddMainButton->Location = System::Drawing::Point(215, 315);
			this->AddMainButton->Name = L"AddMainButton";
			this->AddMainButton->Size = System::Drawing::Size(75, 23);
			this->AddMainButton->TabIndex = 4;
			this->AddMainButton->Text = L"Add";
			this->AddMainButton->UseVisualStyleBackColor = true;
			this->AddMainButton->Click += gcnew System::EventHandler(this, &LibraryForm::AddMainButton_Click);
			// 
			// DeleteMainButton
			// 
			this->DeleteMainButton->Location = System::Drawing::Point(119, 371);
			this->DeleteMainButton->Name = L"DeleteMainButton";
			this->DeleteMainButton->Size = System::Drawing::Size(75, 23);
			this->DeleteMainButton->TabIndex = 5;
			this->DeleteMainButton->Text = L"Delete";
			this->DeleteMainButton->UseVisualStyleBackColor = true;
			this->DeleteMainButton->Click += gcnew System::EventHandler(this, &LibraryForm::DeleteMainButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(119, 417);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(171, 23);
			this->SaveButton->TabIndex = 6;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &LibraryForm::SaveButton_Click);
			// 
			// SortButtons
			// 
			this->SortButtons->Location = System::Drawing::Point(215, 371);
			this->SortButtons->Name = L"SortButtons";
			this->SortButtons->Size = System::Drawing::Size(75, 23);
			this->SortButtons->TabIndex = 7;
			this->SortButtons->Text = L"Sort";
			this->SortButtons->UseVisualStyleBackColor = true;
			this->SortButtons->Click += gcnew System::EventHandler(this, &LibraryForm::SortButtons_Click);
			// 
			// LibraryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 462);
			this->Controls->Add(this->SortButtons);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->DeleteMainButton);
			this->Controls->Add(this->AddMainButton);
			this->Controls->Add(this->SearchMainButton);
			this->Controls->Add(this->ShowAllButton);
			this->Controls->Add(this->MemoBox);
			this->Controls->Add(this->ReadButton);
			this->Name = L"LibraryForm";
			this->Text = L"LibraryForm";
			this->ResumeLayout(false);

		}
#pragma endregion

    // Done

	private: System::Void ReadButton_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ filename = "";
		String^ line = "";
		Info info;
		bool repeat = false;
		int i = 0,
			k=0,
			size = 0,
			amount=0;

		if (OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			filename = OpenFileDialog->FileName;

			try
			{

				StreamReader^ file = gcnew StreamReader(filename);

				while (file->Peek() >= 0)
				{
					line = file->ReadLine();
					if (line != "")size++;
				}

				if (size != 0)if (list == nullptr)list = new Library<Info>;

				file->BaseStream->Seek(0, SeekOrigin::Begin);

				while (k < size)
				{
					line = file->ReadLine();
					while (line == "")line = file->ReadLine();
					switch (i)
					{
					case 0:
					{
						info.SetRegnum(Convert::ToInt32(line)), i++;
						break;
					}
					case 1:
					{
						info.SetAuthor(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 2:
					{
						info.SetName(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 3:
					{
						info.SetDate(Convert::ToInt32(line)), i++;
						break;
					}
					case 4:
					{
						info.SetOffice(msclr::interop::marshal_as<std::string>(line)), i++;
						break;
					}
					case 5:
					{
						info.SetAmount(Convert::ToInt32(line));
						list->push_back(info);
						i = 0;
						amount++;
						break;
					}
					}
					k++;
				}

				file->Close();

				if (list != nullptr)
				{

					for (int j = 0; j < list->GetSize(); j++)
						for (int d = 0; d < j; d++)
							if ((*list)[j].GetRegnum() == (*list)[d].GetRegnum())
							{
								repeat = true;
								j = list->GetSize();
								break;
							}

					if (repeat == false)MessageBox::Show(this, "Successfully read", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					else
					{
						if (list->GetSize() == amount)
						{

							while (list->End() != NULL)list->pop_back();
							delete list, list = nullptr;
						}
						else
						{

							for (int j = 0; j < amount; j++)list->pop_back();

						}
						MessageBox::Show(this, "Repeated books", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

					}
				}
				else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			}
			catch (NullReferenceException^ e)
			{
				if (list != nullptr)while (list->End() != nullptr)list->pop_back();
				list = nullptr;
				MessageBox::Show(this, "Incorrect pattern", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ e)
			{
				MessageBox::Show(this, "Can't read file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	}

    // Done

	private: System::Void ShowAllButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->Clear();
		
		if (list != nullptr)
		{

			for (int i = 0; i < list->GetSize(); i++)
			{
				this->MemoBox->AppendText(Convert::ToString((*list)[i].GetRegnum())+"\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[i].GetAuthor()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[i].GetName()) + "\n");
				this->MemoBox->AppendText(Convert::ToString((*list)[i].GetDate()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>((*list)[i].GetOffice()) + "\n");
				this->MemoBox->AppendText(Convert::ToString((*list)[i].GetAmount()) + "\n\n");
			}

			this->MemoBox->Show();

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	// Done

    private: System::Void AddMainButton_Click(System::Object^ sender, System::EventArgs^ e) {

	MyAddForm newform;

	newform.SetList(list);
    
	newform.ShowDialog();

	list = newform.GetList();

    }

	// Done

    private: System::Void DeleteMainButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (list != nullptr)
		{

			MyDeleteForm newform;

			newform.SetList(list);

			newform.ShowDialog();

			list = newform.GetList();

			if (list == nullptr)MessageBox::Show(this, "Your list is empty", "Attention", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

    }

	// Done

    private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ filename = "";

	if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		filename = SaveFileDialog->FileName;

		try
		{
			StreamWriter^ file = gcnew StreamWriter(filename);
			
			for (int i = 0; i < list->GetSize(); i++)
			{
				file->WriteLine(Convert::ToString((*list)[i].GetRegnum()));
				file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetAuthor()));
				file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetName()));
				file->WriteLine(Convert::ToString((*list)[i].GetDate()));
				file->WriteLine(msclr::interop::marshal_as<String^>((*list)[i].GetOffice()));
				file->WriteLine(Convert::ToString((*list)[i].GetAmount()) + "\n");
			}

			file->Close();

			MessageBox::Show(this, "Successfully saved", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (NullReferenceException^ e)
		{
			MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

    }

	// Done

    private: System::Void SortButtons_Click(System::Object^ sender, System::EventArgs^ e) {

		if (list != nullptr)
		{

			MySortForm newform;

			newform.SetList(list);

			newform.ShowDialog();

			list=newform.GetList();

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

    }

	// Done

    private: System::Void SearchMainButton_Click(System::Object^ sender, System::EventArgs^ e) {

	this->MemoBox->Clear();

	if (list != nullptr)
	{

		MyShowForm newform;;

		newform.SetList(list);

		newform.ShowDialog();

		if (newform.GetRes() != nullptr)
			for (int i = 0; i < newform.GetRes()->GetSize(); i++)
			{
				this->MemoBox->AppendText(Convert::ToString((*newform.GetRes())[i].GetRegnum()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>((*newform.GetRes())[i].GetAuthor()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>((*newform.GetRes())[i].GetName()) + "\n");
				this->MemoBox->AppendText(Convert::ToString((*newform.GetRes())[i].GetDate()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>((*newform.GetRes())[i].GetOffice()) + "\n");
				this->MemoBox->AppendText(Convert::ToString((*newform.GetRes())[i].GetAmount()) + "\n\n");
			}

		if (newform.GetRes() != nullptr)
		{
			while (newform.GetRes()->End() != nullptr)newform.GetRes()->pop_back();
			delete newform.GetRes();
		}

	}
	else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

};
}