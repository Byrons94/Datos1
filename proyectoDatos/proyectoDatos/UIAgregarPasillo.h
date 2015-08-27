#pragma once
#include "GestorInventario.h"
#include "Utilitario.h"
namespace proyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;

	/// <summary>
	/// Summary for UIAgregarPasillo
	/// </summary>
	public ref class UIAgregarPasillo : public System::Windows::Forms::Form
	{
		ListaPasillos * listaP;

	public:

		UIAgregarPasillo(void)
		{
			InitializeComponent();
		}

		UIAgregarPasillo(ListaPasillos * listaPasillos)
		{
			InitializeComponent();
			listaP = listaPasillos;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIAgregarPasillo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::TextBox^  txtCodigo;
	private: System::Windows::Forms::Label^  label7;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  requerido;
	private: System::Windows::Forms::TextBox^  txtDescripcion;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtNumero;

	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIAgregarPasillo::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtNumero = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->requerido = (gcnew System::Windows::Forms::Label());
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->txtNumero);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtCodigo);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->requerido);
			this->panel1->Controls->Add(this->txtDescripcion);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(428, 347);
			this->panel1->TabIndex = 8;
			// 
			// txtNumero
			// 
			this->txtNumero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNumero->Location = System::Drawing::Point(186, 41);
			this->txtNumero->MaxLength = 15;
			this->txtNumero->Name = L"txtNumero";
			this->txtNumero->Size = System::Drawing::Size(180, 31);
			this->txtNumero->TabIndex = 32;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(44, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 18);
			this->label3->TabIndex = 31;
			this->label3->Text = L"Numero:";
			// 
			// txtCodigo
			// 
			this->txtCodigo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCodigo->Location = System::Drawing::Point(186, 91);
			this->txtCodigo->MaxLength = 15;
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(180, 31);
			this->txtCodigo->TabIndex = 30;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label7->Location = System::Drawing::Point(44, 96);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(71, 18);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Codigo:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkRed;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 302);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(428, 45);
			this->panel2->TabIndex = 25;
			// 
			// requerido
			// 
			this->requerido->AutoSize = true;
			this->requerido->ForeColor = System::Drawing::Color::DarkRed;
			this->requerido->Location = System::Drawing::Point(199, 208);
			this->requerido->Name = L"requerido";
			this->requerido->Size = System::Drawing::Size(160, 13);
			this->requerido->TabIndex = 20;
			this->requerido->Text = L"Todos lo campos son requeridos";
			this->requerido->Visible = false;
			// 
			// txtDescripcion
			// 
			this->txtDescripcion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDescripcion->Location = System::Drawing::Point(186, 143);
			this->txtDescripcion->MaxLength = 15;
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(180, 31);
			this->txtDescripcion->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(44, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Descripcion";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(211, 239);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UIAgregarPasillo::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(167, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 23);
			this->label1->TabIndex = 8;
			// 
			// UIAgregarPasillo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 347);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UIAgregarPasillo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UIAgregarPasillo";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
	#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		GestorInventario * gestor = new GestorInventario();
		char * numeroPasillo = Utilitario::toChar(txtNumero->Text);
		char * codPasillo = Utilitario::toChar(txtCodigo->Text);
		char * descPasillo = Utilitario::toChar(txtDescripcion->Text);
		int num = atoi(numeroPasillo);
		gestor->agregarPasillo(num, codPasillo, descPasillo, listaP);
		Hide();
	}
};
}
