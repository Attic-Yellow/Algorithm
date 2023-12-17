#include <iostream>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

int recursion(const char* s, int l, int r, int& count)
{
	count++; // 재귀함수 호출 횟수 증가

	if (l >= r) // 문자열의 왼쪽 끝 인덱스가 오른쪽 끝 인덱스보다 크거나 같으면
	{
		return 1; // 팰린드롬
	}
	else // 문자열의 왼쪽 끝 인덱스가 오른쪽 끝 인덱스보다 작으면
	{
		if (s[l] == s[r]) // 왼쪽 끝 인덱스와 오른쪽 끝 인덱스의 문자가 같으면
		{
			return recursion(s, l + 1, r - 1, count); // 재귀함수 호출
		}
		else // 왼쪽 끝 인덱스와 오른쪽 끝 인덱스의 문자가 다르면
		{
			return 0; // 팰린드롬이 아님
		}
	}
}

int isPalindrome(const char* s, int& count)
{
	int l = 0; // 문자열의 왼쪽 끝 인덱스
	int r = strlen(s) - 1; // 문자열의 오른쪽 끝 인덱스
	int result = recursion(s, l, r, count); // 재귀함수 호출 결과

	if (result == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int N; // 팰린드롬을 검사할 문자열의 개수
	int count; // 재귀함수 호출 횟수
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < N; i++)
	{
		char s[1001];
		cin.getline(s, 1001);

			count = 0;

		if (isPalindrome(s, count) == 1)
		{
			cout << 1 << " " << count;
		}
		else
		{
			cout << 0 << " " << count;
		}
		cout << endl;
	}
}