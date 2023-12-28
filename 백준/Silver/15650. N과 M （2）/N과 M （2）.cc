#include <iostream>
#include <vector>

using namespace std;

void dfs(int num, int cnt, int n, int m, vector<int>& arr, vector<bool>& visited)
{
    if (cnt == m) // m개를 모두 고른 경우
    {
        for (int i = 0; i < m; i++) // arr에 기록해둔 수 출력
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = num; i <= n; i++) // 1부터 n까지의 수에 대해
    {
        if (!visited[i]) // 아직 i가 사용되지 않았으면
        {
            visited[i] = true; // i 사용 체크
            arr[cnt] = i; // arr의 다음 칸에 i를 써라
            dfs(i + 1, cnt + 1, n, m, arr, visited); // 다음 수에 대해 재귀적으로 수행
            visited[i] = false; // i를 다시 사용할 수 있도록 해제
        }
    }
}

int main()
{
    int n, m; // 1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열
    cin >> n >> m;

    vector<int> arr(m); // 수열이 들어갈 벡터
    vector<bool> visited(n + 1, false); // 방문 여부를 기록할 벡터

    dfs(1, 0, n, m, arr, visited); // 1부터 시작
    
    return 0;
}