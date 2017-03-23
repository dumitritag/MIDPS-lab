#include "MyForm.h"
#include "Header.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	VCPP_Scientific_Calculator::MyForm form;
	Application::Run(%form);
}
