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
	//alt constructor cu parametrii
	Student(char* nume, int varsta)
	{
		cout << "Constructor cu parametrii" << endl;

		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;

		//atribute
		this->nrNote = 0;
		this->note = NULL;
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

	//Get/Set Varsta
	int getVarsta()
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
	char* getNume() {
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
	int getNrNote()
	{
		return nrNote;
	}
	int* getNote()
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
};

void main()
{
	int marks[] = { 10,9 };
	Student s("Nume", 21, 2, marks);
}

