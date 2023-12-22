#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int T, N;
    cin >> T >> N; // 파댕이를 돌봐야 하는 시간 T와 사탕의 개수 N을 입력받음

    vector<int> candies(N); // 사탕의 맛을 저장할 벡터 선언
    int totalFlavor = 0; // 사탕의 맛의 총합을 저장할 변수

    for (int i = 0; i < N; ++i) 
    {
        cin >> candies[i]; // 사탕의 맛을 입력받아 벡터에 저장
        totalFlavor += candies[i]; // 사탕의 맛을 총합에 더함
    }

    if (totalFlavor >= T) 
    {
        cout << "Padaeng_i Happy" << endl; // 사탕의 맛의 총합이 T 이상이면 파댕이는 행복
    } 
    else 
    {
        cout << "Padaeng_i Cry" << endl; // 사탕의 맛의 총합이 T 미만이면 파댕이는 울음
    }

    return 0;
}