// Rekursiv funktion fib () som returnra fibonaccitalet
// Rekursiv d�rf�r att funktionen anrop sig s�jlv 2 g�nger
// I den andra breturn _satse
int fib(int n) {

	if (n == 1 || n ==2 || n ==3)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}