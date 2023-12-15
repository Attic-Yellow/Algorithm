/*
*  작성 일자 : 2023.12.15
*  문제 번호 : 20920번
*  문제 이름 : 영단어 암기는 괴로워
*  문제 링크 : https://www.acmicpc.net/problem/20920
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) 
{
    if (a.second != b.second) // 빈도수가 다르면 높은 순으로 정렬
    {
        return a.second > b.second; 
    }
    if (a.first.length() != b.first.length()) // 길이가 다르면 긴 순으로 정렬
    {
        return a.first.length() > b.first.length(); 
    }

    return a.first < b.first; // 길이가 같다면 사전순으로 정렬
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // N : 단어의 개수, M : 암기할 단어의 길이
    cin >> N >> M; 

    map<string, int> words; // 단어, 단어의 등장 횟수
 
    for (int i = 0; i < N; i++) 
    {
        string word; // 단어
		cin >> word;

        if (word.size() < M) // 단어의 길이가 M보다 작으면
        {
			continue; // 다음 단어로 넘어감
        }

        words[word]++; // 단어의 등장 횟수 증가
    }

    vector<pair<string, int>> wordList; // 단어, 단어의 등장 횟수 리스트

    for (auto& word : words) // map을 vector로 변환
    {
        wordList.push_back(word);
    }

    sort(wordList.begin(), wordList.end(), compare); // 정렬

    for (auto& word : wordList) 
    {
        cout << word.first << '\n';
    }

    return 0;
}