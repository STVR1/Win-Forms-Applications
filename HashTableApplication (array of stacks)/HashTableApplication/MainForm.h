#pragma once

#include"..\HashTableLibrary\HashTable.h"

namespace HashTableApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;

	public ref class MainForm : public System::Windows::Forms::Form
	{

	private:

		HashTable* table = nullptr;
		
		int circle = 0;

	public:

		MainForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MainForm()
		{

			if (table != nullptr)table->Clear(), delete table, table=nullptr;

			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ CreateButton;

	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::RichTextBox^ MemoBox;

	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::Button^ TaskButton;
	private: System::Windows::Forms::TextBox^ TextBox;
	private: System::Windows::Forms::PrintDialog^ PrintDialog;
	private: System::Windows::Forms::Button^ PrintButton;

	private: System::Windows::Forms::PrintPreviewDialog^ PrintPreviewDialog;
	private: System::Drawing::Printing::PrintDocument^ PrintDocument;
	private: System::Windows::Forms::Button^ PreviewButton;
	private: System::Windows::Forms::PageSetupDialog^ PageSetupDialog;
	private: System::Windows::Forms::Button^ PageSetupButton;
	private: System::Windows::Forms::Button^ ShowTableButton;
	private: System::Windows::Forms::RichTextBox^ MemoBoxPositive;
	private: System::Windows::Forms::RichTextBox^ MemoBoxNegative;
	private: System::Windows::Forms::Button^ CleanButton;
	private: System::Windows::Forms::TextBox^ KeyTextBox;
	private: System::Windows::Forms::TextBox^ ValueTextBox;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->CreateButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->MemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->TaskButton = (gcnew System::Windows::Forms::Button());
			this->TextBox = (gcnew System::Windows::Forms::TextBox());
			this->PrintDialog = (gcnew System::Windows::Forms::PrintDialog());
			this->PrintButton = (gcnew System::Windows::Forms::Button());
			this->PrintPreviewDialog = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->PrintDocument = (gcnew System::Drawing::Printing::PrintDocument());
			this->PreviewButton = (gcnew System::Windows::Forms::Button());
			this->PageSetupDialog = (gcnew System::Windows::Forms::PageSetupDialog());
			this->PageSetupButton = (gcnew System::Windows::Forms::Button());
			this->ShowTableButton = (gcnew System::Windows::Forms::Button());
			this->MemoBoxPositive = (gcnew System::Windows::Forms::RichTextBox());
			this->MemoBoxNegative = (gcnew System::Windows::Forms::RichTextBox());
			this->CleanButton = (gcnew System::Windows::Forms::Button());
			this->KeyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// CreateButton
			// 
			this->CreateButton->Location = System::Drawing::Point(569, 48);
			this->CreateButton->Name = L"CreateButton";
			this->CreateButton->Size = System::Drawing::Size(75, 44);
			this->CreateButton->TabIndex = 0;
			this->CreateButton->Text = L"Create";
			this->CreateButton->UseVisualStyleBackColor = true;
			this->CreateButton->Click += gcnew System::EventHandler(this, &MainForm::CreateButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(12, 425);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(88, 46);
			this->AddButton->TabIndex = 1;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &MainForm::AddButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(119, 425);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(85, 46);
			this->DeleteButton->TabIndex = 2;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MainForm::DeleteButton_Click);
			// 
			// MemoBox
			// 
			this->MemoBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->MemoBox->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MemoBox->Location = System::Drawing::Point(-2, 0);
			this->MemoBox->Name = L"MemoBox";
			this->MemoBox->ReadOnly = true;
			this->MemoBox->Size = System::Drawing::Size(489, 409);
			this->MemoBox->TabIndex = 3;
			this->MemoBox->Text = L"";
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(12, 477);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(88, 44);
			this->SearchButton->TabIndex = 4;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MainForm::SearchButton_Click);
			// 
			// TaskButton
			// 
			this->TaskButton->Location = System::Drawing::Point(119, 477);
			this->TaskButton->Name = L"TaskButton";
			this->TaskButton->Size = System::Drawing::Size(85, 44);
			this->TaskButton->TabIndex = 5;
			this->TaskButton->Text = L"Task";
			this->TaskButton->UseVisualStyleBackColor = true;
			this->TaskButton->Click += gcnew System::EventHandler(this, &MainForm::TaskButton_Click);
			// 
			// TextBox
			// 
			this->TextBox->Location = System::Drawing::Point(570, 10);
			this->TextBox->Name = L"TextBox";
			this->TextBox->Size = System::Drawing::Size(74, 22);
			this->TextBox->TabIndex = 6;
			this->TextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::TextBox_MouseClick);
			this->TextBox->Leave += gcnew System::EventHandler(this, &MainForm::TextBox_Leave);
			// 
			// PrintDialog
			// 
			this->PrintDialog->AllowCurrentPage = true;
			this->PrintDialog->UseEXDialog = true;
			// 
			// PrintButton
			// 
			this->PrintButton->Location = System::Drawing::Point(576, 436);
			this->PrintButton->Name = L"PrintButton";
			this->PrintButton->Size = System::Drawing::Size(75, 35);
			this->PrintButton->TabIndex = 7;
			this->PrintButton->Text = L"Print";
			this->PrintButton->UseVisualStyleBackColor = true;
			this->PrintButton->Click += gcnew System::EventHandler(this, &MainForm::PrintButton_Click);
			// 
			// PrintPreviewDialog
			// 
			this->PrintPreviewDialog->AutoScrollMargin = System::Drawing::Size(0, 0);
			this->PrintPreviewDialog->AutoScrollMinSize = System::Drawing::Size(0, 0);
			this->PrintPreviewDialog->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->PrintPreviewDialog->ClientSize = System::Drawing::Size(400, 300);
			this->PrintPreviewDialog->Document = this->PrintDocument;
			this->PrintPreviewDialog->Enabled = true;
			this->PrintPreviewDialog->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"PrintPreviewDialog.Icon")));
			this->PrintPreviewDialog->Name = L"PrintPreviewDialog";
			this->PrintPreviewDialog->Visible = false;
			// 
			// PrintDocument
			// 
			this->PrintDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MainForm::PrintDocument_PrintPage);
			// 
			// PreviewButton
			// 
			this->PreviewButton->Location = System::Drawing::Point(496, 436);
			this->PreviewButton->Name = L"PreviewButton";
			this->PreviewButton->Size = System::Drawing::Size(75, 35);
			this->PreviewButton->TabIndex = 8;
			this->PreviewButton->Text = L"Preview";
			this->PreviewButton->UseVisualStyleBackColor = true;
			this->PreviewButton->Click += gcnew System::EventHandler(this, &MainForm::PreviewButton_Click);
			// 
			// PageSetupButton
			// 
			this->PageSetupButton->Location = System::Drawing::Point(496, 477);
			this->PageSetupButton->Name = L"PageSetupButton";
			this->PageSetupButton->Size = System::Drawing::Size(155, 33);
			this->PageSetupButton->TabIndex = 9;
			this->PageSetupButton->Text = L"Page setup";
			this->PageSetupButton->UseVisualStyleBackColor = true;
			this->PageSetupButton->Click += gcnew System::EventHandler(this, &MainForm::PageSetupButton_Click);
			// 
			// ShowTableButton
			// 
			this->ShowTableButton->Location = System::Drawing::Point(210, 425);
			this->ShowTableButton->Name = L"ShowTableButton";
			this->ShowTableButton->Size = System::Drawing::Size(84, 46);
			this->ShowTableButton->TabIndex = 10;
			this->ShowTableButton->Text = L"Show";
			this->ShowTableButton->UseVisualStyleBackColor = true;
			this->ShowTableButton->Click += gcnew System::EventHandler(this, &MainForm::ShowTableButton_Click);
			// 
			// MemoBoxPositive
			// 
			this->MemoBoxPositive->Location = System::Drawing::Point(0, 0);
			this->MemoBoxPositive->Name = L"MemoBoxPositive";
			this->MemoBoxPositive->ReadOnly = true;
			this->MemoBoxPositive->Size = System::Drawing::Size(256, 409);
			this->MemoBoxPositive->TabIndex = 11;
			this->MemoBoxPositive->Text = L"";
			// 
			// MemoBoxNegative
			// 
			this->MemoBoxNegative->Location = System::Drawing::Point(262, 0);
			this->MemoBoxNegative->Name = L"MemoBoxNegative";
			this->MemoBoxNegative->ReadOnly = true;
			this->MemoBoxNegative->Size = System::Drawing::Size(225, 409);
			this->MemoBoxNegative->TabIndex = 12;
			this->MemoBoxNegative->Text = L"";
			// 
			// CleanButton
			// 
			this->CleanButton->Location = System::Drawing::Point(211, 478);
			this->CleanButton->Name = L"CleanButton";
			this->CleanButton->Size = System::Drawing::Size(83, 43);
			this->CleanButton->TabIndex = 13;
			this->CleanButton->Text = L"Clean";
			this->CleanButton->UseVisualStyleBackColor = true;
			this->CleanButton->Click += gcnew System::EventHandler(this, &MainForm::CleanButton_Click);
			// 
			// KeyTextBox
			// 
			this->KeyTextBox->Location = System::Drawing::Point(571, 113);
			this->KeyTextBox->Name = L"KeyTextBox";
			this->KeyTextBox->Size = System::Drawing::Size(74, 22);
			this->KeyTextBox->TabIndex = 14;
			this->KeyTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::KeyTextBox_MouseClick);
			this->KeyTextBox->Leave += gcnew System::EventHandler(this, &MainForm::KeyTextBox_Leave);
			// 
			// ValueTextBox
			// 
			this->ValueTextBox->Location = System::Drawing::Point(571, 160);
			this->ValueTextBox->Name = L"ValueTextBox";
			this->ValueTextBox->Size = System::Drawing::Size(73, 22);
			this->ValueTextBox->TabIndex = 15;
			this->ValueTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::ValueTextBox_MouseClick);
			this->ValueTextBox->Leave += gcnew System::EventHandler(this, &MainForm::ValueTextBox_Leave);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 530);
			this->Controls->Add(this->ValueTextBox);
			this->Controls->Add(this->KeyTextBox);
			this->Controls->Add(this->CleanButton);
			this->Controls->Add(this->MemoBoxNegative);
			this->Controls->Add(this->MemoBoxPositive);
			this->Controls->Add(this->ShowTableButton);
			this->Controls->Add(this->PageSetupButton);
			this->Controls->Add(this->PreviewButton);
			this->Controls->Add(this->PrintButton);
			this->Controls->Add(this->TextBox);
			this->Controls->Add(this->TaskButton);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->MemoBox);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->CreateButton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		   // For main form

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->TextBox->ForeColor = Color::Gray;
		this->TextBox->Text = "Size";

		this->KeyTextBox->ForeColor = Color::Gray;
		this->KeyTextBox->Text = "Key";

		this->ValueTextBox->ForeColor = Color::Gray;
		this->ValueTextBox->Text = "Value";

		this->MemoBox->WordWrap = false;
		this->MemoBox->ScrollBars = RichTextBoxScrollBars::Both;


		this->MemoBoxNegative->Hide();
		this->MemoBoxPositive->Hide();

	}

	private: System::Void MainForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->TextBox->Text->ToString() == "")this->TextBox->ForeColor = Color::Gray, this->TextBox->Text = "Size";
		if (this->KeyTextBox->Text->ToString() == "")this->KeyTextBox->ForeColor = Color::Gray, this->KeyTextBox->Text = "Key";

	}

		   // Functions for textbox

	private: System::Void TextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->TextBox->ForeColor == Color::Gray)this->TextBox->Clear();
		this->TextBox->ForeColor = Color::Black;

	}

	private: System::Void TextBox_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (this->TextBox->Text->ToString() == "")this->TextBox->ForeColor = Color::Gray, this->TextBox->Text = "Size";

	}

		   // Functions for keytextbox

	private: System::Void KeyTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->KeyTextBox->ForeColor == Color::Gray)
		{
			this->KeyTextBox->ForeColor = Color::Black;
			this->KeyTextBox->Text = "";
		}

	}

	private: System::Void KeyTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (this->KeyTextBox->Text->ToString() == "")this->KeyTextBox->ForeColor = Color::Gray, this->KeyTextBox->Text = "Key";

	}
		   
		   // Functions for printer

	private: System::Void PrintDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {

			e->HasMorePages = false;

			for (int height = 0; circle < this->MemoBox->Lines->Length; height++, circle++)
			{
				e->Graphics->DrawString(this->MemoBox->Lines[circle]->ToString(), gcnew System::Drawing::Font("Time New Roman", 14, FontStyle::Regular), Brushes::Black, Point(10, 10 + height * 30));
				if (circle % 38 == 0 && circle != 0)
				{
					e->HasMorePages = true;
					circle++;
					return;
				}

			}

		}

	private: System::Void PrintButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (PrintDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->PrintDocument->Print();
		}

	}

	private: System::Void PreviewButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->PrintPreviewDialog->Document = this->PrintDocument;

		this->PrintPreviewDialog->ShowDialog();

		circle = 0;

	}

	private: System::Void PageSetupButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->PageSetupDialog->Document = this->PrintDocument;
		this->PageSetupDialog->ShowDialog();

	}

		   // Buttons 

	private: System::Void CreateButton_Click(System::Object^ sender, System::EventArgs^ e) {

		try
		{
			int size = Convert::ToInt32(this->TextBox->Text->ToString());

			if (size < 1)
			{
				MessageBox::Show(this, "Incorrect size", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (table != nullptr)table->Clear(), delete table, table = nullptr;

			table = new HashTable(size);

			Random^ rand = gcnew Random();

			for (int i = 0; i < size; i++)
			{
				table->Insert(rand->Next(-50, 50), rand->Next(20000, 50000));
			}

			MessageBox::Show(this, "Successfully created", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (Exception^)
		{
			MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	private: System::Void ShowTableButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->Clear();
		this->MemoBoxNegative->Hide();
		this->MemoBoxPositive->Hide();
		this->MemoBox->Show();

		if (table == nullptr)
		{
			MessageBox::Show(this, "Empty table","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		for (int i = 0; i < table->Size(); i++)
		{
			this->MemoBox->AppendText(Convert::ToString(i) + ": ");

			auto searched = table->ExtendedSearch(i);
			if (searched == nullptr)
			{
				this->MemoBox->AppendText("\n\n");
				continue;
			}
			
			auto field = searched->mystack.top();

			while (field != nullptr)
			{
				this->MemoBox->AppendText("\t| " + Convert::ToString(field->info.first) + "\t" + Convert::ToString(field->info.second) + " |");
				field = field->next;
			}
			this->MemoBox->AppendText("\n\n");
			
		}

	}

    private: System::Void TaskButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (table == nullptr)
		{
			MessageBox::Show(this, "Empty table","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		this->MemoBoxPositive->Clear();
		this->MemoBoxNegative->Clear();

		this->MemoBox->Clear();
		this->MemoBox->Hide();

		DivideTables task;

		auto temp=task.Divide(table);
		
		while (temp->first.top() != nullptr)
		{

			this->MemoBoxPositive->AppendText(Convert::ToString(temp->first.top()->info.first) + "\t" + Convert::ToString(temp->first.top()->info.second) + "\n");
			temp->first.pop();
		}

		while (temp->second.top() != nullptr)
		{

			this->MemoBoxNegative->AppendText(Convert::ToString(temp->second.top()->info.first) + "\t" + Convert::ToString(temp->second.top()->info.second) + "\n");
			temp->second.pop();
		}
		
		this->MemoBoxNegative->Show();
		this->MemoBoxPositive->Show();

		delete temp, temp = nullptr;

		MessageBox::Show(this,"Successfully fulfilled","Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

    }

    private: System::Void CleanButton_Click(System::Object^ sender, System::EventArgs^ e) {
    
		this->MemoBox->Clear();
		this->MemoBoxNegative->Clear();
		this->MemoBoxPositive->Clear();

		MessageBox::Show(this, "Successfully cleaned","Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}

    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
    
		if (table == nullptr)
		{
			MessageBox::Show(this,"Empty table","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try
		{
			int key = Convert::ToInt32(this->KeyTextBox->Text->ToString());

			if (table->Delete(key))MessageBox::Show(this, "Successfully deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else MessageBox::Show(this,"Unsuccessfully deleted","Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (Exception^)
		{
			MessageBox::Show(this,"Incorrect input","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

    private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (table == nullptr)
		{
			MessageBox::Show(this, "Empty table", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (this->MemoBox->Lines->Length == 0)
		{
			MessageBox::Show(this, "Empty text box", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try
		{
			int key = Convert::ToInt32(this->KeyTextBox->Text->ToString());

			String^ searched = Convert::ToString(table->Search(key));
			bool success = false;

			if (searched != "-100")
			{

				for (int i = 0; i < this->MemoBox->Lines->Length; i++)
				{
				
					if (this->MemoBox->Lines[i]->ToString()->Contains("| "+Convert::ToString(key) +"\t"+searched+" |"))
					{
						
						int start = this->MemoBox->GetFirstCharIndexFromLine(i);
						this->MemoBox->Select(start, Convert::ToString(i)->Length+1);
						this->MemoBox->SelectionBackColor = Color::Yellow;

						String^ line1 = Convert::ToString(key);
						String^ line2 = this->MemoBox->Lines[i]->ToString();
						int first = 0;
						bool bracket = false;
						for (int j = 0; j < line2->Length; j++)
						{
							if (Convert::ToChar(line2[j]) == '|' && success == false && bracket==false)
							{
								
								first = start+j;
								j+=2;
								for (int k = 0; k < line1->Length && j<line2->Length; k++, j++)
								{
									
									if (Convert::ToChar(line1[k]) != Convert::ToChar(line2[j]))break;
									if (k == line1->Length - 1)success = true;
									
								}
								bracket = true;
							}
							else if (Convert::ToChar(line2[j]) == '|' && success == true)
							{
								
								this->MemoBox->Select(first, j+start-first);
								this->MemoBox->SelectionBackColor = Color::Yellow;
								break;
							}
							if (Convert::ToChar(line2[j]) == '|' && bracket == true)bracket = false;
						}
						
						MessageBox::Show(this, "Successfully searched", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
						break;
					}

				}

			}
			else MessageBox::Show(this, "Unsuccessfully searched", "Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (Exception^)
		{
			MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

    }

    private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
    
		if (table == nullptr)
		{
			MessageBox::Show(this,"Empty table","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		try
		{
			int key = Convert::ToInt32(this->KeyTextBox->Text->ToString());
			int value = Convert::ToInt32(this->ValueTextBox->Text->ToString());
			table->Insert(key, value);
			MessageBox::Show(this, "Successfully added", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (Exception^)
		{
			MessageBox::Show(this, "Incorrect input", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

    private: System::Void ValueTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	if (this->ValueTextBox->ForeColor == Color::Gray)
	{
		this->ValueTextBox->Text = "";
		this->ValueTextBox->ForeColor = Color::Black;
	}

    }

    private: System::Void ValueTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {

	if (this->ValueTextBox->Text->ToString() == "")
	{
		this->ValueTextBox->Text = "Value";
		this->ValueTextBox->ForeColor = Color::Gray;
	}

    }

};
}