#include "MyBracketsCheckForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	BracketsCheckApplication::MyBracketsCheckForm form;
	Application::Run(% form);
}