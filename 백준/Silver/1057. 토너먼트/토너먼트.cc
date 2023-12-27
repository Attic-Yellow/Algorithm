#include <iostream>

using namespace std;

int win(int num) 
{
	return num % 2 == 0 ? num / 2 : num / 2 + 1;
}

int main() 
{
	int n; // 참가자 수
	int kim, lim; // 김지민, 임한수

	cin >> n >> kim >> lim;

	int round = 0; // 라운드

	while (kim != lim) 
	{
		round++; // 라운드 증가
		kim = win(kim); // 김지민
		lim = win(lim); // 임한수
	}

	cout << round;
}