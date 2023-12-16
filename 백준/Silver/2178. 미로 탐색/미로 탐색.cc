#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m; // 세로, 가로
vector<vector<int>> maze; // 미로
vector<vector<int>> visited; // 방문 여부

// 상하좌우 이동을 위한 배열
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 좌표가 미로 내부에 있는지 확인
bool isValid(int x, int y) 
{
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1;
}

// BFS를 이용하여 미로 탐색
int bfs() 
{
    queue<pair<int, int>> q; // 좌표를 저장할 큐
    q.push({ 0, 0 });
    visited[0][0] = 1;

    // 큐가 빌 때까지 반복
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 도착지에 도착한 경우
        if (x == n - 1 && y == m - 1) 
        {
            return visited[x][y];
        }

        // 상하좌우 이동
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 이동할 수 있는 좌표인 경우
            if (isValid(nx, ny) && visited[nx][ny] == 0) 
            {
                visited[nx][ny] = visited[x][y] + 1; // 이동 횟수를 저장
                q.push({ nx, ny }); // 큐에 좌표를 저장
            }
        }
    }

    return -1; // 경로가 없는 경우
}

int main() 
{
    cin >> n >> m;
    maze = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%1d", &maze[i][j]);
        }
    }

    cout << bfs();

    return 0;
}