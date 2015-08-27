#pragma once
#include "GestorUsuarios.h"
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
	/// Resumen de UIRegistro
	/// </summary>
	public ref class UIRegistro : public System::Windows::Forms::Form
	{
	public:
		UIRegistro(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			comboRol->Items->Add("Administrador");
			comboRol->Items->Add("Dependiente");
			comboRol->Items->Add("Cliente");
			comboRol->SelectedIndex = 2;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~UIRegistro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Label^  requerido;
	private: System::Windows::Forms::ComboBox^  comboRol;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtClave;
	private: System::Windows::Forms::TextBox^  txtNombre;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  txtCodigo;

	private: System::Windows::Forms::Label^  label6;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIRegistro::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->requerido = (gcnew System::Windows::Forms::Label());
			this->comboRol = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtClave = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->requerido);
			this->panel1->Controls->Add(this->comboRol);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtClave);
			this->panel1->Controls->Add(this->txtNombre);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(427, 355);
			this->panel1->TabIndex = 4;
			// 
			// txtCodigo
			// 
			this->txtCodigo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCodigo->Location = System::Drawing::Point(192, 32);
			this->txtCodigo->MaxLength = 15;
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(180, 31);
			this->txtCodigo->TabIndex = 28;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(38, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 18);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Codigo:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkRed;
			this->panel2->Location = System::Drawing::Point(0, 307);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(428, 45);
			this->panel2->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::DarkRed;
			this->label5->Location = System::Drawing::Point(217, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(132, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Necesita una contrasenna";
			this->label5->Visible = false;
			// 
			// requerido
			// 
			this->requerido->AutoSize = true;
			this->requerido->ForeColor = System::Drawing::Color::DarkRed;
			this->requerido->Location = System::Drawing::Point(228, 119);
			this->requerido->Name = L"requerido";
			this->requerido->Size = System::Drawing::Size(102, 13);
			this->requerido->TabIndex = 20;
			this->requerido->Text = L"Necesita un nombre";
			this->requerido->Visible = false;
			// 
			// comboRol
			// 
			this->comboRol->BackColor = System::Drawing::Color::White;
			this->comboRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboRol->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboRol->FormattingEnabled = true;
			this->comboRol->Location = System::Drawing::Point(192, 195);
			this->comboRol->Name = L"comboRol";
			this->comboRol->Size = System::Drawing::Size(180, 21);
			this->comboRol->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(38, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 18);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Rol:";
			// 
			// txtClave
			// 
			this->txtClave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtClave->Location = System::Drawing::Point(192, 138);
			this->txtClave->Name = L"txtClave";
			this->txtClave->PasswordChar = '*';
			this->txtClave->Size = System::Drawing::Size(180, 31);
			this->txtClave->TabIndex = 15;
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(192, 85);
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
			this->label3->Location = System::Drawing::Point(38, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 18);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Contrasenna:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(38, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Nombre:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(220, 231);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UIRegistro::button1_Click);
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
			// UIRegistro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 355);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UIRegistro";
			this->Text = L"UIRegistro";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		GestorUsuarios *gestor = new GestorUsuarios();
		gestor->agregarUsuario(Utilitario::toChar(txtCodigo->Text), Utilitario::toChar(txtNombre->Text), 
			Utilitario::toChar(txtClave->Text), 
			Utilitario::toInt(comboRol->SelectedIndex+1));
	}
};
}
