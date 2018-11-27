/**
 * Input: An array of integers
 * Output: A true or false value whether the pair exists or not
 */
#include <iostream>
#include <unordered_set>

using namespace std;

const bool find_sum_pair(const int [], const int, const int);

int main(void) {
	int n, k;
	cout << "Enter the no of elements: ";
	cin >> n;
	int a[n];
	cout << "Enter the space separated list of integers: \n";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
	}	
	cout << "Enter the sum to be found: ";
	cin >> k;
	if (find_sum_pair(a, n, k)) {
		cout << "Present!\n";	
	} else {
		cout << "Absent!\n";	
	}
	return 0;
}


const bool find_sum_pair(const int a[], const int n, const int k) {
	unordered_set<int> visited;
	for (int i = 0; i < n; ++i) {
		if (visited.find(k - a[i]) != visited.end()) {
			return true;	
		}	
		visited.insert(a[i]);
	}
	return false;
}
