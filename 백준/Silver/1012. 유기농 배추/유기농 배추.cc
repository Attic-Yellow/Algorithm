#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<vector<int>> field;
vector<vector<bool>> visited;

void bfs(int x, int y, int M, int N) 
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) 
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) 
            {
                if (field[next_x][next_y] && !visited[next_x][next_y]) 
                {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int M, N, K, count = 0;
        cin >> M >> N >> K;

        field = vector<vector<int>>(M, vector<int>(N, 0));
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        for (int i = 0; i < K; i++) 
        {
            int X, Y;
            cin >> X >> Y;
            field[X][Y] = 1;
        }

        for (int i = 0; i < M; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                if (field[i][j] && !visited[i][j]) 
                {
                    bfs(i, j, M, N);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}
