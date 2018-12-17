#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    int n;
    cout << "Enter the no of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
    }
    int max_one = a[0];
    int max_two = 0;
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) {
            max_one = max(max_one + a[i], max_two); 
        } else {
            max_two = max(max_one, max_two + a[i]); 
        }
    }
    cout << max(max_one, max_two) << "\n";
    return 0;
}
