#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int T;
    cin >> T;

    vector<int> zero(41, 0);
    vector<int> one(41, 0);
    
    zero[0] = 1; one[0] = 0;
    zero[1] = 0; one[1] = 1;

    for(int i=2; i<=40; i++) 
    {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }

    for(int i=0; i<T; i++) 
    {
        int N;
        cin >> N;
        cout << zero[N] << " " << one[N] << endl;
    }

    return 0;
}
