#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//TestForma es el nombre del proyecto
	Interfaz::MyForm form;
	Application::Run(%form);
}