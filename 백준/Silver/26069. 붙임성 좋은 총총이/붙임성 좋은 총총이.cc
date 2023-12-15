#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string Chong = "ChongChong";

    int N;
    cin >> N;
    cin.ignore();

    map<string, string> dancer;
    dancer[Chong] = Chong; // 초기에 총총이는 무지개 댄스를 추고 있음

    for (int i = 0; i < N; i++) 
    {
        string line, rabbit, meanRabbit;
        getline(cin, line); // 한 줄 전체를 읽음
        istringstream iss(line); // istringstream에 해당 줄을 넣음
        iss >> rabbit >> meanRabbit; // rabbit과 meanRabbit을 추출

        // 총총이 또는 무지개 댄스를 추는 사람을 만난 경우
        if (dancer.find(rabbit) != dancer.end() || dancer.find(meanRabbit) != dancer.end()) 
        {
            dancer[rabbit] = Chong;
            dancer[meanRabbit] = Chong;
        }
        // 두 사람 모두 무지개 댄스를 추지 않는 경우에는 아무 변화도 없음
    }

    cout << dancer.size();

    return 0;
}
