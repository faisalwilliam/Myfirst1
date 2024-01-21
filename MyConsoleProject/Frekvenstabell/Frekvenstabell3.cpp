#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

int main()
{
// define number of simulations for which thr program will run
	cout << "\n\t";
	const int simulations[] = { 50,100,1000,5000,10000 };
	// There are 6 sides on a dice
	const int numberofSides = 6;
	// Array to hold the frequency of each dice side
	int frequency[numberofSides] = { 0 };
	// Setup a random number generator
	random_device rd; // obtain a random seed
	mt19937 gen(rd()); // Seed the Mersenne Twister generator
	uniform_int_distribution<> distrib(1, numberofSides);
	// Print header for frequency table
	cout << left << setw(12) << "Rolls" << setw(12) << "1" << setw(12)
		<< "2" << setw(12) << "3" << setw(12) << "4" << setw(12) << "5" << setw(12) << "6"
		<< setw(12) << "Probability" << endl;
	// Perform simulatios
	for (int sim : simulations) {
		// Reset frequency array for this simulation
		fill(begin(frequency), end(frequency), 0);
		// simulate dice rolls
		for (int i = 0; i < sim; ++i) {
			// Roll the dice and update corresponding frequency
			++frequency[distrib(gen) - 1];
		}
		// Display the results for the current number of simulations
		cout << left << setw(12) << sim;
		for (int count : frequency) {
			cout << setw(12) << count;
		}
		// Calculate the experimental  probabilities display them
		for (int side = 0; side < numberofSides; ++side) {
			cout << setw(12) << fixed << setprecision(5)
				<<static_cast<double>(frequency[side]) / sim;

		}
		cout << "\n"; // End of current row in the result table

	} 
	return  0;

}