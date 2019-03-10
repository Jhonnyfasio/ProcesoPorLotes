#pragma once

namespace ProcesoPorLotes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de bcp
	/// </summary>
	public ref class bcp : public System::Windows::Forms::Form
	{
	public:
		bcp(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		bcp(System::String ^aux) {
			InitializeComponent();
			this->Show();
			txtBcp->Text = aux->ToString();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~bcp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtBcp;
	protected:

	private: System::Windows::Forms::Label^  label1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtBcp = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtBcp
			// 
			this->txtBcp->Location = System::Drawing::Point(15, 28);
			this->txtBcp->Multiline = true;
			this->txtBcp->Name = L"txtBcp";
			this->txtBcp->ReadOnly = true;
			this->txtBcp->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBcp->Size = System::Drawing::Size(247, 380);
			this->txtBcp->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"BCP";
			// 
			// bcp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 420);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBcp);
			this->Name = L"bcp";
			this->Text = L"bcp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public:
		
#pragma endregion
	};
}
