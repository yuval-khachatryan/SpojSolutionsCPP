#include <iostream>
#include <vector>

// mark all the elemens of the array that are multiplicies of divisor - used in the sieve 
void filterPrimes(unsigned low, unsigned divisor, std::vector<bool>& numbers) {
	int start = (low / divisor) * divisor < low ? low / divisor + 1 : low / divisor;
	if (start == 1 && !numbers[divisor - low]) return;
	else if (start == true) ++start;
	
	for (int i = start; i * divisor < low + numbers.size(); ++i)
		numbers[i * divisor - low] = false;
}

// generate primes using the seive method and print the results
void generatePrimes(unsigned low, unsigned high) {
	int firstNumber = low;
	if (low <= 2) firstNumber = 2;
	std::vector<bool> numbers(high - firstNumber + 1, true);
	
	for (int mult = 2; mult * mult <= high; ++mult) {
		filterPrimes(firstNumber, mult, numbers);
	}

	std::vector<unsigned> result;
	
	for (int i = 0; i < numbers.size(); ++i) {
		if (numbers[i]) std::cout << i + firstNumber << "\n";
	}

	std::cout << "\n";
}

// main routine - need to change the name to main in order to submit
int PrimeGenerator() {
	int amount;
	std::cin >> amount;
	std::vector<unsigned> lows(amount);
	std::vector<unsigned> highs(amount);

	for (int i = 0; i < amount; ++i)
		std::cin >> lows[i] >> highs[i];

	for (int i = 0; i < amount; ++i)
		generatePrimes(lows[i], highs[i]);
}