#include <iostream>
using namespace std;

struct Student
{
	char* nume;
	int varsta;
	int nrNote;
	int *note;

	void(*fAfisare)(Student);

	void afiseazaStudent()
	{
		cout << this->nume;

		/*cout << endl << "nume: " << s.nume;
		cout << endl << "varsta: " << s.varsta;
		cout << endl << "note: ";
		for (int i = 0; i < s.nrNote; i++)
			cout << s.note[i] << " ";*/
	}
};

void afiseazaStudent(Student s)
{
	cout << endl << "nume: " << s.nume;
	cout << endl << "varsta: " << s.varsta;
	cout << endl << "note: ";
	for (int i = 0; i < s.nrNote; i++)
		cout << s.note[i] << " ";
}

Student initStudent(char* n, int varsta,
	int nrNote, int *note)
{
	Student st;
	st.varsta = varsta;
	st.nrNote = nrNote;

	//gresit
	//s.nume = nume;
	st.nume = new char[strlen(n) + 1];
	strcpy(st.nume, n);

	st.note = new int[nrNote];
	for (int i = 0; i < nrNote; i++)
		st.note[i] = note[i];

	return st;
}

void incrementareVarsta(Student *st)
{
	//st->varsta++;
	(*st).varsta++;
	(*st).note[0] = 11;
}

void main()
{
	char nume[5];
	nume[0] = 'N';
	nume[1] = 'u';
	nume[2] = 'm';
	nume[3] = 'e';
	nume[4] = '\0';

	int note[2];
	note[0] = 10; note[1] = 9;

	//initializare
	Student s = initStudent(nume, 21, 2, note);
	Student s2 = initStudent(nume, 21, 2, note);

	//modificare nota
	s.note[1] = 10;

	//modificare varsta
	incrementareVarsta(&s);

	//afisare
	//afiseazaStudent(s);
	//afiseazaStudent(s2);
	//initializare pointer metoda
	s.fAfisare = &afiseazaStudent;

	//s.fAfisare(s);
	//s.fAfisare(s2);
	s.afiseazaStudent();
}