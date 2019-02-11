#pragma once

#include <time.h>
#include "programer.h"
#include "process.h"
#include "collection.h"

namespace ProcesoPorLotes {
	Process generalProcess;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de principalProcess
	/// </summary>
	public ref class principalProcess : public System::Windows::Forms::Form
	{
	public:
		int lote = 1;
		int counter = 0;
		int totalTime;
		int actualLote = 0;
		float generalResult = 0;
		int counterId = 0;
		int status = 0 ;
		Collection<Process>* secondListData;
		Collection<Process>* listData;
		Collection<Process>* listAux = new Collection<Process>;
		
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  labelLote;
			 
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  labelTotalTime;
	private: System::Windows::Forms::TextBox^  txtStatus;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labelRestantTime;


	public:
			 principalProcess(void)
			 {
				 InitializeComponent();
				 //
				 //TODO: agregar código de constructor aquí
				 //
				 listData = new Collection<Process>;
				 secondListData = new Collection<Process>;
			 }

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~principalProcess()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtNProcess;
	protected:

	protected:

	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;






	private: System::Windows::Forms::Button^  btnAdd;




	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  txtPending;
	private: System::Windows::Forms::TextBox^  txtProcess;

	private: System::Windows::Forms::TextBox^  txtFinished;
	private: System::Windows::Forms::Button^  buttonProcess;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->txtNProcess = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->txtPending = (gcnew System::Windows::Forms::TextBox());
			this->txtProcess = (gcnew System::Windows::Forms::TextBox());
			this->txtFinished = (gcnew System::Windows::Forms::TextBox());
			this->buttonProcess = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelLote = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labelTotalTime = (gcnew System::Windows::Forms::Label());
			this->labelRestantTime = (gcnew System::Windows::Forms::Label());
			this->txtStatus = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtNProcess
			// 
			this->txtNProcess->Location = System::Drawing::Point(110, 34);
			this->txtNProcess->Name = L"txtNProcess";
			this->txtNProcess->Size = System::Drawing::Size(136, 20);
			this->txtNProcess->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Número de lotes";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(264, 31);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Agregar";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &principalProcess::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(264, 89);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &principalProcess::button2_Click);
			// 
			// txtPending
			// 
			this->txtPending->Location = System::Drawing::Point(12, 204);
			this->txtPending->Multiline = true;
			this->txtPending->Name = L"txtPending";
			this->txtPending->ReadOnly = true;
			this->txtPending->Size = System::Drawing::Size(213, 133);
			this->txtPending->TabIndex = 10;
			// 
			// txtProcess
			// 
			this->txtProcess->Location = System::Drawing::Point(231, 204);
			this->txtProcess->Multiline = true;
			this->txtProcess->Name = L"txtProcess";
			this->txtProcess->ReadOnly = true;
			this->txtProcess->Size = System::Drawing::Size(213, 84);
			this->txtProcess->TabIndex = 11;
			// 
			// txtFinished
			// 
			this->txtFinished->Location = System::Drawing::Point(450, 15);
			this->txtFinished->Multiline = true;
			this->txtFinished->Name = L"txtFinished";
			this->txtFinished->ReadOnly = true;
			this->txtFinished->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtFinished->Size = System::Drawing::Size(213, 322);
			this->txtFinished->TabIndex = 12;
			// 
			// buttonProcess
			// 
			this->buttonProcess->Location = System::Drawing::Point(362, 162);
			this->buttonProcess->Name = L"buttonProcess";
			this->buttonProcess->Size = System::Drawing::Size(75, 23);
			this->buttonProcess->TabIndex = 13;
			this->buttonProcess->Text = L"Empezar";
			this->buttonProcess->UseVisualStyleBackColor = true;
			this->buttonProcess->Click += gcnew System::EventHandler(this, &principalProcess::buttonProcess_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Lotes pendientes: ";
			// 
			// labelLote
			// 
			this->labelLote->AutoSize = true;
			this->labelLote->Location = System::Drawing::Point(112, 172);
			this->labelLote->Name = L"labelLote";
			this->labelLote->Size = System::Drawing::Size(0, 13);
			this->labelLote->TabIndex = 15;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &principalProcess::timer1_Tick);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(267, 291);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Tiempo Total:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(248, 314);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Tiempo Restante:";
			// 
			// labelTotalTime
			// 
			this->labelTotalTime->AutoSize = true;
			this->labelTotalTime->Location = System::Drawing::Point(359, 291);
			this->labelTotalTime->Name = L"labelTotalTime";
			this->labelTotalTime->Size = System::Drawing::Size(0, 13);
			this->labelTotalTime->TabIndex = 18;
			// 
			// labelRestantTime
			// 
			this->labelRestantTime->AutoSize = true;
			this->labelRestantTime->Location = System::Drawing::Point(365, 318);
			this->labelRestantTime->Name = L"labelRestantTime";
			this->labelRestantTime->Size = System::Drawing::Size(0, 13);
			this->labelRestantTime->TabIndex = 19;
			// 
			// txtStatus
			// 
			this->txtStatus->Location = System::Drawing::Point(110, 91);
			this->txtStatus->Name = L"txtStatus";
			this->txtStatus->Size = System::Drawing::Size(136, 20);
			this->txtStatus->TabIndex = 20;
			this->txtStatus->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &principalProcess::txtStatus_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Estado";
			// 
			// principalProcess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 349);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtStatus);
			this->Controls->Add(this->labelRestantTime);
			this->Controls->Add(this->labelTotalTime);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->labelLote);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonProcess);
			this->Controls->Add(this->txtFinished);
			this->Controls->Add(this->txtProcess);
			this->Controls->Add(this->txtPending);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtNProcess);
			this->Name = L"principalProcess";
			this->Text = L"Proceso";
			this->Load += gcnew System::EventHandler(this, &principalProcess::principalProcess_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Programer programer;
		Process process;
		std::string aux, aux2, aux3;
		int counterLocal = counter;
		int loteLocal;
		int auxInt, auxInt2, caracter;

		if (txtNProcess->Text->IsNullOrWhiteSpace(txtProcess->Text) || txtStatus->Text->IsNullOrWhiteSpace(txtStatus->Text))
		{
			MessageBox::Show("Error, no puede haber campos vacíos");
			return;
		}
	
		marshalString(txtNProcess->Text, aux);
		if ((auxInt = atoi(aux.c_str())) < 1) {
			MessageBox::Show("Error, no se puede pedir menos de un lote");
			return;
		}
		
		for (int i = 0; i < auxInt; i++) {
			process.setId(i + 1);

			srand(time(NULL));

			auxInt = rand() % 50;
			auxInt2 = rand() % 50;
			caracter = rand() % 5;

			switch (caracter)
			{
			case 0:
				aux = "+";
				break;
			case 1:
				aux = "-";
				break;
			case 2:
				aux = "*";
				break;
			case 3:
				aux = "/";
				break;
			case 4:
				aux = "%";
				break;
			default:
				MessageBox::Show("Error en generación caracter");
				break;
			}
			marshalString(auxInt.ToString(), aux2);
			marshalString(auxInt2.ToString(), aux3);
			aux = aux2 + aux + aux3;
			process.setOperation(aux);

			auxInt = generalResult;
			process.setResult(auxInt);


			process.setTme(rand() % 18 + 7);

			counter++;
			if (counter > 3) {
				lote++;
				counter = 1;
			}
			labelLote->Text = lote.ToString();
			loteLocal = lote;
			process.setLote(loteLocal);

			listData->insertData(process);
		}
		
		clearTxtBox();	
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		clearTxtBox();
	}

	void marshalString(String ^ s, std::string& os) {
		 using namespace Runtime::InteropServices;
		 const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		 os = chars;
		 Marshal::FreeHGlobal(IntPtr((void*)chars));
	 }
	public:

		void clearTxtBox() {
			txtProcess->Clear();
			txtStatus->Clear();
		}

	bool automatonOperational(std::string expression) {
		int qActual = 0, digit1, digit2, position;
		int i = 0;
		float result = 0;
		char operation;
		bool exit = false;
		while (!exit) {
			switch (qActual) {
			case 0:
				if (isdigit(expression[i])) {
					qActual = 1;
				}
				else {
					qActual = 5;
				}
				break;
			case 1:
				if (isdigit(expression[i])) {
					qActual = 1;
				}
				else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%') {
					qActual = 2;
					digit1 = atoi(expression.substr(0, i).c_str());
					operation = expression[i];
				}
				else {
					qActual = 5;
				}
				break;
			case 2:
				if (isdigit(expression[i])) {
					qActual = 4;
					position = i;
				}
				else {
					qActual = 5;
				}
				break;
			case 4:
				if (isdigit(expression[i])) {
					qActual = 4;
				}
				else if (expression[i] == '\0') {
					qActual = 3;
				}
				else {
					qActual = 5;
				}
				break;
			case 3:
				//MessageBox::Show("q 3");
				digit2 = atoi((expression.substr(position, expression.length() - (position))).c_str());
				exit = true;
				break;
			case 5:
				exit = true;
				MessageBox::Show("Error, la operación no ha sido definida correctamente");
				return false;
				break;
			default:
				MessageBox::Show("default");
				break;
			}
			i++;
		}
		//MessageBox::Show("Por entrar a 3 \r\n QActual=" + qActual.ToString());
		if (qActual == 3) {
			//MessageBox::Show("Entré a 3");
			if (operation == '-') {
				result = float(digit1 - digit2);
			}
			else if (operation == '+') {
				result = float(digit1 + digit2);
			}
			else if (operation == '*') {
				result = float(digit1 * digit2);
			}
			else if (operation == '/') {
				if (digit2 == 0) {
					MessageBox::Show("Error, 0 no puede ser el dividendo");
					return false;
				}
				else {
					//MessageBox::Show("Diviendo");
					result = float(digit1 / digit2);
				}
			}
			else if (operation == '%') {
				if (digit2 == 0) {
					MessageBox::Show("Error, 0 no puede ser el dividendo");
					return false;
				}
				else {
					result = float(digit1 % digit2);
				}
			}
			else {
				MessageBox::Show("What?");
			}
			}
			generalResult = result;
			//MessageBox::Show("Resultado: " + generalResult.ToString());
			return true;
			}

		void executeProcessName() {
			Process process;
			if (listData->isEmpty()) {
				return;
			}
			txtPending->Text = "";
			for (int i = 0; (i < 3 && !listData->isEmpty()); i++) {
				process = listData->dequeue();
				listAux->insertData(process);
				txtPending->Text += "TME = " + process.getTme().ToString()+"\r\n";
				
			}
			//txtPending->Text = "Lote en ejecución: " + process.getLote().ToString()+"\r\n"+txtPending->Text;
			executeProcess();
		}

		void executeProcess() {
			Process process;
			int tmeTotal = 0;
			

			if(!listAux->isEmpty()) {
				//process = listData->retrieveData(listData->getFirst());
				process = listAux->dequeue();
				txtProcess->Text = "ID: " + process.getId().ToString() + "\r\n" +
					"Operación: " + gcnew String(process.getOperation().c_str()) + "\r\n" + "TME: " + process.getTme().ToString();
				
				int toErase;
				toErase = ("TME = " + process.getTme().ToString() + "\r\n")->Length;
				
				//MessageBox::Show("Lenght: " + toErase.ToString());
				int max = txtPending->Text->Length - toErase;
				txtPending->Text = txtPending->Text->Substring(toErase,max);
				//MessageBox::Show("Pass");
				timer1->Interval = 1000;
				totalTime = process.getTme();
				
				generalProcess = process;

				timer1->Start();
				
			}
			else {
				executeProcessName();
			}
			
		}


