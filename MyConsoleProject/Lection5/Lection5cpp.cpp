
// FibonacciTest.cpp
// Testar funktionen fib() genom att anropa den för de
// första 30 fibonaccitalen och skriva ut dem
#include <iostream>
using namespace std;
#include "Fibonacci.h"
int main()
{
	cout << "\n\n\tDe första 30 Fibonaccitalen:\n\n\t";
	for (int i = 1; i <= 30; i++)
	{
		cout<<fib(i) << "\t"; // Vanliga anrop
		if (i % 6 == 0)
			cout << "\n\n\t";
	}
	cout << "\n";
}
