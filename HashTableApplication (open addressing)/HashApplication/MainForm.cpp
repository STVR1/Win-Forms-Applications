#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	HashApplication::MainForm form;
	form.FormBorderStyle = FormBorderStyle::FixedSingle;
	form.MaximizeBox = false;
	Application::Run(%form);

}