#include <iostream>

using namespace std;



int main() 
{
    int N, K;
    cin >> N >> K;
    
    int temp;
    int sum[100001];
    int ret = -2147483647;
    
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}
	
	for (int i = K; i <= N; i++)
	{
		ret = max(ret, (sum[i] - sum[i - K]));
	}

	cout << ret;
    
    return 0;
}