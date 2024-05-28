#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	int time = 0, T=3, x;
	cout << " RANDMAX " << RAND_MAX << endl;
	while (time++ < 18) {
		Sleep(T*1000);
		x = rand( ) % T;
		cout << " Elapsed time[sec] " <<  time  << " " << x << endl;
	}	
	return 1;
}