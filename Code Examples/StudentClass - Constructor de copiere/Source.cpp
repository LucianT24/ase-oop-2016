#include <iostream>
using namespace std;

class Student {
private:
	char* nume;
	int varsta;
	int nrNote;
	int* note;
public:
	//constructor implicit
	Student() 
	{
		cout << "Constructor implicit" << endl;

		nume = NULL;
		varsta = 0;
		nrNote = 0;
		note = NULL;
	}
	//constructor cu parametrii
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
	//constructor copiere
	Student(const Student & source)
	{
		cout << "Constructor copiere" << endl;

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
		cout << "Destructor" << endl;

		if (this->nume != NULL)
			delete[] this->nume;
		if (this->note != NULL)
			delete[] this->note;
	}
};

void OMetodaSimpla(Student st){
	cout << "OMetodaSimpla" << endl;
}

void main()
{
	Student s("nume", 21);
	Student s2 = s; //constructor copiere

	OMetodaSimpla(s); //constructor copiere (transmitere parametru prin valoare)
}