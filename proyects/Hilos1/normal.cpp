#include <iostream>
#include <ctime>
using namespace std;

void func() {
	for (int i = 0; i < 40000; i++) {
		cout << i << endl;
	}
	return;
}

int main() {
	unsigned t1, t2;
	t1 = clock();
	func();
	t2 = clock();
	double tiempoT = double(double(t2 - t1) / CLOCKS_PER_SEC);
	cout<< "El tiempo fue de " << tiempoT << " segundos" << endl;
	return 0;
}