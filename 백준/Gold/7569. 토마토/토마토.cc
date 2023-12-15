/*
*  작성 일자 : 2023.12.15
*  문제 번호 : 7569번
*  문제 이름 : 토마토
*  문제 링크 : https://www.acmicpc.net/problem/7569
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    // 상, 하, 좌, 우, 위, 아래
    int dx[6] = { 0, 0, 0, 0, 1, -1 };
    int dy[6] = { 0, 0, 1, -1, 0, 0 };
    int dz[6] = { 1, -1, 0, 0, 0, 0 };

    int M, N, H; // M : 가로, N : 세로, H : 높이
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, 0))); 
    queue<pair<pair<int, int>, int>> q;

    for (int h = 0; h < H; h++) // h : 높이
    { 
        for (int n = 0; n < N; n++) // n : 세로
        {
            for (int m = 0; m < M; m++) // m : 가로
            {
				cin >> box[h][n][m];
                if (box[h][n][m] == 1) // 익은 토마토가 있는 위치를 큐에 넣음
                {
					q.push(make_pair(make_pair(n, m), h)); 
					visited[h][n][m] = 1;
				}
			}
		}
	}

    // BFS
    while (!q.empty())
    {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

        for (int i = 0; i < 6; i++)
        {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H) // 범위 내에 있고
            {
                if (box[nz][nx][ny] == 0 && visited[nz][nx][ny] == 0) // 익지 않은 토마토이고, 방문하지 않은 곳이면
                {
					q.push(make_pair(make_pair(nx, ny), nz));
					visited[nz][nx][ny] = visited[z][x][y] + 1;
				}
			}
		}
	}

    int max = 0;

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (visited[h][n][m] == 0 && box[h][n][m] == 0) // 방문하지 않은 곳이 있으면
                {
                    cout << -1 << endl;
					return 0;
				}
				else if (visited[h][n][m] > max) // 최대값 구하기
				{
					max = visited[h][n][m];
                }
            }
        }
    }

    cout << max - 1 << endl;

    return 0;
}