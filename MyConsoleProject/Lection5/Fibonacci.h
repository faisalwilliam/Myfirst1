// Fibonacci.h
// Rekursiv funktion fib() som returnerar fibonaccitalen
// Rekursiv därför att funktionen anropar sig själv 2 gånger
// i den andra return-satsen
int fib(int n) // Funktionens definition
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2); // 2 rekursiva anrop i
} 
