//Tema:
//1. Implementati operatorii din exemplul de mai jos pentru a compara mediile a doi studenti
//2. Implementati operatorii din exemplul de mai jos pentru a compara media unui student cu o valoare
//3. Implementati operatorii din exemplul de mai jos pentru a compara un intreg cu media unui student 
//4. Adugati un camp id constant, incrementat automat la declararea unui nou student. Implementati operatorii == si != pentru a compara doua obiecte de tip student pe baza id-ului


#include <iostream>
using namespace std;

class Student
{
private:
	int varsta;
	char* nume;
	int nrNote;
	int *note;
public:
#pragma region Constructori, Destructor
	//constructor fara parametrii
	Student()
	{
		nume = NULL;
		varsta = 0;
		nrNote = 0;
		note = NULL;
	}
	//constructor cu parametrii
	Student(char* nume, int varsta, int nrNote, int*note)
		:varsta(varsta), nrNote(nrNote)
	{
		//this->varsta = varsta;
		//this->nrNote = nrNote;
		//nume
		//this->nume = nume; //gresit
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		//note
		//this->note = note; //gresit
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
	}
	//constructor copiere
	Student(const Student & source)
	{
		//copiere nume
		if (source.nume == NULL)
			this->nume = NULL;
		else
		{
			this->nume = new char[strlen(source.nume) + 1];
			strcpy(this->nume, source.nume);
		}

		//copiere varsta
		this->varsta = source.varsta;

		//copiere nrNote
		this->nrNote = source.nrNote;

		//copiere note
		if (source.note == NULL)
			this->note = NULL;
		else
		{
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = source.note[i];
		}
	}
	//destructor
	~Student()
	{
		//dezalocare spatiu (doar daca exista spatiu alocat)
		if (nume != NULL)
			delete[] nume;
		//dezalocare spatiu (doar daca exista spatiu alocat)
		if (note != NULL)
			delete[] note;
	}
#pragma endregion 

#pragma region Metode acces
	//Get/Set Varsta
	int getVarsta() const
	{
		return varsta;
	}
	void setVarsta(int varstaNoua)
	{
		if (varstaNoua >= 0 && varstaNoua < 150)
			varsta = varstaNoua;
		else
			throw new exception("Varsta intre 0 si 150!");
	}

	//Get/Set Nume
	char* getNume() const {
		return nume;
	}
	void setNume(char* numeNou) {
		if (numeNou == NULL)
			throw new exception("Nume nu poate fi NULL!");
		else
		{
			if (this->nume != NULL)
				delete[] this->nume;
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}
	}

	//Get/Set Note & NrNote
	int getNrNote() const
	{
		return nrNote;
	}
	int* getNote() const
	{
		return note;
	}
	void setNote(int nrNote, int*note)
	{
		if (this->note != NULL)
			delete[] this->note;
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
	}
#pragma endregion 

#pragma region Operatori
#pragma region Operator atribuire
	//supraincarcare operator=
	Student & operator=(const Student & source)
	{
		cout << "Operator =" << endl;

		//1.
		this->varsta = source.varsta;
		this->nrNote = source.nrNote;

		//2. copiere atribute *

		//Nume
		//a) stergere spatiu existent
		if (this->nume != NULL)
			delete[] this->nume;

		if (source.nume == NULL)
			this->nume = NULL;
		else
		{
			//b) alocare spatiu
			this->nume = new char[strlen(source.nume) + 1];
			//c) copiere
			strcpy(this->nume, source.nume);
		}

		//Note
		//a) stergere spatiu existent
		if (this->note != NULL)
			delete[] this->note;

		if (source.note == NULL)
			this->note = NULL;
		else
		{
			//b) alocare spatiu
			this->note = new int[this->nrNote];
			//c) copiere
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = source.note[i];
		}

		return  *this;
	}
#pragma endregion

#pragma region Operatori binari comparatie (Primul operand este de tip Student)
	//== , >, <. >= , =<
	//comparare obiecte de tip student
	//NU modifica datele obiectului referit prin this
	bool operator==(const Student& other) const
	{
		/* do actual comparison */
		return this->varsta == other.varsta;
	}
	//comparare obiecte de tip student
	//NU modifica datele obiectului referit prin this
	bool operator!=(const Student& other) const { return !operator==(other); }
	//comparare obiecte de tip student
	//NU modifica datele obiectului referit prin this
	bool operator< (const Student& other) const { /* do actual comparison */ }
	//comparare obiecte de tip student
	//NU modifica datele obiectului referit prin this
	bool operator> (const Student& other) const { return  operator< (other); }
	//comparare obiecte de tip student
	//NU modifica datele obiectului referit prin this
	bool operator<=(const Student& other) const { return !operator> (other); }
	//comparare obiecte de tip student
	//NU modifica datele obiectului referit prin this
	bool operator>=(const Student& other) const { return !operator< (other); }
#pragma endregion

#pragma endregion
};

#pragma region Operatori binari comparatie (Primul operand NU este de tip Student)
//comparare int cu obiect de tip student
bool operator==(int varsta, const Student& other)
{
	/* do actual comparison */
	return varsta == other.getVarsta();
}
#pragma endregion


#pragma region Operatori InputOutput
ostream & operator<<(ostream & consola, const Student & st)
{
	consola << "Nume: ";
	if (st.getNume() != NULL)
		consola << st.getNume();
	consola << endl << "Varsta: " << st.getVarsta();
	consola << endl << "Note: ";
	for (int i = 0; i < st.getNrNote(); i++)
		consola << " " << st.getNote()[i];

	return consola << endl;
}

istream & operator >> (istream & consola, Student & st)
{
#pragma region Nume
	cout << endl << "Nume: ";
	char buffer[200];
	consola >> buffer;

	/*if (st.nume != NULL)
	delete[] st.nume;
	st.nume = new char[strlen(buffer) + 1];
	strcpy(st.nume, buffer);*/
	st.setNume(buffer);
#pragma endregion

#pragma region Varsta
	cout << "Varsta: ";
	//cin >> st.varsta;
	int varsta;
	cin >> varsta;
	st.setVarsta(varsta);
#pragma endregion

#pragma region Note
	cout << "NrNote: ";
	/*
	cin >> st.nrNote;
	if (st.note != NULL)
	delete[] st.note;
	st.note = new int[st.nrNote];
	for (int i = 0; i < st.nrNote; i++)
	{
	cout << "nota[" << i << "]: ";
	cin >> st.note[i];
	}*/

	int nrNote;
	cin >> nrNote;
	int *note = new int[nrNote];
	for (int i = 0; i < nrNote; i++)
	{
		cout << "nota[" << i << "]: ";
		cin >> note[i];
	}
	st.setNote(nrNote, note);

#pragma endregion

	return consola;
}
#pragma endregion

void main()
{
	int marks[] = { 10,9 };
	Student s("Nume", 21, 2, marks);
	Student s2("Nume", 21, 2, marks);

	if (s == s2)
		cout << "s.vasrta = s2.varsta";
	else
		cout << "s.vasrta != s2.varsta";

	if (21 == s)
		cout << "21 = s.varsta";
	else
		cout << "21 != s.varsta";

	//similar pentru ceilalti operatori ( >, <. >= , = )
}

