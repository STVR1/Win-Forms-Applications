#pragma once
#include"EditForm.h"
#include"Delete.h"
#include"Add.h"
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
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Runtime::InteropServices;

	public ref class FirmForm : public System::Windows::Forms::Form
	{
	public:

	    Firm* List = NULL;
	    int size = 0;
		String^ buf = "";

	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;
	private: System::Windows::Forms::Button^ FailDeadline;
	public: System::Windows::Forms::ComboBox^ NameComboBox;
	private: System::Windows::Forms::RichTextBox^ MemoBox;
	private: System::Windows::Forms::Button^ SaveToFileButton;
	private: System::Windows::Forms::Button^ ReadInfoButton;
	private: System::Windows::Forms::ComboBox^ TasksComboBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::Button^ SortButton;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ EditButton;
	private: System::Windows::Forms::RichTextBox^ PatterRichTextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::SaveFileDialog^ SaveFileDialog;

	public:

		FirmForm(void)
		{
			InitializeComponent();
		}

	protected:

		~FirmForm()
		{
			if (components)
			{
				delete components;
			}
			delete[] List;
			List = nullptr;
		}

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FirmForm::typeid));
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->FailDeadline = (gcnew System::Windows::Forms::Button());
			this->NameComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->MemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SaveToFileButton = (gcnew System::Windows::Forms::Button());
			this->ReadInfoButton = (gcnew System::Windows::Forms::Button());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->TasksComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->PatterRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// FailDeadline
			// 
			this->FailDeadline->BackColor = System::Drawing::Color::Gold;
			this->FailDeadline->ForeColor = System::Drawing::Color::Black;
			this->FailDeadline->Location = System::Drawing::Point(333, 281);
			this->FailDeadline->Name = L"FailDeadline";
			this->FailDeadline->Size = System::Drawing::Size(75, 23);
			this->FailDeadline->TabIndex = 1;
			this->FailDeadline->Text = L"FailDate";
			this->FailDeadline->UseVisualStyleBackColor = false;
			this->FailDeadline->Click += gcnew System::EventHandler(this, &FirmForm::FailDeadline_Click);
			// 
			// NameComboBox
			// 
			this->NameComboBox->BackColor = System::Drawing::Color::Gold;
			this->NameComboBox->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NameComboBox->FormattingEnabled = true;
			this->NameComboBox->Location = System::Drawing::Point(117, 26);
			this->NameComboBox->Name = L"NameComboBox";
			this->NameComboBox->Size = System::Drawing::Size(140, 24);
			this->NameComboBox->TabIndex = 2;
			this->NameComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &FirmForm::NameComboBox_SelectedIndexChanged);
			// 
			// MemoBox
			// 
			this->MemoBox->BackColor = System::Drawing::SystemColors::Window;
			this->MemoBox->Location = System::Drawing::Point(291, 3);
			this->MemoBox->Name = L"MemoBox";
			this->MemoBox->ReadOnly = true;
			this->MemoBox->Size = System::Drawing::Size(368, 260);
			this->MemoBox->TabIndex = 3;
			this->MemoBox->Text = L"";
			this->MemoBox->TextChanged += gcnew System::EventHandler(this, &FirmForm::MemoBox_TextChanged);
			// 
			// SaveToFileButton
			// 
			this->SaveToFileButton->BackColor = System::Drawing::Color::Gold;
			this->SaveToFileButton->ForeColor = System::Drawing::Color::Black;
			this->SaveToFileButton->Location = System::Drawing::Point(525, 281);
			this->SaveToFileButton->Name = L"SaveToFileButton";
			this->SaveToFileButton->Size = System::Drawing::Size(75, 23);
			this->SaveToFileButton->TabIndex = 4;
			this->SaveToFileButton->Text = L"SaveInfo";
			this->SaveToFileButton->UseVisualStyleBackColor = false;
			this->SaveToFileButton->Click += gcnew System::EventHandler(this, &FirmForm::SaveToFileButton_Click);
			// 
			// ReadInfoButton
			// 
			this->ReadInfoButton->BackColor = System::Drawing::Color::Gold;
			this->ReadInfoButton->ForeColor = System::Drawing::Color::Black;
			this->ReadInfoButton->Location = System::Drawing::Point(425, 281);
			this->ReadInfoButton->Name = L"ReadInfoButton";
			this->ReadInfoButton->Size = System::Drawing::Size(75, 23);
			this->ReadInfoButton->TabIndex = 5;
			this->ReadInfoButton->Text = L"ReadInfo";
			this->ReadInfoButton->UseVisualStyleBackColor = false;
			this->ReadInfoButton->Click += gcnew System::EventHandler(this, &FirmForm::ReadInfoButton_Click);
			// 
			// TasksComboBox
			// 
			this->TasksComboBox->BackColor = System::Drawing::Color::Gold;
			this->TasksComboBox->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->TasksComboBox->FormattingEnabled = true;
			this->TasksComboBox->Location = System::Drawing::Point(117, 76);
			this->TasksComboBox->Name = L"TasksComboBox";
			this->TasksComboBox->Size = System::Drawing::Size(140, 24);
			this->TasksComboBox->TabIndex = 10;
			this->TasksComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &FirmForm::TasksComboBox_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->PatterRichTextBox);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->DeleteButton);
			this->panel1->Controls->Add(this->SortButton);
			this->panel1->Controls->Add(this->AddButton);
			this->panel1->Controls->Add(this->EditButton);
			this->panel1->Controls->Add(this->MemoBox);
			this->panel1->Controls->Add(this->TasksComboBox);
			this->panel1->Controls->Add(this->SaveToFileButton);
			this->panel1->Controls->Add(this->NameComboBox);
			this->panel1->Controls->Add(this->ReadInfoButton);
			this->panel1->Controls->Add(this->FailDeadline);
			this->panel1->Location = System::Drawing::Point(-3, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(670, 566);
			this->panel1->TabIndex = 11;
			// 
			// PatterRichTextBox
			// 
			this->PatterRichTextBox->Location = System::Drawing::Point(34, 323);
			this->PatterRichTextBox->Name = L"PatterRichTextBox";
			this->PatterRichTextBox->ReadOnly = true;
			this->PatterRichTextBox->Size = System::Drawing::Size(148, 119);
			this->PatterRichTextBox->TabIndex = 16;
			this->PatterRichTextBox->Text = L"1. Project name\n2. Task\n3. Executor\n4.Supervisor\n5.Date of issue\n6. Deadline\n7. D"
				L"ate of delivery";
			this->PatterRichTextBox->TextChanged += gcnew System::EventHandler(this, &FirmForm::PatterRichTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Gold;
			this->label1->Location = System::Drawing::Point(41, 288);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 16);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Pattern of info to edit";
			// 
			// DeleteButton
			// 
			this->DeleteButton->BackColor = System::Drawing::Color::Gold;
			this->DeleteButton->Location = System::Drawing::Point(333, 369);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(75, 23);
			this->DeleteButton->TabIndex = 14;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = false;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &FirmForm::DeleteButton_Click);
			// 
			// SortButton
			// 
			this->SortButton->BackColor = System::Drawing::Color::Gold;
			this->SortButton->Location = System::Drawing::Point(333, 323);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(75, 23);
			this->SortButton->TabIndex = 13;
			this->SortButton->Text = L"Sort";
			this->SortButton->UseVisualStyleBackColor = false;
			this->SortButton->Click += gcnew System::EventHandler(this, &FirmForm::SortButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::Color::Gold;
			this->AddButton->Location = System::Drawing::Point(525, 323);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 23);
			this->AddButton->TabIndex = 12;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &FirmForm::AddButton_Click);
			// 
			// EditButton
			// 
			this->EditButton->BackColor = System::Drawing::Color::Gold;
			this->EditButton->Location = System::Drawing::Point(425, 323);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(75, 23);
			this->EditButton->TabIndex = 11;
			this->EditButton->Text = L"Edit";
			this->EditButton->UseVisualStyleBackColor = false;
			this->EditButton->Click += gcnew System::EventHandler(this, &FirmForm::EditButton_Click);
			// 
			// FirmForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(665, 564);
			this->Controls->Add(this->panel1);
			this->Name = L"FirmForm";
			this->Text = L"FirmForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	// Done 

	private: System::Void SaveToFileButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (List != NULL)
		{

			String^ filename = "";

			if (SaveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) filename = SaveFileDialog->FileName;

			try
			{

				StreamWriter^ file = gcnew StreamWriter(filename);
				file->WriteLine(buf);
				file->Close();

				MessageBox::Show(this, "Successfully saved", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			}
			catch (Exception^ e)
			{
				MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	// Done

	private: System::Void ReadInfoButton_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ filename = "";
		String^ line = "";
		std::string Info[7];
		int i = 0;

		if (OpenFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)filename = OpenFileDialog->FileName;

		try
		{

			StreamReader^ file = gcnew StreamReader(filename);

			if (List != NULL) delete[] List, List = nullptr, size = 0, buf = "", this->NameComboBox->Items->Clear();

			file->BaseStream->Seek(0, SeekOrigin::Begin);
			buf = file->ReadToEnd();

			for (int t = 0, k = 0; t < buf->Length; t++)
			{
				if (buf[t] == '\n')k++;
				if (k == 7)size++, k = 0;
			}

			if (size != 0)List = new Firm[size];
			else MessageBox::Show(this, "Empty file", "Error", MessageBoxButtons::OK, MessageBoxIcon::None);

			file->BaseStream->Seek(0, SeekOrigin::Begin);

			while (i < size)
			{
				for (int j = 0; j < 7;)
				{
					line = Convert::ToString(file->ReadLine());
					if (line != "") Info[j++] = msclr::interop::marshal_as<std::string>(line);
				}
				List[i++].SetInfo(Info);
			}

			file->Close();

			if (size != 0)MessageBox::Show(this, "Successfully read", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			for (i = 0; i < size; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (j == i)this->NameComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
					else if (List[i].GetProjectName() == List[j].GetProjectName())break;
				}
			}

		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

    // Done

	private: System::Void NameComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->Clear();
		this->TasksComboBox->Items->Clear();
		
		for (int i = 0; i < size; i++)
		{
			if (this->NameComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>(List[i].GetProjectName()))
			{

				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetTask()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetExecutor()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetSupervisor()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetDateOfIssue()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetDeadLine()) + "\n");
				this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetDateOfDelivery()) + "\n\n");

				this->TasksComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetExecutor()));

			}
		}

		for (int i = 0; i < this->TasksComboBox->Items->Count; i++)
		{
			for (int j = i; j < this->TasksComboBox->Items->Count; j++)
			{
				if (msclr::interop::marshal_as<std::string>(this->TasksComboBox->Items[i]->ToString()) > msclr::interop::marshal_as<std::string>(this->TasksComboBox->Items[j]->ToString()))
				{
					Object^ temp = this->TasksComboBox->Items[i];
					this->TasksComboBox->Items[i] = this->TasksComboBox->Items[j];
					this->TasksComboBox->Items[j] = temp;
				}
			}
		}

		this->MemoBox->Show();

	}

	// Done

	private: System::Void FailDeadline_Click(System::Object^ sender, System::EventArgs^ e) {

		if (List != NULL)
		{

			bool nothing = true;

			this->MemoBox->Clear();

			for (int i = 0; i < size; i++)
				if (!List[i].GetFailExecutor().empty())this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetFailExecutor()) + "\n"), nothing = false;

			if (nothing == true)MessageBox::Show(this, "Nothing found", "Attention", MessageBoxButtons::OK, MessageBoxIcon::Information);

			this->MemoBox->Show();

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

    // Done

	private: System::Void TasksComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->Clear();
		try
		{
			for (int i = 0; i < size; i++)
			{
				if (this->NameComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>(List[i].GetProjectName()))
					if (this->TasksComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>(List[i].GetExecutor()))
						this->MemoBox->AppendText(msclr::interop::marshal_as<String^>(List[i].GetTask()));
			}

			this->MemoBox->Show();
		}
		catch (NullReferenceException^ e)
		{
			MessageBox::Show(this, "Project name isn't selected", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	// Done

	private: void qs(Firm* List, int first, int last)
		   {
			   if (first < last)
			   {
				   int left = first;
				   int right = last;
				   std::string middle = List[(left + right) / 2].GetProjectName();

				   do
				   {

					   while (List[left].GetProjectName() < middle)
						   left++;

					   while (List[right].GetProjectName() > middle)
						   right--;

					   if (left <= right)
					   {
						   Firm temp = List[left];
						   List[left] = List[right];
						   List[right] = temp;
						   left++;
						   right--;
					   }

				   } while (left < right);
				   qs(List, first, right);
				   qs(List, left, last);
			   }
		   }

	private: System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (List != NULL)
		{
			qs(List, 0, size - 1);

			this->NameComboBox->Items->Clear();
			this->TasksComboBox->Items->Clear();

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (i == j)this->NameComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
					if (List[i].GetProjectName() == List[j].GetProjectName())break;
				}
			}

			MessageBox::Show(this, "Successfully sorted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			
		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	// Done

    private: System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		EditForm newform;
		
		if (List != NULL)
		{
			for(int i=0;i<size;i++)
				for (int j = 0; j <= i; j++)
				{
					if (i == j)newform.ProjectComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
					if (List[i].GetProjectName() == List[j].GetProjectName())break;
				}
			
			newform.SetSize(size);
			newform.SetList(List);
	
			newform.ShowDialog();

			this->NameComboBox->Items->Clear();
			this->TasksComboBox->Items->Clear();

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (i == j)this->NameComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
					if (List[i].GetProjectName() == List[j].GetProjectName())break;
				}
			}

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}
    
	// Done

    private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (List != NULL)
		{

			Add newform;

			newform.SetList(List);
			newform.SetSize(size);
			
			newform.ShowDialog();

			List = newform.GetList();
			size = newform.GetSize();

			this->NameComboBox->Items->Clear();
			this->TasksComboBox->Items->Clear();

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (i == j)this->NameComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
					if (List[i].GetProjectName() == List[j].GetProjectName())break;
				}
			}

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

    }
    
	// Done

    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (List != NULL)
		{
			Delete newform;

			for (int i = 0; i < this->NameComboBox->Items->Count; i++) newform.DeleteNameComboBox->Items->Add(this->NameComboBox->Items[i]->ToString());

			newform.SetList(List);
			newform.SetSize(size);

			newform.ShowDialog();

			List = newform.GetList();
			size = newform.GetSize();

			this->NameComboBox->Items->Clear();
			this->TasksComboBox->Items->Clear();

			if (List != NULL)
			{
				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j <= i; j++)
					{
						if (i == j)this->NameComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetProjectName()));
						if (List[i].GetProjectName() == List[j].GetProjectName())break;
					}
				}
			}
			else MessageBox::Show(this, "Your list is empty", "Attention", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

    }

    private: System::Void PatterRichTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }

	private: System::Void MemoBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}