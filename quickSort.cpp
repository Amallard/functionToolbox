#include <iostream>
#include <string>
#include <vector>

void partition(std::vector<int> &arr, int first, int last, int &rHalf, int &lHalf) {

	// Use middle of array for split point
	int split = arr[(first + last) / 2];
	bool onCorrectSide;

	do {
		// Move up array until you find an element on the wrong side
		onCorrectSide = true;
		while (onCorrectSide)
			if (arr[first] >= split)
				onCorrectSide = false;
			else
				first++;

		// Move down array until you find an element on the wrong side
		onCorrectSide = true;
		while (onCorrectSide)
			if (arr[last] <= split)
				onCorrectSide = false;
			else
				last--;

		// Swap the elements so they are on the correct sides
		if (first <= last) {
			std::swap(arr[first], arr[last]);

			// Move to next elements and continue
			first++;
			last--;
		}
	} while (first <= last);

	// Store where we left off at, AKA the starting points for next time
	rHalf = first;
	lHalf = last;
}

void quickSort(std::vector<int> &arr, int first, int last) {
	if (first < last) {
		int rHalf;
		int lHalf;

		partition(arr, first, last, rHalf, lHalf);

		// If the right half starting point has not reached the end, sort the right half
		if (rHalf < last)
			quickSort(arr, rHalf, last);
		// If the left half starting point has not reached the beginning, sort the left half
		if (first < lHalf)
			quickSort(arr, first, lHalf);
	}
}

int main() {

	std::vector <int> arr = { 321,654,987,123,456,7489,156,21,489,1,3,0,2,6,8,798,161,6984,45};

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	quickSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	char endProgram;
	std::cout << "\n\nTo exit, press [Enter]";
	std::cin.get(endProgram);
	return 0;
}
