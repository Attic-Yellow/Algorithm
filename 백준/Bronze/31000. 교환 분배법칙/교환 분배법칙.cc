#include <iostream>

using namespace std;

int main() 
{	
    // 입출력 최적화 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    cin >> N;

    // a = 0 인 경우 세기
    count += (2 * N + 1) * (2 * N + 1);

    // a + b + c = 1 이면서 a != 0 인 경우 세기
    for (int a = -N; a <= N; a++) 
    {
        if (a != 0) 
        {
            for (int b = -N; b <= N; b++) 
            {
                int c = 1 - a - b;

                if (c >= -N && c <= N) 
                {
                    count++;
                }
            }
        }
    }

    cout << count;

    return 0;
}