#include <iostream>
using namespace std;

class Student
{
private:
	//atribut constant
	const int id;

	int varsta;
	char* nume;
	int nrNote;
	int *note;
	static int nrStudenti;
public:
#pragma region Constructori, Destructor
	//constructor fara parametrii
	Student()
		:id(nrStudenti)
	{
		nume = NULL;
		varsta = 0;
		nrNote = 0;
		note = NULL;
		//incrementare valoare variabila statica
		nrStudenti++;
	}
	Student(char* nume, int varsta, int nrNote, int*note)
		:varsta(varsta), nrNote(nrNote), id(nrStudenti)
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
		//incrementare valoare variabila statica
		nrStudenti += 1;
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

	//Get nrStudenti
	static int GetNrStudenti()
	{
		return nrStudenti;
	}
#pragma endregion 

#pragma region Operatori
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
};

int Student::nrStudenti = 0;

ostream & operator<<(ostream & consola, const Student & st)
{
	consola << endl << "Nume: ";
	if (st.getNume() != NULL)
		consola << st.getNume();
	consola << endl << "Varsta: " << st.getVarsta();
	consola << endl << "Note: ";
	for (int i = 0; i < st.getNrNote(); i++)
		consola << " " << st.getNote()[i];

	return consola;
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

void OMetodaSimpla(Student st)
{

}

void main()
{
	int marks[] = { 10,9 };
	Student s("Nume", 21, 2, marks);

	//Constructor de copiere
	//OMetodaSimpla(s); //apeleaza constructorul de copiere
	//Student s2 = s; //apeleaza constructorul de copiere
	
	Student s2;
	
	//Operator=
	s2 = s; //apeleaza operator=
	//s2.operator=(s); //echivalent cu s2 = s;
}

