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
		int totalTime;
		float generalResult = 0;
		int counterId = 0;
		int status = 0 ;
		int y = 0;
		bool statusBool = true;
		int generalWatch = 0;
		int qGeneral = 0;
		Collection<Process>* secondListData;
		Collection<Process>* queueNews;
		Collection<Process>* queueReady = new Collection<Process>;
		Collection<Process>* queueExecution = new Collection<Process>;
		Collection<Process>* queueBlocked = new Collection<Process>;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  labelNews;

			 
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  labelTotalTime;
	private: System::Windows::Forms::TextBox^  txtStatus;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labelWatch;
	private: System::Windows::Forms::TextBox^  txtBlocked;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  labelRestantTime;


	public:
			 principalProcess(void)
			 {
				 InitializeComponent();
				 //
				 //TODO: agregar código de constructor aquí
				 //
				 queueNews = new Collection<Process>;
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





	private: System::Windows::Forms::TextBox^  txtPending;
	private: System::Windows::Forms::TextBox^  txtProcess;

	private: System::Windows::Forms::TextBox^  txtFinished;

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
			this->txtPending = (gcnew System::Windows::Forms::TextBox());
			this->txtProcess = (gcnew System::Windows::Forms::TextBox());
			this->txtFinished = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelNews = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labelTotalTime = (gcnew System::Windows::Forms::Label());
			this->labelRestantTime = (gcnew System::Windows::Forms::Label());
			this->txtStatus = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelWatch = (gcnew System::Windows::Forms::Label());
			this->txtBlocked = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtNProcess
			// 
			this->txtNProcess->Location = System::Drawing::Point(110, 34);
			this->txtNProcess->Name = L"txtNProcess";
			this->txtNProcess->Size = System::Drawing::Size(66, 20);
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
			this->btnAdd->Location = System::Drawing::Point(110, 135);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Empezar";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &principalProcess::button1_Click);
			// 
			// txtPending
			// 
			this->txtPending->Location = System::Drawing::Point(12, 184);
			this->txtPending->Multiline = true;
			this->txtPending->Name = L"txtPending";
			this->txtPending->ReadOnly = true;
			this->txtPending->Size = System::Drawing::Size(213, 153);
			this->txtPending->TabIndex = 10;
			// 
			// txtProcess
			// 
			this->txtProcess->Location = System::Drawing::Point(231, 53);
			this->txtProcess->Multiline = true;
			this->txtProcess->Name = L"txtProcess";
			this->txtProcess->ReadOnly = true;
			this->txtProcess->Size = System::Drawing::Size(213, 105);
			this->txtProcess->TabIndex = 11;
			// 
			// txtFinished
			// 
			this->txtFinished->Location = System::Drawing::Point(450, 53);
			this->txtFinished->Multiline = true;
			this->txtFinished->Name = L"txtFinished";
			this->txtFinished->ReadOnly = true;
			this->txtFinished->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtFinished->Size = System::Drawing::Size(213, 284);
			this->txtFinished->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 145);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Nuevos:";
			// 
			// labelNews
			// 
			this->labelNews->AutoSize = true;
			this->labelNews->Location = System::Drawing::Point(65, 145);
			this->labelNews->Name = L"labelNews";
			this->labelNews->Size = System::Drawing::Size(13, 13);
			this->labelNews->TabIndex = 15;
			this->labelNews->Text = L"0";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &principalProcess::timer1_Tick);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(314, 291);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Tiempo Total:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(295, 314);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Tiempo Restante:";
			// 
			// labelTotalTime
			// 
			this->labelTotalTime->AutoSize = true;
			this->labelTotalTime->Location = System::Drawing::Point(406, 291);
			this->labelTotalTime->Name = L"labelTotalTime";
			this->labelTotalTime->Size = System::Drawing::Size(13, 13);
			this->labelTotalTime->TabIndex = 18;
			this->labelTotalTime->Text = L"0";
			// 
			// labelRestantTime
			// 
			this->labelRestantTime->AutoSize = true;
			this->labelRestantTime->Location = System::Drawing::Point(406, 314);
			this->labelRestantTime->Name = L"labelRestantTime";
			this->labelRestantTime->Size = System::Drawing::Size(13, 13);
			this->labelRestantTime->TabIndex = 19;
			this->labelRestantTime->Text = L"0";
			// 
			// txtStatus
			// 
			this->txtStatus->Location = System::Drawing::Point(110, 91);
			this->txtStatus->Name = L"txtStatus";
			this->txtStatus->Size = System::Drawing::Size(66, 20);
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(228, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Ejecución:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(231, 291);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Reloj:";
			// 
			// labelWatch
			// 
			this->labelWatch->AutoSize = true;
			this->labelWatch->Location = System::Drawing::Point(271, 291);
			this->labelWatch->Name = L"labelWatch";
			this->labelWatch->Size = System::Drawing::Size(13, 13);
			this->labelWatch->TabIndex = 24;
			this->labelWatch->Text = L"0";
			// 
			// txtBlocked
			// 
			this->txtBlocked->Location = System::Drawing::Point(231, 184);
			this->txtBlocked->Multiline = true;
			this->txtBlocked->Name = L"txtBlocked";
			this->txtBlocked->ReadOnly = true;
			this->txtBlocked->Size = System::Drawing::Size(213, 104);
			this->txtBlocked->TabIndex = 25;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(231, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Bloqueados:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(447, 34);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Terminados:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(13, 168);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(34, 13);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Listos";
			// 
			// principalProcess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 349);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->txtBlocked);
			this->Controls->Add(this->labelWatch);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelRestantTime);
			this->Controls->Add(this->labelTotalTime);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtStatus);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->labelNews);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtFinished);
			this->Controls->Add(this->txtProcess);
			this->Controls->Add(this->txtPending);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtNProcess);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"principalProcess";
			this->Text = L"Proceso";
			this->Load += gcnew System::EventHandler(this, &principalProcess::principalProcess_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Process process;
		std::string aux, aux2, aux3;
		int auxInt, auxInt2, auxInt3, caracter;

		if (txtNProcess->Text->IsNullOrWhiteSpace(txtNProcess->Text))
		{
			MessageBox::Show("Error, no puede haber campos vacíos");
			return;
		}

		marshalString(txtNProcess->Text, aux);
		if ((auxInt = atoi(aux.c_str())) < 1) {
			MessageBox::Show("Error, no se puede pedir menos de un lote");
			return;
		}
		srand(time(NULL));
		for (int i = 0; i < auxInt; i++) {
			//MessageBox::Show("Generando: "+ (i+1).ToString()+ "de: "+auxInt.ToString());
			process.setId(i + 1);
			//MessageBox::Show("Numer:" + time(NULL).ToString());

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
			do {
				auxInt2 = rand() % 50;
				auxInt3 = rand() % 50;			
			} while (auxInt2 == 0 && (caracter == 4 || caracter == 3));

			marshalString(auxInt2.ToString(), aux2);
			marshalString(auxInt3.ToString(), aux3);
			aux = aux2 + aux + aux3 + '\0';
			process.setOperation(aux);
			automatonOperational(aux);
			auxInt2 = generalResult;
			process.setResult(auxInt2);
			
			process.setTme(rand() % 12 + 7);
			process.setTimeTrans(0);
			process.setTimeRespuesta(-1);

			queueNews->insertData(process);
		}
		
		labelNews->Text = auxInt.ToString();
		clearTxtBox();
		btnAdd->Enabled = false;
		executeProcess();
	}

	public:

		void clearTxtBox() {
			txtNProcess->Clear();
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

	void executeProcess() {
		Process process;
		int tmeTotal = 0;
		int toErase, max;
		int maxProcess = 0;

		while (!queueNews->isEmpty() && maxProcess < 3) {
			maxProcess++;
			process = queueNews->dequeue();
			txtPending->Text += "ID: " + process.getId() + "\r\nTME = " + process.getTme().ToString() + "\r\n" +
				"T Rest: " + (process.getTme() - process.getTimeTrans()).ToString() + "\r\n";

			process.setTimeLlegada(y);
			queueReady->insertData(process);
		}
		if (queueExecution->isEmpty()) {
			queueExecution->insertData(queueReady->dequeue());
			generalProcess = queueExecution->getTop();
		}

		toErase = ("ID: " + generalProcess.getId() + "\r\nTME = " + generalProcess.getTme().ToString() + "\r\n" +
			"T Rest: " + (generalProcess.getTme() - generalProcess.getTimeTrans()).ToString() + "\r\n")->Length;
		max = txtPending->Text->Length - toErase;
		txtPending->Text = txtPending->Text->Substring(toErase, max);
		totalTime = generalProcess.getTme();

		txtProcess->Text = "ID: " + generalProcess.getId().ToString() + "\r\n T Trans: " + generalProcess.getTimeTrans().ToString() +
			"\r\nT Trans: " + (generalProcess.getTme() - generalProcess.getTimeTrans()).ToString() +"\r\n";
		timer1->Interval = 1000;
		timer1->Start();	
		}


	private: System::Void principalProcess_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Process process;
		int time;
		std::string aux;
		if (!queueBlocked->isEmpty() && queueBlocked->getFront().getTimeBlocked() == y) {
			queueReady->insertData(queueBlocked->dequeue());
		}

		if (qGeneral == 1) {
			marshalString(labelTotalTime->Text, aux);
			generalProcess.setTimeTrans(atoi(aux.c_str()));
			txtBlocked->Text += "ID: " + generalProcess.getId() + "\r\nTME = " + generalProcess.getTme().ToString() + "\r\n" +
				"T Trans: " + (generalProcess.getTme() - generalProcess.getTimeTrans()).ToString() + "\r\n";
			labelTotalTime->Text = "0";
			labelRestantTime->Text = "0";

			generalProcess.setTimeBlocked(y + 10);
			queueBlocked->insertData(generalProcess);
			queueExecution->dequeue();

			if (!queueReady->isEmpty()) {
				generalProcess = queueReady->dequeue();

				if (generalProcess.getTimeRespuesta() == -1) {
					generalProcess.setTimeRespuesta(y);
				}
				queueExecution->insertData(generalProcess);
			}
			else {
				generalProcess.setTme(30);
				generalProcess.setTimeTrans(0);
				}
			
		}
		y = generalProcess.getTimeTrans();
		if (y <= generalProcess.getTme()) {
			y++;
			generalWatch++;
			
			labelTotalTime->Text = y.ToString();
			labelRestantTime->Text = (generalProcess.getTme() - y).ToString();
			labelWatch->Text = generalWatch.ToString();
			generalProcess.setTimeTrans((int)y);
		}
		else {
			labelTotalTime->Text = "0";
			labelRestantTime->Text = "0";
			y = 0;
			//timer1->Stop();

			time = (generalProcess.getTimeFinalizacion() - generalProcess.getTimeLlegada() - generalProcess.getTimeServicio());
			txtFinished->Text += "Número de programa: " + generalProcess.getId() +
				"\r\nOperación: " + gcnew String(generalProcess.getOperation().c_str()) +
				"\r\nResultado: " + generalProcess.getResult() + "\r\n Tiempo de Llegada: " + generalProcess.getTimeLlegada() +
				"\r\nTiempo de Finalizacion" + generalProcess.getTimeFinalizacion() + "\r\n Tiempo de Retorno: " +
				(generalProcess.getTimeServicio() + "\r\nTiempo de Retorno: " + time + "\r\nTiempo de Respuesta: " + generalProcess.getTimeRespuesta()) +
				"\r\nTiempo de Espera: " + generalProcess.getTimeRespuesta() + "\r\nTiempo de Servicio: " + generalProcess.getTimeServicio() + "\r\n"; 
		}
		qGeneral = 0;
	}

	private: System::Void txtStatus_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		int toErase, max;
		std::string aux;
		Char ch;
		e->KeyChar = Char::ToUpper(e->KeyChar);
		ch = e->KeyChar;
		e->Handled = true;
		//MessageBox::Show("Lote: " + lote.ToString()+ "Actual: " + actualLote.ToString());
	if (!statusBool) {
		return;
	}

	if (ch == 'I') {
		if (status == 3) {

		}
		else {
			qGeneral = 1;
			status = 1;
			//timer1->Stop();


			txtStatus->Clear();
			e->Handled = false;
			//MessageBox::Show("I");
		}
	}
	else if (ch == 'E') {
		if (status == 3) {
		}
		else {
			status = 2;
			timer1->Stop();
			labelTotalTime->Text = "0";
			labelRestantTime->Text = "0";
			generalProcess.setResult(0);
			//MessageBox::Show("Actual: "+ actualLote.ToString() + "Lote: " + generalProcess.getLote().ToString());
			
			txtFinished->Text += "Número de programa: " + generalProcess.getId() + "\r\nEstado: ERROR\r\n";
			txtStatus->Clear();
			e->Handled = false;
			//MessageBox::Show("E");
			executeProcess();
		}
	}
	else if (ch == 'P') {
		if(status == 3){
		}
		else {
			status = 3;
			timer1->Stop();
			txtStatus->Clear();
			e->Handled = false;
			//MessageBox::Show("P");
		}
	}
	else if (ch == 'C') {
		if (status == 3) {
			status = 4;
			timer1->Start();
			txtStatus->Clear();
			e->Handled = false;
			//MessageBox::Show("C");
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

	void marshalString(String ^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
};
}
