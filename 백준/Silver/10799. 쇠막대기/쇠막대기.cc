#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    string a;
    int cnt = 0;
    cin >> a;
    vector<char> v;  // 벡터 생성

    for (int i = 0; i < a.size(); i++) // 문자열 크기만큼 반복
    {  
        if (a[i] == '(')  // '('가 들어오면 벡터에 넣는다.
        {
            v.push_back(a[i]);
        } 
        else // ')' 가 들어오는 경우
        {  
            if (a[i - 1] == '(') // 이전에 '('가 들어왔다면 pop하고 벡터의 크기를 cnt에 더해준다.
            {  
                v.pop_back();
                cnt += v.size();
                
            } 
            else // 그렇지 않다면 pop하고 cnt에 1을 더한다.
            {  
                v.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}