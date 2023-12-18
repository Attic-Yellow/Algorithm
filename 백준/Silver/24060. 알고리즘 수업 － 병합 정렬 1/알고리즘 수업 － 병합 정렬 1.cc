#include <iostream>
#include <vector>

using namespace std;

int K, storageCount = 0, answer = -1;

// 병합
void merge(vector<int>& A, int p, int q, int r, vector<int>& tmp) 
{
    int i = p, j = q + 1, t = 1;

    while (i <= q && j <= r) 
    {
        if (A[i] <= A[j]) 
        {
            tmp[t++] = A[i++];
        }
        else 
        {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q) 
    {
        tmp[t++] = A[i++];
    }

    while (j <= r) 
    {
        tmp[t++] = A[j++];
    }

    i = p; t = 1;

    while (i <= r) 
    {
        A[i] = tmp[t++];

        if (++storageCount == K) 
        {
            answer = A[i];
        }

        i++;
    }
}

// 병합 정렬
void merge_sort(vector<int>& A, int p, int r, vector<int>& tmp) 
{
    if (p < r) 
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q, tmp);
        merge_sort(A, q + 1, r, tmp);
        merge(A, p, q, r, tmp);
    }
}

int main() 
{
    int N; // N : 배열의 크기
    cin >> N >> K;

    vector<int> A(N + 1), tmp(N + 1); // A : 배열, tmp : 임시 배열

    for (int i = 1; i <= N; i++) 
    {
        cin >> A[i];
    }

    merge_sort(A, 1, N, tmp);
    cout << answer;

    return 0;
}