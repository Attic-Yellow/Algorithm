#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 소수 판별 함수
bool isPrime(long long number)
{
    if (number <= 1) // 1은 소수가 아니다.
    {
        return false;
    }
    if (number == 2) // 2는 소수이다.
    {
        return true;
    }
    if (number % 2 == 0) // 2를 제외한 모든 짝수는 소수가 아니다.
    {
        return false;
    }
    for (long long i = 3; i <= sqrt(number); i += 2) // 2를 제외한 모든 짝수는 소수가 아니다.
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    long long N; // 테스트 케이스 N
    long long count; // N보다 크고, 2N보다 작거나 같은 소수의 개수

    vector<long long> prime;

    while (true)
    {
        cin >> N;
        count = 0;

        if (N == 0)
        {
            break;
        }

        for (long long i = N + 1; i <= (2 * N); i++)
        {
            if (isPrime(i)) // 소수이면
            {
                count++;
            }
            else // 소수가 아니면
            {
                continue; // 다음 수로 넘어간다.
            }
        }

        prime.push_back(count);
    }

    for (long long i = 0; i < prime.size(); i++)
    {
        cout << prime[i] << "\n";
    }

    return 0;
}