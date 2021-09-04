#include <iostream>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;

int * get_nearest_larger_number(int [], int);

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int * nearest_larger_number = get_nearest_larger_number(a, n);
	int i;
	cin >> i;
	if (i >= n || nearest_larger_number[i] == INT_MAX) {
		cout << "null\n";
	} else {
		cout << nearest_larger_number[i] << '\n';
	}
	return 0;
}


int * get_nearest_larger_number(int a[], int n) {
	// stack to store the intermediate maxes
	stack<int> maxes;
	int * ans = new int[n];
	// Initially every number is the nearest largest number to itself
	// So we fill the array with infinity
	fill(ans, ans + n, INT_MAX);
	// Go from left to right and store the left nearest larger number 
	maxes.push(0);
	for (int i = 1; i < n; ++i) {
		if (a[maxes.top()] > a[i]) {
			ans[i] = min(abs(maxes.top() - i), ans[i]);
		} else {
			while(!maxes.empty() && a[maxes.top()] <= a[i]) {
				maxes.pop();
			}
			if (!maxes.empty()) {
				ans[i] = min(abs(maxes.top() - i), ans[i]);
			}
		}
		maxes.push(i);
	}
	// Clear the stack for the next iteration	
	while(!maxes.empty()) {
		maxes.pop();
	}
	// Go from right to left and store the right nearest larger number
	maxes.push(n - 1);
	for (int i = n - 2; i >= 0; --i) {
		if (a[maxes.top()] > a[i]) {
			ans[i] = min(abs(maxes.top() - i), ans[i]);
		} else {
			while(!maxes.empty() && a[maxes.top()] <= a[i]) {
				maxes.pop();
			}
			if (!maxes.empty()) {
				ans[i] = min(abs(maxes.top() - i), ans[i]);
			}
		}
		maxes.push(i);
	}
    return ans;
}

