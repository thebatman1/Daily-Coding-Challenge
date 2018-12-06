/**
 * Input: An array containing positive and negative values
 * Output: The first missing positive integer
 */

#include <iostream>
#include <algorithm>

using namespace std;

int segregate(int [], int);
int find_missing_positive(int [], int);
int find_missing(int [], int);

int main(void) {
	int n;
	cout << "Enter no of elements: ";
	cin >> n;
	cout << "Enter the elements: ";
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];		
	}
	int missing = find_missing(a, n);
	cout << "The smallest missing positive number is " << missing << "\n";
	return 0;
}


/**
 * Utility function that puts all the non-positive
 * numbers on the left side of arr[] and return count 
 * of such numbers
 */
int segregate(int a[], int n) {
	int j = 0, i;
	for(i = 0; i < n; ++i) {
		if (a[i] <= 0) {
			swap(a[i], a[j]);
			++j;
		}
	}
	return j;
}


/**
 * Find the smallest positive missing number in an array
 * that contains all positive integers
 */
int find_missing_positive(int a[], int n) {
	int i;
	// Mark a[i] as visited by marking a[a[i] - 1] negative.
	for (i = 0; i < n; ++i) {
		if (abs(a[i]) - 1 < n && a[abs(a[i]) - 1] > 0) {
			a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];		
		}	
	}
	for (i = 0; i < n; ++i) {
		if (a[i] > 0)
			return i + 1;
	}
	return n + 1;
}


/**
 * Find the smallest positive missing number in an array
 * that contains both positive and negative integers
 */
int find_missing(int a[], int n) {
	int shift = segregate(a, n);
	return find_missing_positive(a + shift, n - shift);
}
