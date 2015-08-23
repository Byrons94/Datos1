#pragma once
#include "GestorUsuarios.h"
#include <windows.h> 
#include <string> 
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "Utilitario.h"

namespace proyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
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

	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtClave;
	private: System::Windows::Forms::TextBox^  txtNombre;
	private: System::Windows::Forms::Label^  label4;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtClave = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(127, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Bienvenido";
			this->label1->Click += gcnew System::EventHandler(this, &UI::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(171, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 39);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Iniciar Sesión";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UI::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(4, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Username:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(4, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 18);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Password:";
			// 
			// txtClave
			// 
			this->txtClave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtClave->Location = System::Drawing::Point(107, 175);
			this->txtClave->Name = L"txtClave";
			this->txtClave->Size = System::Drawing::Size(180, 31);
			this->txtClave->TabIndex = 2;
			// 
			// txtNombre
			// 
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->Location = System::Drawing::Point(107, 109);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(180, 31);
			this->txtNombre->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(118, 211);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Usuario o contraseña inválidos";
			this->label4->Visible = false;
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 331);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtClave);
			this->Controls->Add(this->label1);
			this->Name = L"UI";
			this->Text = L"UI";
			this->Load += gcnew System::EventHandler(this, &UI::UI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UI_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		GestorUsuarios * gestor = new GestorUsuarios();
		char * userName = Utilitario::toChar(txtNombre->Text);
		char * clave	= Utilitario::toChar(txtClave->Text);

		int  ^b = gcnew int(gestor->iniciarSesion(userName, clave));
		if (Utilitario::toInt(b) == 0) {
			label4->Visible = true;
		}else{
			label4->Visible = false;
		}
	}
};
}
