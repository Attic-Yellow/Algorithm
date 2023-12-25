/*
* 1. 작성 일자 : 2023.12.25
* 2. 문제 번호 : 30999
* 3. 문제 이름 : 민주주의 
* 3. 문제 링크 : https://www.acmicpc.net/problem/30999
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int N, M; // N : 투표자 수, M : 후보자 수
    cin >> N >> M;

    int count = 0; // 민주주의를 지지하는 사람의 수

    for (int i = 0; i < N; ++i) 
    {
        string opinions; // 투표자의 의견
        cin >> opinions;

        int yesVotes = 0; // 찬성 표

        for (char opinion : opinions)  
        {
            if (opinion == 'O') // 찬성 표일 경우 
            {
                yesVotes++; // 찬성 표 증가
            }
        }

        if (yesVotes >= (M / 2) + 1) // 찬성 표가 과반수 이상일 경우
        {
            count++; // 민주주의를 지지하는 사람의 수 증가
        }
    }

    cout << count;

    return 0;
}