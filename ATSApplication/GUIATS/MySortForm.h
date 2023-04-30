#pragma once

#include"ATSForm.h"

namespace GUIATS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MySortForm : public System::Windows::Forms::Form
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
			return list;
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
			this->SortComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Date", L"Code", L"City", L"Time", L"Rate",
					L"City number", L"Custom number"
			});
			this->SortComboBox->Location = System::Drawing::Point(68, 75);
			this->SortComboBox->Name = L"SortComboBox";
			this->SortComboBox->Size = System::Drawing::Size(172, 24);
			this->SortComboBox->TabIndex = 0;
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(113, 162);
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
			this->ClientSize = System::Drawing::Size(311, 291);
			this->Controls->Add(this->SortButton);
			this->Controls->Add(this->SortComboBox);
			this->Name = L"MySortForm";
			this->Text = L"MySortForm";
			this->ResumeLayout(false);

		}
#pragma endregion

		bool Compare(std::string date1, std::string date2)
		{
			std::string day1="";
			for (int i = 0; i < 2; i++) day1+= date1[i];
			std::string day2="";
			for (int i = 0; i < 2; i++)day2 += date2[i];
			std::string month1;
			for (int i = 3; i < 5; i++)month1+= date1[i];
			std::string month2;
			for (int i = 3; i < 5; i++)month2+= date2[i];
			std::string year1;
			for (int i = 6; i < 10; i++)year1+= date1[i];
			std::string year2;
			for (int i = 6; i < 10; i++)year2+= date2[i];

			if (stoi(year1) > stoi(year2))return true;
			else if (stoi(year1) == stoi(year2))
			{
				if (stoi(month1) > stoi(month2))return true;
				else if (stoi(month1) == stoi(month2))
				{
					if (stoi(day1) >= stoi(day2))return true;
					return false;
				}
				return false;
			}
			return false;

		}

		void MergeSortDate(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if (Compare((*list)[start].GetDate(), (*list)[start+1].GetDate()))
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortDate(start, start + (end - start) / 2);
			MergeSortDate(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && Compare((*list)[b1].GetDate(), (*list)[b2].GetDate())))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

		void MergeSortCode(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if ((*list)[start].GetCode()> (*list)[start + 1].GetCode())
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortCode(start, start + (end - start) / 2);
			MergeSortCode(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && (*list)[b1].GetCode()>=(*list)[b2].GetCode()))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

		void MergeSortCity(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if ((*list)[start].GetCity() > (*list)[start + 1].GetCity())
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortCity(start, start + (end - start) / 2);
			MergeSortCity(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && (*list)[b1].GetCity() >= (*list)[b2].GetCity()))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

		void MergeSortTime(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if ((*list)[start].GetTime() > (*list)[start + 1].GetTime())
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortTime(start, start + (end - start) / 2);
			MergeSortTime(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && (*list)[b1].GetTime() >= (*list)[b2].GetTime()))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

		void MergeSortRate(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if ((*list)[start].GetRate() > (*list)[start + 1].GetRate())
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortRate(start, start + (end - start) / 2);
			MergeSortRate(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && (*list)[b1].GetRate() >= (*list)[b2].GetRate()))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

		void MergeSortCitynumber(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if (stoll((*list)[start].GetCitynumber()) > stoll((*list)[start + 1].GetCitynumber()))
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortCitynumber(start, start + (end - start) / 2);
			MergeSortCitynumber(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && stoll((*list)[b1].GetCitynumber()) >= stoll((*list)[b2].GetCitynumber())))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

		void MergeSortCustomnumber(int start, int end)
		{

			if (end - start < 2)return;
			if (end - start == 2)
			{
				if (stoll((*list)[start].GetCustomnumber()) > stoll((*list)[start + 1].GetCustomnumber()))
				{
					auto temp1 = (*list)[start].GetDate();
					(*list)[start].SetDate((*list)[start + 1].GetDate());
					(*list)[start + 1].SetDate(temp1);
					auto temp2 = (*list)[start].GetCode();
					(*list)[start].SetCode((*list)[start + 1].GetCode());
					(*list)[start + 1].SetCode(temp2);
					auto temp3 = (*list)[start].GetCity();
					(*list)[start].SetCity((*list)[start + 1].GetCity());
					(*list)[start + 1].SetCity(temp3);
					auto temp4 = (*list)[start].GetTime();
					(*list)[start].SetTime((*list)[start + 1].GetTime());
					(*list)[start + 1].SetTime(temp4);
					auto temp5 = (*list)[start].GetRate();
					(*list)[start].SetRate((*list)[start + 1].GetRate());
					(*list)[start + 1].SetRate(temp5);
					auto temp6 = (*list)[start].GetCitynumber();
					(*list)[start].SetCitynumber((*list)[start + 1].GetCitynumber());
					(*list)[start + 1].SetCitynumber(temp6);
					auto temp7 = (*list)[start].GetCustomnumber();
					(*list)[start].SetCustomnumber((*list)[start + 1].GetCustomnumber());
					(*list)[start + 1].SetCustomnumber(temp7);
				}
				return;
			}

			MergeSortCustomnumber(start, start + (end - start) / 2);
			MergeSortCustomnumber(start + (end - start) / 2, end);

			ATS<Info> list2;

			int b1 = start;
			int e1 = start + (end - start) / 2;
			int b2 = e1;
			while (list2.Size() < end - start)
			{
				if (b1 >= e1 || (b2 < end && stoll((*list)[b1].GetCustomnumber()) >= stoll((*list)[b2].GetCustomnumber())))
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
				(*list)[i].SetDate(list2[i - start].GetDate());
				(*list)[i].SetCode(list2[i - start].GetCode());
				(*list)[i].SetCity(list2[i - start].GetCity());
				(*list)[i].SetTime(list2[i - start].GetTime());
				(*list)[i].SetRate(list2[i - start].GetRate());
				(*list)[i].SetCitynumber(list2[i - start].GetCitynumber());
				(*list)[i].SetCustomnumber(list2[i - start].GetCustomnumber());
			}
		}

	private: System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->SortComboBox->SelectedItem == nullptr)
		{
			MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		switch (this->SortComboBox->SelectedIndex)
		{
		case 0:
		{
			MergeSortDate(0, list->Size());
			break;
		}
		case 1:
		{
			MergeSortCode(0, list->Size());
			break;
		}
		case 2:
		{
			MergeSortCity(0, list->Size());
			break;
		}
		case 3:
		{
			MergeSortTime(0, list->Size());
			break;
		}
		case 4:
		{
			MergeSortRate(0, list->Size());
			break;
		}
		case 5:
		{
			MergeSortCitynumber(0, list->Size());
			break;
		}
		case 6:
		{
			MergeSortCustomnumber(0, list->Size());
			break;
		}
		}

		MessageBox::Show(this, "Successfully sorted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		Close();

	}

	};
}