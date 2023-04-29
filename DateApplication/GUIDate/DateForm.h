#pragma once

#include"..\ClassDate\Date.h"
#include<msclr/marshal_cppstd.h>
#include<regex>
#include<string>
#include"ChangeForm.h"

namespace GUIDate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// —водка дл€ DateForm
	/// </summary>
	public ref class DateForm : public System::Windows::Forms::Form
	{
	public:

		// Our list with date type and its side

		Date* List = NULL;
		int Size = 0;

	private: System::Windows::Forms::ListView^ WeekListView;
	public:
	private: System::Windows::Forms::Label^ WeekListLabel;
	private: System::Windows::Forms::TextBox^ AnyDateTextBox;
	private: System::Windows::Forms::Label^ DurationDatesLabel;
	private: System::Windows::Forms::ListView^ DurationDatesListView;
	private: System::Windows::Forms::Button^ DurationButton;
	private: System::Windows::Forms::Button^ BirthdayDateButton;
	private: System::Windows::Forms::Label^ BirthdayListLabel;
	private: System::Windows::Forms::ListView^ BirthdayListView;
	private: System::Windows::Forms::Label^ DurationMethod;
	private: System::Windows::Forms::Label^ LeapLabel;
	private: System::Windows::Forms::ListView^ LeapListView;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ AddTextBox;



	public:

		DateForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			timer1->Start();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DateForm()
		{
			if (components)
			{
				delete components;
			}
			delete[] List;
		}
	private: System::Windows::Forms::Button^ NextDayButton;
	private: System::Windows::Forms::TextBox^ DateTextBox;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ NextDayLabel;
	private: System::Windows::Forms::Label^ DateBirthdayLabel;
	private: System::Windows::Forms::ListView^ OutputOldDatesListView;



	private: System::Windows::Forms::Button^ PrevDayButton;
	private: System::Windows::Forms::Label^ PrevDayLabel;
	private: System::Windows::Forms::Label^ BirthdayLabel;
	private: System::Windows::Forms::Label^ DurationLabel;
	private: System::Windows::Forms::Label^ WeekLabel;
	private: System::Windows::Forms::Label^ IsLeapLabel;








	private: System::Windows::Forms::Button^ WeekButton;
	private: System::Windows::Forms::Button^ IsLeapButton;






	private: System::Windows::Forms::Label^ ReadDatesLabel;
	private: System::Windows::Forms::Label^ AddLabel;
	private: System::Windows::Forms::Label^ ChangeLabel;



	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ ChangeButton;


	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ListView^ OutputNewDatesListView;

	private: System::Windows::Forms::Label^ OutputOldDatesLabel;
	private: System::Windows::Forms::Label^ OutputNewDatesLabel;
	private: System::Windows::Forms::Button^ ReadDatesButton;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DateForm::typeid));
			this->NextDayButton = (gcnew System::Windows::Forms::Button());
			this->DateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NextDayLabel = (gcnew System::Windows::Forms::Label());
			this->DateBirthdayLabel = (gcnew System::Windows::Forms::Label());
			this->OutputOldDatesListView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->PrevDayButton = (gcnew System::Windows::Forms::Button());
			this->PrevDayLabel = (gcnew System::Windows::Forms::Label());
			this->BirthdayLabel = (gcnew System::Windows::Forms::Label());
			this->DurationLabel = (gcnew System::Windows::Forms::Label());
			this->WeekLabel = (gcnew System::Windows::Forms::Label());
			this->IsLeapLabel = (gcnew System::Windows::Forms::Label());
			this->WeekButton = (gcnew System::Windows::Forms::Button());
			this->IsLeapButton = (gcnew System::Windows::Forms::Button());
			this->ReadDatesLabel = (gcnew System::Windows::Forms::Label());
			this->AddLabel = (gcnew System::Windows::Forms::Label());
			this->ChangeLabel = (gcnew System::Windows::Forms::Label());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->ChangeButton = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->OutputNewDatesListView = (gcnew System::Windows::Forms::ListView());
			this->OutputOldDatesLabel = (gcnew System::Windows::Forms::Label());
			this->OutputNewDatesLabel = (gcnew System::Windows::Forms::Label());
			this->ReadDatesButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->WeekListView = (gcnew System::Windows::Forms::ListView());
			this->WeekListLabel = (gcnew System::Windows::Forms::Label());
			this->AnyDateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DurationDatesLabel = (gcnew System::Windows::Forms::Label());
			this->DurationDatesListView = (gcnew System::Windows::Forms::ListView());
			this->DurationButton = (gcnew System::Windows::Forms::Button());
			this->BirthdayDateButton = (gcnew System::Windows::Forms::Button());
			this->BirthdayListLabel = (gcnew System::Windows::Forms::Label());
			this->BirthdayListView = (gcnew System::Windows::Forms::ListView());
			this->DurationMethod = (gcnew System::Windows::Forms::Label());
			this->LeapLabel = (gcnew System::Windows::Forms::Label());
			this->LeapListView = (gcnew System::Windows::Forms::ListView());
			this->AddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// NextDayButton
			// 
			this->NextDayButton->BackColor = System::Drawing::Color::SpringGreen;
			this->NextDayButton->Location = System::Drawing::Point(913, 68);
			this->NextDayButton->Name = L"NextDayButton";
			this->NextDayButton->Size = System::Drawing::Size(75, 38);
			this->NextDayButton->TabIndex = 0;
			this->NextDayButton->Text = L"Click";
			this->NextDayButton->UseVisualStyleBackColor = false;
			this->NextDayButton->Click += gcnew System::EventHandler(this, &DateForm::NextDayButton_Click);
			// 
			// DateTextBox
			// 
			this->DateTextBox->BackColor = System::Drawing::Color::Gold;
			this->DateTextBox->Location = System::Drawing::Point(1029, 101);
			this->DateTextBox->Name = L"DateTextBox";
			this->DateTextBox->Size = System::Drawing::Size(125, 22);
			this->DateTextBox->TabIndex = 1;
			this->DateTextBox->TextChanged += gcnew System::EventHandler(this, &DateForm::DateTextBox_TextChanged);
			// 
			// NextDayLabel
			// 
			this->NextDayLabel->AutoSize = true;
			this->NextDayLabel->Location = System::Drawing::Point(916, 49);
			this->NextDayLabel->Name = L"NextDayLabel";
			this->NextDayLabel->Size = System::Drawing::Size(59, 16);
			this->NextDayLabel->TabIndex = 2;
			this->NextDayLabel->Text = L"NextDay";
			// 
			// DateBirthdayLabel
			// 
			this->DateBirthdayLabel->AutoSize = true;
			this->DateBirthdayLabel->Location = System::Drawing::Point(1024, 82);
			this->DateBirthdayLabel->Name = L"DateBirthdayLabel";
			this->DateBirthdayLabel->Size = System::Drawing::Size(130, 16);
			this->DateBirthdayLabel->TabIndex = 3;
			this->DateBirthdayLabel->Text = L"Date of your birthday";
			// 
			// OutputOldDatesListView
			// 
			this->OutputOldDatesListView->BackColor = System::Drawing::SystemColors::Window;
			this->OutputOldDatesListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader1 });
			this->OutputOldDatesListView->HideSelection = false;
			this->OutputOldDatesListView->Location = System::Drawing::Point(15, 49);
			this->OutputOldDatesListView->Name = L"OutputOldDatesListView";
			this->OutputOldDatesListView->Size = System::Drawing::Size(110, 564);
			this->OutputOldDatesListView->TabIndex = 4;
			this->OutputOldDatesListView->UseCompatibleStateImageBehavior = false;
			this->OutputOldDatesListView->SelectedIndexChanged += gcnew System::EventHandler(this, &DateForm::OutputOldDatesListView_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Width = 200;
			// 
			// PrevDayButton
			// 
			this->PrevDayButton->BackColor = System::Drawing::Color::SpringGreen;
			this->PrevDayButton->Location = System::Drawing::Point(914, 158);
			this->PrevDayButton->Name = L"PrevDayButton";
			this->PrevDayButton->Size = System::Drawing::Size(75, 37);
			this->PrevDayButton->TabIndex = 5;
			this->PrevDayButton->Text = L"Click";
			this->PrevDayButton->UseVisualStyleBackColor = false;
			this->PrevDayButton->Click += gcnew System::EventHandler(this, &DateForm::PrevDayButton_Click);
			// 
			// PrevDayLabel
			// 
			this->PrevDayLabel->AutoSize = true;
			this->PrevDayLabel->Location = System::Drawing::Point(910, 119);
			this->PrevDayLabel->Name = L"PrevDayLabel";
			this->PrevDayLabel->Size = System::Drawing::Size(88, 16);
			this->PrevDayLabel->TabIndex = 6;
			this->PrevDayLabel->Text = L"Previous Day";
			// 
			// BirthdayLabel
			// 
			this->BirthdayLabel->AutoSize = true;
			this->BirthdayLabel->Location = System::Drawing::Point(898, 224);
			this->BirthdayLabel->Name = L"BirthdayLabel";
			this->BirthdayLabel->Size = System::Drawing::Size(111, 16);
			this->BirthdayLabel->TabIndex = 7;
			this->BirthdayLabel->Text = L"Between Birthday";
			// 
			// DurationLabel
			// 
			this->DurationLabel->AutoSize = true;
			this->DurationLabel->Location = System::Drawing::Point(1066, 179);
			this->DurationLabel->Name = L"DurationLabel";
			this->DurationLabel->Size = System::Drawing::Size(60, 16);
			this->DurationLabel->TabIndex = 8;
			this->DurationLabel->Text = L"Any date";
			// 
			// WeekLabel
			// 
			this->WeekLabel->AutoSize = true;
			this->WeekLabel->Location = System::Drawing::Point(928, 395);
			this->WeekLabel->Name = L"WeekLabel";
			this->WeekLabel->Size = System::Drawing::Size(43, 16);
			this->WeekLabel->TabIndex = 9;
			this->WeekLabel->Text = L"Week";
			// 
			// IsLeapLabel
			// 
			this->IsLeapLabel->AutoSize = true;
			this->IsLeapLabel->Location = System::Drawing::Point(924, 467);
			this->IsLeapLabel->Name = L"IsLeapLabel";
			this->IsLeapLabel->Size = System::Drawing::Size(47, 16);
			this->IsLeapLabel->TabIndex = 10;
			this->IsLeapLabel->Text = L"Is leap";
			// 
			// WeekButton
			// 
			this->WeekButton->BackColor = System::Drawing::Color::SpringGreen;
			this->WeekButton->Location = System::Drawing::Point(910, 426);
			this->WeekButton->Name = L"WeekButton";
			this->WeekButton->Size = System::Drawing::Size(75, 31);
			this->WeekButton->TabIndex = 13;
			this->WeekButton->Text = L"Click";
			this->WeekButton->UseVisualStyleBackColor = false;
			this->WeekButton->Click += gcnew System::EventHandler(this, &DateForm::WeekButton_Click);
			// 
			// IsLeapButton
			// 
			this->IsLeapButton->BackColor = System::Drawing::Color::SpringGreen;
			this->IsLeapButton->Location = System::Drawing::Point(910, 494);
			this->IsLeapButton->Name = L"IsLeapButton";
			this->IsLeapButton->Size = System::Drawing::Size(75, 38);
			this->IsLeapButton->TabIndex = 14;
			this->IsLeapButton->Text = L"Click";
			this->IsLeapButton->UseVisualStyleBackColor = false;
			this->IsLeapButton->Click += gcnew System::EventHandler(this, &DateForm::IsLeapButton_Click);
			// 
			// ReadDatesLabel
			// 
			this->ReadDatesLabel->AutoSize = true;
			this->ReadDatesLabel->Location = System::Drawing::Point(1094, 271);
			this->ReadDatesLabel->Name = L"ReadDatesLabel";
			this->ReadDatesLabel->Size = System::Drawing::Size(70, 16);
			this->ReadDatesLabel->TabIndex = 16;
			this->ReadDatesLabel->Text = L"Read from";
			// 
			// AddLabel
			// 
			this->AddLabel->AutoSize = true;
			this->AddLabel->Location = System::Drawing::Point(1122, 379);
			this->AddLabel->Name = L"AddLabel";
			this->AddLabel->Size = System::Drawing::Size(32, 16);
			this->AddLabel->TabIndex = 17;
			this->AddLabel->Text = L"Add";
			// 
			// ChangeLabel
			// 
			this->ChangeLabel->AutoSize = true;
			this->ChangeLabel->Location = System::Drawing::Point(1103, 516);
			this->ChangeLabel->Name = L"ChangeLabel";
			this->ChangeLabel->Size = System::Drawing::Size(54, 16);
			this->ChangeLabel->TabIndex = 18;
			this->ChangeLabel->Text = L"Change";
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::Color::SpringGreen;
			this->AddButton->Location = System::Drawing::Point(1089, 398);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 31);
			this->AddButton->TabIndex = 19;
			this->AddButton->Text = L"Click";
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &DateForm::AddButton_Click);
			// 
			// ChangeButton
			// 
			this->ChangeButton->BackColor = System::Drawing::Color::SpringGreen;
			this->ChangeButton->Location = System::Drawing::Point(1089, 560);
			this->ChangeButton->Name = L"ChangeButton";
			this->ChangeButton->Size = System::Drawing::Size(75, 37);
			this->ChangeButton->TabIndex = 20;
			this->ChangeButton->Text = L"Click";
			this->ChangeButton->UseVisualStyleBackColor = false;
			this->ChangeButton->Click += gcnew System::EventHandler(this, &DateForm::ChangeButton_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1075, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 16);
			this->label11->TabIndex = 21;
			this->label11->Text = L"label11";
			this->label11->Click += gcnew System::EventHandler(this, &DateForm::label11_Click);
			// 
			// OutputNewDatesListView
			// 
			this->OutputNewDatesListView->BackColor = System::Drawing::SystemColors::Window;
			this->OutputNewDatesListView->HideSelection = false;
			this->OutputNewDatesListView->Location = System::Drawing::Point(144, 49);
			this->OutputNewDatesListView->Name = L"OutputNewDatesListView";
			this->OutputNewDatesListView->Size = System::Drawing::Size(130, 564);
			this->OutputNewDatesListView->TabIndex = 22;
			this->OutputNewDatesListView->UseCompatibleStateImageBehavior = false;
			this->OutputNewDatesListView->SelectedIndexChanged += gcnew System::EventHandler(this, &DateForm::OutputNewDatesListView_SelectedIndexChanged);
			// 
			// OutputOldDatesLabel
			// 
			this->OutputOldDatesLabel->AutoSize = true;
			this->OutputOldDatesLabel->Location = System::Drawing::Point(12, 30);
			this->OutputOldDatesLabel->Name = L"OutputOldDatesLabel";
			this->OutputOldDatesLabel->Size = System::Drawing::Size(104, 16);
			this->OutputOldDatesLabel->TabIndex = 23;
			this->OutputOldDatesLabel->Text = L"Output old dates";
			// 
			// OutputNewDatesLabel
			// 
			this->OutputNewDatesLabel->AutoSize = true;
			this->OutputNewDatesLabel->Location = System::Drawing::Point(152, 30);
			this->OutputNewDatesLabel->Name = L"OutputNewDatesLabel";
			this->OutputNewDatesLabel->Size = System::Drawing::Size(109, 16);
			this->OutputNewDatesLabel->TabIndex = 24;
			this->OutputNewDatesLabel->Text = L"Output new dates";
			// 
			// ReadDatesButton
			// 
			this->ReadDatesButton->BackColor = System::Drawing::Color::SpringGreen;
			this->ReadDatesButton->Location = System::Drawing::Point(1089, 290);
			this->ReadDatesButton->Name = L"ReadDatesButton";
			this->ReadDatesButton->Size = System::Drawing::Size(75, 39);
			this->ReadDatesButton->TabIndex = 15;
			this->ReadDatesButton->Text = L"Click";
			this->ReadDatesButton->UseVisualStyleBackColor = false;
			this->ReadDatesButton->Click += gcnew System::EventHandler(this, &DateForm::ReadDatesButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// WeekListView
			// 
			this->WeekListView->BackColor = System::Drawing::SystemColors::Window;
			this->WeekListView->HideSelection = false;
			this->WeekListView->Location = System::Drawing::Point(294, 49);
			this->WeekListView->Name = L"WeekListView";
			this->WeekListView->Size = System::Drawing::Size(86, 564);
			this->WeekListView->TabIndex = 25;
			this->WeekListView->UseCompatibleStateImageBehavior = false;
			this->WeekListView->SelectedIndexChanged += gcnew System::EventHandler(this, &DateForm::WeekListView_SelectedIndexChanged);
			// 
			// WeekListLabel
			// 
			this->WeekListLabel->AutoSize = true;
			this->WeekListLabel->Location = System::Drawing::Point(267, 30);
			this->WeekListLabel->Name = L"WeekListLabel";
			this->WeekListLabel->Size = System::Drawing::Size(128, 16);
			this->WeekListLabel->TabIndex = 26;
			this->WeekListLabel->Text = L"Output week number";
			// 
			// AnyDateTextBox
			// 
			this->AnyDateTextBox->BackColor = System::Drawing::Color::Gold;
			this->AnyDateTextBox->Location = System::Drawing::Point(1035, 198);
			this->AnyDateTextBox->Name = L"AnyDateTextBox";
			this->AnyDateTextBox->Size = System::Drawing::Size(125, 22);
			this->AnyDateTextBox->TabIndex = 28;
			this->AnyDateTextBox->TextChanged += gcnew System::EventHandler(this, &DateForm::AnyDateTextBox_TextChanged);
			// 
			// DurationDatesLabel
			// 
			this->DurationDatesLabel->AutoSize = true;
			this->DurationDatesLabel->Location = System::Drawing::Point(438, 30);
			this->DurationDatesLabel->Name = L"DurationDatesLabel";
			this->DurationDatesLabel->Size = System::Drawing::Size(93, 16);
			this->DurationDatesLabel->TabIndex = 29;
			this->DurationDatesLabel->Text = L"DurationDates";
			// 
			// DurationDatesListView
			// 
			this->DurationDatesListView->BackColor = System::Drawing::SystemColors::Window;
			this->DurationDatesListView->HideSelection = false;
			this->DurationDatesListView->Location = System::Drawing::Point(441, 49);
			this->DurationDatesListView->Name = L"DurationDatesListView";
			this->DurationDatesListView->Size = System::Drawing::Size(90, 564);
			this->DurationDatesListView->TabIndex = 30;
			this->DurationDatesListView->UseCompatibleStateImageBehavior = false;
			this->DurationDatesListView->SelectedIndexChanged += gcnew System::EventHandler(this, &DateForm::DurationDatesListView_SelectedIndexChanged);
			// 
			// DurationButton
			// 
			this->DurationButton->BackColor = System::Drawing::Color::SpringGreen;
			this->DurationButton->Location = System::Drawing::Point(910, 342);
			this->DurationButton->Name = L"DurationButton";
			this->DurationButton->Size = System::Drawing::Size(75, 44);
			this->DurationButton->TabIndex = 31;
			this->DurationButton->Text = L"Click";
			this->DurationButton->UseVisualStyleBackColor = false;
			this->DurationButton->Click += gcnew System::EventHandler(this, &DateForm::DurationButton_Click);
			// 
			// BirthdayDateButton
			// 
			this->BirthdayDateButton->BackColor = System::Drawing::Color::SpringGreen;
			this->BirthdayDateButton->Location = System::Drawing::Point(913, 260);
			this->BirthdayDateButton->Name = L"BirthdayDateButton";
			this->BirthdayDateButton->Size = System::Drawing::Size(75, 36);
			this->BirthdayDateButton->TabIndex = 32;
			this->BirthdayDateButton->Text = L"Click";
			this->BirthdayDateButton->UseVisualStyleBackColor = false;
			this->BirthdayDateButton->Click += gcnew System::EventHandler(this, &DateForm::BirthdayDateButton_Click);
			// 
			// BirthdayListLabel
			// 
			this->BirthdayListLabel->AutoSize = true;
			this->BirthdayListLabel->Location = System::Drawing::Point(583, 30);
			this->BirthdayListLabel->Name = L"BirthdayListLabel";
			this->BirthdayListLabel->Size = System::Drawing::Size(104, 16);
			this->BirthdayListLabel->TabIndex = 33;
			this->BirthdayListLabel->Text = L"To your birthday";
			// 
			// BirthdayListView
			// 
			this->BirthdayListView->BackColor = System::Drawing::SystemColors::Window;
			this->BirthdayListView->HideSelection = false;
			this->BirthdayListView->Location = System::Drawing::Point(586, 49);
			this->BirthdayListView->Name = L"BirthdayListView";
			this->BirthdayListView->Size = System::Drawing::Size(101, 580);
			this->BirthdayListView->TabIndex = 34;
			this->BirthdayListView->UseCompatibleStateImageBehavior = false;
			this->BirthdayListView->SelectedIndexChanged += gcnew System::EventHandler(this, &DateForm::BirthdayListView_SelectedIndexChanged);
			// 
			// DurationMethod
			// 
			this->DurationMethod->AutoSize = true;
			this->DurationMethod->Location = System::Drawing::Point(924, 323);
			this->DurationMethod->Name = L"DurationMethod";
			this->DurationMethod->Size = System::Drawing::Size(57, 16);
			this->DurationMethod->TabIndex = 35;
			this->DurationMethod->Text = L"Duration";
			// 
			// LeapLabel
			// 
			this->LeapLabel->AutoSize = true;
			this->LeapLabel->Location = System::Drawing::Point(764, 30);
			this->LeapLabel->Name = L"LeapLabel";
			this->LeapLabel->Size = System::Drawing::Size(34, 16);
			this->LeapLabel->TabIndex = 36;
			this->LeapLabel->Text = L"leap";
			// 
			// LeapListView
			// 
			this->LeapListView->BackColor = System::Drawing::SystemColors::Window;
			this->LeapListView->HideSelection = false;
			this->LeapListView->Location = System::Drawing::Point(737, 49);
			this->LeapListView->Name = L"LeapListView";
			this->LeapListView->Size = System::Drawing::Size(84, 564);
			this->LeapListView->TabIndex = 37;
			this->LeapListView->UseCompatibleStateImageBehavior = false;
			this->LeapListView->SelectedIndexChanged += gcnew System::EventHandler(this, &DateForm::LeapListView_SelectedIndexChanged);
			// 
			// AddTextBox
			// 
			this->AddTextBox->BackColor = System::Drawing::Color::Gold;
			this->AddTextBox->Location = System::Drawing::Point(1060, 435);
			this->AddTextBox->Name = L"AddTextBox";
			this->AddTextBox->Size = System::Drawing::Size(100, 22);
			this->AddTextBox->TabIndex = 38;
			this->AddTextBox->TextChanged += gcnew System::EventHandler(this, &DateForm::AddTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1003, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 39;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &DateForm::label1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &DateForm::timer1_Tick);
			// 
			// DateForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1170, 609);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->AddTextBox);
			this->Controls->Add(this->LeapListView);
			this->Controls->Add(this->LeapLabel);
			this->Controls->Add(this->DurationMethod);
			this->Controls->Add(this->BirthdayListView);
			this->Controls->Add(this->BirthdayListLabel);
			this->Controls->Add(this->BirthdayDateButton);
			this->Controls->Add(this->DurationButton);
			this->Controls->Add(this->DurationDatesListView);
			this->Controls->Add(this->DurationDatesLabel);
			this->Controls->Add(this->AnyDateTextBox);
			this->Controls->Add(this->WeekListLabel);
			this->Controls->Add(this->WeekListView);
			this->Controls->Add(this->OutputNewDatesLabel);
			this->Controls->Add(this->OutputOldDatesLabel);
			this->Controls->Add(this->OutputNewDatesListView);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->ChangeButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->ChangeLabel);
			this->Controls->Add(this->AddLabel);
			this->Controls->Add(this->ReadDatesLabel);
			this->Controls->Add(this->ReadDatesButton);
			this->Controls->Add(this->IsLeapButton);
			this->Controls->Add(this->WeekButton);
			this->Controls->Add(this->IsLeapLabel);
			this->Controls->Add(this->WeekLabel);
			this->Controls->Add(this->DurationLabel);
			this->Controls->Add(this->BirthdayLabel);
			this->Controls->Add(this->PrevDayLabel);
			this->Controls->Add(this->PrevDayButton);
			this->Controls->Add(this->OutputOldDatesListView);
			this->Controls->Add(this->DateBirthdayLabel);
			this->Controls->Add(this->NextDayLabel);
			this->Controls->Add(this->DateTextBox);
			this->Controls->Add(this->NextDayButton);
			this->Name = L"DateForm";
			this->Text = L"DateForm";
			this->Load += gcnew System::EventHandler(this, &DateForm::DateForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// These functinos are used to work with buttons

	private: System::Void NextDayButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->OutputNewDatesListView->Clear();

		String^ nextdate = "";
		if (List != NULL)
		{
			ColumnHeader^ col = gcnew ColumnHeader("XX.YY.ZZZZ");
			this->OutputNewDatesListView->Columns->Add(col);
			this->OutputNewDatesListView->Scrollable = true;
			this->OutputNewDatesListView->HeaderStyle = ColumnHeaderStyle::None;

			for (int i = 0; i < Size; i++)
			{
				nextdate = gcnew String(List[i].NextDay().c_str());
				this->OutputNewDatesListView->Items->Add(nextdate);
			}
			this->OutputNewDatesListView->View = View::Details;
			this->OutputNewDatesListView->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

		}
		else  MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	private: System::Void PrevDayButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->OutputNewDatesListView->Clear();

		String^ prevdate = "";

		if (List != NULL)
		{

			ColumnHeader^ col = gcnew ColumnHeader();
			this->OutputNewDatesListView->Columns->Add(col);
			this->OutputNewDatesListView->Scrollable = true;
			this->OutputNewDatesListView->HeaderStyle = ColumnHeaderStyle::None;

			for (int i = 0; i < Size; i++)
			{
				prevdate = gcnew String(List[i].PreviousDay().c_str());
				this->OutputNewDatesListView->Items->Add(prevdate);
			}

			this->OutputNewDatesListView->View = View::Details;
			this->OutputNewDatesListView->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	private: System::Void ReadDatesButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->OutputOldDatesListView->Clear();

		String^ filename = "";
		String^ date;
		int i = 0, size = 0;

		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) filename = openFileDialog1->FileName;

		try
		{

			StreamReader^ file;
			if (filename != "")
			{
				file = gcnew StreamReader(filename);

				while (file->ReadLine()) size++;

				file->BaseStream->Seek(0, SeekOrigin::Begin);
			}
			if (List != NULL)delete[] List, Size = 0;

			if (size != 0)List = new Date[size], Size = size;
			else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			ColumnHeader^ col = gcnew ColumnHeader("XX.YY.ZZZZ");
			this->OutputOldDatesListView->Columns->Add(col);
			this->OutputOldDatesListView->Scrollable = true;
			this->OutputOldDatesListView->HeaderStyle = ColumnHeaderStyle::None;

			while (i < Size && List!=NULL)
			{
				date = file->ReadLine();
				List[i].Set(msclr::interop::marshal_as<std::string>(date));
				this->OutputOldDatesListView->Items->Add(date);
				i++;
			}
			if (filename != "")file->Close();

			this->OutputOldDatesListView->View = View::Details;
			this->OutputOldDatesListView->AutoResizeColumn(0, ColumnHeaderAutoResizeStyle::HeaderSize);

		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	private: System::Void WeekButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->WeekListView->Clear();

		if (List != NULL)
		{
			for (int i = 0; i < Size; i++) this->WeekListView->Items->Add(Convert::ToString(List[i].WeekNumber()));
		}
		else  MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void DurationButton_Click(System::Object^ sender, System::EventArgs^ e) {

		Date date;
		std::regex check("^([0-9]{2}[.]{1}){2}([0-9]{4})$");
		String^ line = AnyDateTextBox->Text;
		if (std::regex_match(msclr::interop::marshal_as<std::string>(line), check))
		{

			date.Set(msclr::interop::marshal_as<std::string>(this->AnyDateTextBox->Text));
			this->DurationDatesListView->Clear();
			if (List != NULL)for (int i = 0; i < Size; i++)this->DurationDatesListView->Items->Add(Convert::ToString(List[i].Duration(date)));
			else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else MessageBox::Show(this, "Incorrect date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	private: System::Void BirthdayDateButton_Click(System::Object^ sender, System::EventArgs^ e) {

		Date date;
		String^ line = this->DateTextBox->Text;
		std::regex check("^([0-9]{2}[.]{1}){2}([0-9]{4})$");

		if (std::regex_match(msclr::interop::marshal_as<std::string>(line), check))
		{

			date.Set(msclr::interop::marshal_as<std::string>(line));
			this->BirthdayListView->Clear();
			if (List != NULL)for (int i = 0; i < Size; i++)this->BirthdayListView->Items->Add(Convert::ToString(List[i].DaysTillYourBirthday(date)));
			else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else MessageBox::Show(this, "Incorrect date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	private: System::Void IsLeapButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (List != NULL)
		{
			this->LeapListView->Clear();
			for (int i = 0; i < Size; i++) if (List[i].IsLeap())this->LeapListView->Items->Add("true"); else this->LeapListView->Items->Add("false");
		}
		else MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ filename = "";
		String^ date = this->AddTextBox->Text;
		std::regex check("^([0-9]{2}[.]{1}){2}([0-9]{4})$");

		if (std::regex_match(msclr::interop::marshal_as<std::string>(date), check))
		{

			if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)filename = openFileDialog1->FileName;

			try
			{
				StreamWriter^ file = gcnew StreamWriter(filename, true);
				file->BaseStream->Seek(0, SeekOrigin::End);
				file->WriteLine(date);
				file->Close();
			}
			catch (Exception^ e)
			{
				MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else MessageBox::Show(this, "Incorrect date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

		   // These functions don't consist line of code

	private: System::Void BirthdayListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void OutputOldDatesListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void OutputNewDatesListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void WeekListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void DateForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void AnyDateTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void DurationDatesListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void DateTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void LeapListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void AddTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void ChangeButton_Click(System::Object^ sender, System::EventArgs^ e) {


		ChangeForm changeform;


		if (List != NULL)
		{
			changeform.DateChangeList->ColumnCount = 1;

			for (int i = 0; i < Size; i++)changeform.DateChangeList->Rows->Add(this->OutputOldDatesListView->Items[i]->Text);
			changeform.ShowDialog();

		}
		else  MessageBox::Show(this, "Empty list", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = DateTime::Now.ToLongTimeString();
		label11->Text = DateTime::Now.ToLongDateString();
	}
};
}