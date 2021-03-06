#pragma once
#include "GestorUsuarios.h"
#include <windows.h> 
#include <string> 
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "Utilitario.h"
#include "UIPrincipal.h"

namespace proyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;

	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
	public:
		UI(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtNombre;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  txtClave;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UI::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtClave = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->txtClave);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtNombre);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(434, 331);
			this->panel1->TabIndex = 0;
			// 
			// txtClave
			// 
			this->txtClave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtClave->Location = System::Drawing::Point(140, 120);
			this->txtClave->Name = L"txtClave";
			this->txtClave->PasswordChar = '*';
			this->txtClave->Size = System::Drawing::Size(180, 31);
			this->txtClave->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::DarkRed;
			this->label4->Location = System::Drawing::Point(151, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Usuario o contrase�a inv�lidos";
			this->label4->Visible = false;
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(140, 59);
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
			this->label3->Location = System::Drawing::Point(37, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 18);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Password:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(37, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Username:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(154, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Iniciar Sesi�n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UI::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 23);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Bienvenido";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkRed;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 286);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(434, 45);
			this->panel2->TabIndex = 1;
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(434, 331);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UI";
			this->Load += gcnew System::EventHandler(this, &UI::UI_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void UI_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	GestorUsuarios * gestor = new GestorUsuarios();
	char * userName = Utilitario::toChar(txtNombre->Text);
	char * clave = Utilitario::toChar(txtClave->Text);

	int  ^b = gcnew int(gestor->iniciarSesion(userName, clave));
	if (Utilitario::toInt(b) == 0) {
		label4->Visible = true;
	}
	else {
		label4->Visible = false;
		String ^ codUser = txtNombre->Text;
		UIPrincipal ^ principal = gcnew UIPrincipal(Utilitario::toInt(b), codUser);
		Hide();
		principal->Show();
	}
}
};
}
