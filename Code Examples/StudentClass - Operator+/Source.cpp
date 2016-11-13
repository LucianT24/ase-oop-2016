#include <iostream>
using namespace std;

class Student
{
private:
	char* nume;
	int varsta;
	int nrNote;
	int* note;
public:
	Student(char* nume)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		note = NULL;
		nrNote = 0;

		varsta = 0;
	}
	Student(const Student & sursa)
	{
		this->varsta = sursa.varsta;
		this->nrNote = sursa.nrNote;

		if (sursa.nume == NULL)
			this->nume = NULL;
		else
		{
			//alocare spatiu
			this->nume = new char[strlen(sursa.nume) + 1];
			//copiere
			strcpy(this->nume, sursa.nume);
		}

		if (sursa.note == NULL)
			this->note = NULL;
		else
		{
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = sursa.note[i];
		}
	}
	~Student()
	{
		if (this->nume)
			delete[] this->nume;
		if (this->note)
			delete[] this->note;
	}
	Student operator=(const Student sursa)
	{
		this->varsta = sursa.varsta;
		this->nrNote = sursa.nrNote;

		//nume
		//a) stergem spatiu
		if (this->nume)
			delete[] this->nume;

		if (sursa.nume == NULL)
			this->nume = NULL;
		else
		{
			//b) alocare spatiu
			this->nume = new char[strlen(sursa.nume) + 1];
			//c) copiere
			strcpy(this->nume, sursa.nume);
		}

		//note
		//a) stergem spatiu
		if (this->note != NULL)
			delete[] this->note;

		if (sursa.note == NULL)
			this->note = NULL;
		else
		{
			//b) alocam spatiu
			this->note = new int[this->nrNote];
			//c) copiere
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = sursa.note[i];
		}

		return *this;
	}

	Student operator+(int nota)
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
};

void OMetodaSimpla(Student st)
{

}

void main()
{
	Student s("nume");
	Student s2 = s; //constructor copiere
	//OMetodaSimpla(s); //constructor copiere
	//s2 = s; //operator=
	//s2.operator=(s);
	s = s + 10;
	s = s.operator+(10);
}