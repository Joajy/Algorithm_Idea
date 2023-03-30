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
	�ּ� ���� ����

	1. DFS�� ���� �� ����� ���� ����
	2-1. LCA �Լ����� �� ���� ��带 ����÷� ���� ���̷� �����
	2-2. �� ��尡 ���� �� ����(�θ� ���� �� ����) while������ �θ� �� ���� �� ����� ��ȯ
*/

void dfs(int st, int dep) {
	vis[st] = true;
	depth[st] = dep;

	//st�� ��忡 ������ ��� ���� ��ȸ
	for (int i = 0; i < node[st].size(); i++) {
		int idx = node[st][i];
		//node[x].push_back(y), node[y].push_back(x)
		//���� ��忡 ���� �����Ͽ����Ƿ� �ߺ��Ǵ� ��� continue�� ����
		if (vis[idx]) continue;
		par[idx] = st;
		dfs(idx, dep + 1);
	}
}

int lca(int a, int b) {
	//������ ���̷� ����
	while (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) a = par[a];
		else b = par[b];
	}

	//�� ����� ���� ����� ���� Ȯ��
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

	//���� ���ǿ��� ��Ʈ ��带 1�� ������
	dfs(1, 0);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;
}