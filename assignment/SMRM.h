#pragma once
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>
#include <functional>
class SMRM {
public:
	void Boil() {
		while (true)
		{
			if (RamenCount <= 0) {
				std::cout << "RamenCount" << RamenCount << std::endl;
				std::cout << "TotalCount" << TotalCount << std::endl;
				break;
			}
			else {
				--RamenCount;
				++TotalCount;
			}
		}
	}

	void Count(int _ThreadCount, int _RamenCount) {
		RamenCount = _RamenCount;
		while (_ThreadCount) {
			--_ThreadCount;
			std::thread* T = new std::thread(&SMRM::Boil, this);
			ThreadVec.push_back(T);
		}
	}

	void Start() {
		for (std::thread* TIndex : ThreadVec) {
			TIndex->join();
		}
	}

private:
	std::atomic<int> RamenCount = 0;
	std::atomic<int> TotalCount = 0;
	std::vector<std::thread*> ThreadVec;
};
