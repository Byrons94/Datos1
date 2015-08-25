#pragma once

#include "GestorCompras.h"
#include "GestorInventario.h"
#include "ListaCompra.h"
#include "ListaCarrito.h"
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
	/// Summary for Facturar
	/// </summary>
	public ref class Facturar : public System::Windows::Forms::Form
	{
		String ^codigoUsuario = "";
		int totalCarrito=0;
		ListaCarrito * listaCarrito = NULL;
		ListaCompra * listaCompra = NULL;
		Label^   lblTotal1;

		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::Button^  btnAgregar;
				 


	public:
		Facturar(void)
		{
			InitializeComponent();
			
		}


		Facturar(String^ usuario, int ptotalCarrito, ListaCompra * plistaCompra, ListaCarrito *plistaCarrito) {
			InitializeComponent();
		/*	codigoUsuario = usuario;
			totalCarrito = ptotalCarrito;
			
			listaCompra = plistaCompra;
			listaCarrito = plistaCarrito;*/
			//cargarFactura();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Facturar()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  lblCarrito;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  lblTotal;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblCarrito = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->btnAgregar);
			this->panel2->Controls->Add(this->lblTotal);
			this->panel2->Controls->Add(this->lblCarrito);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1164, 94);
			this->panel2->TabIndex = 8;
			// 
			// btnAgregar
			// 
			this->btnAgregar->BackColor = System::Drawing::Color::DarkRed;
			this->btnAgregar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAgregar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAgregar->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAgregar->ForeColor = System::Drawing::Color::White;
			this->btnAgregar->Location = System::Drawing::Point(1010, 3);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(154, 37);
			this->btnAgregar->TabIndex = 10;
			this->btnAgregar->Text = L"Facturar";
			this->btnAgregar->UseVisualStyleBackColor = false;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &Facturar::btnAgregar_Click);
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->BackColor = System::Drawing::Color::White;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->ForeColor = System::Drawing::Color::Maroon;
			this->lblTotal->Location = System::Drawing::Point(1021, 65);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(0, 23);
			this->lblTotal->TabIndex = 8;
			// 
			// lblCarrito
			// 
			this->lblCarrito->AutoSize = true;
			this->lblCarrito->BackColor = System::Drawing::Color::White;
			this->lblCarrito->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarrito->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblCarrito->Location = System::Drawing::Point(782, 61);
			this->lblCarrito->Name = L"lblCarrito";
			this->lblCarrito->Size = System::Drawing::Size(73, 23);
			this->lblCarrito->TabIndex = 7;
			this->lblCarrito->Text = L"Total:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(506, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Factura";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label7->Location = System::Drawing::Point(94, 65);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(92, 18);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Supermercados";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(53, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 39);
			this->label6->TabIndex = 2;
			this->label6->Text = L"CFT";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::DarkRed;
			this->panel3->Controls->Add(this->label8);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 623);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1164, 48);
			this->panel3->TabIndex = 7;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label8->Location = System::Drawing::Point(3, 28);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(135, 21);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Derechos reservados.";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Monto total";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 150;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Cantidad";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 110;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Precio";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Tamaño";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->Width = 150;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Marca";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 150;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Descripcion";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 300;
			// 
			// Column1
			// 
			this->Column1->FillWeight = 110;
			this->Column1->HeaderText = L"Codigo";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 110;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::Silver;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleVertical;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column5, this->Column3, this->Column4, this->Column6, this->Column7
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnF2;
			this->dataGridView1->GridColor = System::Drawing::Color::White;
			this->dataGridView1->Location = System::Drawing::Point(0, 94);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle9;
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::Maroon;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle10;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1164, 529);
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->TabIndex = 9;
			// 
			// Facturar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1164, 671);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->MaximizeBox = false;
			this->Name = L"Facturar";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Facturar";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	//private: System::Void cargarFactura() {
	//	ListaArticulo * listaArticulos = new ListaArticulo();
	//	listaArticulos->cargarArticulos();

	//	NodoCompra * nodo = listaCompra->getCab();
	//	double total = 0;
	//	while (nodo != NULL) {
	//		NodoArticulo * nodoArti = listaArticulos->getCab();
	//		while (nodoArti != NULL)
	//		{
	//			if (strcmp(nodoArti->getInfo()->getCodigo(), nodo->getLineaDetalle()->getProducto()) == 0) {
	//				total = total + nodo->getLineaDetalle()->getMonto();

	//				dataGridView1->Rows->Add(Utilitario::toSystemString(nodo->getLineaDetalle()->getProducto()),
	//					Utilitario::toSystemString(nodoArti->getInfo()->getNombre()),
	//					Utilitario::toSystemString(nodoArti->getInfo()->getMarca()),
	//					Utilitario::toSystemString(nodoArti->getInfo()->getTamanio()),
	//					Utilitario::toInt32(nodoArti->getInfo()->getPrecio()),
	//					Utilitario::toInt32(nodo->getLineaDetalle()->getCantidad()),
	//					Utilitario::toInt32(nodo->getLineaDetalle()->getMonto()));
	//			}
	//			nodoArti = nodoArti->getSgte();
	//		}
	//		nodo = nodo->getSgte();
	//	}
	//	lblTotal->Text = Utilitario::toInt32(total)->ToString();
	//}

	
	private: System::Void btnAgregar_Click(System::Object^  sender, System::EventArgs^  e) {
		ListaCarrito * lista = new ListaCarrito();
		GestorCompras * gestor = new GestorCompras();


		std::string s = std::to_string(5);
		char palabra[15];
		std::string palabraString;
		std::memcpy(palabra, s.c_str(), s.size() + 1);
		/*
		gestor->agregarListaCompras(listaCarrito, palabra, "Regular",
			Utilitario::toChar(codigoUsuario), 1, totalCarrito, listaCompra);*/
		Close();
	}
};
}
