#include <iostream>
#include <fstream>
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
		//nume
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		//note
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
		this->nrNote = nrNote;

		if (this->note != NULL)
			delete[] this->note;
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
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

Student* citireDateFisierText(char* numeFisier, int& nr) {
	Student* studenti = NULL;
	nr = 0;
	ifstream fisier;
	fisier.open(numeFisier, ifstream::in);
	if (fisier.is_open()) {
		int nrStudenti;
		fisier >> nrStudenti;
		studenti = new Student[nrStudenti];
		int index = 0;
		while (!fisier.eof() && nrStudenti>0) {
			nrStudenti--;

			int varsta;
			fisier >> varsta;
			char nume[200];
			//fisier >> nume; // se va opri la primul caracter de tip spatiu din nume
			fisier.getline(nume, 200, '\n'); 
			//\n is the default value.
			//putem utiliza si alti delimitatori John|83|52.2
			fisier.getline(nume, 200);
			int nrNote;
			fisier >> nrNote;
			int* note = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
				fisier >> note[i];
			Student temp(nume, varsta, nrNote, note);

			delete[] note;

			studenti[index] = temp; //apel operator=
			index++;
		}
		nr = index;
		fisier.close();
	}
	else
		cout << "Fisierul nu a putut fi deschis";

	return studenti;
}

void scrieFisierText(char* numeRaport, Student* studenti, int nr) {
	ofstream fisier;
	fisier.open(numeRaport, ofstream::out | ofstream::trunc);
	if (!fisier.is_open()) {
		cout << endl << "Raportul nu a putut fi generat";
	}
	else
	{
		for (int i = 0; i < nr; i++)
			fisier << studenti[i].getNume() << endl;
		fisier.close();
	}
}

void salvareDateFisierBinar(char* numeFisier, Student* studenti, int nr) {
	
	ofstream fisier;
	
	fisier.open(numeFisier, ofstream::out | ofstream::binary | ofstream::trunc);
	
	if (!fisier.is_open())
		cout << endl << "Eroare salvare date";
	else
	{
		//scriem numarul de studenti
		fisier.write((char*)&nr, sizeof(int));

		for (int i = 0; i < nr; i++) {
			//varsta
			int varsta = studenti[i].getVarsta();
			fisier.write((char*)&varsta, sizeof(int));
			//scriu numarul de caractere al numelui + \0
			int nrCaractere = strlen(studenti[i].getNume()) + 1;
			fisier.write((char*)&nrCaractere, sizeof(int));
			//scriu numele + \0
			fisier.write(studenti[i].getNume(), nrCaractere);
			//scriu numarul de note
			int nrNote = studenti[i].getNrNote();
			fisier.write((char*)&nrNote, sizeof(int));
			
			//scriem vectorul de note - GRESIT
			//fisier.write((char*)studenti[i].getNote(), sizeof(studenti[i].getNote()));
					
			for (int j = 0; j < studenti[i].getNrNote(); j++)
				fisier.write((char*)&studenti[i].getNote()[j], sizeof(int));

			/* sau:
			fisier.write((char*) studenti[i].getNote(),sizeof(int)*studenti[i].getNrNote());
			*/
		}
		fisier.close();
	}
}

void citireDateFisierBinar(char* numeFisier, Student*& studenti, int& nrStudenti) {
	
	ifstream fisier;
	fisier.open(numeFisier, ifstream::binary | ifstream::in);
	
	if (fisier.is_open()) {
		
		fisier.read((char*)&nrStudenti, sizeof(int));

		studenti = new Student[nrStudenti];

		for (int i = 0; i < nrStudenti; i++) {
			//varsta
			int varsta;
			fisier.read((char*)&varsta, sizeof(int));
			//nume - citire numar caractere
			int nrCaractere;
			fisier.read((char*)&nrCaractere, sizeof(int));
			//nume - alocare spatiu
			char * nume = new char[nrCaractere];
			//nume - citire
			fisier.read(nume, nrCaractere * sizeof(char));
			//nrNote
			int nrNote;
			fisier.read((char*)&nrNote, sizeof(int));
			int* note = new int[nrNote];
			for (int j = 0; j < nrNote; j++)
				fisier.read((char*)&note[j], sizeof(int));
			Student temp(nume, varsta, nrNote, note);
			studenti[i] = temp;

			delete[] nume;
		}
		fisier.close();
	}
	else {
		studenti = NULL;
		nrStudenti = 0;
	}
}

void main() {
	int nrStudenti = 0;
	Student *studenti = citireDateFisierText("Studenti.txt", nrStudenti);
	//Student *studenti;
	
	for (int i = 0; i < nrStudenti; i++)
		cout << studenti[i];

	scrieFisierText("Raport.txt", studenti, nrStudenti);

	salvareDateFisierBinar("test.dat", studenti, nrStudenti);
	citireDateFisierBinar("test.dat", studenti, nrStudenti);

	for (int i = 0; i < nrStudenti; i++)
		cout << studenti[i];
}