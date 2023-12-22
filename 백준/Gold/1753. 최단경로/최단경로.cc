#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// 정점, 간선, 시작 정점을 나타내는 변수
int V, E, K;
// 그래프를 나타내는 인접 리스트
vector<pair<int, int>> graph[20001];

// 다익스트라 알고리즘을 구현한 함수
void dijkstra(int start) 
{
    // 각 정점까지의 최단 경로값을 저장할 벡터, 초기값은 무한대(INT_MAX)로 설정
    vector<int> dist(V + 1, INT_MAX);
    // 우선순위 큐를 이용하여 가장 가까운 정점을 먼저 방문
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작 정점의 최단 경로값을 0으로 설정하고 큐에 삽입
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) 
    {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        // 이미 처리된 정점은 무시
        if (dist[current] < distance) 
        {
            continue;
        }
        
        // 인접한 모든 정점을 확인
        for (auto &neighbor : graph[current]) 
        {
            int next = neighbor.first;
            int nextDist = distance + neighbor.second;

            // 더 짧은 경로를 발견한 경우 업데이트
            if (nextDist < dist[next]) 
            {
                dist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    // 모든 정점에 대한 최단 경로 출력
    for (int i = 1; i <= V; i++) 
    {
        if (dist[i] == INT_MAX) 
        {
            cout << "INF\n";
        }
        else 
        {
            cout << dist[i] << '\n';
        }
    }
}

int main() 
{
    // 정점과 간선의 개수 입력
    cin >> V >> E;
    // 시작 정점 입력
    cin >> K;

    // 간선 정보 입력
    for (int i = 0; i < E; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        // u에서 v로 가는 가중치 w인 간선 추가
        graph[u].push_back(make_pair(v, w));
    }

    // 다익스트라 알고리즘 실행
    dijkstra(K);

    return 0;
}