#include <iostream>

using namespace std;


/** Method to get the no of ways to reach the bottom right from top left
  * @param n: No of rows
  * @param m: No of columns
  */
const int get_no_of_ways(const int &, const int &); 


int main(void) {
    int n, m;
    cout << "Enter no of rows and columns: ";
    cin >> n >> m;
    cout << "The no of ways to reach bottom right column is: "
         << get_no_of_ways(n, m) << "\n";
    return 0;
}


const int get_no_of_ways(const int & n, const int & m) {
    int dp[n][m];
    dp[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = 1;
    }

    for (int j = 1; j < m; ++j) {
        dp[0][j] = 1; 
    }
    
    for (int i = 1; i < n; ++i ) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
        } 
    }
    return dp[n - 1][m - 1];
} 
