#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 20000
#define INF 2'147'483'647
#define DIST first
#define NODE second

vector<pair<int, int>> v[MAX + 1];   //dist, destination
int V, E, K;
int dist[MAX + 1];

/*
    DIJKSTRA Algorithm
    다익스트라 알고리즘을 이용한 모든 구간 최단 거리 측정

    Priority_Queue를 사용하여 구현
    시작점을 pq에 대입한 후 pq가 빌 때까지 curDist, curNode를 통해 해당 노드에서의 최적해 찾기
    최적해 찾은 후 dist[i] 변경 및 pq에 새로운 값 담고 과정 반복
*/

void init() {
    cin >> V >> E >> K;
    for (int i = 1; i <= MAX; i++) dist[i] = INF;
    dist[K] = 0;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ c, b });
    }
}

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, K });
    while (!pq.empty()) {
        int curDist = -pq.top().DIST;
        int curNode = pq.top().NODE;
        pq.pop();
        for (auto i : v[curNode]) {
            int nxtDist = curDist + i.DIST;
            if (nxtDist < dist[i.NODE]) {
                dist[i.NODE] = nxtDist;
                pq.push({ -nxtDist, i.NODE });
            }
        }
    }
}

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}