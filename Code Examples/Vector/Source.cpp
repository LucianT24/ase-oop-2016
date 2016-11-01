#include <iostream>
using namespace std;

void main() {

	//definire vector static
	int vectorInt[50];
	char vectorChar[50];

	for (int i = 0; i < 50; i++)
		vectorInt[i] = i + 1;

	cout << endl << "Vector int:";
	for (int i = 0; i < 50; i++)
		cout << " " << vectorInt[i];

	//int vectorInt2[100];
	//vectorInt = vectorInt2;
	//vectorInt = new int[100];

	//definire vector dinamic
	int *vector1;
	int nrElemente;
	cout << endl << "Nr elemente:";
	cin >> nrElemente;

	//alocare vector
	vector1 = new int[nrElemente];

	for (int i = 0; i < nrElemente; i++) {
		cout << endl << "Element " << i + 1 << ":";
		cin >> vector1[i];
	}
	cout << endl << "Vectorul citit este:";
	for (int i = 0; i < nrElemente; i++)
		cout << " " << vector1[i];

	//copiere vectori
	int* vector2;
	vector2 = vector1;
	cout << endl << "Vectorul copiat este:";
	for (int i = 0; i < nrElemente; i++)
		cout << " " << vector2[i];
	//modificare copie
	for (int i = 0; i < nrElemente; i++)
		vector2[i] = 99;

	cout << endl << "Vectorul copiat este:";
	for (int i = 0; i < nrElemente; i++)
		cout << " " << vector2[i];

	cout << endl << "Vectorul citit initial este:";
	for (int i = 0; i < nrElemente; i++)
		cout << " " << vector1[i];

	//copiere vector
	int *vector3 = new int[nrElemente];
	for (int i = 0; i < nrElemente; i++)
		vector3[i] = vector1[i];

	//generare memory leak-uri
	int* vector4;
	
	for (;;) {
	vector4 = new int[5];
	//procesare vector
	//eliberare memorie
	//delete[] vector4;
	}
	
	//siruri de caractere
	char nume[50];
	nume[0] = 'A';
	nume[1] = 'n';
	nume[2] = 'a';
	nume[3] = '\0';

	cout << endl << "Numele este:" << nume;
}