#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

void SM2178() {
	int X;
	int Y;
	int Num;
	std::cin >> Y;
	std::cin >> X;

	int arr[101][101];
	int Des[101][101];
	memset(arr, -1, sizeof(arr));

	for (int j = 0; j < Y; ++j) {
		std::cin >> Num;
		for (int i = X - 1; i >= 0; --i) {
			arr[j][i] = Num % 10;
			Num /= 10;
		}
	}

	while (1) {

	}


	int a = 0;
}