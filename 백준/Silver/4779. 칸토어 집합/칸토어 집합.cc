#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string cantor(int n) 
{
	if (n == 0)
	{
		return "-";
	}

	string s = cantor(n - 1); 

	return s + string(pow(3, n - 1), ' ') + s; 
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	while (cin >> n)
	{
		cout << cantor(n) << "\n";
	}

	return 0;
}