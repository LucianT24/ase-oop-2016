#include <iostream> 
using namespace std; 
/* 
<iostream> uses _STD_BEGIN defined in "yvals.h" as #define _STD_BEGIN namespace std {
*/

void swapValue(int a, int b);
void swapPointer(int *pa, int *pb);
void swapReference(int& a, int& b);

void main() {
	//int * p;
	//*p = 100;
	std::cout << "Hello World";

	int x = 10, y = 20;
	
	cout << endl << "Initial values:";
	cout << endl << "x = " << x;
	cout << endl << "y = " << y;

	//Let's swap the values of the variables x and y
	//swap
	int temp = x;
	x = y;
	y = temp;

	//swap - values
	x = 10, y = 20;
	swapValue(x, y);
	cout << endl << "After swapValue():";
	cout << endl << "x = " << x; //10
	cout << endl << "y = " << y; //20
	
	//swap - pointers
	x = 10, y = 20;
	swapPointer(&x, &y);
	cout << endl << "After swapPointer():";
	cout << endl << "x = " << x; //20
	cout << endl << "y = " << y; //10

	//swap - references
	x = 10, y = 20;
	swapReference(x, y);
	cout << endl << "After swapReference():";
	cout << endl << "x = " << x; //20
	cout << endl << "y = " << y; //10
}

void swapValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapPointer(int *pa, int *pb) {
	/*int temp = *pa;
	*pa = *pb;
	*pb = temp;*/

	int* temp = pa;
	pa = pb;
	pb = temp;
}

void swapReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}