#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; // 테스트 케이스
    cin >> T;

    for (int t = 0; t < T; ++t) 
    {
        int N, M; // N: 서쪽, M: 동쪽
        int res = 1;
        int tmp = 1;

        cin >> N >> M;

        for (int i = M; i > M - N; --i) 
        {
            res = res * i;
            res = res / tmp++;
        }

        cout << res << "\n";
    }

    return 0;
}