#pragma once

#include"ATSForm.h"

#include<msclr/marshal_cppstd.h>
#include<regex>
#include<string>

namespace GUIATS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyAddForm : public System::Windows::Forms::Form
	{
	private:

		ATS<Info>* list = nullptr;

	public:

		void SetList(ATS<Info>* list)
		{
			this->list = list;
		}

		ATS<Info>* GetList()
		{
			return this->list;
		}

		MyAddForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyAddForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ CodeTextBox;
	protected:
	private: System::Windows::Forms::TextBox^ CityTextBox;
	private: System::Windows::Forms::TextBox^ TimeTextBox;
	private: System::Windows::Forms::TextBox^ RateTextBox;
	private: System::Windows::Forms::TextBox^ DateTextBox;
	private: System::Windows::Forms::TextBox^ CitynumTextBox;
	private: System::Windows::Forms::TextBox^ CustomnumTextBox;
	private: System::Windows::Forms::Button^ AddButton;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->CodeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CitynumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CustomnumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// CodeTextBox
			// 
			this->CodeTextBox->Location = System::Drawing::Point(86, 73);
			this->CodeTextBox->Name = L"CodeTextBox";
			this->CodeTextBox->Size = System::Drawing::Size(155, 22);
			this->CodeTextBox->TabIndex = 0;
			this->CodeTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::CodeTextBox_MouseClick);
			this->CodeTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::CodeTextBox_Leave);
			// 
			// CityTextBox
			// 
			this->CityTextBox->Location = System::Drawing::Point(86, 123);
			this->CityTextBox->Name = L"CityTextBox";
			this->CityTextBox->Size = System::Drawing::Size(155, 22);
			this->CityTextBox->TabIndex = 1;
			this->CityTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::CityTextBox_MouseClick);
			this->CityTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::CityTextBox_Leave);
			// 
			// TimeTextBox
			// 
			this->TimeTextBox->Location = System::Drawing::Point(86, 173);
			this->TimeTextBox->Name = L"TimeTextBox";
			this->TimeTextBox->Size = System::Drawing::Size(155, 22);
			this->TimeTextBox->TabIndex = 2;
			this->TimeTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::TimeTextBox_MouseClick);
			this->TimeTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::TimeTextBox_Leave);
			// 
			// RateTextBox
			// 
			this->RateTextBox->Location = System::Drawing::Point(86, 224);
			this->RateTextBox->Name = L"RateTextBox";
			this->RateTextBox->Size = System::Drawing::Size(155, 22);
			this->RateTextBox->TabIndex = 3;
			this->RateTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::RateTextBox_MouseClick);
			this->RateTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::RateTextBox_Leave);
			// 
			// DateTextBox
			// 
			this->DateTextBox->Location = System::Drawing::Point(86, 29);
			this->DateTextBox->Name = L"DateTextBox";
			this->DateTextBox->Size = System::Drawing::Size(155, 22);
			this->DateTextBox->TabIndex = 4;
			this->DateTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::DateTextBox_MouseClick);
			this->DateTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::DateTextBox_Leave);
			// 
			// CitynumTextBox
			// 
			this->CitynumTextBox->Location = System::Drawing::Point(86, 276);
			this->CitynumTextBox->Name = L"CitynumTextBox";
			this->CitynumTextBox->Size = System::Drawing::Size(155, 22);
			this->CitynumTextBox->TabIndex = 5;
			this->CitynumTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::CitynumTextBox_MouseClick);
			this->CitynumTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::CitynumTextBox_Leave);
			// 
			// CustomnumTextBox
			// 
			this->CustomnumTextBox->Location = System::Drawing::Point(86, 328);
			this->CustomnumTextBox->Name = L"CustomnumTextBox";
			this->CustomnumTextBox->Size = System::Drawing::Size(155, 22);
			this->CustomnumTextBox->TabIndex = 6;
			this->CustomnumTextBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::CustomnumTextBox_MouseClick);
			this->CustomnumTextBox->Leave += gcnew System::EventHandler(this, &MyAddForm::CustomnumTextBox_Leave);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(122, 382);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 23);
			this->AddButton->TabIndex = 7;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyAddForm::AddButton_Click);
			// 
			// MyAddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(346, 417);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->CustomnumTextBox);
			this->Controls->Add(this->CitynumTextBox);
			this->Controls->Add(this->DateTextBox);
			this->Controls->Add(this->RateTextBox);
			this->Controls->Add(this->TimeTextBox);
			this->Controls->Add(this->CityTextBox);
			this->Controls->Add(this->CodeTextBox);
			this->Name = L"MyAddForm";
			this->Text = L"MyAddForm";
			this->Load += gcnew System::EventHandler(this, &MyAddForm::MyAddForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyAddForm::MyAddForm_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Done

	private: System::Void MyAddForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->DateTextBox->Text = "Date";
		this->DateTextBox->ForeColor = Color::Gray;

		this->CodeTextBox->Text = "Code";
		this->CodeTextBox->ForeColor = Color::Gray;

		this->CityTextBox->Text = "City";
		this->CityTextBox->ForeColor = Color::Gray;

		this->TimeTextBox->Text = "Time";
		this->TimeTextBox->ForeColor = Color::Gray;

		this->RateTextBox->Text = "Rate";
		this->RateTextBox->ForeColor = Color::Gray;

		this->CitynumTextBox->Text = "City number";
		this->CitynumTextBox->ForeColor = Color::Gray;

		this->CustomnumTextBox->Text = "Custom number";
		this->CustomnumTextBox->ForeColor = Color::Gray;

	}
 
	// Done

    private: System::Void MyAddForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->DateTextBox->Text == "")
		{
			this->DateTextBox->Text = "Date";
			this->DateTextBox->ForeColor = Color::Gray;
		}

		if (this->CodeTextBox->Text == "")
		{
			this->CodeTextBox->Text = "Code";
			this->CodeTextBox->ForeColor = Color::Gray;
		}

		if (this->CityTextBox->Text == "")
		{
			this->CityTextBox->Text = "City";
			this->CityTextBox->ForeColor = Color::Gray;
		}

		if (this->TimeTextBox->Text == "")
		{
			this->TimeTextBox->Text = "Time";
			this->TimeTextBox->ForeColor = Color::Gray;
		}

		if (this->RateTextBox->Text == "")
		{
			this->RateTextBox->Text = "Rate";
			this->RateTextBox->ForeColor = Color::Gray;
		}

		if (this->CitynumTextBox->Text == "")
		{
			this->CitynumTextBox->Text = "City number";
			this->CitynumTextBox->ForeColor = Color::Gray;
		}

		if (this->CustomnumTextBox->Text == "")
		{
			this->CustomnumTextBox->Text = "Custom number";
			this->CustomnumTextBox->ForeColor = Color::Gray;
		}

    }

	// DateTextBox

    private: System::Void DateTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	if (this->DateTextBox->ForeColor == Color::Gray)
	{
		this->DateTextBox->Text = "";
		this->DateTextBox->ForeColor = Color::Black;
	}
}

		   private: System::Void DateTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			   if (this->DateTextBox->Text == "")
			   {
				   this->DateTextBox->ForeColor = Color::Gray;
				   this->DateTextBox->Text = "Date";
			   }
		   }

	// CodeTextBox

    private: System::Void CodeTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	if (this->CodeTextBox->ForeColor == Color::Gray)
	{
		this->CodeTextBox->Text = "";
		this->CodeTextBox->ForeColor = Color::Black;
	}

}

		   private: System::Void CodeTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			   if (this->CodeTextBox->Text == "")
			   {
				   this->CodeTextBox->Text = "Code";
				   this->CodeTextBox->ForeColor = Color::Gray;
			   }
		   }

    // CityTextBox    

    private: System::Void CityTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->CityTextBox->ForeColor == Color::Gray)
		{
			this->CityTextBox->Text = "";
			this->CityTextBox->ForeColor = Color::Black;
		}

    }

			private: System::Void CityTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
				if (this->CityTextBox->Text == "")
				{
					this->CityTextBox->Text = "City";
					this->CityTextBox->ForeColor = Color::Gray;
				}
			}

	// TimeTextBox

    private: System::Void TimeTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->TimeTextBox->ForeColor == Color::Gray)
		{
			this->TimeTextBox->Text = "";
			this->TimeTextBox->ForeColor = Color::Black;
		}

    }


		   private: System::Void TimeTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			   if (this->TimeTextBox->Text == "")
			   {
				   this->TimeTextBox->ForeColor = Color::Gray;
				   this->TimeTextBox->Text = "Time";
			   }
		   }



	// RateTextBox

    private: System::Void RateTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->RateTextBox->ForeColor == Color::Gray)
		{
			this->RateTextBox->Text = "";
			this->RateTextBox->ForeColor = Color::Black;
		}

    }

		   private: System::Void RateTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			   if (this->RateTextBox->Text == "")
			   {
				   this->RateTextBox->ForeColor = Color::Gray;
				   this->RateTextBox->Text = "Rate";
			   }
		   }

	// CitynumberTextBox

    private: System::Void CitynumTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->CitynumTextBox->ForeColor == Color::Gray)
		{
			this->CitynumTextBox->Text = "";
			this->CitynumTextBox->ForeColor = Color::Black;
		}

    }

				  private: System::Void CitynumTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
					  if (this->CitynumTextBox->Text == "")
					  {
						  this->CitynumTextBox->ForeColor = Color::Gray;
						  this->CitynumTextBox->Text = "City number";
					  }
				  }

	// Customnumber

    private: System::Void CustomnumTextBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->CustomnumTextBox->ForeColor == Color::Gray)
		{
			this->CustomnumTextBox->Text = "";
			this->CustomnumTextBox->ForeColor = Color::Black;
		}

    }

		   private: System::Void CustomnumTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			   if (this->CustomnumTextBox->Text == "")
			   {
				   this->CustomnumTextBox->ForeColor = Color::Gray;
				   this->CustomnumTextBox->Text = "Custom number";
			   }

		   }

    private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if ((this->DateTextBox->Text == "" || this->DateTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if ((this->CodeTextBox->Text == "" || this->CodeTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty code", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if ((this->CityTextBox->Text == "" || this->CityTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty city", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if ((this->TimeTextBox->Text == "" || this->TimeTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty time", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if ((this->RateTextBox->Text == "" || this->RateTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty rate", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if ((this->CitynumTextBox->Text == "" || this->CitynumTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty city number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if ((this->CustomnumTextBox->Text == "" || this->CustomnumTextBox->ForeColor == Color::Gray))
		{
			MessageBox::Show(this, "Empty custom number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		std::regex date("^([0-9]{2}[.]{1}){2}([0-9]{4}){1}$");
		std::regex code("^[+]{1}[0-9]+$");
		std::regex time("^[0-9]+$");
		std::regex number("^[+]?[0-9]+$");

		if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->DateTextBox->Text), date))
		{
			MessageBox::Show(this, "Incorrect date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->CodeTextBox->Text), code))
		{
			MessageBox::Show(this, "Incorrect code", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->TimeTextBox->Text), time))
		{
			MessageBox::Show(this, "Incorrect time", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->CitynumTextBox->Text), number))
		{
			MessageBox::Show(this, "Incorrect city number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->CustomnumTextBox->Text), number))
		{
			MessageBox::Show(this, "Incorrect custom number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Info info;

		info.SetDate(msclr::interop::marshal_as<std::string>(this->DateTextBox->Text));
		info.SetCode(Convert::ToInt32(this->CodeTextBox->Text));
		info.SetCity(msclr::interop::marshal_as<std::string>(this->CityTextBox->Text));
		info.SetTime(Convert::ToInt32(this->TimeTextBox->Text));
		info.SetRate(msclr::interop::marshal_as<std::string>(this->	RateTextBox->Text));
		info.SetCitynumber(msclr::interop::marshal_as<std::string>(this->CitynumTextBox->Text));
		info.SetCustomnumber(msclr::interop::marshal_as<std::string>(this->CustomnumTextBox->Text));

		list->push_back(info);

		MessageBox::Show(this, "Successfully added", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		Close();

    }

};
}