#include "pch.h"
#include "Student.h"
#include "Catalog.h"

using namespace System;
using System::Collections::Generic::List;

Catalog::Catalog()
{
	studenti = gcnew List<Student^>();
}
Catalog::~Catalog() {
	/// Folosim destructor-ul pentru a goli listele;
	/// Memoria este de-alocata oricum cand obiectele nu mai au nici o referinta,
	/// nu este neaparat sa facem asta aici;
	for each (Student ^ student in studenti) {
		student->~Student();
	}
	studenti->Clear();
	studenti = nullptr;
}

void Catalog::adaugaStudent(Student^ student) {
	studenti->Add(student);
}

void Catalog::afiseazaStudenti() {
	Console::WriteLine("Numar de studenti: {0}", studenti->Count);
	Console::WriteLine("-------------------------------------");
	for each (Student ^ student in studenti) {
		student->afiseazaDetaliiStudent();
	}
	Console::WriteLine("-------------------------------------");
}