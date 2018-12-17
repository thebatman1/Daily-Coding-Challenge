#include "node.h"
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;
	Node * head = nullptr;
	int m;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		if (head == nullptr) {
			head = new Node(m);	
		} else {
			head->add(m);
		}
	}
	int index;
    cout << "Enter the index to get the data: ";
    cin >> index;
    while (index >= n) {
        cout << "Enter a valid index (less than "<< n <<"): ";
        cin >> index;
    }
	cout << head->get(index) << "\n";
	return 0;
}
