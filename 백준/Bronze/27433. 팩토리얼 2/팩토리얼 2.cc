/*
*  작성 일자 : 2023.12.15
*  문제 번호 : 27433번
*  문제 이름 : 팩토리얼 2
*  문제 링크 : https://www.acmicpc.net/problem/27433
*/

#include <iostream>

using namespace std;

// 팩토리얼 함수
long long Factorial(long long n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
		
}

int main()
{
	int N; // 입력받을 정수 N
	cin >> N;

	// 첫째 줄에 N!을 출력한다.
	cout << Factorial(N);

    return 0;
}