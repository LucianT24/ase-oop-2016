#include <iostream> 
using namespace std;

struct TheVector
{
	double elem[10];
	int dim;
};

void aduna(TheVector x, TheVector y, TheVector &rez)
{
	for (int i = 0; i<x.dim; i++)
		rez.elem[i] = x.elem[i] + y.elem[i];
}

void main()
{
	TheVector a1, a2, a3;
	a1.dim = 3;
	a2.dim = 3;
	a3.dim = 3;

	for (int i = 0; i < a1.dim; i++)
	{
		cout<<"a1.elem["<<i<<"]=";
		cin>>a1.elem[i];
		cout<<"a2elem["<<i<<"]=";
		cin>>a2.elem[i];
	}

	aduna(a1, a2, a3);

	for (int i = 0; i < 3; i++)
		cout<<endl<<"a3.elem["<<i<<"] = "<<a3.elem[i];
}
