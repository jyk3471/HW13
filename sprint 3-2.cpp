#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;
void main() {
	int itime = 0, ni = 10, no = 5, capacity = 120, lost = 0;
	int NofPacket[120];
	vector <int> queue;
	while (itime++ < 120) {
		Sleep(1000);
		// push
		if (capacity >= queue.size() + ni) {
			for (int i = 0; i < ni; i++) {
				queue.push_back(rand() % 20);
				//cout << queue[queue.size() - 1] << "  " << queue.size() << endl;
			}
		}
		else {
			lost += queue.size() + ni - capacity;
			ni = capacity - queue.size();
			cout << "overflow" << endl;
			for (int i = 0; i < ni; i++) {
				queue.push_back(rand() % 20);
			}
		}
		//pop
		for (int i = 0; i < no; i++) {
			if (queue.size() > 0) { // if not underflow
				//cout << queue[0] << "\n";
				queue.erase(queue.begin());
			}
			else cout << "underflow" << endl;
		}
		NofPacket[itime] = queue.size();
		cout << NofPacket[itime] << endl;
	}
	float sum = 0, average, highest = 0;
	for (int i = 0; i < 120; i++) {
		sum += NofPacket[i];
	}
	average = sum / 120.0;
	for (int i = 0; i < 120; i++) {
		if (highest < NofPacket[i]) {
			highest = NofPacket[i];
		}
	}
	cout << "average is " << average << endl;
	cout << "higest value is " << highest << endl;

	ofstream data("databox.txt");
	for (int i = 0; i < 120; i++) {
		data << NofPacket[i] << endl;
	}
	data.close();
	getchar();
}