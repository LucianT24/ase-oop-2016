//Tema:
//

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

#pragma region Operatori binari aritmetici (Primul operand este de tip Student)
	//+, -, *, /, +=, -=
	//supraincarcare operator+ pentru adaugarea unei note la vectorul de note
	//NU modifica datele obiectului referit prin this
	Student operator+(int nota) const
	{
		Student temp = *this; //constructor copiere

		//alocare spatiu
		int* noteActualizat = new int[temp.nrNote + 1];
		//copiere note existente
		for (int i = 0; i < temp.nrNote; i++)
			noteActualizat[i] = temp.note[i];
		//adaugare nota noua
		noteActualizat[temp.nrNote] = nota;

		//actualizare numar note
		temp.nrNote = temp.nrNote + 1;

		//stergere vector vechi
		if (temp.note != NULL)
			delete[] temp.note;

		temp.note = noteActualizat;

		return temp;
	}

	//supraincarcare operator- pentru scaderea unui numar de ani din varsta
	//NU modifica datele obiectului referit prin this
	Student operator-(int ani) const 
	{
		Student temp = *this; //constructor copiere
		
		//actualizare varsta
		temp.varsta -= ani;

		return temp;
	}

	//supraincarcare operator* pentru multiplicarea varstei cu o valoare
	//NU modifica datele obiectului referit prin this
	Student operator*(int valoare) const 
	{
		Student temp = *this; //constructor copiere

		//actualizare varsta
		temp.varsta *= valoare;

		return temp;
	}

	//supraincarcare operator/ pentru impartirea varstei cu o valoare
	//NU modifica datele obiectului referit prin this
	Student operator/(int valoare) const 
	{
		Student temp = *this; //constructor copiere

		//actualizare varsta
		temp.varsta /= valoare;

		return temp;
	}

	//supraincarcare operator-= pentru scaderea unui numar de ani din varsta
	//modifica datele obiectului referit prin this
	Student& operator-=(int valoare)
	{
		this->varsta -= valoare;
		return *this;
	}

	//supraincarcare operator+= pentru adaugarea unui numar de ani la varsta
	//modifica datele obiectului referit prin this
	Student& operator+=(int valoare)
	{
		this->varsta += valoare;
		return *this;
	}
#pragma endregion

#pragma endregion
};

#pragma region Operatori binari aritmetici (Primul operand NU este de tip Student)
//adunare intreg cu varsta unui student
int operator+(int varsta, const Student& other)
{
	return varsta + other.getVarsta();
}
//Tema: implementati supraincarcarea operatorilor >, <. >= , = 
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

	return consola<<endl;
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
	s = s + 10; //adaugare nota 10
	cout << s;
	s = s + 9; // adaugare nota 9
	cout << s;
	s = s - 1; // scadem 1 din varsta persoanei
	cout << s;
	cout << endl << endl << "Inmultire varsta cu 2"<<endl;
	s = s * 2; // inmultire varsta cu 2
	cout << s;
	cout << endl << endl <<"Impartire varsta cu 2" << endl;
	s = s / 2; // impartire varsta cu 2
	cout << s;
	cout << endl << endl << "Adunare intreg cu varsta" << endl;
	cout << 2 + s<<endl;
}