private: System::Void principalProcess_Load(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void buttonProcess_Click(System::Object^  sender, System::EventArgs^  e) {
		btnAdd->Enabled = false;
		executeProcess();
	}
	
			 int y = 0;
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	Process process;
	if (y <= totalTime) {
		labelTotalTime->Text = y.ToString();
		labelRestantTime->Text = (totalTime - y).ToString();
		y++;
	}
	else {
		labelTotalTime->Text = "0";
		labelRestantTime->Text = "0";
		y = 0;
		timer1->Stop();
		//executeProcess();
		if (actualLote != generalProcess.getLote()) {
			actualLote++;
			txtFinished->Text += "------------------ Lote #" + actualLote.ToString() + " -------------------\r\n";
			labelLote->Text = (lote - actualLote).ToString();
		}
		
		txtFinished->Text += "Número de programa: " + generalProcess.getId() +
			"\r\nOperación: " + gcnew String(generalProcess.getOperation().c_str()) +
			"\r\nResultado: " + generalProcess.getResult()+ "\r\n";

		executeProcess();
		
	}
	}

private: System::Void txtStatus_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	e->KeyChar = Char::ToUpper(e->KeyChar);
	Char ch = e->KeyChar;
	//MessageBox::Show("Key = "+ ch);
	e->Handled = true;
	if (ch == 'I') {
		if (ch == 3) {

		}
		else {
			txtStatus->Clear();
			e->Handled = false;
			MessageBox::Show("I");
		}
	}
	else if (ch == 'E') {
		if (ch == 3) {
		}
		else {
			txtStatus->Clear();
			e->Handled = false;
			MessageBox::Show("E");
		}
	}
	else if (ch == 'P') {
		txtStatus->Clear();
		e->Handled = false;
		MessageBox::Show("P");
	}
	else if (ch == 'C') {
		if (status == 3) {
			// Continuar
			txtStatus->Clear();
			e->Handled = false;
			MessageBox::Show("C");
		}
		else {
		
		}
		
	}
	else if (ch == 8) {
		//MessageBox::Show("Erase");
	}
	else {

	}
}
};
}
