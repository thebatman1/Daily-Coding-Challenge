#include <iostream>
#include <vector>

using namespace std;


/** Function to print a matrix in clockwise spiral order
  * @param matrix : An n x m integer matrix
  * @param n      : No of rows
  * @param m      : No of columns
  */
void print_spiral(const vector<vector<int>> &, const int &, const int &);


int main(void) {
    vector<vector<int>> mat = {{1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20}};
    print_spiral(mat, mat.size(), mat.at(0).size());
    return 0;
}


void print_spiral(const vector<vector<int>> & arr, const int & n, const int & m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom) {
        for (int i = left; i <= right; ++i) {
            cout << arr[top][i] << "\n"; 
        } 
        top++;
        for (int i = top; i <= bottom; ++i) {
            cout << arr[i][right] << "\n"; 
        } 
        right--;
        for (int i = right; i >= left; --i) {
            cout << arr[bottom][i] << "\n"; 
        } 
        bottom--;
        for (int i = bottom; i >= top; --i) {
            cout << arr[i][left] << "\n"; 
        } 
        left++;
    }
}
