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
    // If the sizes are 0 or less than 0
    // As 0 x 0 or -1 x -2 size matrices are absurd
    if (n <= 0 || m <= 0)
        return 0;

    int dp[n][m];

    // Starting position has 0 ways to reach itself
    dp[0][0] = 0;

    // All the first column cells have only one way to be reached
    for (int i = 1; i < n; ++i) {
        dp[i][0] = 1;
    }

    // All the first row cells have only one way to be reached
    for (int j = 1; j < m; ++j) {
        dp[0][j] = 1; 
    }
    
    // For the rest of the cells
    // dist(i, j) = dist(i - 1, j) + dist(i, j - 1)
    for (int i = 1; i < n; ++i ) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
        } 
    }
    return dp[n - 1][m - 1];
} 
