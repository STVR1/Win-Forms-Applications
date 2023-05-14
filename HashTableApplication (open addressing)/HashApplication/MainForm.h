#pragma once

#include"..\HashTableLibrary\HashTable.h"

#include<msclr/marshal_cppstd.h>
#include<regex>
#include<chrono>

namespace HashApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	public ref class MainForm : public System::Windows::Forms::Form
	{

	private:

		HashTable* table = nullptr;

	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MainForm()
		{

			if (table != nullptr)delete table, table = nullptr;

			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::CheckBox^ CheckBox16;
	private: System::Windows::Forms::CheckBox^ CheckBox64;
	private: System::Windows::Forms::CheckBox^ CheckBox128;
	private: System::Windows::Forms::CheckBox^ CheckBox2048;

	protected:

	protected:

	private: System::Windows::Forms::Button^ CreateButton;
	private: System::Windows::Forms::Button^ ChooseButton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ TimeChart;
	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::TextBox^ SearchTextBox;
	private: System::Windows::Forms::Button^ DeletItemButton;
	private: System::Windows::Forms::Button^ CleanButton;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->CheckBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox64 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox128 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckBox2048 = (gcnew System::Windows::Forms::CheckBox());
			this->CreateButton = (gcnew System::Windows::Forms::Button());
			this->ChooseButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->DeletItemButton = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->TimeChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->CleanButton = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeChart))->BeginInit();
			this->SuspendLayout();
			// 
			// CheckBox16
			// 
			this->CheckBox16->AutoSize = true;
			this->CheckBox16->Location = System::Drawing::Point(21, 211);
			this->CheckBox16->Name = L"CheckBox16";
			this->CheckBox16->Size = System::Drawing::Size(72, 20);
			this->CheckBox16->TabIndex = 0;
			this->CheckBox16->Text = L"Size 16";
			this->CheckBox16->UseVisualStyleBackColor = true;
			// 
			// CheckBox64
			// 
			this->CheckBox64->AutoSize = true;
			this->CheckBox64->Location = System::Drawing::Point(21, 247);
			this->CheckBox64->Name = L"CheckBox64";
			this->CheckBox64->Size = System::Drawing::Size(72, 20);
			this->CheckBox64->TabIndex = 1;
			this->CheckBox64->Text = L"Size 64";
			this->CheckBox64->UseVisualStyleBackColor = true;
			// 
			// CheckBox128
			// 
			this->CheckBox128->AutoSize = true;
			this->CheckBox128->Location = System::Drawing::Point(21, 284);
			this->CheckBox128->Name = L"CheckBox128";
			this->CheckBox128->Size = System::Drawing::Size(79, 20);
			this->CheckBox128->TabIndex = 2;
			this->CheckBox128->Text = L"Size 128";
			this->CheckBox128->UseVisualStyleBackColor = true;
			// 
			// CheckBox2048
			// 
			this->CheckBox2048->AutoSize = true;
			this->CheckBox2048->Location = System::Drawing::Point(21, 321);
			this->CheckBox2048->Name = L"CheckBox2048";
			this->CheckBox2048->Size = System::Drawing::Size(86, 20);
			this->CheckBox2048->TabIndex = 3;
			this->CheckBox2048->Text = L"Size 2048";
			this->CheckBox2048->UseVisualStyleBackColor = true;
			// 
			// CreateButton
			// 
			this->CreateButton->Location = System::Drawing::Point(18, 395);
			this->CreateButton->Name = L"CreateButton";
			this->CreateButton->Size = System::Drawing::Size(89, 44);
			this->CreateButton->TabIndex = 4;
			this->CreateButton->Text = L"Create";
			this->CreateButton->UseVisualStyleBackColor = true;
			this->CreateButton->Click += gcnew System::EventHandler(this, &MainForm::CreateButton_Click);
			// 
			// ChooseButton
			// 
			this->ChooseButton->Location = System::Drawing::Point(18, 347);
			this->ChooseButton->Name = L"ChooseButton";
			this->ChooseButton->Size = System::Drawing::Size(89, 42);
			this->ChooseButton->TabIndex = 5;
			this->ChooseButton->Text = L"Choose";
			this->ChooseButton->UseVisualStyleBackColor = true;
			this->ChooseButton->Click += gcnew System::EventHandler(this, &MainForm::ChooseButton_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel1->Location = System::Drawing::Point(178, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(559, 74);
			this->panel1->TabIndex = 6;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel1_MouseClick);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel2->Controls->Add(this->CleanButton);
			this->panel2->Controls->Add(this->DeletItemButton);
			this->panel2->Controls->Add(this->SearchButton);
			this->panel2->Controls->Add(this->SearchTextBox);
			this->panel2->Controls->Add(this->DeleteButton);
			this->panel2->Controls->Add(this->CreateButton);
			this->panel2->Controls->Add(this->CheckBox128);
			this->panel2->Controls->Add(this->CheckBox64);
			this->panel2->Controls->Add(this->CheckBox2048);
			this->panel2->Controls->Add(this->ChooseButton);
			this->panel2->Controls->Add(this->CheckBox16);
			this->panel2->Location = System::Drawing::Point(1, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(178, 585);
			this->panel2->TabIndex = 7;
			this->panel2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel2_MouseClick);
			// 
			// DeletItemButton
			// 
			this->DeletItemButton->Location = System::Drawing::Point(18, 149);
			this->DeletItemButton->Name = L"DeletItemButton";
			this->DeletItemButton->Size = System::Drawing::Size(89, 45);
			this->DeletItemButton->TabIndex = 9;
			this->DeletItemButton->Text = L"Delete Item";
			this->DeletItemButton->UseVisualStyleBackColor = true;
			this->DeletItemButton->Click += gcnew System::EventHandler(this, &MainForm::DeletItemButton_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(18, 84);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(89, 46);
			this->SearchButton->TabIndex = 8;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MainForm::SearchButton_Click);
			// 
			// SearchTextBox
			// 
			this->SearchTextBox->Location = System::Drawing::Point(18, 34);
			this->SearchTextBox->Name = L"SearchTextBox";
			this->SearchTextBox->Size = System::Drawing::Size(136, 22);
			this->SearchTextBox->TabIndex = 7;
			this->SearchTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::SearchTextBox_MouseClick);
			this->SearchTextBox->Leave += gcnew System::EventHandler(this, &MainForm::SearchTextBox_Leave);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(18, 445);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(89, 45);
			this->DeleteButton->TabIndex = 6;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MainForm::DeleteButton_Click);
			// 
			// TimeChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->TimeChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->TimeChart->Legends->Add(legend1);
			this->TimeChart->Location = System::Drawing::Point(178, 70);
			this->TimeChart->Name = L"TimeChart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Time";
			this->TimeChart->Series->Add(series1);
			this->TimeChart->Size = System::Drawing::Size(559, 502);
			this->TimeChart->TabIndex = 8;
			this->TimeChart->Text = L"TimeAnalyse";
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->FileName = L"OpenFileDialog";
			// 
			// CleanButton
			// 
			this->CleanButton->Location = System::Drawing::Point(18, 509);
			this->CleanButton->Name = L"CleanButton";
			this->CleanButton->Size = System::Drawing::Size(89, 40);
			this->CleanButton->TabIndex = 10;
			this->CleanButton->Text = L"Clean";
			this->CleanButton->UseVisualStyleBackColor = true;
			this->CleanButton->Click += gcnew System::EventHandler(this, &MainForm::CleanButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 584);
			this->Controls->Add(this->TimeChart);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseClick);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeChart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->CheckBox16->Enabled = false;
		this->CheckBox64->Enabled = false;
		this->CheckBox128->Enabled = false;
		this->CheckBox2048->Enabled = false;
		this->SearchTextBox->ReadOnly = true;

	}
    
    private: System::Void ChooseButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->CheckBox16->Enabled = true;
		this->CheckBox64->Enabled = true;
		this->CheckBox128->Enabled = true;
		this->CheckBox2048->Enabled = true;

	}

    private: System::Void CreateButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->CheckBox16->Enabled = false;
		this->CheckBox64->Enabled = false;
		this->CheckBox128->Enabled = false;
		this->CheckBox2048->Enabled = false;

		if (table != nullptr)
		{
			MessageBox::Show(this,"Table is created","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int counter = 0;

		if (this->CheckBox16->Checked == true) counter++;
		if (this->CheckBox64->Checked == true) counter++;
		if (this->CheckBox128->Checked == true) counter++;
		if (this->CheckBox2048->Checked == true) counter++;

		if (counter > 1 || counter==0)
		{
			MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (this->CheckBox16->Checked == true)table = new HashTable(16);
		if (this->CheckBox64->Checked == true)table = new HashTable(64);
		if (this->CheckBox128->Checked == true)table = new HashTable(128);
		if (this->CheckBox2048->Checked == true)table = new HashTable(2048);
		
		if (OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				
				StreamReader^ file = gcnew StreamReader(OpenFileDialog->FileName);

				while (file->Peek() >= 0)
				{
					std::string line1 = msclr::interop::marshal_as<std::string>(file->ReadLine());
					std::string line2 = msclr::interop::marshal_as<std::string>(file->ReadLine());
					
					if (!table->Insert(line1, line2))
					{
						MessageBox::Show(this, "Table is full. Can't read more", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						break;
					}

				}

				file->Close();

				MessageBox::Show(this, "Successfully read", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				
			}
			catch (Exception^)
			{
				MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

		}
		else
		{
			delete table, table = nullptr;
			return;
		}
		
	}
    
    private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (table != nullptr) table->Clear(), delete table, table = nullptr;
		else
		{
			MessageBox::Show(this, "Table isn't created","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		MessageBox::Show(this,"Successfully deleted","Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

    }

	private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
    
		std::regex pattern("^([0-9]{2}[-]{1}){2}[0-9]{2}$");
		std::string line, result;

		if (table == nullptr)
		{
			MessageBox::Show(this, "Empty table", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		line = msclr::interop::marshal_as<std::string>(this->SearchTextBox->Text->ToString());

		if (!std::regex_match(line, pattern))
		{
			MessageBox::Show(this, "Incorrect input","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		auto start=std::chrono::high_resolution_clock::now();
		result = table->Search(line);
		auto end = std::chrono::high_resolution_clock::now();
		
		if (result == "")
		{
			MessageBox::Show(this, "Nothing found", "Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		std::chrono::duration<float> duration = end - start;

		MessageBox::Show(this,"Successfully found", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		this->TimeChart->Series["Time"]->Points->AddXY(msclr::interop::marshal_as<String^>(result),duration.count());

	}

    private: System::Void SearchTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    
		this->SearchTextBox->ReadOnly = false;

	}
    
    private: System::Void SearchTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    
		this->SearchTextBox->ReadOnly = true;
		this->panel1->Focus();

	}

    private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    
		this->SearchTextBox->ReadOnly = true;
		this->panel1->Focus();

	}
    
    private: System::Void panel2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    
		this->SearchTextBox->ReadOnly = true;
		this->panel1->Focus();
		
	}
    
    private: System::Void MainForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		this->SearchTextBox->ReadOnly = true;
		
		this->panel1->Focus();

	}

    private: System::Void DeletItemButton_Click(System::Object^ sender, System::EventArgs^ e) {
    
		std::regex pattern("^([0-9]{2}[-]{1}){2}[0-9]{2}$");
		std::string line = msclr::interop::marshal_as<std::string>(this->SearchTextBox->Text->ToString());

		if (table == nullptr)
		{
			MessageBox::Show(this,"Empty table","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (this->SearchTextBox->Text->ToString() == "" || !std::regex_match(line, pattern))
		{
			MessageBox::Show(this,"Incorrect input","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (table->DeleteField(line))MessageBox::Show(this, "Successfully deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else MessageBox::Show(this, "Nothind found", "Unsuccess", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}

    private: System::Void CleanButton_Click(System::Object^ sender, System::EventArgs^ e) {
    
		this->TimeChart->Series["Time"]->Points->Clear();

	}


    };
}