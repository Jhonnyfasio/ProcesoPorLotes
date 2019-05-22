#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <time.h>
#include <fstream>
#include "programer.h"
#include "process.h"
#include "collection.h"
#include "bcp.h"
#include "memory.h"

#define TOTAL_MEMORY 180
#define FRAME 5
#define FILENAME "Suspendidos.txt"
#define FILENAME_AUX "AuxSuspendidos.txt"

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
		int quantum = 0;
		int quantumCounter = 0;
		Collection<Process>* secondListData;
		Collection<Process>* queueNews;
		Collection<Process>* queueReady = new Collection<Process>;
		Collection<Process>* queueExecution = new Collection<Process>;
		Collection<Process>* queueBlocked = new Collection<Process>;
		Collection<Process>* queueFinished = new Collection<Process>;
		Collection<Process>* queueSuspend = new Collection<Process>;
		Collection<Memory>* listInMemory = new Collection<Memory>;
		Collection<Memory>* listOutMemory = new Collection<Memory>;
		Collection<Memory>* listAuxMemory = new Collection<Memory>;
		Graphics ^g;
		SolidBrush ^sbYellow = gcnew SolidBrush(Color::Yellow);
		SolidBrush ^sbGreen = gcnew SolidBrush(Color::Green);
		SolidBrush ^sbOrange = gcnew SolidBrush(Color::Orange);
		SolidBrush ^sbWhite = gcnew SolidBrush(Color::White);
		SolidBrush ^sbBlack = gcnew SolidBrush(Color::Black);
		SolidBrush ^sbBlue = gcnew SolidBrush(Color::Blue);

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
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  labelQuantum;


	private: System::Windows::Forms::Label^  maxQuantum;
	private: System::Windows::Forms::Panel^  panelDrawing;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  labelOutMemory;
	private: System::Windows::Forms::TextBox^  txtNew;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  txtQuantum;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  txtSuspend;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label17;

	private: System::Windows::Forms::Label^  labelRestantTime;


	public:
			 principalProcess(void)
			 {
				 InitializeComponent();
				 g = panelDrawing->CreateGraphics();
				 Memory memory;
				 //
				 //TODO: agregar código de constructor aquí
				 //
				 remove(FILENAME);

				 queueNews = new Collection<Process>;
				 secondListData = new Collection<Process>;

				 memory.setSize(0);
				 memory.setMax(FRAME);
				 for(int i(0); i < 36; i++){
					 memory.setId(i);
					 listOutMemory->insertData(memory);
				 }
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
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->labelQuantum = (gcnew System::Windows::Forms::Label());
			this->maxQuantum = (gcnew System::Windows::Forms::Label());
			this->panelDrawing = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->labelOutMemory = (gcnew System::Windows::Forms::Label());
			this->txtNew = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtQuantum = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtSuspend = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtNProcess
			// 
			this->txtNProcess->Location = System::Drawing::Point(80, 9);
			this->txtNProcess->Name = L"txtNProcess";
			this->txtNProcess->Size = System::Drawing::Size(66, 20);
			this->txtNProcess->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"N# Procesos";
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(149, 55);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Empezar";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &principalProcess::button1_Click);
			// 
			// txtPending
			// 
			this->txtPending->Location = System::Drawing::Point(11, 177);
			this->txtPending->Multiline = true;
			this->txtPending->Name = L"txtPending";
			this->txtPending->ReadOnly = true;
			this->txtPending->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtPending->Size = System::Drawing::Size(213, 228);
			this->txtPending->TabIndex = 10;
			// 
			// txtProcess
			// 
			this->txtProcess->Location = System::Drawing::Point(230, 28);
			this->txtProcess->Multiline = true;
			this->txtProcess->Name = L"txtProcess";
			this->txtProcess->ReadOnly = true;
			this->txtProcess->Size = System::Drawing::Size(213, 105);
			this->txtProcess->TabIndex = 11;
			// 
			// txtFinished
			// 
			this->txtFinished->Location = System::Drawing::Point(449, 46);
			this->txtFinished->Multiline = true;
			this->txtFinished->Name = L"txtFinished";
			this->txtFinished->ReadOnly = true;
			this->txtFinished->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtFinished->Size = System::Drawing::Size(213, 359);
			this->txtFinished->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 90);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Nuevos:";
			// 
			// labelNews
			// 
			this->labelNews->AutoSize = true;
			this->labelNews->Location = System::Drawing::Point(66, 90);
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
			this->label7->Location = System::Drawing::Point(322, 158);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Tiempo Total:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(303, 178);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Tiempo Restante:";
			// 
			// labelTotalTime
			// 
			this->labelTotalTime->AutoSize = true;
			this->labelTotalTime->Location = System::Drawing::Point(414, 158);
			this->labelTotalTime->Name = L"labelTotalTime";
			this->labelTotalTime->Size = System::Drawing::Size(13, 13);
			this->labelTotalTime->TabIndex = 18;
			this->labelTotalTime->Text = L"0";
			// 
			// labelRestantTime
			// 
			this->labelRestantTime->AutoSize = true;
			this->labelRestantTime->Location = System::Drawing::Point(414, 178);
			this->labelRestantTime->Name = L"labelRestantTime";
			this->labelRestantTime->Size = System::Drawing::Size(13, 13);
			this->labelRestantTime->TabIndex = 19;
			this->labelRestantTime->Text = L"0";
			// 
			// txtStatus
			// 
			this->txtStatus->Location = System::Drawing::Point(80, 57);
			this->txtStatus->Name = L"txtStatus";
			this->txtStatus->Size = System::Drawing::Size(66, 20);
			this->txtStatus->TabIndex = 20;
			this->txtStatus->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &principalProcess::txtStatus_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Estado";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(227, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Ejecución:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(239, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Reloj:";
			// 
			// labelWatch
			// 
			this->labelWatch->AutoSize = true;
			this->labelWatch->Location = System::Drawing::Point(279, 158);
			this->labelWatch->Name = L"labelWatch";
			this->labelWatch->Size = System::Drawing::Size(13, 13);
			this->labelWatch->TabIndex = 24;
			this->labelWatch->Text = L"0";
			// 
			// txtBlocked
			// 
			this->txtBlocked->Location = System::Drawing::Point(230, 226);
			this->txtBlocked->Multiline = true;
			this->txtBlocked->Name = L"txtBlocked";
			this->txtBlocked->ReadOnly = true;
			this->txtBlocked->Size = System::Drawing::Size(213, 104);
			this->txtBlocked->TabIndex = 25;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(230, 210);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Bloqueados:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(446, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(65, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Terminados:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 161);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(34, 13);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Listos";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(341, 198);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(53, 13);
			this->label14->TabIndex = 29;
			this->label14->Text = L"Quantum:";
			// 
			// labelQuantum
			// 
			this->labelQuantum->AutoSize = true;
			this->labelQuantum->Location = System::Drawing::Point(414, 198);
			this->labelQuantum->Name = L"labelQuantum";
			this->labelQuantum->Size = System::Drawing::Size(13, 13);
			this->labelQuantum->TabIndex = 30;
			this->labelQuantum->Text = L"0";
			// 
			// maxQuantum
			// 
			this->maxQuantum->AutoSize = true;
			this->maxQuantum->Location = System::Drawing::Point(208, 9);
			this->maxQuantum->Name = L"maxQuantum";
			this->maxQuantum->Size = System::Drawing::Size(13, 13);
			this->maxQuantum->TabIndex = 33;
			this->maxQuantum->Text = L"0";
			// 
			// panelDrawing
			// 
			this->panelDrawing->Location = System::Drawing::Point(14, 430);
			this->panelDrawing->Name = L"panelDrawing";
			this->panelDrawing->Size = System::Drawing::Size(649, 91);
			this->panelDrawing->TabIndex = 34;
			this->panelDrawing->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &principalProcess::panel1_Paint);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(16, 416);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(649, 13);
			this->label12->TabIndex = 35;
			this->label12->Text = L"01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  2"
				L"1  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36";
			// 
			// labelOutMemory
			// 
			this->labelOutMemory->AutoSize = true;
			this->labelOutMemory->Location = System::Drawing::Point(239, 180);
			this->labelOutMemory->Name = L"labelOutMemory";
			this->labelOutMemory->Size = System::Drawing::Size(13, 13);
			this->labelOutMemory->TabIndex = 36;
			this->labelOutMemory->Text = L"0";
			// 
			// txtNew
			// 
			this->txtNew->Location = System::Drawing::Point(14, 106);
			this->txtNew->Multiline = true;
			this->txtNew->Name = L"txtNew";
			this->txtNew->Size = System::Drawing::Size(210, 52);
			this->txtNew->TabIndex = 37;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(134, 90);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(90, 13);
			this->label13->TabIndex = 38;
			this->label13->Text = L"Primer Candidato:";
			// 
			// txtQuantum
			// 
			this->txtQuantum->Location = System::Drawing::Point(80, 33);
			this->txtQuantum->Name = L"txtQuantum";
			this->txtQuantum->Size = System::Drawing::Size(66, 20);
			this->txtQuantum->TabIndex = 39;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(4, 31);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(50, 13);
			this->label15->TabIndex = 40;
			this->label15->Text = L"Quantum";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(152, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(50, 13);
			this->label11->TabIndex = 31;
			this->label11->Text = L"Quantum";
			// 
			// txtSuspend
			// 
			this->txtSuspend->Location = System::Drawing::Point(233, 354);
			this->txtSuspend->Multiline = true;
			this->txtSuspend->Name = L"txtSuspend";
			this->txtSuspend->ReadOnly = true;
			this->txtSuspend->Size = System::Drawing::Size(213, 51);
			this->txtSuspend->TabIndex = 41;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(230, 338);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(71, 13);
			this->label16->TabIndex = 42;
			this->label16->Text = L"Suspendidos:";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(14, 541);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(649, 91);
			this->panel1->TabIndex = 35;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(8, 525);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(71, 13);
			this->label17->TabIndex = 43;
			this->label17->Text = L"Suspendidos:";
			// 
			// principalProcess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 644);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->txtSuspend);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->txtQuantum);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->txtNew);
			this->Controls->Add(this->labelOutMemory);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->panelDrawing);
			this->Controls->Add(this->maxQuantum);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->labelQuantum);
			this->Controls->Add(this->label14);
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
	private: System::Void principalProcess_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
	int intPublic = 0, idFinal = 0 ;
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Process process;
		std::string aux, aux2, aux3;
		int auxInt, auxInt2, auxInt3, caracter;

		if (txtNProcess->Text->IsNullOrWhiteSpace(txtNProcess->Text) || txtQuantum->Text->IsNullOrWhiteSpace(txtQuantum->Text))
		{
			MessageBox::Show("Error, no puede haber campos vacíos");
			return;
		}

		marshalString(txtQuantum->Text, aux);
		if ((auxInt = atoi(aux.c_str())) < 1) {
			MessageBox::Show("Error, no se puede pedir menos de 1 de Quantum");
			return;
		}

		quantum = auxInt;

		marshalString(txtNProcess->Text, aux);
		if ((auxInt = atoi(aux.c_str())) < 1) {
			MessageBox::Show("Error, no se puede pedir menos de un proceso");
			return;
		}

		for (int i = 0; i < auxInt; i++) {
			chargeProcess(i+1);
		}
		idFinal = auxInt;
		
		//intPublic = auxInt;
		clearTxtBox();
		btnAdd->Enabled = false;
		executeProcess();
	}

	public:

	void chargeProcess(const int& idX) {
		Process process;
		int auxInt2, auxInt3, caracter;
		std::string aux, aux2, aux3;

		//MessageBox::Show("Generando: "+ (i+1).ToString()+ "de: "+auxInt.ToString());
		process.setId(idX);
		//MessageBox::Show("Numer:" + time(NULL).ToString());
		intPublic++;

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

		process.setSize(rand() % 30 + 6);
		process.setLocation(-1);

		process.setTme(rand() % 12 + 7);
		process.setTimeTrans(0);
		process.setTimeRespuesta(-1);
		process.setTimeBlocked(0);
		process.setTimeEspera(0);
		process.setIsError(false);
		process.setTimeServicio(0);

		queueNews->insertData(process);
	}

	void executeProcess() {
		Process process;
		Memory memory;
		SolidBrush ^sbGray = gcnew SolidBrush(Color::Gray);

		int tmeTotal = 0;
		int toErase, max, aux, sizeAux, j(0);
		bool isFull = false;

		process.setId(0);
		for (int i(0); i < 2; i++) {
			memory = listOutMemory->dequeue();
			memory.setSize(FRAME);
			memory.setId(-1);
			listInMemory->insertData(memory);

			g->FillRectangle(sbGray, j + 1, 1, 17, (17.6)*memory.getSize() + 1);
			g->DrawString(process.getId().ToString(), this->Font, sbWhite, PointF(j + 2, 40));
			j = j + 18;
		}

		while (!queueNews->isEmpty() && !isFull) {
			
			process = queueNews->getFront();

			aux = process.getSize() / FRAME;
			if (process.getSize() % FRAME != 0) {
				aux++;
			}
			sizeAux = process.getSize();

			if (aux <= listOutMemory->getItemCounter()) {
				--intPublic;
				queueNews->dequeue();
				for (int i(0); i < aux; i++) {
					memory = listOutMemory->dequeue();
					// memory.setId(process.getId());
					if (sizeAux >= FRAME) {
						memory.setSize(FRAME);
						sizeAux = sizeAux - 5;
					}
					else {
						memory.setSize(sizeAux);
					}
					memory.setIdProcess(process.getId());

					listInMemory->insertData(memory);
					g->FillRectangle(sbBlue, j + 1, 1, 17, (17.6)*memory.getSize() + 1);
					g->DrawString(process.getId().ToString(), this->Font, sbBlack, PointF(j + 2, 40));
					j = j + 18;
				}
				txtPending->Text += "ID: " + process.getId() + "\r\nTME = " + process.getTme().ToString() + "\r\n" +
					"T Rest: " + (process.getTme() - process.getTimeTrans()).ToString() + "\r\n";

				process.setTimeLlegada(y);
				queueReady->insertData(process);
			}
			else {
				isFull = true;
			}


		}
		if (queueExecution->isEmpty()) {
			process = queueReady->dequeue();
			process.setTimeRespuesta(0);
			queueExecution->insertData(process);
			generalProcess = queueExecution->getTop();
		}

		if (!queueNews->isEmpty()) {
			process = queueNews->getFront();
			txtNew->Text = "ID: " + process.getId() + "\r\nTamaño: " + process.getSize();
			aux = process.getSize() / FRAME;
			if (process.getSize() % FRAME != 0) {
				aux++;
			}
			txtNew->Text += "\r\nMarcos: " + aux.ToString();
		}


		totalTime = generalProcess.getTme();

		/*txtProcess->Text = "ID: " + generalProcess.getId().ToString() + "\r\nTiempo Trans: " + generalProcess.getTimeTrans().ToString() +
		"\r\nTiempo Restante: " + (generalProcess.getTme() - generalProcess.getTimeTrans()).ToString() +"\r\n"¨*/
		actualizeTxtProcess(generalProcess);
		actualizeMemory(generalProcess, sbGreen);

		labelNews->Text = intPublic.ToString();
		timer1->Interval = 500;
		timer1->Start();
	}

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

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Collection<Process>* queueAux = new Collection<Process>;
		Process process;
		bool space;
		int time, auxInt;
		int max, toErase;
		std::string aux;
		txtBlocked->Text = "";

		maxQuantum->Text = quantum.ToString();

		if (generalProcess.getId() != -1 && y < generalProcess.getTme()) {
			y++;
			quantumCounter++;
		}

		generalProcess.setTimeTrans((int)y);
		generalProcess.setTimeServicio((int)y);

		if(!queueExecution->isEmpty() && generalProcess.getId() != -1){
			queueExecution->dequeue();
			queueExecution->insertData(generalProcess);
		}

		generalWatch++;
		labelTotalTime->Text = y.ToString();
		labelRestantTime->Text = (generalProcess.getTme() - y).ToString();
		labelWatch->Text = generalWatch.ToString();
		labelQuantum->Text = quantumCounter.ToString();

		if (!queueNews->isEmpty()) {
			auxInt = queueNews->getFront().getSize() / FRAME;
			if (queueNews->getFront().getSize() % FRAME != 0) {
				auxInt++;
			}
		}
		
		// Añadiendo a memoria por espacio disponible
		while (!queueNews->isEmpty() && auxInt <= listOutMemory->getItemCounter()) {
			process = queueNews->dequeue();
			process.setTimeLlegada(generalWatch);
			//process.setTimeRespuesta(generalWatch);
			labelNews->Text = (--intPublic).ToString();
			
			actualizeTxtPending(process);

			queueReady->insertData(process);
			addToMemory(process);

			if (!queueNews->isEmpty()) {
				auxInt = queueNews->getFront().getSize() / FRAME;
				if (queueNews->getFront().getSize() % FRAME != 0) {
					auxInt++;
				}
			}
		}

		// Salen los procesos por error o por finalización normal
		if ((generalProcess.getId() != -1 && (y >= generalProcess.getTme() || qGeneral == 2)) && !queueExecution->isEmpty()) {
			std::string toConver;
			int toConverInt;
			marshalString(labelNews->Text, toConver);

			/*if (!queueNews->isEmpty()) {
				
			}*/

			y = 0;
			quantumCounter = 0;

			process = queueExecution->dequeue();
			txtProcess->Text = "";

			generalProcess.setTimeFinalizacion(generalWatch); // En caso de fallo moverle a esto por retorno
			time = (generalProcess.getTimeFinalizacion() - generalProcess.getTimeLlegada() - generalProcess.getTimeServicio());
			txtFinished->Text += "Número de programa: " + generalProcess.getId() +
				"\r\nOperación: " + gcnew String(generalProcess.getOperation().c_str());
			if (qGeneral == 2) {
				generalProcess.setIsError(true);
				txtFinished->Text += "\r\nResultado: ERROR";
			}
			else {
				txtFinished->Text += "\r\nResultado: " + generalProcess.getResult();
			}
			time = (generalProcess.getTimeFinalizacion() - generalProcess.getTimeLlegada());
			txtFinished->Text += "\r\n Tiempo de Llegada: " + generalProcess.getTimeLlegada() +
				"\r\nTiempo de Finalizacion" + generalProcess.getTimeFinalizacion() +
				"\r\nTiempo de Retorno: " + time +
				"\r\nTiempo de Respuesta: " + generalProcess.getTimeRespuesta() +
				"\r\nTiempo de Espera: " + (time - generalProcess.getTimeServicio()).ToString() +
				"\r\nTiempo de Servicio: " + generalProcess.getTimeServicio() +
				"\r\n---------------------------------------------------------------\r\n";

			queueFinished->insertData(generalProcess);
			clearMemory(generalProcess);

			while (!queueNews->isEmpty() && calculateSize(queueNews->getFront()) <= listOutMemory->getItemCounter()) {
				labelNews->Text = (--intPublic).ToString();
				process = queueNews->dequeue();
				process.setTimeLlegada(generalWatch);
				queueReady->insertData(process);
				actualizeTxtPending(process);
				//actualizeMemory(process, sbBlue);
				addToMemory(process);
			}

			if (!queueReady->isEmpty()) {
				generalProcess = queueReady->dequeue();
				y = generalProcess.getTimeTrans();

				if (generalProcess.getTimeRespuesta() == -1) {
					//MessageBox::Show("ID:"+generalProcess.getId()+"\r\nRespuesta: "+(generalWatch - generalProcess.getTimeLlegada()));
					generalProcess.setTimeRespuesta(generalWatch - generalProcess.getTimeLlegada());
				}

				queueExecution->insertData(generalProcess);
				/*txtProcess->Text = "ID: " + generalProcess.getId().ToString() + "\r\nTiempo Trans: " + generalProcess.getTimeTrans().ToString() +
					"\r\nTiempo Restante: " + (generalProcess.getTme() - generalProcess.getTimeTrans()).ToString() + "\r\n";*/

				actualizeTxtProcess(generalProcess);
				actualizeMemory(generalProcess, sbGreen);
			}
			else {
				txtProcess->Text = "";
				//timer1->Stop();

			}
		}

		// Quantum por round robbin
		if (quantumCounter >= quantum && generalProcess.getId() != -1) {
			queueReady->insertData(process = queueExecution->dequeue());

			actualizeTxtPending(process);
			actualizeMemory(process, sbBlue);

			if (!queueReady->isEmpty()) {

				generalProcess = queueReady->dequeue();

				if (generalProcess.getTimeRespuesta() == -1) {
					//MessageBox::Show("ID:" + generalProcess.getId() + "\r\nRespuesta: " + (generalWatch - generalProcess.getTimeLlegada()));
					generalProcess.setTimeRespuesta(generalWatch - generalProcess.getTimeLlegada());
				}

				queueExecution->insertData(generalProcess);

				actualizeTxtProcess(generalProcess);
				actualizeMemory(generalProcess, sbGreen);
			}
			quantumCounter = 0;
		}

		while(!queueBlocked->isEmpty()){
			process = queueBlocked->dequeue();
			queueAux->insertData(process);
			txtBlocked->Text += "ID: " + process.getId().ToString() + "\r\nT Trans: " + (generalWatch+9 - process.getTimeBlocked()).ToString() + "\r\n";
		}
		
		while(!queueAux->isEmpty()){
			queueBlocked->insertData(queueAux->dequeue());
		}
		
		if (!queueBlocked->isEmpty() && queueBlocked->getFront().getTimeBlocked() == generalWatch) {
			queueReady->insertData(process = queueBlocked->dequeue());
			
			toErase = ("ID: " + process.getId().ToString() + "\r\nT Trans: 9\r\n")->Length;
			//MessageBox::Show("A eliminar: " + toErase.ToString());
			max = txtBlocked->Text->Length - toErase;
			txtBlocked->Text = txtBlocked->Text->Substring(toErase, max);

			txtPending->Text += "ID: " + process.getId() + "\r\nTME = " + process.getTme().ToString() + "\r\n" +
				"T Rest: " + (process.getTme() - process.getTimeTrans()).ToString() + "\r\n";
			actualizeMemory(process, sbBlue);

		}

		// Añadiendo a memoria desde suspendidos
		if (!queueSuspend->isEmpty() && qGeneral == 5) {
			//MessageBox::Show("Hi");
			qGeneral = 0;
			process = readFile();
			auxInt = process.getSize() / FRAME;
			if (process.getSize() % FRAME != 0) {
				auxInt++;
			}
			//MessageBox::Show("Holi" + auxInt.ToString());
			if (auxInt <= listOutMemory->getItemCounter()) {

				queueReady->insertData(queueSuspend->dequeue());
				if (!queueSuspend->isEmpty()) {
					txtSuspend->Text = "ID: " + queueSuspend->getFront().getId() + "\r\nTamaño: " + queueSuspend->getFront().getSize();
					auxInt = queueSuspend->getFront().getSize() / FRAME;
					if (queueSuspend->getFront().getSize() % FRAME != 0) {
						auxInt++;
					}
					txtSuspend->Text += "\r\nMarcos: " + auxInt.ToString();
					}
				else {
					txtSuspend->Text = "";
				}
				actualizeTxtPending(process);
				addToMemory(process);

				deleteFile(process);
			}
			
		}

		// Agregando a supendido desde bloqueado
		if (!queueBlocked->isEmpty() && qGeneral == 4) {
			qGeneral = 0;
			process = queueBlocked->dequeue();

			toErase = ("ID: " + process.getId().ToString() + "\r\nT Trans: 9\r\n")->Length;
			//MessageBox::Show("A eliminar: " + toErase.ToString());
			max = txtBlocked->Text->Length - toErase;
			txtBlocked->Text = txtBlocked->Text->Substring(toErase, max);

			clearMemory(process);
			saveToFile(process);

			queueSuspend->insertData(process);
			txtSuspend->Text = "ID: " + queueSuspend->getFront().getId() + "\r\nTamaño: " + queueSuspend->getFront().getSize();
			auxInt = queueSuspend->getFront().getSize() / FRAME;
			if (queueSuspend->getFront().getSize() % FRAME != 0) {
				auxInt++;
			}
			txtSuspend->Text += "\r\nMarcos: " + auxInt.ToString();
		}

		if (generalProcess.getId() == -1) {
			labelTotalTime->Text = "0";
			labelRestantTime->Text = "0";
			labelQuantum->Text = "0";
			//MessageBox::Show("Hi");
		}
		
		y = generalProcess.getTimeTrans();
		
		if (!queueExecution->isEmpty() && qGeneral == 1) {
			queueExecution->dequeue();
			process = generalProcess;
			txtProcess->Text = "";
			quantumCounter = 0;
			//marshalString(labelTotalTime->Text, aux);
			//process.setTimeTrans(atoi(aux.c_str()));

			labelTotalTime->Text = "0";
			labelRestantTime->Text = "0";
			process.setTimeTrans((int)y);
			process.setTimeBlocked(generalWatch + 9);
			queueBlocked->insertData(process);
			txtBlocked->Text += "ID: " + process.getId() + "\r\nT Trans: " + (generalWatch + 9 - process.getTimeBlocked()).ToString() + "\r\n";
			actualizeMemory(process, sbOrange);

			if (!queueReady->isEmpty()) {
				generalProcess = queueReady->dequeue();
				y = generalProcess.getTimeTrans();
				// Si error, aquí va primera parte de actualizetxt process
				if (generalProcess.getTimeRespuesta() == -1) {
					//MessageBox::Show("ID:" + generalProcess.getId() + "\r\nRespuesta: " + (generalWatch - generalProcess.getTimeLlegada()));
					generalProcess.setTimeRespuesta(generalWatch - generalProcess.getTimeLlegada());
				}
				queueExecution->insertData(generalProcess);
				// aquí la segunda parte o antes de insertar

				actualizeTxtProcess(generalProcess);

				actualizeMemory(generalProcess, sbGreen);
				labelTotalTime->Text = y.ToString();
				labelRestantTime->Text = (generalProcess.getTme() - y).ToString();
			}
			else {
				generalProcess.setId(-1);
				generalProcess.setTme(0);
				generalProcess.setTimeTrans(0);
				y = 0;
			}

		}

		if (queueExecution->isEmpty()) {
			if(queueReady->isEmpty()){
				if (queueNews->isEmpty()) {
					if (queueBlocked->isEmpty()) {
						if (queueSuspend->isEmpty()) {
							generalProcess.setId(-1);

							labelTotalTime->Text = "0";
							labelRestantTime->Text = "0";
							labelQuantum->Text = "0";
							labelOutMemory->Text = listOutMemory->getItemCounter().ToString();
							timer1->Stop();
						}
					}
				}
			}
			else {
				generalProcess = queueReady->dequeue();

				y = generalProcess.getTimeTrans();
				if (generalProcess.getTimeRespuesta() == -1) {
					generalProcess.setTimeRespuesta(generalWatch - generalProcess.getTimeLlegada());
				}
				queueExecution->insertData(generalProcess);
				
				actualizeTxtProcess(generalProcess);
				actualizeMemory(generalProcess, sbGreen);

			}
		}
		
		if (generalProcess.getId() != -1) {
			labelTotalTime->Text = y.ToString();
			labelRestantTime->Text = (generalProcess.getTme() - y).ToString();
			labelWatch->Text = generalWatch.ToString();
			labelQuantum->Text = quantumCounter.ToString();
			qGeneral = 0;
			labelOutMemory->Text = listOutMemory->getItemCounter().ToString();
		}

		if (!queueNews->isEmpty()) {
			process = queueNews->getFront();
			txtNew->Text = "ID: " + process.getId() + "\r\nTamaño: " + process.getSize();
			auxInt = process.getSize() / FRAME;
			if (process.getSize() % FRAME != 0) {
				auxInt++;
			}
			txtNew->Text += "\r\nMarcos: " + auxInt.ToString();
		}
		else {
			txtNew->Text = "";
		}
		
	}

	private: System::Void txtStatus_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		int toErase, max, auxInt;
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
			qGeneral = 2;
			status = 2;
			generalProcess.setResult(0);
			
			txtStatus->Clear();
			e->Handled = false;
		}
	}
	else if (ch == 'P' || ch == 'M') {
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
	else if (ch == 'T') {
		if (status == 3) {
		}
		else {
			status = 3;
			timer1->Stop();
			showBCP();
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
	else if (ch == 'N') {
		if (status == 3) {
		}
		else {
			qGeneral = 3;
			status = 2;
			auxInt = ++idFinal;
			chargeProcess(auxInt);
			labelNews->Text = (intPublic).ToString();
			txtStatus->Clear();
			e->Handled = false;
			//MessageBox::Show("N");
		}
	}
	else if (ch == 'S') {
		qGeneral = 4;
		status = 2;
		txtStatus->Clear();
		e->Handled = false;
	}
	else if (ch == 'R') {
		qGeneral = 5;
		status = 2;
		txtStatus->Clear();
		e->Handled = false;
	}
	else if (ch == 'U') {
	
	}
	else if (ch == 8) {
		//MessageBox::Show("Erase");
	}
	else {

	}
}

	void showBCP() { // Conitnuar BCP
		Collection<Process>* queueAux = new Collection<Process>;
		Process process;
		int time;
		bcp ^bcpForm;
		//bcpForm->Show();
		System::String ^auxString;

		auxString += "Procesos Finalizados: " + queueFinished->getItemCounter() + "\r\n";
		auxString += "------------------------------------------------------------------\r\n";
		while (!queueFinished->isEmpty()) {
			queueAux->insertData(queueFinished->dequeue());
		}
		while (!queueAux->isEmpty()) {
			queueFinished->insertData(process = queueAux->dequeue());

			time = (process.getTimeFinalizacion() - process.getTimeLlegada());
			auxString += "Número de programa: " + process.getId() +
				"\r\nOperación: " + gcnew String(process.getOperation().c_str()) +
				"\r\nTME: " + process.getTme();
			if (process.getIsError()) {
				auxString += "\r\nResultado: ERROR";
			}
			else {
				auxString += "\r\nResultado: " + process.getResult();
			}
			
			auxString += "\r\n Tiempo de Llegada: " + process.getTimeLlegada() +
				"\r\nTiempo de Finalizacion" + process.getTimeFinalizacion() +
				"\r\nTiempo de Retorno: " + time +
				"\r\nTiempo de Respuesta: " + process.getTimeRespuesta() +
				"\r\nTiempo de Espera: " + (time - process.getTimeServicio()).ToString() +
				"\r\nTiempo de Servicio: " + process.getTimeServicio() +
				"\r\n------------------------------------------------------------------\r\n";
		}


		auxString += "Procesos Nuevos: " + queueNews->getItemCounter() + "\r\n";
		auxString += "------------------------------------------------------------------\r\n";
		while (!queueNews->isEmpty()) {
			queueAux->insertData(queueNews->dequeue());
		}
		while (!queueAux->isEmpty()) {
			queueNews->insertData(process = queueAux->dequeue());

			auxString += "Número de programa: " + process.getId() +
				"\r\nOperación: " + gcnew String(process.getOperation().c_str()) +
				"\r\nResultado: N/A" + 
				"\r\nTME: " + process.getTme() +
				"\r\n Tiempo de Llegada: N/A" +
				"\r\nTiempo de Finalizacion N/A" +
				"\r\nTiempo de Retorno: N/A" +
				"\r\nTiempo de Respuesta: N/A" +
				"\r\nTiempo de Espera: N/A" +
				"\r\nTiempo de Servicio: N/A" +
				"\r\n------------------------------------------------------------------\r\n";
		}
		

		auxString += "Procesos Listos: " + queueReady->getItemCounter() + "\r\n";
		auxString += "------------------------------------------------------------------\r\n";
		while (!queueReady->isEmpty()) {
			queueAux->insertData(queueReady->dequeue());
		}
		while (!queueAux->isEmpty()) {
			queueReady->insertData(process = queueAux->dequeue());

			time = (generalWatch - process.getTimeLlegada());
			auxString += "Número de programa: " + process.getId() +
				"\r\nOperación: " + gcnew String(process.getOperation().c_str()) +
				"\r\nResultado: N/A" +
				"\r\nTME: " + process.getTme() +
				"\r\n Tiempo de Llegada: " + process.getTimeLlegada() +
				"\r\nTiempo de Finalizacion: N/A" +
				"\r\nTiempo de Retorno: N/A";
				if (process.getTimeRespuesta() == -1) {
					auxString += "\r\nTiempo de Respuesta: N/A";
				}
				else {
					auxString += "\r\nTiempo de Respuesta: " + process.getTimeRespuesta();
				}
				
				auxString += 
				"\r\nTiempo de Espera: " + (time - process.getTimeServicio()).ToString() +
				"\r\nTiempo de Servicio: " + process.getTimeServicio() +
				"\r\n------------------------------------------------------------------\r\n";
		}


		auxString += "Proceso en Ejecución: " + queueExecution->getItemCounter() + "\r\n";
		auxString += "------------------------------------------------------------------\r\n";
		while (!queueExecution->isEmpty()) {
			queueAux->insertData(queueExecution->dequeue());
		}
		while (!queueAux->isEmpty()) {
			queueExecution->insertData(process = queueAux->dequeue());

			time = (generalWatch - process.getTimeLlegada());
			auxString += "Número de programa: " + process.getId() +
				"\r\nOperación: " + gcnew String(process.getOperation().c_str()) +
				"\r\nResultado: N/A" +
				"\r\nTME: " + process.getTme() +
				"\r\n Tiempo de Llegada: " + process.getTimeLlegada() +
				"\r\nTiempo de Finalizacion: N/A" +
				"\r\nTiempo de Retorno: N/A" +
				"\r\nTiempo de Respuesta: " + process.getTimeRespuesta() +
				"\r\nTiempo de Espera: " + (time - process.getTimeServicio()).ToString() +
				"\r\nTiempo de Servicio: " + process.getTimeServicio() +
				"\r\n------------------------------------------------------------------\r\n";
		}


		auxString += "Procesos Bloqueados: " + queueBlocked->getItemCounter() + "\r\n";
		auxString += "------------------------------------------------------------------\r\n";
		while (!queueBlocked->isEmpty()) {
			queueAux->insertData(queueBlocked->dequeue());
		}
		while (!queueAux->isEmpty()) {
			queueBlocked->insertData(process = queueAux->dequeue());

			process.setTimeFinalizacion(generalWatch); // En caso de fallo moverle a esto por retorno
			time = (process.getTimeFinalizacion() - process.getTimeLlegada() - process.getTimeServicio());
			auxString += "Número de programa: " + process.getId() +
				"\r\nOperación: " + gcnew String(process.getOperation().c_str()) +
				"\r\nResultado: N/A" +
				"\r\nBloqueado: " + (generalWatch + 10 - process.getTimeBlocked()).ToString();

			time = (process.getTimeFinalizacion() - process.getTimeLlegada());
			auxString += "\r\n Tiempo de Llegada: " + process.getTimeLlegada() +
				"\r\nTiempo de Finalizacion: N/A" +
				"\r\nTiempo de Retorno: N/A" +
				"\r\nTiempo de Respuesta: " + process.getTimeRespuesta() +
				"\r\nTiempo de Espera: " + (time - process.getTimeServicio()).ToString() +
				"\r\nTiempo de Servicio: " + process.getTimeServicio() +
				"\r\n------------------------------------------------------------------\r\n";
		}

		auxString += "Procesos Suspendidos: " + queueSuspend->getItemCounter() + "\r\n";
		auxString += "------------------------------------------------------------------\r\n";
		while (!queueSuspend->isEmpty()) {
			queueAux->insertData(queueSuspend->dequeue());
		}
		int auxInt;
		while (!queueAux->isEmpty()) {
			queueSuspend->insertData(process = queueAux->dequeue());
			time = (generalWatch - process.getTimeLlegada());

			auxString += "Número de programa: " + process.getId() + "\r\nTamaño: " + process.getSize();
			auxInt = process.getSize() / FRAME;
			if (process.getSize() % FRAME != 0) {
				auxInt++;
			}
			auxString += "\r\nMarcos: " + auxInt.ToString();

			auxString += "\r\nOperación: " + gcnew String(process.getOperation().c_str()) +
				"\r\nResultado: N/A" +
				"\r\nTME: " + process.getTme() +
				"\r\n Tiempo de Llegada: " + process.getTimeLlegada() +
				"\r\nTiempo de Finalizacion: N/A" +
				"\r\nTiempo de Retorno: N/A";
			if (process.getTimeRespuesta() == -1) {
				auxString += "\r\nTiempo de Respuesta: N/A";
			}
			else {
				auxString += "\r\nTiempo de Respuesta: " + process.getTimeRespuesta();
			}

			auxString += "\r\nTiempo de Espera: " + (time - process.getTimeServicio()).ToString() +
				"\r\nTiempo de Servicio: " + process.getTimeServicio();

			auxString+="\r\n------------------------------------------------------------------\r\n";
		}

		bcpForm = gcnew bcp(auxString);
		//bcpForm->Show();
	}

	void actualizePanel(Process process, SolidBrush ^sb) {
		int maxSize, size, j(0);
		maxSize = process.getSize();
		size = maxSize / FRAME;

		for (int i(0); i < maxSize; i++) {
			g->FillRectangle(sb, j + 1, 1, 17, (17.6)*size + 1);
			g->DrawString(process.getId().ToString(), this->Font, sbBlack, PointF(j + 2, 40));
			j = j + 18;
		}
		
	}

	void actualizeMemory(Process process, SolidBrush ^sbFill) {
		Memory memory;

		if (listInMemory->findIdProcessProcess(process.getId())) {
			while (listInMemory->findIdProcessProcess(process.getId())) {
				listAuxMemory->insertData(listInMemory->retrieveData(listInMemory->findIdProcessProcessNode(process.getId())));
				listInMemory->deleteData(listInMemory->findIdProcessProcessNode(process.getId()));
			}
			while (!listAuxMemory->isEmpty()) {
				memory = listAuxMemory->dequeue();
				g->FillRectangle(sbFill, memory.getId() * 18 + 1, 1, 17, (17.6)*memory.getSize() + 1);
				g->DrawString(process.getId().ToString(), this->Font, sbBlack, PointF(memory.getId() * 18 + 2, 40));
				listInMemory->insertData(memory);
			}
			
			  
		}	
	}

	void addToMemory(Process process) {
		Memory memory;
		int auxId, aux;
		auxId = process.getId();
		aux = process.getSize();

		while (!listOutMemory->isEmpty() && aux > 0) {
			memory = listOutMemory->dequeue();
			memory.setIdProcess(auxId);
			if (aux >= FRAME) {
				memory.setSize(FRAME);
			}
			else {
				memory.setSize(aux);
			}
			aux -= FRAME;
			listInMemory->enqueue(memory);

			g->FillRectangle(sbBlue, memory.getId() * 18 + 1, 1, 17, (17.6)*memory.getSize() + 1);
			g->DrawString(process.getId().ToString(), this->Font, sbBlack, PointF(memory.getId() * 18 + 2, 40));
		}

			
	}

	void clearMemory(Process process) {
		Pen ^p = gcnew Pen(Color::Black);
		Memory memory;
		int auxId, aux;

		while (!listInMemory->isEmpty() && listInMemory->findIdProcessProcess(process.getId())) {
			memory = listInMemory->retrieveData(listInMemory->findIdProcessProcessNode(process.getId()));
			listInMemory->deleteData(listInMemory->findIdProcessProcessNode(process.getId()));
			
			listOutMemory->insertData(memory);

			g->DrawRectangle(p, memory.getId() * 18, 0, 18, 90);
			g->FillRectangle(sbWhite, memory.getId() * 18 + 1, 1, 17, 89);
			//g->DrawString(process.getId().ToString(), this->Font, sbBlack, PointF(memory.getId() * 18 + 2, 40));

		}


	}

	int calculateSize(Process process) {
		int auxInt = 0;

		auxInt = process.getSize() / FRAME;
		if (process.getSize() % FRAME != 0) {
			auxInt++;
		}

		return auxInt;
	}

	void actualizeTxtProcess(Process process) {
		int toErase, max;
		toErase = ("ID: " + process.getId() + "\r\nTME = " + process.getTme().ToString() + "\r\n" +
			"T Rest: " + (process.getTme() - process.getTimeTrans()).ToString() + "\r\n")->Length;
		max = txtPending->Text->Length - toErase;
		txtPending->Text = txtPending->Text->Substring(toErase, max);

		max = calculateSize(process);
		txtProcess->Text = "ID: " + process.getId().ToString() + "\r\nTiempo Trans: " + process.getTimeTrans().ToString() +
			"\r\nTiempo Restante: " + (process.getTme() - process.getTimeTrans()).ToString() + "\r\nRespuesta: " +
			process.getTimeRespuesta() + "\r\nLlegada: " + process.getTimeLlegada() + "\r\nTamaño: " + process.getSize() + 
			"\r\nMarcos: " + max.ToString();
	}

	void actualizeTxtPending(Process process) {
		txtPending->Text += "ID: " + process.getId() + "\r\nTME = " + process.getTme().ToString() + "\r\n" +
			"T Rest: " + (process.getTme() - process.getTimeTrans()).ToString() + "\r\n";
	}

	void actualizeTxtNew(Process process) {
	
	}

	void marshalString(String ^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void saveToFile(Process process) {
		std::fstream readerFile;
		readerFile.open(FILENAME,std::ios::app|std::ios::out);
		if (!readerFile.is_open()) {
			return;
		}
		readerFile << process.getId() << "°";
		readerFile << process.getOperation().c_str() << "°";
		readerFile << process.getSize() << "°" << process.getLocation() << "°" << process.getTme() << "°" << process.getTimeTrans() << "°"
			<< process.getTimeLlegada() << "°" << process.getTimeFinalizacion() << "°" << process.getTimeServicio() << "°"
			<< process.getTimeRespuesta() << "°" << process.getTimeBlocked() << "°" << process.getTimeEspera() << "°"
			<< process.getIsError() << "°" << process.getResult() << "°";
		
		readerFile.close();
	}

	Process readFile() {
		Process process;
		std::fstream readerFile, readerFileAux;
		std::string str1;
		std::string str2, str3, str4, str5, str6, str7, str8, str9, str10, str11, str12, str13, str14;
		readerFile.open(FILENAME,std::ios::in|std::ios::out);
		if (!readerFile.is_open()) {
			MessageBox::Show("Error, no se pudo abrir el archivo de texto para lectura/escritura");
		}
		else {
			if (!readerFile.eof()) {
				std::getline(readerFile, str1, '°');
				if (!readerFile.eof()) {
					process.setId(atoi(str1.c_str()));
					std::getline(readerFile, str1, '°');
					process.setOperation(str1);

					std::getline(readerFile, str1, '°');
					process.setSize(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setLocation(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTme(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeTrans(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeLlegada(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeFinalizacion(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeServicio(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeRespuesta(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeBlocked(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setTimeEspera(atoi(str1.c_str()));

					std::getline(readerFile, str1, '°');
					process.setIsError(false);

					std::getline(readerFile, str1, '°');
					process.setResult(atof(str1.c_str()));

				}
			}
			readerFile.close();
		
			return process;
		}
	}

	void deleteFile(Process process) {
		std::fstream readerFile, readerFileAux;
		std::string str1;
		std::string str2, str3, str4, str5, str6, str7, str8, str9, str10, str11, str12, str13, str14;
		readerFile.open(FILENAME, std::ios::in | std::ios::out);
		readerFileAux.open(FILENAME_AUX, std::ios::trunc | std::ios::out);
		if (!readerFile.is_open()) {
			MessageBox::Show("Error, no se pudo abrir el archivo de texto para lectura/escritura");
		}
		else if (!readerFileAux.is_open()) {
			MessageBox::Show("Error, no se puede abrir el archivo "+FILENAME_AUX);
		}
		else {
			while (!readerFile.eof()) {
				std::getline(readerFile, str1, '°');
				std::getline(readerFile, str2, '°');
				std::getline(readerFile, str3, '°');
				std::getline(readerFile, str4, '°');
				std::getline(readerFile, str5, '°');
				std::getline(readerFile, str6, '°');
				std::getline(readerFile, str7, '°');
				std::getline(readerFile, str8, '°');
				std::getline(readerFile, str9, '°');
				std::getline(readerFile, str10, '°');
				std::getline(readerFile, str11, '°');
				std::getline(readerFile, str12, '°');
				std::getline(readerFile, str13, '°');
				std::getline(readerFile, str14, '°');
				if (!readerFile.eof() && atoi(str1.c_str()) != process.getId()) {
					readerFileAux << str1 << "°" << str2 << "°" << str3 << "°" << str4 << "°" << str5 << "°" << str6 << "°" << str7 << "°"
						<< str8 << "°" << str9 << "°" << str10 << "°" << str11 << "°" << str12 << "°" << str13 << "°" << str14 << "°";
				}

			}
			readerFile.close();
			readerFileAux.close();
			remove(FILENAME);

			rename(FILENAME_AUX, FILENAME);
		}
	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Pen ^p = gcnew Pen(Color::Black);
		//

		for (int i(0), j(0); i < 36; i++) {
			g->DrawRectangle(p, j, 0, 18, 90);
			g->FillRectangle(sbWhite, j+1, 1, 17, 89);
			j = j + 18;
		}
	}
	
};
}