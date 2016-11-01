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
	int GetNrNote()
	{
		return nrNote;
	}
	int* GetNote()
	{
		return note;
	}
	void SetNote(int nrNote, int*note)
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
	Student s;
	try {
		s.setVarsta(2000);
		cout << "Varsta: " << s.getVarsta() << endl;
	}
	catch (exception* e)
	{
		cout << e->what();
	}
	//catch(...)
}*/
