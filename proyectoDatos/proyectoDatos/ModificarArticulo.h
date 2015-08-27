#pragma once
#include "ModificarArticulo2.h"
#include "Utilitario.h"
#include "InfoArticulo.h"
#include "ListaArticulo.h"

namespace proyectoDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;


	/// <summary>
	/// Resumen de ModificarArticulo
	/// </summary>
	public ref class ModificarArticulo : public System::Windows::Forms::Form
	{
	public:
		ListaPasillos * lista;

		ModificarArticulo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		ModificarArticulo(ListaPasillos * plista){
			InitializeComponent();
			lista = plista;
			cargarCombo();
		}
			
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ModificarArticulo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ModificarArticulo::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(356, 206);
			this->panel1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(99, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(174, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Articulo a modificar:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(121, 143);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Modificar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ModificarArticulo::button1_Click);
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
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(91, 82);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(182, 24);
			this->comboBox1->TabIndex = 12;
			// 
			// ModificarArticulo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(356, 206);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ModificarArticulo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ModificarArticulo";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

	private: System::Void cargarCombo(){
		ListaArticulo * listaAr = new ListaArticulo();
		listaAr->cargarArticulos();
		NodoArticulo * nodo = listaAr->getCab();
		while (nodo != NULL) {
			char * codigo = nodo->getInfo()->getCodigo();
			char * nombre = nodo->getInfo()->getNombre();
			comboBox1->Items->Add(Utilitario::Contanenado(codigo, nombre));
			nodo = nodo->getSgte();
		}
		comboBox1->SelectedIndex = 0;
	}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		char * codigo = Utilitario::getElementCode(comboBox1->SelectedItem->ToString());
		ModificarArticulo2 ^modif = gcnew ModificarArticulo2(codigo);
		modif->Show();
		Hide();

	}
};
}
