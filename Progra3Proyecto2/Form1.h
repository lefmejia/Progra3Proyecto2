#pragma once
#include <gdiplus.h>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	Matriz solution;
	Matriz mat1, mat2;
	LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);
	void draw(HDC hdc);
	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ matriz2;
	private: System::Windows::Forms::TextBox^ matriz1;
	private: System::Windows::Forms::Button^ determinanteButton;

	private: System::Windows::Forms::Button^ multiplicacionButton;
	private: System::Windows::Forms::Button^ restaButton;
	private: System::Windows::Forms::Button^ sumaButton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ solucion;
	private: System::Windows::Forms::TextBox^ nombreG;
	private: System::Windows::Forms::Button^ guardar;
	private: System::Windows::Forms::Button^ Cargar2;
	private: System::Windows::Forms::Button^ cargar1;
	private: System::Windows::Forms::RichTextBox^ mat2box;
	private: System::Windows::Forms::RichTextBox^ mat1box;











	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->mat2box = (gcnew System::Windows::Forms::RichTextBox());
			this->mat1box = (gcnew System::Windows::Forms::RichTextBox());
			this->Cargar2 = (gcnew System::Windows::Forms::Button());
			this->cargar1 = (gcnew System::Windows::Forms::Button());
			this->nombreG = (gcnew System::Windows::Forms::TextBox());
			this->guardar = (gcnew System::Windows::Forms::Button());
			this->solucion = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->matriz2 = (gcnew System::Windows::Forms::TextBox());
			this->matriz1 = (gcnew System::Windows::Forms::TextBox());
			this->determinanteButton = (gcnew System::Windows::Forms::Button());
			this->multiplicacionButton = (gcnew System::Windows::Forms::Button());
			this->restaButton = (gcnew System::Windows::Forms::Button());
			this->sumaButton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->mat2box);
			this->panel1->Controls->Add(this->mat1box);
			this->panel1->Controls->Add(this->Cargar2);
			this->panel1->Controls->Add(this->cargar1);
			this->panel1->Controls->Add(this->nombreG);
			this->panel1->Controls->Add(this->guardar);
			this->panel1->Controls->Add(this->solucion);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->matriz2);
			this->panel1->Controls->Add(this->matriz1);
			this->panel1->Controls->Add(this->determinanteButton);
			this->panel1->Controls->Add(this->multiplicacionButton);
			this->panel1->Controls->Add(this->restaButton);
			this->panel1->Controls->Add(this->sumaButton);
			this->panel1->Location = System::Drawing::Point(1, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(533, 362);
			this->panel1->TabIndex = 1;
			// 
			// mat2box
			// 
			this->mat2box->Location = System::Drawing::Point(367, 78);
			this->mat2box->Name = L"mat2box";
			this->mat2box->Size = System::Drawing::Size(149, 94);
			this->mat2box->TabIndex = 14;
			this->mat2box->Text = L"";
			// 
			// mat1box
			// 
			this->mat1box->Location = System::Drawing::Point(157, 75);
			this->mat1box->Name = L"mat1box";
			this->mat1box->Size = System::Drawing::Size(149, 97);
			this->mat1box->TabIndex = 13;
			this->mat1box->Text = L"";
			// 
			// Cargar2
			// 
			this->Cargar2->Location = System::Drawing::Point(449, 47);
			this->Cargar2->Name = L"Cargar2";
			this->Cargar2->Size = System::Drawing::Size(67, 23);
			this->Cargar2->TabIndex = 12;
			this->Cargar2->Text = L"Cargar";
			this->Cargar2->UseVisualStyleBackColor = true;
			this->Cargar2->Click += gcnew System::EventHandler(this, &Form1::Cargar2_Click);
			// 
			// cargar1
			// 
			this->cargar1->Location = System::Drawing::Point(230, 47);
			this->cargar1->Name = L"cargar1";
			this->cargar1->Size = System::Drawing::Size(67, 22);
			this->cargar1->TabIndex = 11;
			this->cargar1->Text = L"Cargar";
			this->cargar1->UseVisualStyleBackColor = true;
			this->cargar1->Click += gcnew System::EventHandler(this, &Form1::cargar1_Click);
			// 
			// nombreG
			// 
			this->nombreG->Location = System::Drawing::Point(258, 304);
			this->nombreG->Name = L"nombreG";
			this->nombreG->Size = System::Drawing::Size(97, 20);
			this->nombreG->TabIndex = 10;
			// 
			// guardar
			// 
			this->guardar->Location = System::Drawing::Point(373, 304);
			this->guardar->Name = L"guardar";
			this->guardar->Size = System::Drawing::Size(66, 22);
			this->guardar->TabIndex = 9;
			this->guardar->Text = L"Guardar";
			this->guardar->UseVisualStyleBackColor = true;
			this->guardar->Click += gcnew System::EventHandler(this, &Form1::guardar_Click);
			// 
			// solucion
			// 
			this->solucion->Location = System::Drawing::Point(258, 205);
			this->solucion->Name = L"solucion";
			this->solucion->Size = System::Drawing::Size(153, 91);
			this->solucion->TabIndex = 8;
			this->solucion->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(338, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Matriz 2";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(128, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Matriz 1";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// matriz2
			// 
			this->matriz2->Location = System::Drawing::Point(388, 21);
			this->matriz2->Name = L"matriz2";
			this->matriz2->Size = System::Drawing::Size(128, 20);
			this->matriz2->TabIndex = 5;
			// 
			// matriz1
			// 
			this->matriz1->Location = System::Drawing::Point(178, 21);
			this->matriz1->Name = L"matriz1";
			this->matriz1->Size = System::Drawing::Size(128, 20);
			this->matriz1->TabIndex = 4;
			// 
			// determinanteButton
			// 
			this->determinanteButton->Location = System::Drawing::Point(24, 138);
			this->determinanteButton->Name = L"determinanteButton";
			this->determinanteButton->Size = System::Drawing::Size(81, 31);
			this->determinanteButton->TabIndex = 3;
			this->determinanteButton->Text = L"Determinante";
			this->determinanteButton->UseVisualStyleBackColor = true;
			this->determinanteButton->Click += gcnew System::EventHandler(this, &Form1::determinanteButton_Click);
			// 
			// multiplicacionButton
			// 
			this->multiplicacionButton->Location = System::Drawing::Point(24, 99);
			this->multiplicacionButton->Name = L"multiplicacionButton";
			this->multiplicacionButton->Size = System::Drawing::Size(81, 33);
			this->multiplicacionButton->TabIndex = 2;
			this->multiplicacionButton->Text = L"Multiplicacion";
			this->multiplicacionButton->UseVisualStyleBackColor = true;
			this->multiplicacionButton->Click += gcnew System::EventHandler(this, &Form1::multiplicacionButton_Click_1);
			// 
			// restaButton
			// 
			this->restaButton->Location = System::Drawing::Point(24, 60);
			this->restaButton->Name = L"restaButton";
			this->restaButton->Size = System::Drawing::Size(81, 33);
			this->restaButton->TabIndex = 1;
			this->restaButton->Text = L"Resta";
			this->restaButton->UseVisualStyleBackColor = true;
			this->restaButton->Click += gcnew System::EventHandler(this, &Form1::restaButton_Click_1);
			// 
			// sumaButton
			// 
			this->sumaButton->Location = System::Drawing::Point(24, 21);
			this->sumaButton->Name = L"sumaButton";
			this->sumaButton->Size = System::Drawing::Size(81, 33);
			this->sumaButton->TabIndex = 0;
			this->sumaButton->Text = L"Suma";
			this->sumaButton->UseVisualStyleBackColor = true;
			this->sumaButton->Click += gcnew System::EventHandler(this, &Form1::sumaButton_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(536, 367);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void sumaButton_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void restaButton_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void multiplicacionButton_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void divisionButton_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void sumaButton_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
	//Matriz mat1, mat2, sol;
	//string path1 = msclr::interop::marshal_as<string>(matriz1->Text);
	//mat1.cargarMatriz(matriz1->Text);
	//mat2.cargarMatriz(matriz2->Text);

	if (mat1.estaVacia() || mat2.estaVacia()) 
	{
		string mensaje = "Error al cargar matriz";
		String^ msg = gcnew System::String(mensaje.c_str());
		solucion->Text = msg;
	}
	else {
		solution = mat1.suma(mat2);
		solucion->Text = solution.imprimir();
	}
	
}
private: System::Void restaButton_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
	//Matriz mat1, mat2, sol;
	//mat1.cargarMatriz(matriz1->Text);
	//mat2.cargarMatriz(matriz2->Text);

	if (mat1.estaVacia() || mat2.estaVacia())
	{
		string mensaje = "Error al cargar matriz";
		String^ msg = gcnew System::String(mensaje.c_str());
		solucion->Text = msg;
	}
	else {
		solution = mat1.resta(mat2);
		solucion->Text = solution.imprimir();
	}
}
private: System::Void multiplicacionButton_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
	//Matriz mat1, mat2, sol;
	//mat1.cargarMatriz(matriz1->Text);
	//mat2.cargarMatriz(matriz2->Text);

	if (mat1.estaVacia() || mat2.estaVacia())
	{
		string mensaje = "Error al cargar matriz";
		String^ msg = gcnew System::String(mensaje.c_str());
		solucion->Text = msg;
	}
	else {
		solution = mat1.multiplicacion(mat2);
		solucion->Text = solution.imprimir();
	}
}
private: System::Void determinanteButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Matriz mat1;
	//mat1.cargarMatriz(matriz1->Text);
	string mensaje;
	String^ msg;
	if (mat1.estaVacia())
	{
		mensaje = "Error al cargar matriz";
		msg = gcnew System::String(mensaje.c_str());
		solucion->Text = msg;
	}
	else if(mat1.getFilas()!=mat1.getColumnas() || (mat1.getColumnas()==1 && mat1.getFilas()==1)){
		mensaje = "Matriz no es cuadrada";
		msg = gcnew System::String(mensaje.c_str());
		solucion->Text = msg;
	}
	else
	{
		mensaje = "Determinante de matriz: "+to_string(mat1.determinante());
		msg = gcnew System::String(mensaje.c_str());
		solucion->Text = msg;
	}
}
private: System::Void guardar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (!solution.estaVacia())
	{
		solution.guardarMatriz(nombreG->Text);
	}
}
private: System::Void cargar1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	mat1.cargarMatriz(matriz1->Text);
	//mat2.cargarMatriz(matriz2->Text);

	if (mat1.estaVacia())
	{
		string mensaje = "Error al cargar matriz";
		String^ msg = gcnew System::String(mensaje.c_str());
		mat1box->Text = msg;
	}
	else {
		mat1box->Text = mat1.imprimir();
	}
}
private: System::Void Cargar2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//mat1.cargarMatriz(matriz1->Text);
	mat2.cargarMatriz(matriz2->Text);

	if (mat2.estaVacia())
	{
		string mensaje = "Error al cargar matriz";
		String^ msg = gcnew System::String(mensaje.c_str());
		mat2box->Text = msg;
	}
	else {
		mat2box->Text = mat2.imprimir();
	}
}
};
}
