#pragma once
#include "GestorInventario.h"
#include "GestorCompras.h"
#include <windows.h> 
#include "stdafx.h"
#include <string> 
#include <iostream>
#include <stdio.h>
#include "Utilitario.h"
#include "UIGuardar.h"
#include "BuscarCarritos.h"
#include "UIFactura.h"
#include "UIRegistro.h"
#include "ModificarUsuario.h"
#include "ModificarArticulo.h"
#include "UIRegArticulo.h"
#include "UIPendientes.h"
#include "UIAgregarPasillo.h"

namespace proyectoDatos {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Utilitario;
	
	/// <summary>
	/// Summary for UIPrincipal
	/// </summary>
	public ref class UIPrincipal : public System::Windows::Forms::Form{
		
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::Button^  btnEliminar;
	
	ListaPasillos * lista = NULL;
	GestorCompras * gestorCompras;
	ListaCompra	  * listaCompra;
	ListaCarrito  * listaCarrito;
	String ^	    codigoUsuario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  marca;
	private: System::Windows::Forms::ToolStripMenuItem^  inventarioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasillosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  agregarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  modificarToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  lGeneralesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  agregarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  modificarToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  lEspecificasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  agregarToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  modificarToolStripMenuItem4;
			 int totalCarrito = 0;
	public:
		UIPrincipal(){
			InitializeComponent();
		}

		UIPrincipal(int idRol, String ^ codUser){
			InitializeComponent();
			validarPermisos(idRol);
			cargarCombos();
			gestorCompras = new GestorCompras();
			listaCompra = new ListaCompra();
			listaCarrito = new ListaCarrito();
			codigoUsuario = codUser;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  articulosToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  usuariosToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolStripMenuItem^  comprasToolStripMenuItem;
	private: System::Windows::Forms::Splitter^  splitter2;
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Label^  lblTotal;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnVaciar;


	private: System::Windows::Forms::Button^  btnFacturar;
	private: System::Windows::Forms::Button^  btnGuardar;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Splitter^  splitter3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ToolStripMenuItem^  registrarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  modificarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  registrarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  modificarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  pendientesEntregaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  entregadasToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  lblProducto;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  btnAgregar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::DataGridView^  dataGridView2;


	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIPrincipal::typeid));
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->panel6 = (gcnew System::Windows::Forms::Panel());
				this->label9 = (gcnew System::Windows::Forms::Label());
				this->lblProducto = (gcnew System::Windows::Forms::Label());
				this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
				this->btnAgregar = (gcnew System::Windows::Forms::Button());
				this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
				this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->splitter2 = (gcnew System::Windows::Forms::Splitter());
				this->splitter1 = (gcnew System::Windows::Forms::Splitter());
				this->panel5 = (gcnew System::Windows::Forms::Panel());
				this->btnEliminar = (gcnew System::Windows::Forms::Button());
				this->splitter3 = (gcnew System::Windows::Forms::Splitter());
				this->lblTotal = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->panel9 = (gcnew System::Windows::Forms::Panel());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->panel10 = (gcnew System::Windows::Forms::Panel());
				this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
				this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->marca = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->panel8 = (gcnew System::Windows::Forms::Panel());
				this->btnGuardar = (gcnew System::Windows::Forms::Button());
				this->btnVaciar = (gcnew System::Windows::Forms::Button());
				this->btnFacturar = (gcnew System::Windows::Forms::Button());
				this->panel7 = (gcnew System::Windows::Forms::Panel());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->panel4 = (gcnew System::Windows::Forms::Panel());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
				this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
				this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				this->panel3 = (gcnew System::Windows::Forms::Panel());
				this->label8 = (gcnew System::Windows::Forms::Label());
				this->panel2 = (gcnew System::Windows::Forms::Panel());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->articulosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->registrarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->modificarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->usuariosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->registrarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->modificarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->comprasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->pendientesEntregaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->entregadasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->inventarioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->pasillosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
				this->lGeneralesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->lEspecificasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->agregarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->modificarToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->agregarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->modificarToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->agregarToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->modificarToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->panel1->SuspendLayout();
				this->panel6->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
				this->panel5->SuspendLayout();
				this->panel9->SuspendLayout();
				this->panel10->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
				this->panel8->SuspendLayout();
				this->panel4->SuspendLayout();
				this->panel3->SuspendLayout();
				this->panel2->SuspendLayout();
				this->menuStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// panel1
				// 
				this->panel1->BackColor = System::Drawing::Color::White;
				this->panel1->Controls->Add(this->panel6);
				this->panel1->Controls->Add(this->panel5);
				this->panel1->Controls->Add(this->panel4);
				this->panel1->Controls->Add(this->panel3);
				this->panel1->Controls->Add(this->panel2);
				this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
				this->panel1->Location = System::Drawing::Point(0, 0);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(1164, 671);
				this->panel1->TabIndex = 0;
				// 
				// panel6
				// 
				this->panel6->AutoScroll = true;
				this->panel6->Controls->Add(this->label9);
				this->panel6->Controls->Add(this->lblProducto);
				this->panel6->Controls->Add(this->numericUpDown1);
				this->panel6->Controls->Add(this->btnAgregar);
				this->panel6->Controls->Add(this->dataGridView1);
				this->panel6->Controls->Add(this->splitter2);
				this->panel6->Controls->Add(this->splitter1);
				this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
				this->panel6->Location = System::Drawing::Point(187, 94);
				this->panel6->Name = L"panel6";
				this->panel6->Size = System::Drawing::Size(698, 529);
				this->panel6->TabIndex = 5;
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->BackColor = System::Drawing::Color::White;
				this->label9->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label9->Location = System::Drawing::Point(360, 20);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(70, 14);
				this->label9->TabIndex = 7;
				this->label9->Text = L"Cantidad:";
				// 
				// lblProducto
				// 
				this->lblProducto->AutoSize = true;
				this->lblProducto->BackColor = System::Drawing::Color::White;
				this->lblProducto->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->lblProducto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->lblProducto->Location = System::Drawing::Point(16, 14);
				this->lblProducto->Name = L"lblProducto";
				this->lblProducto->Size = System::Drawing::Size(0, 23);
				this->lblProducto->TabIndex = 7;
				// 
				// numericUpDown1
				// 
				this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->numericUpDown1->Location = System::Drawing::Point(435, 14);
				this->numericUpDown1->Name = L"numericUpDown1";
				this->numericUpDown1->Size = System::Drawing::Size(120, 23);
				this->numericUpDown1->TabIndex = 5;
				this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				// 
				// btnAgregar
				// 
				this->btnAgregar->BackColor = System::Drawing::Color::DarkRed;
				this->btnAgregar->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnAgregar->Enabled = false;
				this->btnAgregar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->btnAgregar->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnAgregar->ForeColor = System::Drawing::Color::White;
				this->btnAgregar->Location = System::Drawing::Point(561, 3);
				this->btnAgregar->Name = L"btnAgregar";
				this->btnAgregar->Size = System::Drawing::Size(121, 34);
				this->btnAgregar->TabIndex = 4;
				this->btnAgregar->Text = L"Agregar";
				this->btnAgregar->UseVisualStyleBackColor = false;
				this->btnAgregar->Click += gcnew System::EventHandler(this, &UIPrincipal::btnAgregar_Click);
				// 
				// dataGridView1
				// 
				this->dataGridView1->AllowUserToAddRows = false;
				this->dataGridView1->AllowUserToDeleteRows = false;
				this->dataGridView1->AllowUserToResizeColumns = false;
				this->dataGridView1->AllowUserToResizeRows = false;
				dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Silver;
				this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
				this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
				this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleVertical;
				this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
				dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
				dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
				dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
				this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
				this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
					this->Column1,
						this->Column2, this->Column5, this->Column3, this->Column4
				});
				this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Hand;
				dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
				dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
				dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
				this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
				this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnF2;
				this->dataGridView1->GridColor = System::Drawing::Color::White;
				this->dataGridView1->Location = System::Drawing::Point(10, 50);
				this->dataGridView1->MultiSelect = false;
				this->dataGridView1->Name = L"dataGridView1";
				this->dataGridView1->ReadOnly = true;
				dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
				dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
				dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::Gainsboro;
				dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
				dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Black;
				dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::White;
				dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::Maroon;
				this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle5;
				this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
				this->dataGridView1->Size = System::Drawing::Size(678, 479);
				this->dataGridView1->StandardTab = true;
				this->dataGridView1->TabIndex = 2;
				this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIPrincipal::dataGridView1_CellContentClick);
				// 
				// Column1
				// 
				this->Column1->HeaderText = L"Codigo";
				this->Column1->Name = L"Column1";
				this->Column1->ReadOnly = true;
				this->Column1->Width = 90;
				// 
				// Column2
				// 
				this->Column2->HeaderText = L"Descripcion";
				this->Column2->Name = L"Column2";
				this->Column2->ReadOnly = true;
				this->Column2->Width = 215;
				// 
				// Column5
				// 
				this->Column5->HeaderText = L"Marca";
				this->Column5->Name = L"Column5";
				this->Column5->ReadOnly = true;
				this->Column5->Width = 130;
				// 
				// Column3
				// 
				this->Column3->HeaderText = L"Tamaño";
				this->Column3->Name = L"Column3";
				this->Column3->ReadOnly = true;
				this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				// 
				// Column4
				// 
				this->Column4->HeaderText = L"Precio";
				this->Column4->Name = L"Column4";
				this->Column4->ReadOnly = true;
				// 
				// splitter2
				// 
				this->splitter2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
					static_cast<System::Int32>(static_cast<System::Byte>(235)));
				this->splitter2->Cursor = System::Windows::Forms::Cursors::Arrow;
				this->splitter2->Dock = System::Windows::Forms::DockStyle::Right;
				this->splitter2->Location = System::Drawing::Point(688, 0);
				this->splitter2->Name = L"splitter2";
				this->splitter2->Size = System::Drawing::Size(10, 529);
				this->splitter2->TabIndex = 1;
				this->splitter2->TabStop = false;
				// 
				// splitter1
				// 
				this->splitter1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
					static_cast<System::Int32>(static_cast<System::Byte>(235)));
				this->splitter1->Cursor = System::Windows::Forms::Cursors::Arrow;
				this->splitter1->Location = System::Drawing::Point(0, 0);
				this->splitter1->Name = L"splitter1";
				this->splitter1->Size = System::Drawing::Size(10, 529);
				this->splitter1->TabIndex = 0;
				this->splitter1->TabStop = false;
				// 
				// panel5
				// 
				this->panel5->AutoScroll = true;
				this->panel5->Controls->Add(this->btnEliminar);
				this->panel5->Controls->Add(this->splitter3);
				this->panel5->Controls->Add(this->lblTotal);
				this->panel5->Controls->Add(this->label5);
				this->panel5->Controls->Add(this->panel9);
				this->panel5->Controls->Add(this->panel8);
				this->panel5->Controls->Add(this->panel7);
				this->panel5->Controls->Add(this->label4);
				this->panel5->Dock = System::Windows::Forms::DockStyle::Right;
				this->panel5->Location = System::Drawing::Point(885, 94);
				this->panel5->Name = L"panel5";
				this->panel5->Size = System::Drawing::Size(279, 529);
				this->panel5->TabIndex = 4;
				// 
				// btnEliminar
				// 
				this->btnEliminar->BackColor = System::Drawing::Color::DarkRed;
				this->btnEliminar->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnEliminar->Enabled = false;
				this->btnEliminar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnEliminar->ForeColor = System::Drawing::Color::White;
				this->btnEliminar->Location = System::Drawing::Point(3, 53);
				this->btnEliminar->Name = L"btnEliminar";
				this->btnEliminar->Size = System::Drawing::Size(78, 28);
				this->btnEliminar->TabIndex = 7;
				this->btnEliminar->Text = L"Eliminar";
				this->btnEliminar->UseVisualStyleBackColor = false;
				this->btnEliminar->Click += gcnew System::EventHandler(this, &UIPrincipal::btnEliminar_Click);
				// 
				// splitter3
				// 
				this->splitter3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
					static_cast<System::Int32>(static_cast<System::Byte>(235)));
				this->splitter3->Cursor = System::Windows::Forms::Cursors::Arrow;
				this->splitter3->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->splitter3->Location = System::Drawing::Point(0, 82);
				this->splitter3->Name = L"splitter3";
				this->splitter3->Size = System::Drawing::Size(279, 10);
				this->splitter3->TabIndex = 6;
				this->splitter3->TabStop = false;
				// 
				// lblTotal
				// 
				this->lblTotal->AutoSize = true;
				this->lblTotal->BackColor = System::Drawing::Color::White;
				this->lblTotal->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->lblTotal->ForeColor = System::Drawing::Color::Maroon;
				this->lblTotal->Location = System::Drawing::Point(195, 49);
				this->lblTotal->Name = L"lblTotal";
				this->lblTotal->Size = System::Drawing::Size(46, 18);
				this->lblTotal->TabIndex = 5;
				this->lblTotal->Text = L"0.00";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->BackColor = System::Drawing::Color::White;
				this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label5->Location = System::Drawing::Point(134, 49);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(55, 18);
				this->label5->TabIndex = 4;
				this->label5->Text = L"Total:";
				// 
				// panel9
				// 
				this->panel9->AutoScroll = true;
				this->panel9->Controls->Add(this->button2);
				this->panel9->Controls->Add(this->panel10);
				this->panel9->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->panel9->Location = System::Drawing::Point(0, 92);
				this->panel9->Name = L"panel9";
				this->panel9->Size = System::Drawing::Size(279, 404);
				this->panel9->TabIndex = 3;
				// 
				// button2
				// 
				this->button2->BackColor = System::Drawing::Color::DarkRed;
				this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
				this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button2->ForeColor = System::Drawing::Color::White;
				this->button2->Location = System::Drawing::Point(0, 0);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(279, 28);
				this->button2->TabIndex = 8;
				this->button2->Text = L"Mis carritos";
				this->button2->UseVisualStyleBackColor = false;
				this->button2->Click += gcnew System::EventHandler(this, &UIPrincipal::button2_Click);
				// 
				// panel10
				// 
				this->panel10->Controls->Add(this->dataGridView2);
				this->panel10->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->panel10->Location = System::Drawing::Point(0, 28);
				this->panel10->Name = L"panel10";
				this->panel10->Size = System::Drawing::Size(279, 376);
				this->panel10->TabIndex = 0;
				// 
				// dataGridView2
				// 
				this->dataGridView2->AllowUserToAddRows = false;
				this->dataGridView2->AllowUserToDeleteRows = false;
				this->dataGridView2->BackgroundColor = System::Drawing::Color::White;
				dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
				dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Maroon;
				dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::White;
				dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
				this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
					this->Column6,
						this->Column7, this->Column8, this->Column9, this->nombre, this->marca
				});
				dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Window;
				dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
				dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::White;
				dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::Maroon;
				dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
				this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle7;
				this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
				this->dataGridView2->GridColor = System::Drawing::Color::White;
				this->dataGridView2->Location = System::Drawing::Point(0, 0);
				this->dataGridView2->MultiSelect = false;
				this->dataGridView2->Name = L"dataGridView2";
				this->dataGridView2->ReadOnly = true;
				this->dataGridView2->RightToLeft = System::Windows::Forms::RightToLeft::No;
				dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
				dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				dataGridViewCellStyle8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
				this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle8;
				this->dataGridView2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
				this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
				this->dataGridView2->Size = System::Drawing::Size(279, 376);
				this->dataGridView2->TabIndex = 0;
				this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIPrincipal::dataGridView2_CellContentClick);
				// 
				// Column6
				// 
				this->Column6->HeaderText = L"Cod";
				this->Column6->Name = L"Column6";
				this->Column6->ReadOnly = true;
				this->Column6->Width = 35;
				// 
				// Column7
				// 
				this->Column7->HeaderText = L"Nombre";
				this->Column7->Name = L"Column7";
				this->Column7->ReadOnly = true;
				this->Column7->Width = 90;
				// 
				// Column8
				// 
				this->Column8->HeaderText = L"Cant";
				this->Column8->Name = L"Column8";
				this->Column8->ReadOnly = true;
				this->Column8->Width = 40;
				// 
				// Column9
				// 
				this->Column9->HeaderText = L"Precio";
				this->Column9->Name = L"Column9";
				this->Column9->ReadOnly = true;
				this->Column9->Width = 70;
				// 
				// nombre
				// 
				this->nombre->HeaderText = L"Column10";
				this->nombre->Name = L"nombre";
				this->nombre->ReadOnly = true;
				this->nombre->Visible = false;
				// 
				// marca
				// 
				this->marca->HeaderText = L"Column10";
				this->marca->Name = L"marca";
				this->marca->ReadOnly = true;
				this->marca->Visible = false;
				// 
				// panel8
				// 
				this->panel8->Controls->Add(this->btnGuardar);
				this->panel8->Controls->Add(this->btnVaciar);
				this->panel8->Controls->Add(this->btnFacturar);
				this->panel8->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->panel8->Location = System::Drawing::Point(0, 496);
				this->panel8->Name = L"panel8";
				this->panel8->Size = System::Drawing::Size(279, 33);
				this->panel8->TabIndex = 2;
				// 
				// btnGuardar
				// 
				this->btnGuardar->AutoEllipsis = true;
				this->btnGuardar->BackColor = System::Drawing::Color::White;
				this->btnGuardar->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnGuardar->Dock = System::Windows::Forms::DockStyle::Fill;
				this->btnGuardar->Enabled = false;
				this->btnGuardar->FlatAppearance->BorderColor = System::Drawing::Color::Red;
				this->btnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::System;
				this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnGuardar->ForeColor = System::Drawing::Color::Black;
				this->btnGuardar->Location = System::Drawing::Point(99, 0);
				this->btnGuardar->Name = L"btnGuardar";
				this->btnGuardar->Size = System::Drawing::Size(93, 33);
				this->btnGuardar->TabIndex = 3;
				this->btnGuardar->Text = L"Guardar";
				this->btnGuardar->UseVisualStyleBackColor = false;
				this->btnGuardar->Click += gcnew System::EventHandler(this, &UIPrincipal::button3_Click);
				// 
				// btnVaciar
				// 
				this->btnVaciar->AutoEllipsis = true;
				this->btnVaciar->BackColor = System::Drawing::Color::White;
				this->btnVaciar->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnVaciar->Dock = System::Windows::Forms::DockStyle::Right;
				this->btnVaciar->FlatAppearance->BorderColor = System::Drawing::Color::Red;
				this->btnVaciar->FlatStyle = System::Windows::Forms::FlatStyle::System;
				this->btnVaciar->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnVaciar->ForeColor = System::Drawing::Color::Black;
				this->btnVaciar->Location = System::Drawing::Point(192, 0);
				this->btnVaciar->Name = L"btnVaciar";
				this->btnVaciar->Size = System::Drawing::Size(87, 33);
				this->btnVaciar->TabIndex = 2;
				this->btnVaciar->Text = L"Vaciar";
				this->btnVaciar->UseVisualStyleBackColor = false;
				this->btnVaciar->Click += gcnew System::EventHandler(this, &UIPrincipal::btnPagar_Click);
				// 
				// btnFacturar
				// 
				this->btnFacturar->AutoSize = true;
				this->btnFacturar->BackColor = System::Drawing::Color::White;
				this->btnFacturar->Cursor = System::Windows::Forms::Cursors::Hand;
				this->btnFacturar->Dock = System::Windows::Forms::DockStyle::Left;
				this->btnFacturar->Enabled = false;
				this->btnFacturar->FlatAppearance->BorderColor = System::Drawing::Color::White;
				this->btnFacturar->FlatStyle = System::Windows::Forms::FlatStyle::System;
				this->btnFacturar->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnFacturar->ForeColor = System::Drawing::Color::Black;
				this->btnFacturar->Location = System::Drawing::Point(0, 0);
				this->btnFacturar->Name = L"btnFacturar";
				this->btnFacturar->Size = System::Drawing::Size(99, 33);
				this->btnFacturar->TabIndex = 0;
				this->btnFacturar->Text = L"Facturar";
				this->btnFacturar->UseVisualStyleBackColor = false;
				this->btnFacturar->Click += gcnew System::EventHandler(this, &UIPrincipal::btnFacturar_Click);
				// 
				// panel7
				// 
				this->panel7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel7.BackgroundImage")));
				this->panel7->Location = System::Drawing::Point(26, 5);
				this->panel7->Name = L"panel7";
				this->panel7->Size = System::Drawing::Size(32, 26);
				this->panel7->TabIndex = 1;
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->BackColor = System::Drawing::Color::White;
				this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label4->Location = System::Drawing::Point(63, 10);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(113, 23);
				this->label4->TabIndex = 0;
				this->label4->Text = L"Mi carrito";
				// 
				// panel4
				// 
				this->panel4->BackColor = System::Drawing::Color::White;
				this->panel4->Controls->Add(this->label3);
				this->panel4->Controls->Add(this->label2);
				this->panel4->Controls->Add(this->label1);
				this->panel4->Controls->Add(this->comboBox3);
				this->panel4->Controls->Add(this->comboBox2);
				this->panel4->Controls->Add(this->comboBox1);
				this->panel4->Dock = System::Windows::Forms::DockStyle::Left;
				this->panel4->Location = System::Drawing::Point(0, 94);
				this->panel4->Name = L"panel4";
				this->panel4->Size = System::Drawing::Size(187, 529);
				this->panel4->TabIndex = 2;
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label3->Location = System::Drawing::Point(12, 183);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(164, 18);
				this->label3->TabIndex = 5;
				this->label3->Text = L"Lineas Específicas";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label2->Location = System::Drawing::Point(16, 98);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(158, 18);
				this->label2->TabIndex = 4;
				this->label2->Text = L"Lineas Generales";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label1->Location = System::Drawing::Point(98, 19);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(72, 18);
				this->label1->TabIndex = 3;
				this->label1->Text = L"Pasillos";
				// 
				// comboBox3
				// 
				this->comboBox3->Cursor = System::Windows::Forms::Cursors::Hand;
				this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->comboBox3->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->comboBox3->FormattingEnabled = true;
				this->comboBox3->Location = System::Drawing::Point(7, 204);
				this->comboBox3->Name = L"comboBox3";
				this->comboBox3->Size = System::Drawing::Size(171, 24);
				this->comboBox3->TabIndex = 2;
				this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &UIPrincipal::comboBox3_SelectedIndexChanged);
				// 
				// comboBox2
				// 
				this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
				this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->comboBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->comboBox2->FormattingEnabled = true;
				this->comboBox2->Location = System::Drawing::Point(7, 119);
				this->comboBox2->Name = L"comboBox2";
				this->comboBox2->Size = System::Drawing::Size(172, 24);
				this->comboBox2->TabIndex = 1;
				this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &UIPrincipal::comboBox2_SelectedIndexChanged);
				// 
				// comboBox1
				// 
				this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
				this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->comboBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->comboBox1->FormattingEnabled = true;
				this->comboBox1->Location = System::Drawing::Point(7, 40);
				this->comboBox1->Name = L"comboBox1";
				this->comboBox1->Size = System::Drawing::Size(172, 24);
				this->comboBox1->TabIndex = 0;
				this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &UIPrincipal::comboBox1_SelectedIndexChanged);
				// 
				// panel3
				// 
				this->panel3->BackColor = System::Drawing::Color::DarkRed;
				this->panel3->Controls->Add(this->label8);
				this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->panel3->Location = System::Drawing::Point(0, 623);
				this->panel3->Name = L"panel3";
				this->panel3->Size = System::Drawing::Size(1164, 48);
				this->panel3->TabIndex = 3;
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
				// panel2
				// 
				this->panel2->BackColor = System::Drawing::Color::White;
				this->panel2->Controls->Add(this->label7);
				this->panel2->Controls->Add(this->label6);
				this->panel2->Controls->Add(this->button1);
				this->panel2->Controls->Add(this->menuStrip1);
				this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
				this->panel2->Location = System::Drawing::Point(0, 0);
				this->panel2->Name = L"panel2";
				this->panel2->Size = System::Drawing::Size(1164, 94);
				this->panel2->TabIndex = 0;
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
				// button1
				// 
				this->button1->BackColor = System::Drawing::Color::White;
				this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
				this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->button1->Location = System::Drawing::Point(1078, 10);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(75, 28);
				this->button1->TabIndex = 1;
				this->button1->Text = L"Salir";
				this->button1->UseVisualStyleBackColor = false;
				this->button1->Click += gcnew System::EventHandler(this, &UIPrincipal::button1_Click);
				// 
				// menuStrip1
				// 
				this->menuStrip1->BackColor = System::Drawing::Color::White;
				this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
				this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					this->articulosToolStripMenuItem,
						this->usuariosToolStripMenuItem, this->comprasToolStripMenuItem, this->inventarioToolStripMenuItem
				});
				this->menuStrip1->Location = System::Drawing::Point(197, 65);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->Size = System::Drawing::Size(481, 26);
				this->menuStrip1->TabIndex = 0;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// articulosToolStripMenuItem
				// 
				this->articulosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->registrarToolStripMenuItem,
						this->modificarToolStripMenuItem
				});
				this->articulosToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->articulosToolStripMenuItem->Name = L"articulosToolStripMenuItem";
				this->articulosToolStripMenuItem->Size = System::Drawing::Size(91, 22);
				this->articulosToolStripMenuItem->Text = L"Articulos";
				// 
				// registrarToolStripMenuItem
				// 
				this->registrarToolStripMenuItem->Name = L"registrarToolStripMenuItem";
				this->registrarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				this->registrarToolStripMenuItem->Text = L"Registrar";
				this->registrarToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIPrincipal::registrarToolStripMenuItem_Click);
				// 
				// modificarToolStripMenuItem
				// 
				this->modificarToolStripMenuItem->Name = L"modificarToolStripMenuItem";
				this->modificarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				this->modificarToolStripMenuItem->Text = L"Modificar";
				this->modificarToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIPrincipal::modificarToolStripMenuItem_Click);
				// 
				// usuariosToolStripMenuItem
				// 
				this->usuariosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->registrarToolStripMenuItem1,
						this->modificarToolStripMenuItem1
				});
				this->usuariosToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->usuariosToolStripMenuItem->Name = L"usuariosToolStripMenuItem";
				this->usuariosToolStripMenuItem->Size = System::Drawing::Size(91, 22);
				this->usuariosToolStripMenuItem->Text = L"Usuarios";
				// 
				// registrarToolStripMenuItem1
				// 
				this->registrarToolStripMenuItem1->Name = L"registrarToolStripMenuItem1";
				this->registrarToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
				this->registrarToolStripMenuItem1->Text = L"Registrar";
				this->registrarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &UIPrincipal::registrarToolStripMenuItem1_Click);
				// 
				// modificarToolStripMenuItem1
				// 
				this->modificarToolStripMenuItem1->Name = L"modificarToolStripMenuItem1";
				this->modificarToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
				this->modificarToolStripMenuItem1->Text = L"Modificar";
				this->modificarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &UIPrincipal::modificarToolStripMenuItem1_Click);
				// 
				// comprasToolStripMenuItem
				// 
				this->comprasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->pendientesEntregaToolStripMenuItem,
						this->entregadasToolStripMenuItem
				});
				this->comprasToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
					static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->comprasToolStripMenuItem->Name = L"comprasToolStripMenuItem";
				this->comprasToolStripMenuItem->Size = System::Drawing::Size(93, 22);
				this->comprasToolStripMenuItem->Text = L"Compras";
				// 
				// pendientesEntregaToolStripMenuItem
				// 
				this->pendientesEntregaToolStripMenuItem->Name = L"pendientesEntregaToolStripMenuItem";
				this->pendientesEntregaToolStripMenuItem->Size = System::Drawing::Size(169, 22);
				this->pendientesEntregaToolStripMenuItem->Text = L"Pendientes";
				this->pendientesEntregaToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIPrincipal::pendientesEntregaToolStripMenuItem_Click);
				// 
				// entregadasToolStripMenuItem
				// 
				this->entregadasToolStripMenuItem->Name = L"entregadasToolStripMenuItem";
				this->entregadasToolStripMenuItem->Size = System::Drawing::Size(169, 22);
				this->entregadasToolStripMenuItem->Text = L"Entregadas";
				// 
				// inventarioToolStripMenuItem
				// 
				this->inventarioToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					this->pasillosToolStripMenuItem,
						this->lGeneralesToolStripMenuItem, this->lEspecificasToolStripMenuItem
				});
				this->inventarioToolStripMenuItem->Name = L"inventarioToolStripMenuItem";
				this->inventarioToolStripMenuItem->Size = System::Drawing::Size(106, 22);
				this->inventarioToolStripMenuItem->Text = L"Inventario";
				// 
				// pasillosToolStripMenuItem
				// 
				this->pasillosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->agregarToolStripMenuItem,
						this->modificarToolStripMenuItem2
				});
				this->pasillosToolStripMenuItem->Name = L"pasillosToolStripMenuItem";
				this->pasillosToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->pasillosToolStripMenuItem->Text = L"Pasillos";
				// 
				// contextMenuStrip1
				// 
				this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
				this->contextMenuStrip1->Name = L"contextMenuStrip1";
				this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
				// 
				// lGeneralesToolStripMenuItem
				// 
				this->lGeneralesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->agregarToolStripMenuItem1,
						this->modificarToolStripMenuItem3
				});
				this->lGeneralesToolStripMenuItem->Name = L"lGeneralesToolStripMenuItem";
				this->lGeneralesToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->lGeneralesToolStripMenuItem->Text = L"L. Generales";
				// 
				// lEspecificasToolStripMenuItem
				// 
				this->lEspecificasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->agregarToolStripMenuItem2,
						this->modificarToolStripMenuItem4
				});
				this->lEspecificasToolStripMenuItem->Name = L"lEspecificasToolStripMenuItem";
				this->lEspecificasToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->lEspecificasToolStripMenuItem->Text = L"L Especificas";
				// 
				// agregarToolStripMenuItem
				// 
				this->agregarToolStripMenuItem->Name = L"agregarToolStripMenuItem";
				this->agregarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				this->agregarToolStripMenuItem->Text = L"Agregar";
				this->agregarToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIPrincipal::agregarToolStripMenuItem_Click);
				// 
				// modificarToolStripMenuItem2
				// 
				this->modificarToolStripMenuItem2->Name = L"modificarToolStripMenuItem2";
				this->modificarToolStripMenuItem2->Size = System::Drawing::Size(152, 22);
				this->modificarToolStripMenuItem2->Text = L"Modificar";
				// 
				// agregarToolStripMenuItem1
				// 
				this->agregarToolStripMenuItem1->Name = L"agregarToolStripMenuItem1";
				this->agregarToolStripMenuItem1->Size = System::Drawing::Size(152, 22);
				this->agregarToolStripMenuItem1->Text = L"Agregar";
				// 
				// modificarToolStripMenuItem3
				// 
				this->modificarToolStripMenuItem3->Name = L"modificarToolStripMenuItem3";
				this->modificarToolStripMenuItem3->Size = System::Drawing::Size(152, 22);
				this->modificarToolStripMenuItem3->Text = L"Modificar";
				// 
				// agregarToolStripMenuItem2
				// 
				this->agregarToolStripMenuItem2->Name = L"agregarToolStripMenuItem2";
				this->agregarToolStripMenuItem2->Size = System::Drawing::Size(152, 22);
				this->agregarToolStripMenuItem2->Text = L"Agregar";
				// 
				// modificarToolStripMenuItem4
				// 
				this->modificarToolStripMenuItem4->Name = L"modificarToolStripMenuItem4";
				this->modificarToolStripMenuItem4->Size = System::Drawing::Size(152, 22);
				this->modificarToolStripMenuItem4->Text = L"Modificar";
				// 
				// UIPrincipal
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::White;
				this->ClientSize = System::Drawing::Size(1164, 671);
				this->Controls->Add(this->panel1);
				this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				this->MaximizeBox = false;
				this->Name = L"UIPrincipal";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"UIPrincipal";
				this->panel1->ResumeLayout(false);
				this->panel6->ResumeLayout(false);
				this->panel6->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
				this->panel5->ResumeLayout(false);
				this->panel5->PerformLayout();
				this->panel9->ResumeLayout(false);
				this->panel10->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
				this->panel8->ResumeLayout(false);
				this->panel8->PerformLayout();
				this->panel4->ResumeLayout(false);
				this->panel4->PerformLayout();
				this->panel3->ResumeLayout(false);
				this->panel3->PerformLayout();
				this->panel2->ResumeLayout(false);
				this->panel2->PerformLayout();
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	

	private: System::Void validarPermisos(int idRol){
		if (idRol == 3) {
			menuStrip1->Visible = false;
		}
		if (idRol == 2) {
			articulosToolStripMenuItem->Visible = false;
			usuariosToolStripMenuItem->Visible = false;
			inventarioToolStripMenuItem->Visible = false;
		}
	}

	private: System::Void cargarCombos(){
		GestorInventario * gestor = new GestorInventario();
		if (lista == NULL) {
			lista = new ListaPasillos();
			lista->cargarPasillos();
		}
		cargarPasillos(lista);
	}

	private: System::Void cargarPasillos(ListaPasillos * lista){
		NodoPasillo * nodo = lista->getCab();

		while (nodo!=NULL){
			char * nombre = nodo->getInfoPasillo()->getDescripcion();
			char * codigo = nodo->getInfoPasillo()->getCodigo();
		
			comboBox1->Items->Add(Utilitario::Contanenado(codigo, nombre));
			nodo = nodo->getSgte();
		}
		comboBox1->SelectedIndex = 0;
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int index = comboBox1->SelectedIndex;	
		cargarLineassGenerales(index);
	}

	private: System::Void cargarLineassGenerales(int index){
		comboBox2->Items->Clear();
		int contador = 0;
		NodoPasillo * nodo = lista->getCab();
		while (nodo != NULL) {
			if (contador == index) {
				NodoGenerales * nodosG = nodo->getInfoPasillo()->getListaGeneral()->getCab();
				while (nodosG != NULL) {
					char* codigo = nodosG->getInfo()->getCodigo();
					char* nombre = nodosG->getInfo()->getDescripcion();
					comboBox2->Items->Add(Utilitario::Contanenado(codigo, nombre));
					nodosG = nodosG->getSgte();
				}
			}
			nodo = nodo->getSgte();
			++contador;
		}
		//comboBox2->SelectedIndex = 0;
	}
	
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int index = comboBox2->SelectedIndex;
		cargarLineasEspecificas(index);
	}
	
	private: System::Void cargarLineasEspecificas(int index) {
		comboBox3->Items->Clear();
		int contador = 0;
		int indexPasillo = comboBox1->SelectedIndex;
		int contadorG = 0;

		NodoPasillo * nodo = lista->getCab();
		while (nodo != NULL) {
			if (contador == indexPasillo) {
				NodoGenerales * nodosG = nodo->getInfoPasillo()->getListaGeneral()->getCab();
				while (nodosG != NULL) {
					if (contadorG == index) {
						NodoEspecifica * nodoE = nodosG->getInfo()->getListaEspecifica()->getCab();
						while (nodoE!=NULL){
							char* codigo = nodoE->getInfo()->getCodigo();
							char* nombre = nodoE->getInfo()->getDescripcion();
							comboBox3->Items->Add(Utilitario::Contanenado(codigo, nombre));
							nodoE = nodoE->getSgte();
						}
					}
					nodosG = nodosG->getSgte();
					++contadorG;
				}
			}
			nodo = nodo->getSgte();
			++contador;
		}
		comboBox3->SelectedIndex = 0;
	}

	private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int index = comboBox3->SelectedIndex;
		cargarProductos(index);
	}
	
	private: System::Void cargarProductos(int index){
		dataGridView1->Rows->Clear();
		int contador = 0;
		int indexPasillo = comboBox1->SelectedIndex;
		int contadorG = 0;
		int indexEspeficica = comboBox2->SelectedIndex;
		int contadorE = 0;
		NodoPasillo * nodo = lista->getCab();
		while (nodo != NULL) {

			if (contador == indexPasillo) {
				NodoGenerales * nodosG = nodo->getInfoPasillo()->getListaGeneral()->getCab();
				
				while (nodosG != NULL) {
					if (contadorG == indexEspeficica) {
						NodoEspecifica * nodoE = nodosG->getInfo()->getListaEspecifica()->getCab();
				
						while (nodoE != NULL) {
							NodoArticulo *nodoA = nodoE->getInfo()->getListaArticulos()->getCab();
							if (contadorE == index) {
								while (nodoA != NULL){
									dataGridView1->Rows->Add(
												Utilitario::toSystemString(nodoA->getInfo()->getCodigo()),
												Utilitario::toSystemString(nodoA->getInfo()->getNombre()),
												Utilitario::toSystemString(nodoA->getInfo()->getMarca()),
												Utilitario::toSystemString(nodoA->getInfo()->getTamanio()),
												gcnew System::Double(nodoA->getInfo()->getPrecio())
											);
									nodoA = nodoA->getSgte();
								}
							}
							nodoE = nodoE->getSgte();
							++contadorE;
						}
					}

					nodosG = nodosG->getSgte();
					++contadorG;
				}
			}
			nodo = nodo->getSgte();
			++contador;
		}
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		cargarContenidoRow();
	}

	private: System::Void cargarContenidoRow(){
		int fila = dataGridView1->CurrentCell->RowIndex;
		lblProducto->Text = dataGridView1->Rows[fila]->Cells[1]->Value->ToString();
		btnAgregar->Enabled = true;
	}

	private: System::Void btnAgregar_Click(System::Object^  sender, System::EventArgs^  e) {

		char * pasillo    = Utilitario::getElementCode(comboBox1->SelectedItem->ToString());
		char * general    = Utilitario::getElementCode(comboBox2->SelectedItem->ToString());
		char * especifica =	Utilitario::getElementCode(comboBox3->SelectedItem->ToString());
		int fila = dataGridView1->CurrentCell->RowIndex;
		String^ cod = gcnew System::String(dataGridView1->Rows[fila]->Cells[0]->Value->ToString());
		String^ precio = gcnew System::String(dataGridView1->Rows[fila]->Cells[4]->Value->ToString());
		String^ nombre = dataGridView1->Rows[fila]->Cells[1]->Value->ToString();
		int precioFinal = int::Parse(precio);
		char * codigoProd = Utilitario::toChar(cod);
		int cantidad    = (int)numericUpDown1->Value;
		int montoTotal = (precioFinal*cantidad);
		bool existe = gestorCompras->agregarProductoALista(pasillo, general, especifica, codigoProd, cantidad, montoTotal, listaCompra);
		if(existe)
			agregarAlCarrito(cod, nombre, cantidad, montoTotal);
	}
	
	private: System::Void agregarAlCarrito(String^ cod, String^ nombre, int cantidad, int monto){
		btnFacturar->Enabled = true;
		btnGuardar->Enabled = true;
		calcularTotal();
		dataGridView2->Rows->Add(cod, nombre, Utilitario::toInt32(cantidad), Utilitario::toInt32(monto));
	}

	private: System::Void calcularTotal() {
		NodoCompra * nodo = listaCompra->getCab();
		double total = 0;
		while (nodo != NULL) {
			total = total + nodo->getLineaDetalle()->getMonto();
			nodo = nodo->getSgte();
		}
		lblTotal->Text = Utilitario::toInt32(total)->ToString();
		totalCarrito = total;
	}
	
	private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		btnEliminar->Enabled = true;
		btnFacturar->Enabled = true;
		btnGuardar->Enabled = true;
	}
	//revisar
	private: System::Void btnEliminar_Click(System::Object^  sender, System::EventArgs^  e) {
		int fila = dataGridView2->CurrentRow->Index;
		String^ codigoSis = dataGridView2->Rows[fila]->Cells[0]->Value->ToString();
		dataGridView2->Rows->RemoveAt(fila);
		char * codigo = Utilitario::toChar(codigoSis);
		listaCompra->elimina(codigo);
		calcularTotal();
	}
	
	private: System::Void btnPagar_Click(System::Object^  sender, System::EventArgs^  e) {
		dataGridView2->Rows->Clear();
		listaCompra->vaciar();
		calcularTotal();
		numericUpDown1->Value = 1;
		btnEliminar->Enabled = false;
		btnFacturar->Enabled = false;
		btnGuardar->Enabled = false;
	}
	
	public: System::Void limpiarLista(){
		dataGridView2->Rows->Clear();
		listaCompra->vaciar();
		calcularTotal();
		numericUpDown1->Value = 1;
		btnEliminar->Enabled = false;
		btnFacturar->Enabled = false;
		btnGuardar->Enabled = false;
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		UIGuardar ^ guardar = gcnew UIGuardar(codigoUsuario, totalCarrito, 0, listaCompra, listaCarrito);
		guardar->Show();
		restablecerLista();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		BuscarCarritos ^ buscarCarrito = gcnew BuscarCarritos(codigoUsuario, dataGridView2, listaCarrito, listaCompra, lblTotal);
		buscarCarrito->Show();
	}
			 
	private: System::Void btnFacturar_Click(System::Object^  sender, System::EventArgs^  e) {
		UIFactura ^ facturar = gcnew UIFactura(codigoUsuario, totalCarrito, listaCompra, listaCarrito);
		facturar->Show();
		listaCarrito->guardarCarritos();
		restablecerLista();
	}

	private: void restablecerLista() {
		gestorCompras = new GestorCompras();
		listaCompra = new ListaCompra();
		listaCarrito = new ListaCarrito();
	}

	private: System::Void registrarToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		UIRegistro ^ regUsuario = gcnew UIRegistro();
		regUsuario->Show();
	}
	private: System::Void modificarToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		ModificarUsuario ^ modif = gcnew ModificarUsuario();
		modif->Show();
	}
	private: System::Void modificarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		ModificarArticulo ^modif = gcnew ModificarArticulo();
		modif->Show();
	}

	private: System::Void registrarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		UIRegArticulo ^reg = gcnew UIRegArticulo();
		reg->Show();
	}
	private: System::Void pendientesEntregaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		UIPendientes ^ comprasPendientes = gcnew UIPendientes();
		comprasPendientes->Show();
	}

	private: System::Void agregarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		UIAgregarPasillo ^ UIPasillo = gcnew UIAgregarPasillo();
		UIPasillo->Show();
	}
};
}
