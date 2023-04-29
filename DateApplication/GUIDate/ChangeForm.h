#pragma once
#include<msclr/marshal_cppstd.h>
#include<regex>
#include<string>

namespace GUIDate {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// —водка дл€ ChangeForm
	/// </summary>
	public ref class ChangeForm : public System::Windows::Forms::Form
	{
	public:
		
		ChangeForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ChangeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ DateChangeList;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	public:
	protected:

	protected:

	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
	public: void InitializeComponent(void)
		{
		this->DateChangeList = (gcnew System::Windows::Forms::DataGridView());
		this->SaveButton = (gcnew System::Windows::Forms::Button());
		this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DateChangeList))->BeginInit();
		this->SuspendLayout();
		// 
		// DateChangeList
		// 

		this->DateChangeList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->DateChangeList->Location = System::Drawing::Point(12, 12);
		this->DateChangeList->Name = L"DateChangeList";
		this->DateChangeList->RowHeadersWidth = 51;
		this->DateChangeList->RowTemplate->Height = 24;
		this->DateChangeList->Size = System::Drawing::Size(225, 499);
		this->DateChangeList->TabIndex = 1;
		this->DateChangeList->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ChangeForm::DateChangeList_CellContentClick);

		// 
		// SaveButton
		// 
		this->SaveButton->Location = System::Drawing::Point(403, 284);
		this->SaveButton->Name = L"SaveButton";
		this->SaveButton->Size = System::Drawing::Size(75, 23);
		this->SaveButton->TabIndex = 2;
		this->SaveButton->Text = L"Save";
		this->SaveButton->UseVisualStyleBackColor = true;
		this->SaveButton->Click += gcnew System::EventHandler(this, &ChangeForm::SaveButton_Click);
		// 
		// openFileDialog1
		// 
		this->openFileDialog1->FileName = L"openFileDialog1";
		this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &ChangeForm::openFileDialog1_FileOk);
		// 
		// ChangeForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Gold;
		this->ClientSize = System::Drawing::Size(517, 523);
		this->Controls->Add(this->SaveButton);
		this->Controls->Add(this->DateChangeList);
		this->Name = L"ChangeForm";
		this->Text = L"ChangeForm";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DateChangeList))->EndInit();
		this->ResumeLayout(false);

	}
#pragma endregion
	
    // Only this function is using to work with editing dates in user's list

	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		std::regex check("^([0-9]{2}[.]{1}){2}([0-9]{4})$"); // Regular expression to check inputed date
	    
		for (int i = 0; i<this->DateChangeList->Rows->Count; i++)
		{

			// try-catch to check an exception: "Object reference not set to an instance of an object0"

			try
			{

				// If regex_match returns false, the cycle will stop and show the number of line with incorrect inputed date

				if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->DateChangeList->Rows[i]->Cells[0]->Value->ToString()), check))
				{
					MessageBox::Show(this, "Incorrect date in the line" + (i + 1), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					break;
				}

			}
			catch (NullReferenceException^ e)
			{
				
			}

			if (i == this->DateChangeList->Rows->Count-2)
			{

				// the same structure as the previous step, but added streamwriter and removed regex checking

				String^ filename = "";
				if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)filename = openFileDialog1->FileName;

				try
				{

					StreamWriter^ file = gcnew StreamWriter(filename);

					for (int j = 0; j < this->DateChangeList->RowCount; j++) 
						try
					    {
						file->WriteLine(this->DateChangeList->Rows[j]->Cells[0]->Value->ToString());
					    }
					catch (NullReferenceException^ e)
					{
						continue;
					}
					file->Close();

				}
				catch (Exception^ e)
				{
					MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				
			}
		}

	}

	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}

	private: System::Void DateChangeList_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}

};
}
