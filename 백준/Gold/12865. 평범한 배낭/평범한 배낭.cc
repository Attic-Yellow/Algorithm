#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N, K; // N은 물건의 수, K는 준서가 버틸 수 있는 최대 무게
    cin >> N >> K;

    vector<int> W(N), V(N); // 각 물건의 무게와 가치를 저장할 벡터
    
    for (int i = 0; i < N; i++) 
    {
        cin >> W[i] >> V[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0)); // 동적 프로그래밍을 위한 2차원 벡터 초기화

    // 동적 프로그래밍을 이용하여 문제 해결
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= K; j++) 
        {
            if (W[i - 1] <= j) 
            {
                // 현재 물건을 배낭에 넣을 수 있는 경우
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + V[i - 1]);
            } 
            else 
            {
                // 현재 물건을 배낭에 넣을 수 없는 경우
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K] << endl; // 최대 가치 합 출력
    
    return 0;
}