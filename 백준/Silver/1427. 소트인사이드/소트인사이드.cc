#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string number; // 정수를 문자열로 저장할 변수
	vector<int> numbers; // 정수를 한 자리씩 분리하여 저장할 벡터

	cin >> number;

	// 정수를 한 자리씩 분리하여 벡터에 저장
	for (int i = 0; i < number.length(); i++)
	{
		numbers.push_back(number[i] - '0'); // char형을 int형으로 변환
	}

	sort(numbers.begin(), numbers.end(), greater<int>()); // 내림차순 정렬

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i];
	}

	return 0;
}