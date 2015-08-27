#pragma once
#include "GestorInventario.h"
#include "Utilitario.h"
#include "ListaGenerales.h"

namespace proyectoDatos {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;

	/// <summary>
	/// Summary for UIAgregarGenerales
	/// </summary>
	public ref class UIAgregarGenerales : public System::Windows::Forms::Form
	{
		ListaPasillos * lista;
	public:
		UIAgregarGenerales(void)
		{
			InitializeComponent();
			cargarCombo();
		}

		UIAgregarGenerales(ListaPasillos * plista){
			InitializeComponent();
			cargarCombo();
			lista = plista;
		}

	protected:
		
		~UIAgregarGenerales()
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
	private: System::Windows::Forms::ComboBox^  combo;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel2;



	private: System::Windows::Forms::Label^  requerido;


	private: System::Windows::Forms::TextBox^  txtNombre;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIAgregarGenerales::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->combo = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->requerido = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->txtCodigo);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->combo);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->requerido);
			this->panel1->Controls->Add(this->txtNombre);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(428, 347);
			this->panel1->TabIndex = 6;
			// 
			// txtCodigo
			// 
			this->txtCodigo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCodigo->Location = System::Drawing::Point(182, 99);
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
			this->label7->Location = System::Drawing::Point(40, 104);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(71, 18);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Codigo:";
			// 
			// combo
			// 
			this->combo->BackColor = System::Drawing::Color::White;
			this->combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->combo->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->combo->FormattingEnabled = true;
			this->combo->Location = System::Drawing::Point(182, 59);
			this->combo->Name = L"combo";
			this->combo->Size = System::Drawing::Size(180, 21);
			this->combo->TabIndex = 28;
			// 
			// label5
			// 
			this->label5->AutoEllipsis = true;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(40, 59);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 18);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Pasillo";
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
			this->requerido->Location = System::Drawing::Point(195, 199);
			this->requerido->Name = L"requerido";
			this->requerido->Size = System::Drawing::Size(160, 13);
			this->requerido->TabIndex = 20;
			this->requerido->Text = L"Todos lo campos son requeridos";
			this->requerido->Visible = false;
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(182, 151);
			this->txtNombre->MaxLength = 15;
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(180, 31);
			this->txtNombre->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(40, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Descripcion";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(207, 230);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UIAgregarGenerales::button1_Click);
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
			// UIAgregarGenerales
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 347);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UIAgregarGenerales";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UIAgregarGenerales";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
		#pragma endregion

	private: System::Void cargarCombo() {
		ListaPasillos * lista = new ListaPasillos();
		 lista->cargarPasillos();
		 NodoPasillo * nodop = lista->getCab();
		 while (nodop!=NULL){
			 char * codigo = nodop->getInfoPasillo()->getCodigo();
			 char * descripcion = nodop->getInfoPasillo()->getDescripcion();
			 combo->Items->Add(Utilitario::Contanenado(codigo, descripcion));
			 nodop = nodop->getSgte();
		 }
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		GestorInventario * gestor = new GestorInventario();
		char * pasillo = Utilitario::getElementCode(combo->SelectedItem->ToString());
		char * codigo = Utilitario::toChar(txtCodigo->Text);
		char * desc = Utilitario::toChar(txtNombre->Text);
		int numero = atoi(pasillo);
		
		ListaGenerales * listaGe = Utilitario::getGeneral(pasillo, lista);
		if (lista != NULL) {
			gestor->agregarLGeneral(numero, codigo, desc, listaGe);
		}
	}
};
}
