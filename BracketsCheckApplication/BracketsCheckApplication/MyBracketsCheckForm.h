#pragma once

#include"..\StackLibrary\Stack.h"
#include<string>
#include<msclr/marshal_cppstd.h>

namespace BracketsCheckApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MyBracketsCheckForm : public System::Windows::Forms::Form
	{
	public:

		MyBracketsCheckForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyBracketsCheckForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ OpenFIleDialog;
	protected:
	private: System::Windows::Forms::Button^ CheckButton;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->OpenFIleDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->CheckButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// CheckButton
			// 
			this->CheckButton->Location = System::Drawing::Point(157, 332);
			this->CheckButton->Name = L"CheckButton";
			this->CheckButton->Size = System::Drawing::Size(76, 40);
			this->CheckButton->TabIndex = 0;
			this->CheckButton->Text = L"Check";
			this->CheckButton->UseVisualStyleBackColor = true;
			this->CheckButton->Click += gcnew System::EventHandler(this, &MyBracketsCheckForm::CheckButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(54, 36);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(289, 270);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MyBracketsCheckForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(413, 403);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->CheckButton);
			this->Name = L"MyBracketsCheckForm";
			this->Text = L"MyBracketsCheckForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Done

	private: System::Void CheckButton_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ filename = "";
		std::string line="";
		
		if (OpenFIleDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			try
			{

				filename = OpenFIleDialog->FileName;

				StreamReader^ file = gcnew StreamReader(filename);

				MyStack brackets;

				int input = 0;

				bool right = true;
				bool check1 = false;
				bool check2 = false;

				while (file->Peek() >= 0)
				{

					line = msclr::interop::marshal_as<std::string>(file->ReadLine());

					input++;

					for (int i = 0; i < line.size(); i++)
					{
						if (line[i] == '/' && line[++i] == '/')break;
						else if (line[i] == '"')
						{
							if (check1 == false)check1 = true;
							else check1 = false;
						}
						else if (line[i] == '/' && line[++i] == '*')check2 = true;
						else if (line[i] == '*' && line[++i] == '/')check2 = false;
						else if (line[i] == '\'')
						{
							while (line[++i] != '\'');
							if (line[i - 1] == '\\')i++;
						}

						if (check1 == false && check2 == false)
						{
							if (line[i] == '(')
							{
								brackets.push_back(')');
							}
							else if (line[i] == '[')
							{
								brackets.push_back(']');
							}
							else if (line[i] == '{')
							{
								brackets.push_back('}');
							}
							else if (line[i] == ')')
							{
								if (brackets.top() != nullptr)
								{
									if (brackets.top()->info == ')')brackets.pop_back();
									else
									{
										right = false;
										break;
									}
								}
								else
								{
									right = false;
									break;
								}
							}
							else if (line[i] == ']')
							{
								if (brackets.top() != nullptr)
								{
									if (brackets.top()->info == ']')brackets.pop_back();
									else
									{
										right = false;
										break;
									}
								}
								else
								{
									right = false;
									break;
								}
							}
							else if (line[i] == '}')
							{
								if (brackets.top() != nullptr)
								{
									if (brackets.top()->info == '}')brackets.pop_back();
									else
									{
										right = false;
										break;
									}
								}
								else
								{
									right = false;
									break;
								}
							}
						}
					}
					if (right == false)break;
				}

				if (brackets.top() != nullptr)right = false;
				while (brackets.top() != nullptr) brackets.pop_back();

				file->Close();

				if (right == true)
				{
					MessageBox::Show(this, "Brackets are right", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					Bitmap^ myimage = gcnew Bitmap("..\\Pictures\\Cool.png");
					this->pictureBox1->Image = myimage;
				}
				else
				{
					MessageBox::Show(this, "Incorrect. Try again :)", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					Bitmap^ myimage = gcnew Bitmap("..\\Pictures\\Fail.jpg");
					this->pictureBox1->Image = myimage;
				}

			}
			catch(Exception^)
			{
				MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}

	}

	};
}