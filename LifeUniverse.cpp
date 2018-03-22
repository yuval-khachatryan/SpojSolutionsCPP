/**
  * Solution to Spoj - Life, universe and everything
  * Read a list of numbers from input and stop processing after 42 is read.
  * Then write the result to screen
  */
#include <iostream>
#include <vector>

int main() {
	bool keep_processing{ true }; // whether the user has entered 42
	std::vector<int> numbers;

	int number;

	while (std::cin >> number) {
		if (keep_processing) {
			if (number == 42) keep_processing = false;
			else numbers.push_back(number);
		}
	}

	for (int number : numbers) {
		std::cout << number << '\n';
	}

	return 0;
}