#pragma once
#include"..\ClassFirm\Firm.h"
#include<msclr/marshal_cppstd.h>

namespace GUIFirm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Delete : public System::Windows::Forms::Form
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


		Delete(void)
		{
			InitializeComponent();
		}

	protected:

		~Delete()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ComboBox^ DeleteNameComboBox;
	private: System::Windows::Forms::ComboBox^ DeleteExecutorComboBox;
	private: System::Windows::Forms::Button^ DeleteButton;
	protected:

	protected:



	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->DeleteNameComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteExecutorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// DeleteNameComboBox
			// 
			this->DeleteNameComboBox->FormattingEnabled = true;
			this->DeleteNameComboBox->Location = System::Drawing::Point(126, 48);
			this->DeleteNameComboBox->Name = L"DeleteNameComboBox";
			this->DeleteNameComboBox->Size = System::Drawing::Size(150, 24);
			this->DeleteNameComboBox->TabIndex = 0;
			this->DeleteNameComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Delete::DeleteNameComboBox_SelectedIndexChanged);
			// 
			// DeleteExecutorComboBox
			// 
			this->DeleteExecutorComboBox->FormattingEnabled = true;
			this->DeleteExecutorComboBox->Location = System::Drawing::Point(126, 158);
			this->DeleteExecutorComboBox->Name = L"DeleteExecutorComboBox";
			this->DeleteExecutorComboBox->Size = System::Drawing::Size(150, 24);
			this->DeleteExecutorComboBox->TabIndex = 1;
			this->DeleteExecutorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Delete::DeleteExecutorComboBox_SelectedIndexChanged);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(142, 267);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(115, 23);
			this->DeleteButton->TabIndex = 2;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &Delete::DeleteButton_Click);
			// 
			// Delete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 397);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->DeleteExecutorComboBox);
			this->Controls->Add(this->DeleteNameComboBox);
			this->Name = L"Delete";
			this->Text = L"Delete";
			this->ResumeLayout(false);

		}
#pragma endregion

	// Done

	private: System::Void DeleteNameComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		this->DeleteExecutorComboBox->Items->Clear();
		
		for (int i = 0; i < size; i++)
		{
			if (this->DeleteNameComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>(List[i].GetProjectName()))
				this->DeleteExecutorComboBox->Items->Add(msclr::interop::marshal_as<String^>(List[i].GetExecutor()));
		}

	}

	// Done

	private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (MessageBox::Show(this, "Are you sure?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
		{

			if (this->DeleteNameComboBox->SelectedItem != NULL)
			{
				if (this->DeleteExecutorComboBox->SelectedItem != NULL)
				{
					for (int i = 0; i < size; i++)
						if (this->DeleteNameComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>(List[i].GetProjectName()))
							if (this->DeleteExecutorComboBox->SelectedItem->ToString() == msclr::interop::marshal_as<String^>(List[i].GetExecutor()))
							{
								Firm* newlist = new Firm[--size];
								for (int k = 0, p = 0; k < size + 1; k++)
									if (k != i)newlist[p++]=List[k];
								delete[] List, List = nullptr;
								if (size != 0)List = newlist;
								else delete[]newlist, newlist = nullptr;
								break;
							}

					MessageBox::Show(this, "Successfully deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

					Close();

				}
				else MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void DeleteExecutorComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}