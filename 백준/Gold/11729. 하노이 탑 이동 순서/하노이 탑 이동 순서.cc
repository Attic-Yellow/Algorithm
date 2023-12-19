#include <iostream>
#include <vector>

using namespace std;

// 이동 횟수를 카운트하며 이동 경로를 저장하는 하노이 탑 재귀 함수
void hanoi(int N, int from, int by, int to, int& count, vector<int>& v)
{
	// 원판이 한 개일 때는 바로 옮기면 됨
	if (N == 1)
	{
		v.push_back(from);
		v.push_back(to);
		count++;
		return;
	}

	// 원반 N-1개를 A에서 B로 이동(to를 경유지로)
	hanoi(N - 1, from, to, by, count, v);

	// 가장 큰 원반을 A에서 C로 이동
	v.push_back(from);
	v.push_back(to);
	count++;

	// 원반 N-1개를 B에서 C로 이동(from을 경유지로)
	hanoi(N - 1, by, from, to, count, v);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N; // 하노이 탑 원판의 개수
	int count = 0; // 이동 횟수
    cin >> N;

	vector<int> v; // 원판의 이동 경로를 저장할 벡터

	// 하노이 탑 재귀 함수 호출
	hanoi(N, 1, 2, 3, count, v);

	// 이동 횟수와 이동 경로 출력
	cout << count << "\n";

	for (int i = 0; i < v.size(); i += 2)
	{
		cout << v[i] << " " << v[i + 1] << "\n";
	}

    return 0;
}