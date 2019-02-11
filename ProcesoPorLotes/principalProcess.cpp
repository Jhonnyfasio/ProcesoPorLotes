#include "principalProcess.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProcesoPorLotes::principalProcess lote;
	Application::Run(%lote);
	return 0;
	}

