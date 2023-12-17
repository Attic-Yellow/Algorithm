#include <iostream>
#include <vector>

using namespace std;

// 동적 계획법을 이용하여 피보나치 수열을 구한다.
int main() 
{
    int N; // 피보나치 수열의 N번째 항을 구하기 위한 N값
    cin >> N;

    vector<int> Fibonacci(N + 1); // N번째 항까지의 피보나치 수열을 저장하기 위한 벡터

    Fibonacci[0] = 0; // 0번째 항은 0
    Fibonacci[1] = 1; // 1번째 항은 1

    for (int i = 2; i <= N; i++)
    {
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }

    cout << Fibonacci[N];

    return 0;
}