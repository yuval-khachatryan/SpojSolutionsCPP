// Solution to adding reversed numbers on spoj
// Reads the number of inputs to be read
// reads inputs and prints the reverse of the sum of their reverses (reverse of 123 is 321)
// reverse of (10000) is (1)

#include <iostream>
#include <vector>

// the algorithm is clear from the code
int reverse(int number) {
	int result = 0;
	int remains = number;

	while (remains != 0) {
		result = result * 10 + remains % 10;
		remains /= 10;
	}

	return result;
}

int reversereverseSum(int number1, int number2) {
	return reverse(reverse(number1) + reverse(number2));
}

int Addrev() {
	int numberOfInputs;
	std::cin >> numberOfInputs;

	std::vector<int> results;
	for (int i = 0; i < numberOfInputs; ++i) {
		int number1;
		int number2;

		std::cin >> number1 >> number2;
		results.push_back(reversereverseSum(number1, number2));
	}

	for (int i = 0; i < results.size(); ++i) {
		std::cout << results[i] << "\n";
	}
}