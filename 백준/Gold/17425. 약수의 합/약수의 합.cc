#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX_N = 1000000;
    vector<long long> divisorSum(MAX_N + 1, 0); // divisorSum[i] = i의 모든 약수의 합

    // divisorSum[i] = i의 모든 약수의 합
    for (int i = 1; i <= MAX_N; i++) 
    {
        for (int j = i; j <= MAX_N; j += i) 
        {
            divisorSum[j] += i;
        }
    }

    vector<long long> g(MAX_N + 1, 0); // g[i] = 1부터 i까지의 모든 divisorSum의 합

    // g[i] = 1부터 i까지의 모든 divisorSum의 합
    for (int i = 1; i <= MAX_N; i++) 
    {
        g[i] = g[i - 1] + divisorSum[i];
    }

    int T; // 테스트 케이스의 개수
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;
        cout << g[N] << "\n";
    }

    return 0;
}