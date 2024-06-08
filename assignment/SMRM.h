#pragma once
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

class SMRM {
public:
	void Boil() {
		while (true)
		{
			--RamenCount;
			++TotalCount;
			if (RamenCount == 0) {
				std::cout << "RamenCount" << RamenCount << std::endl;
				std::cout << "TotalCount" << TotalCount << std::endl;
				break;
			}
		}
	}

	void Count(int _ThreadCount, int _RamenCount) {
		while (_ThreadCount) {
			--_ThreadCount;
			std::thread* T = new std::thread(Boil);
			ThreadVec.push_back(T);
		}
	}

	void Start() {
		for (std::thread* TIndex : ThreadVec) {
			TIndex->join();
		}
	}

private:
	std::atomic<int> RamenCount;
	std::atomic<int> TotalCount;
	std::vector<std::thread*> ThreadVec;
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