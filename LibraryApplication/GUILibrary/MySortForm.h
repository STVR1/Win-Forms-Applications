#pragma once

#include"LibraryForm.h"

namespace GUILibrary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MySortForm : public System::Windows::Forms::Form
	{

	private:

		Library<Info>* list = nullptr;

	public:

		void SetList(Library<Info>* list)
		{
			this->list = list;
		}

		Library<Info>* GetList()
		{
			return this->list;
		}

		MySortForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MySortForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ SortComboBox;
	protected:
	private: System::Windows::Forms::Button^ SortButton;



	protected:

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->SortComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SortComboBox
			// 
			this->SortComboBox->FormattingEnabled = true;
			this->SortComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Amount", L"Author", L"Date", L"Name", L"Office",
					L"Register number"
			});
			this->SortComboBox->Location = System::Drawing::Point(73, 51);
			this->SortComboBox->Name = L"SortComboBox";
			this->SortComboBox->Size = System::Drawing::Size(121, 24);
			this->SortComboBox->TabIndex = 0;
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(95, 143);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(75, 23);
			this->SortButton->TabIndex = 1;
			this->SortButton->Text = L"Sort";
			this->SortButton->UseVisualStyleBackColor = true;
			this->SortButton->Click += gcnew System::EventHandler(this, &MySortForm::SortButton_Click);
			// 
			// MySortForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(271, 259);
			this->Controls->Add(this->SortButton);
			this->Controls->Add(this->SortComboBox);
			this->Name = L"MySortForm";
			this->Text = L"MySortForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	void MergeSortRegnum(int start, int end)
	{

		if (end - start < 2)return;
		if (end - start == 2)
		{
			if ((*list)[start].GetRegnum() > (*list)[start + 1].GetRegnum())
			{
				auto temp1 = (*list)[start].GetAmount();
				(*list)[start].SetAmount((*list)[start + 1].GetAmount());
				(*list)[start + 1].SetAmount(temp1);
				auto temp2 = (*list)[start].GetAuthor();
				(*list)[start].SetAuthor((*list)[start + 1].GetAuthor());
				(*list)[start + 1].SetAuthor(temp2);
				auto temp3 = (*list)[start].GetName();
				(*list)[start].SetName((*list)[start + 1].GetName());
				(*list)[start + 1].SetName(temp2);
				auto temp4 = (*list)[start].GetDate();
				(*list)[start].SetDate((*list)[start + 1].GetDate());
				(*list)[start + 1].SetDate(temp4);
				auto temp5 = (*list)[start].GetOffice();
				(*list)[start].SetOffice((*list)[start + 1].GetOffice());
				(*list)[start + 1].SetOffice(temp5);
				auto temp6 = (*list)[start].GetRegnum();
				(*list)[start].SetRegnum((*list)[start + 1].GetRegnum());
				(*list)[start + 1].SetRegnum(temp6);
			}
			return;
		}

		MergeSortRegnum(start, start+(end-start)/2);
		MergeSortRegnum(start + (end - start) / 2, end);

		Library<Info> list2;

		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;
		while (list2.GetSize() < end - start)
		{
			if (b1 >= e1 || (b2 < end && (*list)[b2].GetRegnum() <= (*list)[b1].GetRegnum()))
			{
				list2.push_back((*list)[b2]);
				++b2;
			}
			else
			{
				list2.push_back((*list)[b1]);
				++b1;
			}
		}
		for (int i = start; i < end; ++i)
		{
			(*list)[i].SetAmount(list2[i - start].GetAmount());
			(*list)[i].SetAuthor(list2[i - start].GetAuthor());
			(*list)[i].SetName(list2[i - start].GetName());
			(*list)[i].SetDate(list2[i - start].GetDate());
			(*list)[i].SetOffice(list2[i - start].GetOffice());
			(*list)[i].SetRegnum(list2[i - start].GetRegnum());
		}
	}

	void MergeSortAmount(int start, int end)
	{

		if (end - start < 2)return;
		if (end - start == 2)
		{
			if ((*list)[start].GetAmount() > (*list)[start + 1].GetAmount())
			{
				auto temp1 = (*list)[start].GetAmount();
				(*list)[start].SetAmount((*list)[start + 1].GetAmount());
				(*list)[start + 1].SetAmount(temp1);
				auto temp2 = (*list)[start].GetAuthor();
				(*list)[start].SetAuthor((*list)[start + 1].GetAuthor());
				(*list)[start + 1].SetAuthor(temp2);
				auto temp3 = (*list)[start].GetName();
				(*list)[start].SetName((*list)[start + 1].GetName());
				(*list)[start + 1].SetName(temp2);
				auto temp4 = (*list)[start].GetDate();
				(*list)[start].SetDate((*list)[start + 1].GetDate());
				(*list)[start + 1].SetDate(temp4);
				auto temp5 = (*list)[start].GetOffice();
				(*list)[start].SetOffice((*list)[start + 1].GetOffice());
				(*list)[start + 1].SetOffice(temp5);
				auto temp6 = (*list)[start].GetRegnum();
				(*list)[start].SetRegnum((*list)[start + 1].GetRegnum());
				(*list)[start + 1].SetRegnum(temp6);
			}
			return;
		}

		MergeSortRegnum(start, start + (end - start) / 2);
		MergeSortRegnum(start + (end - start) / 2, end);

		Library<Info> list2;

		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;
		while (list2.GetSize() < end - start)
		{
			if (b1 >= e1 || (b2 < end && (*list)[b2].GetAmount() <= (*list)[b1].GetAmount()))
			{
				list2.push_back((*list)[b2]);
				++b2;
			}
			else
			{
				list2.push_back((*list)[b1]);
				++b1;
			}
		}
		for (int i = start; i < end; ++i)
		{
			(*list)[i].SetAmount(list2[i - start].GetAmount());
			(*list)[i].SetAuthor(list2[i - start].GetAuthor());
			(*list)[i].SetName(list2[i - start].GetName());
			(*list)[i].SetDate(list2[i - start].GetDate());
			(*list)[i].SetOffice(list2[i - start].GetOffice());
			(*list)[i].SetRegnum(list2[i - start].GetRegnum());
		}
	}

	void MergeSortAuthor(int start, int end)
	{

		if (end - start < 2)return;
		if (end - start == 2)
		{
			if ((*list)[start].GetAuthor() > (*list)[start + 1].GetAuthor())
			{
				auto temp1 = (*list)[start].GetAmount();
				(*list)[start].SetAmount((*list)[start + 1].GetAmount());
				(*list)[start + 1].SetAmount(temp1);
				auto temp2 = (*list)[start].GetAuthor();
				(*list)[start].SetAuthor((*list)[start + 1].GetAuthor());
				(*list)[start + 1].SetAuthor(temp2);
				auto temp3 = (*list)[start].GetName();
				(*list)[start].SetName((*list)[start + 1].GetName());
				(*list)[start + 1].SetName(temp2);
				auto temp4 = (*list)[start].GetDate();
				(*list)[start].SetDate((*list)[start + 1].GetDate());
				(*list)[start + 1].SetDate(temp4);
				auto temp5 = (*list)[start].GetOffice();
				(*list)[start].SetOffice((*list)[start + 1].GetOffice());
				(*list)[start + 1].SetOffice(temp5);
				auto temp6 = (*list)[start].GetRegnum();
				(*list)[start].SetRegnum((*list)[start + 1].GetRegnum());
				(*list)[start + 1].SetRegnum(temp6);
			}
			return;
		}

		MergeSortRegnum(start, start + (end - start) / 2);
		MergeSortRegnum(start + (end - start) / 2, end);

		Library<Info> list2;

		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;
		while (list2.GetSize() < end - start)
		{
			if (b1 >= e1 || (b2 < end && (*list)[b2].GetAuthor() <= (*list)[b1].GetAuthor()))
			{
				list2.push_back((*list)[b2]);
				++b2;
			}
			else
			{
				list2.push_back((*list)[b1]);
				++b1;
			}
		}
		for (int i = start; i < end; ++i)
		{
			(*list)[i].SetAmount(list2[i - start].GetAmount());
			(*list)[i].SetAuthor(list2[i - start].GetAuthor());
			(*list)[i].SetName(list2[i - start].GetName());
			(*list)[i].SetDate(list2[i - start].GetDate());
			(*list)[i].SetOffice(list2[i - start].GetOffice());
			(*list)[i].SetRegnum(list2[i - start].GetRegnum());
		}
	}

	void MergeSortName(int start, int end)
	{

		if (end - start < 2)return;
		if (end - start == 2)
		{
			if ((*list)[start].GetName() > (*list)[start + 1].GetName())
			{
				auto temp1 = (*list)[start].GetAmount();
				(*list)[start].SetAmount((*list)[start + 1].GetAmount());
				(*list)[start + 1].SetAmount(temp1);
				auto temp2 = (*list)[start].GetAuthor();
				(*list)[start].SetAuthor((*list)[start + 1].GetAuthor());
				(*list)[start + 1].SetAuthor(temp2);
				auto temp3 = (*list)[start].GetName();
				(*list)[start].SetName((*list)[start + 1].GetName());
				(*list)[start + 1].SetName(temp2);
				auto temp4 = (*list)[start].GetDate();
				(*list)[start].SetDate((*list)[start + 1].GetDate());
				(*list)[start + 1].SetDate(temp4);
				auto temp5 = (*list)[start].GetOffice();
				(*list)[start].SetOffice((*list)[start + 1].GetOffice());
				(*list)[start + 1].SetOffice(temp5);
				auto temp6 = (*list)[start].GetRegnum();
				(*list)[start].SetRegnum((*list)[start + 1].GetRegnum());
				(*list)[start + 1].SetRegnum(temp6);
			}
			return;
		}

		MergeSortRegnum(start, start + (end - start) / 2);
		MergeSortRegnum(start + (end - start) / 2, end);

		Library<Info> list2;

		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;
		while (list2.GetSize() < end - start)
		{
			if (b1 >= e1 || (b2 < end && (*list)[b2].GetName() <= (*list)[b1].GetName()))
			{
				list2.push_back((*list)[b2]);
				++b2;
			}
			else
			{
				list2.push_back((*list)[b1]);
				++b1;
			}
		}
		for (int i = start; i < end; ++i)
		{
			(*list)[i].SetAmount(list2[i - start].GetAmount());
			(*list)[i].SetAuthor(list2[i - start].GetAuthor());
			(*list)[i].SetName(list2[i - start].GetName());
			(*list)[i].SetDate(list2[i - start].GetDate());
			(*list)[i].SetOffice(list2[i - start].GetOffice());
			(*list)[i].SetRegnum(list2[i - start].GetRegnum());
		}
	}

	void MergeSortOffice(int start, int end)
	{

		if (end - start < 2)return;
		if (end - start == 2)
		{
			if ((*list)[start].GetOffice() > (*list)[start + 1].GetOffice())
			{
				auto temp1 = (*list)[start].GetAmount();
				(*list)[start].SetAmount((*list)[start + 1].GetAmount());
				(*list)[start + 1].SetAmount(temp1);
				auto temp2 = (*list)[start].GetAuthor();
				(*list)[start].SetAuthor((*list)[start + 1].GetAuthor());
				(*list)[start + 1].SetAuthor(temp2);
				auto temp3 = (*list)[start].GetName();
				(*list)[start].SetName((*list)[start + 1].GetName());
				(*list)[start + 1].SetName(temp2);
				auto temp4 = (*list)[start].GetDate();
				(*list)[start].SetDate((*list)[start + 1].GetDate());
				(*list)[start + 1].SetDate(temp4);
				auto temp5 = (*list)[start].GetOffice();
				(*list)[start].SetOffice((*list)[start + 1].GetOffice());
				(*list)[start + 1].SetOffice(temp5);
				auto temp6 = (*list)[start].GetRegnum();
				(*list)[start].SetRegnum((*list)[start + 1].GetRegnum());
				(*list)[start + 1].SetRegnum(temp6);
			}
			return;
		}

		MergeSortRegnum(start, start + (end - start) / 2);
		MergeSortRegnum(start + (end - start) / 2, end);

		Library<Info> list2;

		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;
		while (list2.GetSize() < end - start)
		{
			if (b1 >= e1 || (b2 < end && (*list)[b2].GetOffice() <= (*list)[b1].GetOffice()))
			{
				list2.push_back((*list)[b2]);
				++b2;
			}
			else
			{
				list2.push_back((*list)[b1]);
				++b1;
			}
		}
		for (int i = start; i < end; ++i)
		{
			(*list)[i].SetAmount(list2[i - start].GetAmount());
			(*list)[i].SetAuthor(list2[i - start].GetAuthor());
			(*list)[i].SetName(list2[i - start].GetName());
			(*list)[i].SetDate(list2[i - start].GetDate());
			(*list)[i].SetOffice(list2[i - start].GetOffice());
			(*list)[i].SetRegnum(list2[i - start].GetRegnum());
		}
	}

	void MergeSortDate(int start, int end)
	{

		if (end - start < 2)return;
		if (end - start == 2)
		{
			if ((*list)[start].GetDate() > (*list)[start + 1].GetDate())
			{
				auto temp1 = (*list)[start].GetAmount();
				(*list)[start].SetAmount((*list)[start + 1].GetAmount());
				(*list)[start + 1].SetAmount(temp1);
				auto temp2 = (*list)[start].GetAuthor();
				(*list)[start].SetAuthor((*list)[start + 1].GetAuthor());
				(*list)[start + 1].SetAuthor(temp2);
				auto temp3 = (*list)[start].GetName();
				(*list)[start].SetName((*list)[start + 1].GetName());
				(*list)[start + 1].SetName(temp2);
				auto temp4 = (*list)[start].GetDate();
				(*list)[start].SetDate((*list)[start + 1].GetDate());
				(*list)[start + 1].SetDate(temp4);
				auto temp5 = (*list)[start].GetOffice();
				(*list)[start].SetOffice((*list)[start + 1].GetOffice());
				(*list)[start + 1].SetOffice(temp5);
				auto temp6 = (*list)[start].GetRegnum();
				(*list)[start].SetRegnum((*list)[start + 1].GetRegnum());
				(*list)[start + 1].SetRegnum(temp6);
			}
			return;
		}

		MergeSortRegnum(start, start + (end - start) / 2);
		MergeSortRegnum(start + (end - start) / 2, end);

		Library<Info> list2;

		int b1 = start;
		int e1 = start + (end - start) / 2;
		int b2 = e1;
		while (list2.GetSize() < end - start)
		{
			if (b1 >= e1 || (b2 < end && (*list)[b2].GetDate() <= (*list)[b1].GetDate()))
			{
				list2.push_back((*list)[b2]);
				++b2;
			}
			else
			{
				list2.push_back((*list)[b1]);
				++b1;
			}
		}
		for (int i = start; i < end; ++i)
		{
			(*list)[i].SetAmount(list2[i - start].GetAmount());
			(*list)[i].SetAuthor(list2[i - start].GetAuthor());
			(*list)[i].SetName(list2[i - start].GetName());
			(*list)[i].SetDate(list2[i - start].GetDate());
			(*list)[i].SetOffice(list2[i - start].GetOffice());
			(*list)[i].SetRegnum(list2[i - start].GetRegnum());
		}
	}

	private: System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->SortComboBox->SelectedItem != nullptr)
		{
			
			switch (this->SortComboBox->SelectedIndex)
			{
			case 0:
			{
				MergeSortAmount(0, list->GetSize());
				break;
			}
			case 1:
			{
				MergeSortAuthor(0, list->GetSize());
				break;
			}
			case 2:
			{
				MergeSortDate(0, list->GetSize());
				break;
			}
			case 3:
			{
				MergeSortName(0, list->GetSize());
				break;
			}
			case 4:
			{
				MergeSortOffice(0, list->GetSize());
				break;
			}
			case 5:
			{
				MergeSortRegnum(0, list->GetSize());
				break;
			}
			}
			
			MessageBox::Show(this, "Successfully sorted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			Close();

		}
		else MessageBox::Show(this, "Option wasn't chosen", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	};
}