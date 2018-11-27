/**
 * Input: An array of integers
 * Output: An array of integers such that each index consists of the product of all other elements except the current one.
 * O(n) time and O(1) space complexity
 */
#include <iostream>
#include <cmath>

// Epsilon value to maintain precision
#define EPS 1e-9
using namespace std;


void product_puzzle(const int[], const int);


int main() {
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	cout << "Enter the array elements in a space separated format:\n";
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
	}
	product_puzzle(a, n);
	return 0;
}


/**
 * Function that prints the product of all other elements except current element
 * We use the antilog method
 * x = a * b * c * d
 * log x = log a + log b + log c + log d
 * x = antilog(log(a) + log(b) + log(c) + log(d))
 */
void product_puzzle(const int a[], const int n) {
	// To hold sum of all values
	long double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (long double)log10(a[i]);	
	}
	
	// output product for each index
	// antilog to find original product value
	for (int i = 0; i < n; ++i) {
		cout << (int)(EPS + pow((long double)10.00, sum - log10(a[i]))) << " ";	
	}
	cout << "\n";
}
