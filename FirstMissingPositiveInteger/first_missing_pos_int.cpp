#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cout << "Enter no of elements: ";
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];		
	}
	int max_n = INT_MAX, min_n = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			if (a[i] > max_n) {
				max_n = a[i];	
			} else if (a[i] < min_n) {
				min_n = a[i];	
			}
		}	
	}	
	return 0;
}
