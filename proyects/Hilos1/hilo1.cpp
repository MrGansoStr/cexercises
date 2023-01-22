#include <iostream>
#include <stdio.h>
#include <thread>
#include <vector>
#include <mutex>
#include <ctime>
using namespace std;

int contador = 0;
mutex counter_mutex;
void thread_func() {
	for(int i = 0; i < 10000; i++) {
		unique_lock<mutex> counter_lock(counter_mutex);
		contador++;
		cout<< contador << endl;
	}
	return;
}

int main() {
	unsigned t1, t2;
	t1 = clock();
	vector<thread> threads;
	for(int i = 0; i < 4; i++) {
		threads.push_back(thread(thread_func));
	}
	for(int i = 0; i < 4; i++) {
			threads[i].join();
	}
	t2 = clock();
	double tiempoT = double(double(t2 - t1) / CLOCKS_PER_SEC);
	cout<< "El tiempo fue de " << tiempoT << "segundos" << endl;
	return 0;
}
