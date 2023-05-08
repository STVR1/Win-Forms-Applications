#pragma once

#include"..\BinaryTree\TreeClass.h"

#include"MyAddForm.h"
#include"MyDeleteForm.h"
#include"MySearchForm.h"

#include<msclr/marshal_cppstd.h>
#include<regex>

namespace GUITree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MyTreeForm : public System::Windows::Forms::Form
	{

	private:

		Tree<int, std::string>* tree = new Tree<int, std::string>; // A tree
		
		Pair<int, std::string>* array = nullptr; // Array of nodes

		int Size = 0; // Array's size

		int printtype = 0; // Type of input

	public:

		MyTreeForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyTreeForm()
		{

			if (tree != nullptr)tree->Clear(), delete tree, tree = nullptr;
			if (array != nullptr)delete[] array, array=nullptr;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^ TreeView;
	protected:

	private: System::Windows::Forms::Label^ LabelMemo;
	private: System::Windows::Forms::RichTextBox^ MemoBox;
	private: System::Windows::Forms::Button^ HistoryButton;
	private: System::Windows::Forms::Button^ AddNodeButton;
	private: System::Windows::Forms::Button^ DeleteNodeButton;
	private: System::Windows::Forms::Button^ BalancedTreeButton;
	private: System::Windows::Forms::Button^ PreorderButton;
	private: System::Windows::Forms::Button^ InorderButton;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::Button^ CreateTreeButton;

	private: System::Windows::Forms::Button^ ReadArrayButton;
	private: System::Windows::Forms::Button^ PostorderButton;

	private: System::Windows::Forms::Button^ DeleteArrayButton;
	private: System::Windows::Forms::Button^ CleanShowBoxButton;
	private: System::Windows::Forms::Button^ TaskButton;

	private: System::Windows::Forms::Label^ LabelTree;


	private: System::Windows::Forms::PictureBox^ PictureBox;
	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;


	protected:

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyTreeForm::typeid));
			this->TreeView = (gcnew System::Windows::Forms::TreeView());
			this->AddNodeButton = (gcnew System::Windows::Forms::Button());
			this->DeleteNodeButton = (gcnew System::Windows::Forms::Button());
			this->BalancedTreeButton = (gcnew System::Windows::Forms::Button());
			this->PreorderButton = (gcnew System::Windows::Forms::Button());
			this->InorderButton = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->CreateTreeButton = (gcnew System::Windows::Forms::Button());
			this->ReadArrayButton = (gcnew System::Windows::Forms::Button());
			this->PostorderButton = (gcnew System::Windows::Forms::Button());
			this->LabelTree = (gcnew System::Windows::Forms::Label());
			this->PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->LabelMemo = (gcnew System::Windows::Forms::Label());
			this->MemoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->HistoryButton = (gcnew System::Windows::Forms::Button());
			this->DeleteArrayButton = (gcnew System::Windows::Forms::Button());
			this->CleanShowBoxButton = (gcnew System::Windows::Forms::Button());
			this->TaskButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// TreeView
			// 
			this->TreeView->Location = System::Drawing::Point(8, 41);
			this->TreeView->Name = L"TreeView";
			this->TreeView->Size = System::Drawing::Size(307, 356);
			this->TreeView->TabIndex = 0;
			this->TreeView->NodeMouseClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &MyTreeForm::TreeView_NodeMouseClick);
			// 
			// AddNodeButton
			// 
			this->AddNodeButton->Location = System::Drawing::Point(8, 412);
			this->AddNodeButton->Name = L"AddNodeButton";
			this->AddNodeButton->Size = System::Drawing::Size(93, 23);
			this->AddNodeButton->TabIndex = 1;
			this->AddNodeButton->Text = L"Add node";
			this->AddNodeButton->UseVisualStyleBackColor = true;
			this->AddNodeButton->Click += gcnew System::EventHandler(this, &MyTreeForm::AddNodeButton_Click);
			// 
			// DeleteNodeButton
			// 
			this->DeleteNodeButton->Location = System::Drawing::Point(108, 412);
			this->DeleteNodeButton->Name = L"DeleteNodeButton";
			this->DeleteNodeButton->Size = System::Drawing::Size(95, 23);
			this->DeleteNodeButton->TabIndex = 2;
			this->DeleteNodeButton->Text = L"Delete";
			this->DeleteNodeButton->UseVisualStyleBackColor = true;
			this->DeleteNodeButton->Click += gcnew System::EventHandler(this, &MyTreeForm::DeleteNodeButton_Click);
			// 
			// BalancedTreeButton
			// 
			this->BalancedTreeButton->Location = System::Drawing::Point(108, 454);
			this->BalancedTreeButton->Name = L"BalancedTreeButton";
			this->BalancedTreeButton->Size = System::Drawing::Size(95, 23);
			this->BalancedTreeButton->TabIndex = 3;
			this->BalancedTreeButton->Text = L"Balance tree";
			this->BalancedTreeButton->UseVisualStyleBackColor = true;
			this->BalancedTreeButton->Click += gcnew System::EventHandler(this, &MyTreeForm::BalancedTreeButton_Click);
			// 
			// PreorderButton
			// 
			this->PreorderButton->Location = System::Drawing::Point(9, 495);
			this->PreorderButton->Name = L"PreorderButton";
			this->PreorderButton->Size = System::Drawing::Size(93, 23);
			this->PreorderButton->TabIndex = 4;
			this->PreorderButton->Text = L"Preorder";
			this->PreorderButton->UseVisualStyleBackColor = true;
			this->PreorderButton->Click += gcnew System::EventHandler(this, &MyTreeForm::PreorderButton_Click);
			// 
			// InorderButton
			// 
			this->InorderButton->Location = System::Drawing::Point(108, 495);
			this->InorderButton->Name = L"InorderButton";
			this->InorderButton->Size = System::Drawing::Size(95, 23);
			this->InorderButton->TabIndex = 5;
			this->InorderButton->Text = L"Inorder";
			this->InorderButton->UseVisualStyleBackColor = true;
			this->InorderButton->Click += gcnew System::EventHandler(this, &MyTreeForm::InorderButton_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(8, 454);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(93, 23);
			this->SearchButton->TabIndex = 6;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyTreeForm::SearchButton_Click);
			// 
			// CreateTreeButton
			// 
			this->CreateTreeButton->Location = System::Drawing::Point(216, 454);
			this->CreateTreeButton->Name = L"CreateTreeButton";
			this->CreateTreeButton->Size = System::Drawing::Size(93, 23);
			this->CreateTreeButton->TabIndex = 7;
			this->CreateTreeButton->Text = L"Create tree";
			this->CreateTreeButton->UseVisualStyleBackColor = true;
			this->CreateTreeButton->Click += gcnew System::EventHandler(this, &MyTreeForm::CreateTreeButton_Click);
			// 
			// ReadArrayButton
			// 
			this->ReadArrayButton->Location = System::Drawing::Point(216, 412);
			this->ReadArrayButton->Name = L"ReadArrayButton";
			this->ReadArrayButton->Size = System::Drawing::Size(93, 23);
			this->ReadArrayButton->TabIndex = 8;
			this->ReadArrayButton->Text = L"Read array";
			this->ReadArrayButton->UseVisualStyleBackColor = true;
			this->ReadArrayButton->Click += gcnew System::EventHandler(this, &MyTreeForm::ReadArrayButton_Click);
			// 
			// PostorderButton
			// 
			this->PostorderButton->Location = System::Drawing::Point(216, 495);
			this->PostorderButton->Name = L"PostorderButton";
			this->PostorderButton->Size = System::Drawing::Size(93, 23);
			this->PostorderButton->TabIndex = 9;
			this->PostorderButton->Text = L"Postorder";
			this->PostorderButton->UseVisualStyleBackColor = true;
			this->PostorderButton->Click += gcnew System::EventHandler(this, &MyTreeForm::PostorderButton_Click);
			// 
			// LabelTree
			// 
			this->LabelTree->AutoSize = true;
			this->LabelTree->Location = System::Drawing::Point(105, 22);
			this->LabelTree->Name = L"LabelTree";
			this->LabelTree->Size = System::Drawing::Size(109, 16);
			this->LabelTree->TabIndex = 11;
			this->LabelTree->Text = L"Show box for tree";
			// 
			// PictureBox
			// 
			this->PictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBox.Image")));
			this->PictureBox->Location = System::Drawing::Point(338, 352);
			this->PictureBox->Name = L"PictureBox";
			this->PictureBox->Size = System::Drawing::Size(200, 212);
			this->PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PictureBox->TabIndex = 13;
			this->PictureBox->TabStop = false;
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->FileName = L"OpenFileDialog";
			// 
			// LabelMemo
			// 
			this->LabelMemo->AutoSize = true;
			this->LabelMemo->Location = System::Drawing::Point(400, 22);
			this->LabelMemo->Name = L"LabelMemo";
			this->LabelMemo->Size = System::Drawing::Size(49, 16);
			this->LabelMemo->TabIndex = 12;
			this->LabelMemo->Text = L"History";
			// 
			// MemoBox
			// 
			this->MemoBox->Enabled = false;
			this->MemoBox->Location = System::Drawing::Point(338, 41);
			this->MemoBox->Name = L"MemoBox";
			this->MemoBox->ReadOnly = true;
			this->MemoBox->Size = System::Drawing::Size(188, 280);
			this->MemoBox->TabIndex = 10;
			this->MemoBox->Text = L"";
			// 
			// HistoryButton
			// 
			this->HistoryButton->Location = System::Drawing::Point(338, 327);
			this->HistoryButton->Name = L"HistoryButton";
			this->HistoryButton->Size = System::Drawing::Size(188, 23);
			this->HistoryButton->TabIndex = 14;
			this->HistoryButton->Text = L"Clean history";
			this->HistoryButton->UseVisualStyleBackColor = true;
			this->HistoryButton->Click += gcnew System::EventHandler(this, &MyTreeForm::HistoryButton_Click);
			// 
			// DeleteArrayButton
			// 
			this->DeleteArrayButton->Location = System::Drawing::Point(216, 533);
			this->DeleteArrayButton->Name = L"DeleteArrayButton";
			this->DeleteArrayButton->Size = System::Drawing::Size(93, 23);
			this->DeleteArrayButton->TabIndex = 15;
			this->DeleteArrayButton->Text = L"Clean array";
			this->DeleteArrayButton->UseVisualStyleBackColor = true;
			this->DeleteArrayButton->Click += gcnew System::EventHandler(this, &MyTreeForm::DeleteArrayButton_Click);
			// 
			// CleanShowBoxButton
			// 
			this->CleanShowBoxButton->Location = System::Drawing::Point(8, 533);
			this->CleanShowBoxButton->Name = L"CleanShowBoxButton";
			this->CleanShowBoxButton->Size = System::Drawing::Size(93, 23);
			this->CleanShowBoxButton->TabIndex = 16;
			this->CleanShowBoxButton->Text = L"Clean box";
			this->CleanShowBoxButton->UseVisualStyleBackColor = true;
			this->CleanShowBoxButton->Click += gcnew System::EventHandler(this, &MyTreeForm::CleanShowBoxButton_Click);
			// 
			// TaskButton
			// 
			this->TaskButton->Location = System::Drawing::Point(108, 533);
			this->TaskButton->Name = L"TaskButton";
			this->TaskButton->Size = System::Drawing::Size(95, 23);
			this->TaskButton->TabIndex = 17;
			this->TaskButton->Text = L"Task";
			this->TaskButton->UseVisualStyleBackColor = true;
			this->TaskButton->Click += gcnew System::EventHandler(this, &MyTreeForm::TaskButton_Click);
			// 
			// MyTreeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 568);
			this->Controls->Add(this->TaskButton);
			this->Controls->Add(this->CleanShowBoxButton);
			this->Controls->Add(this->DeleteArrayButton);
			this->Controls->Add(this->HistoryButton);
			this->Controls->Add(this->PictureBox);
			this->Controls->Add(this->LabelMemo);
			this->Controls->Add(this->LabelTree);
			this->Controls->Add(this->MemoBox);
			this->Controls->Add(this->PostorderButton);
			this->Controls->Add(this->ReadArrayButton);
			this->Controls->Add(this->CreateTreeButton);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->InorderButton);
			this->Controls->Add(this->PreorderButton);
			this->Controls->Add(this->BalancedTreeButton);
			this->Controls->Add(this->DeleteNodeButton);
			this->Controls->Add(this->AddNodeButton);
			this->Controls->Add(this->TreeView);
			this->Name = L"MyTreeForm";
			this->Text = L"MyTreeForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    /*************************************************************************************************/

		                 // FUNCTIONS FOR ARRAY OF NODES

	/*************************************************************************************************/

	private: System::Void ReadArrayButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Read array\"\n\n");

		if (OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			
			if (array != nullptr)delete[] array, array = nullptr, Size=0;

			try
			{
				StreamReader^ file = gcnew StreamReader(OpenFileDialog->FileName);
				String^ line="";
				int i = 0;

				while (file->Peek()>=0)
				{
					line = file->ReadLine();
					if(line=="")while (line == "")line = file->ReadLine();
					line = file->ReadLine();
					if(line=="")while (line == "")line = file->ReadLine();
					Size++;
				}

				if(Size==0)
				{
					file->Close();
					MessageBox::Show(this, "Empty file", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				
				array = new Pair<int, std::string>[Size];
				file->BaseStream->Seek(0, SeekOrigin::Begin);

				while(i<Size)
				{
					line = file->ReadLine();
					while (line == "")line = file->ReadLine();
					array[i].first = Convert::ToInt32(line);

					line = file->ReadLine();
					while (line == "")line = file->ReadLine();
					array[i++].second = msclr::interop::marshal_as<std::string>(line);

				} 

				file->Close();

				MessageBox::Show(this, "Successfully read", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->MemoBox->AppendText("Successful reading from file [" + OpenFileDialog->FileName + "]\n\n");
			}
			catch (Exception^)
			{

				if (array != nullptr) delete[] array, array = nullptr;

				MessageBox::Show(this, "Incorrect inforamtion in file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->MemoBox->AppendText("Unsuccessful reading from file [" + OpenFileDialog->FileName + "]\n\n");

			}
			catch (IOException^)
			{
				MessageBox::Show(this, "Can't open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->MemoBox->AppendText("Unsuccessful reading from file ["+OpenFileDialog->FileName +"]\n\n");
			}

		}

	}

	private: System::Void DeleteArrayButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Clean array\"\n\n");
		if (array != nullptr)delete[] array, array = nullptr, Size = 0;
		MessageBox::Show(this, "Successfully cleaned", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}

	/*************************************************************************************************/

		                 // FUNCTIONS TO SHOW A TREE

	/*************************************************************************************************/

	private: System::Void PreorderButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Preorder\"\n\n");

		if (printtype == 1)return;

		this->TreeView->Nodes->Clear();

		if (tree->IsEmpty())
		{
			MessageBox::Show(this, "Empty tree", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Pair<int, std::string>* temp = tree->Preorder();

		for (int i = 0; i < tree->Size(); i++)
		{
			this->TreeView->Nodes->Add(Convert::ToString(temp[i].first));
			this->TreeView->Nodes[i]->Nodes->Add(msclr::interop::marshal_as<String^>(temp[i].second));
		}

		delete[] temp, temp = nullptr;

		printtype = 1;

	}

	private: System::Void InorderButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Inorder\"\n\n");

		if (printtype == 2)return;

		this->TreeView->Nodes->Clear();

		if (tree->IsEmpty())
		{
			MessageBox::Show(this, "Empty tree", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Pair<int, std::string>* temp = tree->Inorder();

		for (int i = 0; i < tree->Size(); i++)
		{
			this->TreeView->Nodes->Add(Convert::ToString(temp[i].first));
			this->TreeView->Nodes[i]->Nodes->Add(msclr::interop::marshal_as<String^>(temp[i].second));
		}

		delete[] temp, temp = nullptr;

		printtype = 2;

	}

	private: System::Void PostorderButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Postorder\"\n\n");

		if (printtype == 3)return;

		this->TreeView->Nodes->Clear();

		if (tree->IsEmpty())
		{
			MessageBox::Show(this, "Empty tree", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Pair<int, std::string>* temp = tree->Postorder();

		for (int i = 0; i < tree->Size(); i++)
		{
			this->TreeView->Nodes->Add(Convert::ToString(temp[i].first));
			this->TreeView->Nodes[i]->Nodes->Add(msclr::interop::marshal_as<String^>(temp[i].second));
		}

		delete[] temp, temp = nullptr;

		printtype = 3;

	}

	/**************************************************************************************************/

		                 // FUNCTIONS TO WORK WITH TREE

	/**************************************************************************************************/

	private: System::Void CreateTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Create tree\"\n\n");

		if (array == nullptr)
		{
			MessageBox::Show(this, "Empty array", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int prevsize = tree->Size();

		tree->Emplace(array, Size);

		MessageBox::Show(this, "Successfully created", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		if (tree->Size() - prevsize < Size)
			MessageBox::Show(this, "Some of nodes weren't pushed", "Attention", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (tree->Size() - prevsize <= Size && tree->Size() - prevsize > 0 && this->TreeView->Nodes->Count > 0)
		{
			printtype = 0;
			this->TreeView->Nodes->Clear();
			MessageBox::Show(this, "Show box for tree was cleared, because your tree was changed", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}

	private: System::Void BalancedTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Balance tree\"\n\n");

		if (tree->IsEmpty())
		{
			MessageBox::Show(this, "Empty tree", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		tree->MakeBalanced();

		this->TreeView->Nodes->Clear();
		Pair<int, std::string>* temp = nullptr;

		switch (printtype)
		{
		case 1:
		{
			temp = tree->Preorder();
			break;
		}
		case 2:
		{
			temp = tree->Inorder();
			break;
		}
		case 3:
		{
			temp = tree->Postorder();
			break;
		}
		default:return;
		}

		for (int i = 0; i < tree->Size(); i++)
		{
			this->TreeView->Nodes->Add(Convert::ToString(temp[i].first));
			this->TreeView->Nodes[i]->Nodes->Add(msclr::interop::marshal_as<String^>(temp[i].second));
		}

		delete[] temp, temp = nullptr;

		MessageBox::Show(this,"Successfully balances","Success",MessageBoxButtons::OK, MessageBoxIcon::Information);

	}

	private: System::Void AddNodeButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Add node\"\n\n");

		MyAddForm newform;

		int prevsize = tree->Size();

		newform.SetTree(tree);

		newform.ShowDialog();

		tree=newform.GetTree();

		if (tree->Size() - prevsize > 0)this->MemoBox->AppendText("New node was added\n\n");
		else this->MemoBox->AppendText("New node wasn't added\n\n");

		if (tree->Size() - prevsize > 0 && this->TreeView->Nodes->Count>0)
		{
			printtype = 0;
			this->TreeView->Nodes->Clear();
			MessageBox::Show(this, "Show box was cleaned, because your tree had changed", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}

    private: System::Void DeleteNodeButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed thw button \"Delete\"\n\n");

		if (tree->IsEmpty())
		{
			MessageBox::Show(this, "Empty tree","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		MyDeleteForm newform;

		int prevsize = tree->Size();

		newform.MaximizeBox = false;
		newform.FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;

		newform.SetTree(tree);

		newform.ShowDialog();

		tree = newform.GetTree();

		if (tree->IsEmpty())MessageBox::Show(this, "Your tree is empty", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (tree->Size() - prevsize < 0 && this->TreeView->Nodes->Count>0)
		{
			this->TreeView->Nodes->Clear();
			printtype = 0;

			if (tree->IsEmpty())this->MemoBox->AppendText("User deleted a tree\n\n");
			else this->MemoBox->AppendText("User deleted a node\n\n");

			MessageBox::Show(this, "Show box for tree was cleaned, because your tree was changed", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else this->MemoBox->AppendText("User didn't delete a node/tree\n\n");
    }

    private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Search\"\n\n");

		for (int i = 0; i < this->TreeView->Nodes->Count; i++)
			if (this->TreeView->Nodes[i]->BackColor == Color::Yellow)
				this->TreeView->Nodes[i]->BackColor = Color::White;

		if (tree->IsEmpty())
		{
			MessageBox::Show(this,"Empty tree","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		MySearchForm newform;

		newform.SetTree(tree);

		newform.FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
		newform.MaximizeBox = false;

		newform.ShowDialog();

		Pair<int, std::string>* searched = newform.GetPair();

		if (searched != nullptr)
		{
			if (this->TreeView->Nodes->Count > 0)
			{
				String^ key = Convert::ToString(searched->first);
				for (int i = 0; i < this->TreeView->Nodes->Count; i++)
					if (this->TreeView->Nodes[i]->Text->ToString() == key) this->TreeView->Nodes[i]->BackColor=Color::Yellow;
			}
			else {
				this->TreeView->Nodes->Add(Convert::ToString(searched->first));
				this->TreeView->Nodes[0]->Nodes->Add(msclr::interop::marshal_as<String^>(searched->second));
			}
			this->MemoBox->AppendText("User successfully searched a node\n\n");
		}
		else this->MemoBox->AppendText("User unsuccessfully searched a node\n\n");
    }

	/**************************************************************************************************/

		                 // FUNCTION TO COMPLET A TASK

	/**************************************************************************************************/

	private: System::Void TaskButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Task\"\n\n");

		if (tree->IsEmpty())
		{
			MessageBox::Show(this, "Empty tree", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		MyTask<int, std::string> temp(tree->Begin());

		int* searched = temp.GetSearched();

		switch (temp.OneBranchNodes())
		{
		case 0:
		{
			MessageBox::Show(this, "Nothing found", "Notification", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		case 1:
		{
			this->MemoBox->AppendText("Found node was marked\n\n");
			MessageBox::Show(this, "One node has been found", "Notification", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		default:
		{
			this->MemoBox->AppendText("Found nodes were marked\n\n");
			MessageBox::Show(this, Convert::ToString(temp.OneBranchNodes()) + " nodes have been found", "Notification", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		}

		if (this->TreeView->Nodes->Count > 0)
		{
			for (int i = 0; i < this->TreeView->Nodes->Count; i++)
			{
				for (int j = 0; j < temp.OneBranchNodes(); j++)
					if (this->TreeView->Nodes[i]->Text->ToString() == Convert::ToString(searched[j]))
					{
						this->TreeView->Nodes[i]->BackColor = Color::Yellow;
						break;
					}
			}
		}
		else
		{
			for (int i = 0; i < temp.OneBranchNodes(); i++)
			{
				auto pair = tree->Find(searched[i]);
				this->TreeView->Nodes->Add(Convert::ToString(pair->first));
				this->TreeView->Nodes[i]->Nodes->Add(msclr::interop::marshal_as<String^>(pair->second));
			}
		}

	}

	/**************************************************************************************************/

		                 // FUNCTIONS TO CLEAN SHOW BOXES

	/**************************************************************************************************/

    private: System::Void CleanShowBoxButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->AppendText("User pressed the button \"Clean box\"\n\n");
		this->TreeView->Nodes->Clear();
		MessageBox::Show(this, "Successfully cleaned","Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

    }

	private: System::Void HistoryButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->MemoBox->Clear();

		MessageBox::Show(this, "Successfully cleaned", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}

	/**************************************************************************************************/

		                 // FUNCTIONS TO DELETE MARKED NODES

	/**************************************************************************************************/

    private: System::Void TreeView_NodeMouseClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e) {

		for (int i = 0; i < this->TreeView->Nodes->Count; i++)
			if (this->TreeView->Nodes[i]->IsExpanded && this->TreeView->Nodes[i]->BackColor == Color::Yellow)
				this->TreeView->Nodes[i]->BackColor = Color::White;

    }

	/**************************************************************************************************/

};
}