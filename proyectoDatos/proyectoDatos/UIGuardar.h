#pragma once
#include "ListaCompra.h"
#include "ListaCarrito.h"
#include "Utilitario.h"
#include "GestorCompras.h"
namespace proyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;

	/// <summary>
	/// Summary for UIGuardar
	/// </summary>
	public ref class UIGuardar : public System::Windows::Forms::Form{
		
		String ^codigoUsuario = "";
		int totalCarrito=0;
		int estado = 0;
		ListaCarrito * listaCarrito = NULL;
		ListaCompra * listaCompra = NULL;
	private: System::Windows::Forms::TextBox^  txtCod;

	private: System::Windows::Forms::Label^  label6;


	private: System::Windows::Forms::Button^  button2;
			

	public:
		UIGuardar(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	UIGuardar(String^ pcodigoUsuario, int ptotalCarrito, int pestado, 
						ListaCompra * plistaCompra, ListaCarrito *plistaCarrito){
			InitializeComponent();
			codigoUsuario = pcodigoUsuario;
			totalCarrito = ptotalCarrito;
			estado = pestado;
			listaCompra = plistaCompra;
			listaCarrito = plistaCarrito;

			if (pestado == 0) {
				comboBox1->Items->Add("Sin entregar");
			}else {
				comboBox1->Items->Add("Entregado");
			}
			comboBox1->SelectedItem = 0;
			txtCodUsuario->Text = pcodigoUsuario;
			txtMonto->Text = Utilitario::toInt32(ptotalCarrito)->ToString();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIGuardar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel2;
	protected:
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  txtCodUsuario;

	private: System::Windows::Forms::TextBox^  txtNombre;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtMonto;
	private: System::Windows::Forms::Label^  lblrequerido;





	protected:



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIGuardar::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtCod = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lblrequerido = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtMonto = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtCodUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkRed;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 349);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(434, 45);
			this->panel2->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->txtCod);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->lblrequerido);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtMonto);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtCodUsuario);
			this->panel1->Controls->Add(this->txtNombre);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(434, 349);
			this->panel1->TabIndex = 3;
			// 
			// txtCod
			// 
			this->txtCod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCod->Location = System::Drawing::Point(171, 26);
			this->txtCod->MaxLength = 15;
			this->txtCod->Name = L"txtCod";
			this->txtCod->Size = System::Drawing::Size(180, 31);
			this->txtCod->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(17, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 18);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Codigo";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(48, 282);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 39);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UIGuardar::button2_Click);
			// 
			// lblrequerido
			// 
			this->lblrequerido->AutoSize = true;
			this->lblrequerido->ForeColor = System::Drawing::Color::DarkRed;
			this->lblrequerido->Location = System::Drawing::Point(208, 115);
			this->lblrequerido->Name = L"lblrequerido";
			this->lblrequerido->Size = System::Drawing::Size(102, 13);
			this->lblrequerido->TabIndex = 20;
			this->lblrequerido->Text = L"Necesita un nombre";
			this->lblrequerido->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(17, 243);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 18);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Monto:";
			// 
			// txtMonto
			// 
			this->txtMonto->Enabled = false;
			this->txtMonto->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMonto->Location = System::Drawing::Point(171, 230);
			this->txtMonto->Name = L"txtMonto";
			this->txtMonto->Size = System::Drawing::Size(180, 31);
			this->txtMonto->TabIndex = 18;
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::White;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox1->Location = System::Drawing::Point(171, 191);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(180, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(17, 191);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 18);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Estado:";
			// 
			// txtCodUsuario
			// 
			this->txtCodUsuario->Enabled = false;
			this->txtCodUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCodUsuario->Location = System::Drawing::Point(171, 134);
			this->txtCodUsuario->Name = L"txtCodUsuario";
			this->txtCodUsuario->Size = System::Drawing::Size(180, 31);
			this->txtCodUsuario->TabIndex = 15;
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(171, 81);
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
			this->label3->Location = System::Drawing::Point(17, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 18);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Codigo Usuario:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(17, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Nombre carrito:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(232, 282);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UIGuardar::button1_Click);
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
			// UIGuardar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(434, 394);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UIGuardar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UIGuardar";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
	
	#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		char * nombreCarrito = Utilitario::toChar(txtNombre->Text);
		if (nombreCarrito == "") {
			lblrequerido->Visible = true;
		}
		else {
			char* codigo = Utilitario::toChar(txtCod->Text);
			GestorCompras * gestor = new GestorCompras();
			gestor->agregarListaCompras(listaCarrito, codigo, nombreCarrito,
						Utilitario::toChar(codigoUsuario), 0, totalCarrito, listaCompra);
			listaCompra = new ListaCompra();
			
			Close();
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}

};
}
