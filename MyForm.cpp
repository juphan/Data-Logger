#include "MyForm.h"

// Advanced code
// How the code is going to be run

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

// Related to visual elements on screen
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DataLogger::MyForm form; // Project name, Windows Form name
	Application::Run(% form);
}