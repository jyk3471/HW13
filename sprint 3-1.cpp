#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;
int main() {
	int k = 5, n = 2, capacity = 100, lost = 0;
	vector <int> queue;
	//push
	if (capacity < queue.size() + k) {
		lost += queue.size() + k - capacity;
		k = capacity - queue.size();
	}
	for (int i = 0; i < k; i++) {
		queue.push_back(rand() % 20);
		cout << queue[queue.size() - 1] << " " << queue.size() << endl;
	}
	cout << "size " << queue.size() << "=" << k << "\n";
	//pop
	for (int i = 0; i < n; i++) {
		if (queue.size() != 0) {// if not udnerflow
			cout << queue[0] << "\n";
			queue.erase(queue.begin());
		}
	}
}