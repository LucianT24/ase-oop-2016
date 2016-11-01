#include <iostream>
using namespace std;

class Student
{
public:
	char* nume;
	int varsta;
	int nrNote;
	int *note;
	Student()
	{
		nume = NULL;
		varsta = 0;
		nrNote = 0;
		note = NULL;
	}
	~Student()
	{
		//dezalocare spatiu (doar daca exista spatiu alocat)
		if (nume != NULL)
			delete[] nume;
		//dezalocare spatiu (doar daca exista spatiu alocat)
		if (note != NULL)
			delete[] note;
	}
};

//implementare gresita 
void citesteStudent(Student *st)
{
	//1. Citire varsta
	cout << "Varsta: ";
	cin >> (*st).varsta; //echivalent cu st->varsta

	//2. Citire nume
	cout << "Nume:";
	//v1. gresita
	//cin >> st->nume;
	//v2.
	char buf[200];
	cin >> buf;
	//a) dezalocare spatiu (doar daca exista spatiu alocat)
	if (st->nume != NULL)
		delete[] st->nume;
	//b) alocare spatiu pentru noul nume
	(*st).nume = new char[strlen(buf) + 1];
	strcpy((*st).nume, buf);

	//3. Citire nrNote
	cout << "NrNote: ";
	cin >> st->nrNote;

	//4. Citire note
	//v1. gresita
	//cin >> st->note;
	//v2.
	//a) dezalocare spatiu (doar daca exista spatiu alocat)
	if (st->note != NULL)
		delete[] st->note;
	//b) alocare spatiu pentru noul vector de note
	st->note = new int[st->nrNote];
	for (int i = 0; i < st->nrNote; i++)
	{
		cout << "nota[" << i << "]: ";
		cin >> st->note[i];
	}
}

void main()
{
	Student s;
	citesteStudent(&s);
	cout << "Nume: " << s.nume << endl;
	cout << "Varsta: " << s.varsta << endl;
	for (int i = 0; i < s.nrNote; i++)
		cout << s.note[i];
}
