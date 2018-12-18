#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// A function that takes in another function as input and calls it after given amount of time
template <typename F>
void scheduler(F, const long);

void print_hello();

int main(void) {
    long time_in_ms;
    cout << "Enter the time in milliseconds: ";
    cin >> time_in_ms;
    scheduler(print_hello, time_in_ms); 
    return 0;
}

template <typename F>
void scheduler(F f, const long time_in_ms) {
    this_thread::sleep_for(chrono::milliseconds(time_in_ms)); 
    f(); 
}

void print_hello() {
    cout << "Hello world!\n";
}
