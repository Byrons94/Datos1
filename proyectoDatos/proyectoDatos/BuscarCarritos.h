#pragma once
#include "GestorCompras.h"
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
	/// Summary for BuscarCarritos
	/// </summary>
	public ref class BuscarCarritos : public System::Windows::Forms::Form
	{

	GestorCompras * gestor			= NULL;
	ListaCarrito  * lista			= new ListaCarrito();
	ListaArticulo * listaArticulos  = new ListaArticulo();
	ListaCompra   * listaCompra		= new ListaCompra();
	ListaCarrito  * listaActual;
	
	DataGridView^ dataprincipal;
	Label^   lblTotal;
	String^ idUsuario;


	private: System::Windows::Forms::Label^  lblCarrito;
	
	public:
		BuscarCarritos(void)
		{
			InitializeComponent();
		}

		BuscarCarritos(String^ pidUsuario, DataGridView^ data, ListaCarrito * lista, ListaCompra *plistaCompra, Label^ lbl)
		{
			InitializeComponent();
			gestor = new GestorCompras();
			idUsuario = pidUsuario;
			listaActual = lista;
			listaCompra = plistaCompra;
			dataprincipal = data;
			lblTotal = lbl;
			listaArticulos->cargarArticulos();
			cargarCombobox(pidUsuario);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BuscarCarritos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridView^  dataGridView1;





	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnAgregar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(BuscarCarritos::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblCarrito = (gcnew System::Windows::Forms::Label());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1164, 671);
			this->panel1->TabIndex = 0;
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column5, this->Column3, this->Column4, this->Column6, this->Column7
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
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnF2;
			this->dataGridView1->GridColor = System::Drawing::Color::White;
			this->dataGridView1->Location = System::Drawing::Point(0, 94);
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
			this->dataGridView1->Size = System::Drawing::Size(1164, 529);
			this->dataGridView1->StandardTab = true;
			this->dataGridView1->TabIndex = 6;
			// 
			// Column1
			// 
			this->Column1->FillWeight = 110;
			this->Column1->HeaderText = L"Codigo";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 110;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Descripcion";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 300;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Marca";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Tamaño";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->Width = 150;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Precio";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 150;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Cantidad";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 110;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Monto total";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 150;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->lblCarrito);
			this->panel2->Controls->Add(this->btnAgregar);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1164, 94);
			this->panel2->TabIndex = 5;
			// 
			// lblCarrito
			// 
			this->lblCarrito->AutoSize = true;
			this->lblCarrito->BackColor = System::Drawing::Color::White;
			this->lblCarrito->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarrito->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblCarrito->Location = System::Drawing::Point(215, 62);
			this->lblCarrito->Name = L"lblCarrito";
			this->lblCarrito->Size = System::Drawing::Size(0, 23);
			this->lblCarrito->TabIndex = 7;
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
			this->btnAgregar->Location = System::Drawing::Point(998, 51);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(154, 37);
			this->btnAgregar->TabIndex = 6;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = false;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &BuscarCarritos::btnAgregar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(396, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(172, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Nombre del carrito";
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(586, 59);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(172, 24);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &BuscarCarritos::comboBox1_SelectedIndexChanged);
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
			this->panel3->TabIndex = 4;
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
			// BuscarCarritos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1164, 671);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BuscarCarritos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BuscarCarritos";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
	#pragma endregion
	private: System::Void cargarCombobox(String^ idUsuario){
		lista = gestor->obtenerCarritoUsuario(Utilitario::toChar(idUsuario));
		NodoCarrito * nodo = lista->getCab();
		for (int i = 0; i < lista->getTamanio(); i++){
			comboBox1->Items->Add(Utilitario::toSystemString(nodo->getInfo()->getNombre()));
			nodo = nodo->getSgte();
		}
	}


	// te voy a arreglar infeliz!!! xS			
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		btnAgregar->Enabled = true;
		dataGridView1->Rows->Clear();

		int indexCombo = comboBox1->SelectedIndex;
		int contadorArticulos = 0; // cuenta la cantidad de articulos por pedido guardado.

		NodoCarrito * nodo = lista->getCab();

		for (int i = 0; i < lista->getTamanio(); i++){
			if (i == indexCombo) {

				NodoCompra * nodoC = nodo->getInfo()->getListaCompra()->getCab();
				if (strcmp(nodoC->getLineaDetalle()->getCodCarrito(), nodoC->getLineaDetalle()->getCodCarrito())==0 ) {
					
					while (nodoC != NULL){
						NodoArticulo * nodoA = listaArticulos->getCab();
					
						while (nodoA != NULL && contadorArticulos < nodo->getInfo()->getListaCompra()->getTamanio()) {
							InfoArticulo * articulo = nodoA->getInfo();
							
							if (strcmp(nodoC->getLineaDetalle()->getProducto(), nodoA->getInfo()->getCodigo()) == 0) {
								dataGridView1->Rows->Add(Utilitario::toSystemString(nodoC->getLineaDetalle()->getProducto()),
														Utilitario::toSystemString(articulo->getNombre()),
														Utilitario::toSystemString(articulo->getMarca()),
														Utilitario::toSystemString(articulo->getTamanio()),
														Utilitario::toInt32(articulo->getPrecio()),
														Utilitario::toInt32(nodoC->getLineaDetalle()->getCantidad()),
														Utilitario::toInt32(nodoC->getLineaDetalle()->getMonto()));
								++contadorArticulos;
							}

							nodoA = nodoA->getSgte();
						}
						nodoC = nodoC->getSgte();
					}
				}
			}	
				nodo = nodo->getSgte();
		}
	}
	

	private: System::Void btnAgregar_Click(System::Object^  sender, System::EventArgs^  e) {
		NodoCarrito *nodoActual = listaActual->getCab();
		NodoCarrito * nodo = lista->getCab();
		int indexCombo = comboBox1->SelectedIndex;

		for (int i = 0; i < lista->getTamanio(); i++){
			
			if (i == indexCombo) {
				NodoCompra * compra = nodo->getInfo()->getListaCompra()->getCab();
				
				while (compra!=NULL){
					listaCompra->agregarProductoEspecifico(compra->getLineaDetalle()->getPasillo(),
															compra->getLineaDetalle()->getGeneral(),
															compra->getLineaDetalle()->getEspecifica(), 
															compra->getLineaDetalle()->getProducto(),
															compra->getLineaDetalle()->getCantidad(),
															compra->getLineaDetalle()->getMonto());
					compra = compra->getSgte();
				}
			}
			nodo = nodo->getSgte();
		}
		actualizarCarrito();
		Hide();
	}

	private: System::Void actualizarCarrito() {
		ListaArticulo * listaArticulos = new ListaArticulo();
		NodoCompra * nodo = listaCompra->getCab();
		listaArticulos->cargarArticulos();
		dataprincipal->Rows->Clear();
		double total = 0;
		
		while (nodo != NULL) {
				
			NodoArticulo * nodoArti = listaArticulos->getCab();
			while (nodoArti!=NULL)
			{
				if (strcmp(nodoArti->getInfo()->getCodigo(), nodo->getLineaDetalle()->getProducto()) == 0) {
						dataprincipal->Rows->Add(Utilitario::toSystemString(nodo->getLineaDetalle()->getProducto()),
												 Utilitario::toSystemString(nodoArti->getInfo()->getNombre()),
												 Utilitario::toInt32(nodo->getLineaDetalle()->getCantidad()),
												 Utilitario::toInt32(nodo->getLineaDetalle()->getMonto()));

						total = total + nodo->getLineaDetalle()->getMonto();
				}

				nodoArti = nodoArti->getSgte();
			}

			nodo = nodo->getSgte();
		}
		lblTotal->Text = Utilitario::toInt32(total)->ToString();
		
	}
};
}