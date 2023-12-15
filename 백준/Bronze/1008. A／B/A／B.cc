#include <iostream>
using namespace std;

int main() {
	
	double num1 = 0, num2 = 0;

	cin >> num1 >> num2;

	cout.precision(12);
    cout << fixed;
	cout << double(num1 / num2) << endl;

	return 0;
}