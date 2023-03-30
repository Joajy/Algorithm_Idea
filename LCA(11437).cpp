#include<iostream>
#include<vector>
using namespace std;

#define MAX 50001
int par[MAX], depth[MAX];
vector<int> node[MAX];
bool vis[MAX];
int n, m;

/*
	Longest Common Ancestor
	최소 공통 조상

	1. DFS를 통해 각 노드의 깊이 지정
	2-1. LCA 함수에서 더 깊은 노드를 끌어올려 동일 깊이로 만들기
	2-2. 두 노드가 같을 때 까지(부모가 같을 때 까지) while문으로 부모 값 대입 후 결과값 반환
*/

void dfs(int st, int dep) {
	vis[st] = true;
	depth[st] = dep;

	//st번 노드에 연관된 모든 노드들 순회
	for (int i = 0; i < node[st].size(); i++) {
		int idx = node[st][i];
		//node[x].push_back(y), node[y].push_back(x)
		//양측 노드에 값을 대입하였으므로 중복되는 경우 continue로 제외
		if (vis[idx]) continue;
		par[idx] = st;
		dfs(idx, dep + 1);
	}
}

int lca(int a, int b) {
	//동일한 높이로 조정
	while (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) a = par[a];
		else b = par[b];
	}

	//두 노드의 가장 가까운 조상 확인
	while (a != b) {
		a = par[a];
		b = par[b];
	}

	return a;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	//문제 조건에서 루트 노드를 1로 지정함
	dfs(1, 0);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;
}