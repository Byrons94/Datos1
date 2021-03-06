#pragma once
#include "Utilitario.h"
#include "ListaArticulo.h"
#include "ListaEspecifica.h"


namespace proyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;

	/// <summary>
	/// Resumen de ModificarArticulo2
	/// </summary>
	public ref class ModificarArticulo2 : public System::Windows::Forms::Form
	{
		char *codigo;

	public:

		ModificarArticulo2()
		{
			InitializeComponent();
		
		}

		ModificarArticulo2(char * c)
		{
			InitializeComponent();
			codigo = c;
			cargarEspecificas();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~ModificarArticulo2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtPrecio;
	private: System::Windows::Forms::TextBox^  txtTamanno;
	private: System::Windows::Forms::Label^  requerido;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtMarca;
	private: System::Windows::Forms::TextBox^  txtNombre;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ModificarArticulo2::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->txtTamanno = (gcnew System::Windows::Forms::TextBox());
			this->requerido = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtMarca = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txtPrecio);
			this->panel1->Controls->Add(this->txtTamanno);
			this->panel1->Controls->Add(this->requerido);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtMarca);
			this->panel1->Controls->Add(this->txtNombre);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 387);
			this->panel1->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkRed;
			this->panel2->Location = System::Drawing::Point(0, 341);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(428, 45);
			this->panel2->TabIndex = 25;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(25, 226);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 18);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Precio:";
			// 
			// txtPrecio
			// 
			this->txtPrecio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPrecio->Location = System::Drawing::Point(179, 226);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->PasswordChar = '*';
			this->txtPrecio->Size = System::Drawing::Size(180, 31);
			this->txtPrecio->TabIndex = 23;
			// 
			// txtTamanno
			// 
			this->txtTamanno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTamanno->Location = System::Drawing::Point(179, 169);
			this->txtTamanno->Name = L"txtTamanno";
			this->txtTamanno->PasswordChar = '*';
			this->txtTamanno->Size = System::Drawing::Size(180, 31);
			this->txtTamanno->TabIndex = 22;
			// 
			// requerido
			// 
			this->requerido->AutoSize = true;
			this->requerido->ForeColor = System::Drawing::Color::DarkRed;
			this->requerido->Location = System::Drawing::Point(188, 260);
			this->requerido->Name = L"requerido";
			this->requerido->Size = System::Drawing::Size(160, 13);
			this->requerido->TabIndex = 20;
			this->requerido->Text = L"Todos lo campos son requeridos";
			this->requerido->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(25, 169);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 18);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Tamanno:";
			// 
			// txtMarca
			// 
			this->txtMarca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMarca->Location = System::Drawing::Point(179, 112);
			this->txtMarca->Name = L"txtMarca";
			this->txtMarca->PasswordChar = '*';
			this->txtMarca->Size = System::Drawing::Size(180, 31);
			this->txtMarca->TabIndex = 15;
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(179, 59);
			this->txtNombre->MaxLength = 15;
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(180, 31);
			this->txtNombre->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(25, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 18);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Marca:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(25, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Nombre:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(205, 294);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Modificar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ModificarArticulo2::button1_Click);
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
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(25, 14);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(146, 18);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Linea especifica:";
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(179, 14);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(180, 24);
			this->comboBox1->TabIndex = 27;
			// 
			// ModificarArticulo2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(429, 387);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"ModificarArticulo2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ModificarArticulo2";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

	private: System::Void cargarEspecificas(){
		ListaEspecifica * listaE = new ListaEspecifica();
		listaE->leerFicheroEspecificas2();
		NodoEspecifica * nodo = listaE->getCab();
		while (nodo != NULL) {
			char * codigo = nodo->getInfo()->getCodigo();
			char * nombre = nodo->getInfo()->getDescripcion();
			comboBox1->Items->Add(Utilitario::Contanenado(codigo, nombre));
			nodo = nodo->getSgte();
		}
		comboBox1->SelectedIndex = 0;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ListaArticulo *lista = new ListaArticulo();
		lista->cargarArticulos();

		char * codigoPasillo = Utilitario::getElementCode(comboBox1->SelectedItem->ToString());
		int numeroEspecifica = atoi(codigoPasillo);

		InfoArticulo *info = new InfoArticulo(numeroEspecifica, codigo, Utilitario::toChar(txtNombre->Text),
			Utilitario::toChar(txtMarca->Text), Utilitario::toChar(txtTamanno->Text),0);
		lista->modificarArticulo(info);
		Hide();
	}
};
}
