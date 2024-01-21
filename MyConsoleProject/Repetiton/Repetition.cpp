// Demonsterar tilldillning regel som 
// leder till overflow 
#include <iostream>
#include "fibonacci.h"
using namespace std;

int main()
{
	//f(n)={f(n-1)+ f(n-2)
	// 1 => n = 1
	// 1 => n = 2
	// 2 => n = 3
	// 3 => n = 5
	// 4 => n = 8
	// 5 => n = 13
	// 6 => n = 21
	cout << "\n\t de första 30 fibonccistalen:\n\n\t";
	for (int i = 1; i <= 30; i++)
	{
		cout<<fib(i) << "\t";
		if (i % 6 == 0)
			cout << "\n\t";
	}

}