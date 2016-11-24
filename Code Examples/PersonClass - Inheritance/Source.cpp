#include <iostream>
using namespace std;

class Persoana {
protected:
	char* nume;
	int varsta;
public:
	Persoana()
	{
		cout << endl << "Persoana - Constructor default";
		nume = NULL;
		varsta = 0;
	}
	Persoana(const Persoana& source)
	{
		cout << endl << "Persoana - Constructor copiere";

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
	}
	Persoana(char* nume, int varsta) {
		cout << endl << "Persoana - Constructor cu parametrii";
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
	}
	~Persoana() {
		cout << endl << "Persoana - Destructor";
		if (this->nume != NULL)
			delete[] this->nume;
	}
	Persoana & operator=(const Persoana & source)
	{
		cout << "Persoana - Operator =" << endl;

		//varsta
		this->varsta = source.varsta;
		
		//nume
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

		return  *this;
	}
};

//clasa derivata
class Student : public Persoana
{
private:
	int nrNote;
	int* note;
public:
	Student() :Persoana()
	{
		cout << endl << "Student - Constructor default";
		this->nrNote = 0;
		this->note = NULL;
	}
	Student(char* nume, int varsta, int nrNote, int* note)
		:Persoana(nume, varsta), nrNote(nrNote)
	{
		cout << endl << "Student - Constructor cu parametrii";
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
	}
	Student(const Student &source)
		:Persoana(source)
	{
		cout << endl << "Student - Constructor copiere";

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
	~Student() {
		cout << endl << "Student - Destructor";
		if (this->note != NULL)
			delete[] this->note;
	}
	//(13.5.3 Assignment) 
	//An assignment operator shall be implemented by a non - static member function with exactly one parameter.
	//Because a copy assignment operator operator= is implicitly declared for a a class if not declared by the user, a base class assignment operator is always hidden by the copy assignment operator of the derived class.
	Student & operator=(const Student & source)
	{
		cout << "Student - Operator =" << endl;
		//1. apel explicit operator= din clasa de baza
		Persoana::operator=(source);

		//2. copiere campuri specifice
		this->nrNote = source.nrNote;
				
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

	friend ostream& operator<<(ostream& consola, const Student &st);
};

ostream & operator<<(ostream & consola, const Student & st)
{
	consola << endl << "Nume: ";
	if (st.nume != NULL)
		consola << st.nume;
	consola << endl << "Varsta: " << st.varsta;
	consola << endl << "Note: ";
	for (int i = 0; i < st.nrNote; i++)
		consola << " " << st.note[i];

	return consola;
}

void main() {
	cout << endl<<"###Student s1";
	Student s1;
	cout << s1;
	cout << endl << "###Student s1(Nume1, 21)";
	int note[] = { 2, 10 };
	Student s2("Nume2", 21, 2, note);
	cout << s2;
	cout << endl << "###Student s3 = s2";
	Student s3 = s2;
	cout << s3;
	cout << endl << "###s1 = s2";
	s1 = s2;
	cout << s1;
}