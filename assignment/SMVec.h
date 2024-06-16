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