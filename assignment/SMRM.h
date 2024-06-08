#pragma once

class SMRM {

};

//#include <iostream>
//#include <thread>
//#include <atomic>
//using namespace std;
//
//static atomic<int> Mycount = 0;
//
//void MyWhile() {
//	int i = 0;
//	while (i < 10000000) {
//		++i;
//		Mycount.fetch_add(1);
//	}
//}
//
//int main() {
//	void(*ptr) = MyWhile;
//	std::thread MyThread1(MyWhile);
//
//	std::thread MyThread2(MyWhile);
//	std::thread MyThread3(MyWhile);
//	std::thread MyThread4(MyWhile);
//
//
//
//
//	ptr = MyWhile;
//
//	MyThread1.join();
//	MyThread2.join();
//	MyThread3.join();
//	MyThread4.join();
//
//
//	cout << Mycount << endl;
//}