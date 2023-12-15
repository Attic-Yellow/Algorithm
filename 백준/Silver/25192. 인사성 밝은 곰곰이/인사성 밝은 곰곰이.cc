#include <iostream>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 채팅방의 기록 수
    cin >> N;

    int temp = N; // 곰곰티콘 사용 횟수

    map<string, int> chats; // 채팅방의 기록

    for (int i = 0; i < N; i++)
    {
        string chat;
        cin >> chat;

        if (chat == "ENTER") // 입장 메시지일 경우
        {
            temp--; // 곰곰티콘 사용 횟수 감소
            chats.clear(); // 채팅방의 기록 초기화
            continue;
        }

        if (chats.find(chat) != chats.end()) // 이미 존재하는 메시지일 경우
        {
            temp--; // 곰곰티콘 사용 횟수 감소
        }
        else
        {
			chats.insert({chat, 1}); // 채팅방의 기록에 추가
        }
    }

    cout << temp;

    return 0;
}