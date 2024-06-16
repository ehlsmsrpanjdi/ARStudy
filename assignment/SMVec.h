#pragma once
#include <iostream>
#include <string>
#include <vector>

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