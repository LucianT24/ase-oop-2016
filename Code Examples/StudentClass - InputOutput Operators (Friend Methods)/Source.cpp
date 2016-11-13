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
	friend ostream& operator<<(ostream& consola, const Student &st);
	friend istream& operator >> (istream& consola, Student &st);
#pragma endregion
};

ostream & operator<<(ostream & consola, const Student & st)
{
	consola << endl << "Nume: ";
	if(st.nume != NULL)
		consola<< st.nume;
	consola << endl << "Varsta: " << st.varsta ;
	consola << endl << "Note: ";
	for (int i = 0; i < st.nrNote; i++)
		consola << " " << st.note[i];

	return consola;
}

istream & operator >> (istream & consola, Student & st)
{
	#pragma region Nume
	cout << endl << "Nume: ";
	char buffer[200];
	consola >> buffer;
	
	if (st.nume != NULL)
		delete[] st.nume;
	st.nume = new char[strlen(buffer) + 1];
	strcpy(st.nume, buffer);
	#pragma endregion

	#pragma region Varsta
	cout << "Varsta: ";
	cin >> st.varsta;
	#pragma endregion

	#pragma region Note
	cout << "NrNote: ";
	cin >> st.nrNote;

	if (st.note != NULL)
		delete [] st.note;
	st.note = new int[st.nrNote];
	for (int i = 0; i < st.nrNote; i++)
	{
		cout << "nota[" << i << "]: ";
		cin >> st.note[i];
	}
	#pragma endregion

	return consola;
}

void main()
{
	int marks[] = { 10,9 };
	Student s("Nume", 21, 2, marks);
	cout << s;
	cin >> s;
	cout << s;
}

