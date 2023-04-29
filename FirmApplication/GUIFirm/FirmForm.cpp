#include "FirmForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	setlocale(LC_ALL, "Rus");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	GUIFirm::FirmForm form;
	Application::Run(% form);
}