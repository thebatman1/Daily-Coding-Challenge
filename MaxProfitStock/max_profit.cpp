#include <iostream>
#include <stack>

using namespace std;


/** Function to find the maximum profit that could be made by buying and selling the stock once.
 *  @param a : Array containing stock prices in chronological order
 *  @param n : Size of the array
 *  @returns : The max profit
 */
int find_max_profit(int [], const int &);

int main(void) {
    int a[] = {1, 11, 8, 5, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The maximum profit is: " << find_max_profit(a, n) << "\n";
    return 0;
}


int find_max_profit(int a[], const int & n) {
    stack<int> last_max;
    int max = 0;
    int res[n];
    res[n - 1] = max;
    last_max.push(a[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        int t = last_max.top();
        if (a[i] > t) {
            last_max.push(a[i]);
            res[i] = 0;
        } else {
            res[i] = t - a[i]; 
            if (res[i] > max) {
                max = res[i]; 
            }
        }
    }
    return max;
}
