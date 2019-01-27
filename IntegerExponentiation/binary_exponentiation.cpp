#include <iostream>
#define MODULO 1000000007
using namespace std;


/** Function to return binary exponentiation of n ^ k
  * @param n: the base
  * @param k: the exponent
  * returns : the base raised to the exponent
  */
long long int bin_exp(const long long int &, const long long int &);


int main(void) {
    long long int n, k;
    cout << "Enter a number and the power to be raised: ";
    cin >> n >> k;
    cout << n << " raised to " << k << " is: " << bin_exp(n, k) << "\n";
    return 0;
}


long long int bin_exp(const long long int & n, const long long int & k) {
    if (k < 0) {
        return -1; 
    } 
    else if (n == 0 || n == 1) {
        return n; 
    } else if (k == 0) {
        return 1; 
    } else if (k == 1) {
        return n;
    } else if (k % 2 == 0) {
        return bin_exp(((n % MODULO) * (n % MODULO)) % MODULO, k / 2); 
    } else return (n % MODULO * bin_exp(((n % MODULO) * (n % MODULO)) % MODULO, (k - 1) / 2)) % MODULO;
}
