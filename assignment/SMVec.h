#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void SM10808() {
	std::string name;
	std::cin >> name;
	std::vector<int> vec;
	vec.resize(26);
	for (int i = 0; i < name.length(); ++i) {
		++vec[name[i] - 'a'];
	}
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
}

void SM2577() {
	int num = 1;
	int Multy;
	int Time = 3;
	std::vector<int> vec;
	vec.resize(10);
	while (Time--) {
		std::cin >> Multy;
		num *= Multy;
	}
	std::string strNum = std::to_string(num);
	for (int i = 0; i < strNum.size(); ++i) {
		++vec[strNum[i] - 48];
	}
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << std::endl;
	}
}

void SM1475() {
	int num;
	std::vector<int> vec;
	vec.resize(10);
	std::cin >> num;
	std::string strNum = std::to_string(num);
	for (int i = 0; i < strNum.size(); ++i) {
		++vec[strNum[i] - 48];
	}
	vec[6] += vec[9];
	if (vec[6] % 2) {
		++vec[6];
	}
	vec[6] /= 2;
	vec[9] = 0;

	num = 0;
	for (int i = 0; i < vec.size() - 1; ++i) {
		if (num < vec[i]) {
			num = vec[i];
		}
	}

	std::cout << num << std::endl;
}

void SM3273() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int num = 0;
	int Size = 0;
	int Count = 0;
	int Start = 0;
	int Index = 0;
	std::cin >> num;
	std::vector<int> vec;
	vec.resize(num, 0);
	for (int i = 0; i < num; ++i) {
		std::cin >> vec[i];
	}
	std::cin >> Size;
	std::sort(vec.begin(), vec.end());
	while ((vec[num - 1] + vec[Start]) > Size) {
		if (Index % 2) {
			--num;
			++Index;
		}
		else {
			++Start;
			++Index;
		}
	}
	for (int i = Start; i < num; ++i) {
		for (int j = i + 1; j < num; ++j) {
			if ((vec[i] + vec[j]) == Size) {
				++Count;
			}
		}
	}
	std::cout << Count << std::endl;
}