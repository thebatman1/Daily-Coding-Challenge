#include <iostream>
#include <cmath>

using namespace std;

int longest_consecutive_1_run(int);

int main() {
	int n;
	cin >> n;
	cout << longest_consecutive_1_run(n) << '\n';
	return 0;
}

int longest_consecutive_1_run(int n) {
	int longest = 0;
	int count = 0;
	while(n != 0) {
		if (n & 1 == 1) {
			// if n is odd, the remainder will be 1, so increment count
			count++;				
		} else {
			// if n is even, the remeinder will be 0, thus breaking
			// the current run. So we compare the longest with the current
			// and reset count
			longest = max(longest, count);
			count = 0;
		}
		n = (n >> 1);
	}
	return longest;
}

