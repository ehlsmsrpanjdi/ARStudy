#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

void SM2178() {
	int X;
	int Y;
	int Num;
	std::cin >> Y;
	std::cin >> X;
	std::queue<std::pair<int, int>> Qu;


	int arr[101][101];
	memset(arr, -1, sizeof(arr));

	int Visit[101][101];
	memset(Visit, 0, sizeof(Visit));

	for (int j = 1; j <= Y; ++j) {
		std::cin >> Num;
		for (int i = X; i > 0; --i) {
			arr[j][i] = Num % 10;
			Num /= 10;
		}
	}
	Num = 0;
	int StartX = 1;
	int StartY = 1;
	Visit[1][1] = 1;
	Qu.push(std::make_pair(1, 1));

	while (!Qu.empty()) {
		StartX = Qu.front().first;
		StartY = Qu.front().second;
		if (StartX == X && StartY == Y) {
			break;
		}
		Qu.pop();
		if (arr[StartY + 1][StartX] == 1 && Visit[StartY + 1][StartX] == 0) {
			Qu.push(std::make_pair(StartY + 1, StartX));
			Visit[StartY + 1][StartX] = 1;
		}
		if (arr[StartY][StartX + 1] == 1 && Visit[StartY][StartX + 1] == 0) {
			Qu.push(std::make_pair(StartY, StartX + 1));
			Visit[StartY][StartX + 1] = 1;
		}
		if (arr[StartY - 1][StartX] == 1 && Visit[StartY - 1][StartX] == 0) {
			Qu.push(std::make_pair(StartY - 1, StartX));
			Visit[StartY - 1][StartX] = 1;
		}
		if (arr[StartY][StartX - 1] == 1 && Visit[StartY][StartX - 1] == 0) {
			Qu.push(std::make_pair(StartY, StartX - 1));
			Visit[StartY][StartX - 1] = 1;
		}
		Num++;
	}
	std::cout << Num;
}