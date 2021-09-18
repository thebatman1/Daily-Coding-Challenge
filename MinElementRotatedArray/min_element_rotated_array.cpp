#include <iostream>

using namespace std;

int find_min_element(int[], int);

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << find_min_element(a, n) << '\n';
	return 0;
}

int find_min_element(int a[], int n) {
	int start = 0;
	int end = n - 1;
	int mid;
	while (start < end) {
		mid = start + (end - start) / 2;
		if (a[mid] > a[mid + 1]) {
			return a[mid + 1];
		}
		if ((mid < n && a[mid] < a[mid + 1]) && (mid > 0 && a[mid] < a[mid - 1])) {
			return a[mid];
		}
		if (a[mid] < a[mid + 1]) start = mid + 1;
	}
	return a[0]; 
}

