#include <iostream>
using namespace std;

class Student {
private:
	char* nume;
	int varsta;
	int nrNote;
	int* note;
public:
	Student() 
	{
		nume = NULL;
		varsta = 0;
		nrNote = 0;
		note = NULL;
		//incrementare valoare variabila statica
		
	}

	Student(char* nume, int varsta)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;

		//atribute
		this->nrNote = 0;
		this->note = NULL;
	}
	~Student()
	{
		if (this->nume != NULL)
			delete[] this->nume;
		if (this->note != NULL)
			delete[] this->note;
	}

	//operator=
	/*void operator=(const Student &st)
	{
		cout << "Operator =" << endl;

		this->varsta = st.varsta;
		this->nrNote = st.nrNote;

		//copiere nume


		//1. stergere
		if (this->nume != NULL)
			delete[] this->nume;

		if (st.nume == NULL)
			this->nume = NULL;
		else
		{
			//2. alocare spatiu
			int lungimeNumeNou = strlen(st.nume) + 1;
			this->nume = new char[lungimeNumeNou];
			//3. copierea
			strcpy(this->nume, st.nume);
		}
	}*/
};

void main()
{
	Student s("nume", 21);

	//Student s2 = s; //constructor copiere

	Student s2("nume", 21);
	//s2 = s; //operator=
	s2.operator=(s);
}