/*
* 1. 작성 일자 : 2023.12.24
* 2. 문제 번호 : 31009
* 3. 문제 이름 : 진주로 가자! (Easy) 
* 3. 문제 링크 : https://www.acmicpc.net/problem/31009
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    int N; // 교통편의 개수
    cin >> N;

    int jinju = 0; // 진주로 가는 교통편의 요금
    int count = 0; // 진주보다 비싼 교통편의 개수

    vector<string> D(N); // 교통편의 종류를 저장할 벡터
    vector<int> C(N); // 교통편의 종류와 요금을 저장할 벡터

    for (int i = 0; i < N; i++) 
    {
        cin >> D[i] >> C[i]; // 교통편의 종류와 요금 입력

        if (D[i] == "jinju") // 진주로 가는 교통편의 요금이면
        {
            jinju = C[i]; // 진주로 가는 교통편의 요금 저장
        }
    }

    for (int i = 0; i < N; i++) 
    {
        if (C[i] > jinju) // 진주보다 비싼 교통편의 요금이면
        {
            count++; // 진주보다 비싼 교통편의 개수 증가
        }
    }

    cout << jinju << endl; // 진주로 가는 교통편의 요금 출력
    cout << count << endl; // 진주보다 비싼 교통편의 개수 출력

    return 0;
}