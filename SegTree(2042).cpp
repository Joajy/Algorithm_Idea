/*
//////////////////////////////////////////////////////////////
1�Ȱ� 2���� ������, ���������δ� 1���� �����⸦ ������
2���� ��� �Ű���� ���� ���� �ܽǼ��� �߻��� �� ������,
1���� ��� �ش� �ܽǼ��� �ٿ��ִ� ������ �ڵ���

//////////////////////////////////////////////////////////////
*/
#include<iostream>
using namespace std;
#define MAX 1000001
#define ll long long

ll arr[1 << 20];
ll tree[1 << 22];
int n, m, k, a, b;
ll c;

ll init(int idx, int st, int en) {
	if (st == en) return tree[idx] = arr[st];
	int mid = (st + en) >> 1;
	return tree[idx] = init(idx << 1, st, mid) + init((idx << 1) + 1, mid + 1, en);
}

//st, en : ���� �� �� �ε��� / left, right : ���� �� ���ϰ��� �ϴ� ����
ll sum(int st, int en, int idx, int left, int right) {
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return tree[idx];
	int mid = (st + en) >> 1;
	return sum(st, mid, idx << 1, left, right) + sum(mid + 1, en, (idx << 1) + 1, left, right);
}

ll update(int st, int en, int node, int idx, ll tmp) {
	if (idx < st || idx > en) return tree[node];
	if (st == en) return tree[node] = tmp;
	int mid = (st + en) >> 1;
	return tree[node] = update(st, mid, node << 1, idx, tmp) + update(mid + 1, en, (node << 1) + 1, idx, tmp);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			update(1, n, 1, b, c);
		else if (a == 2)
			cout << sum(1, n, 1, b, c) << '\n';
	}
	return 0;
}


/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<sstream>
#include<utility>
#include<stack>
#include<queue>
#include<functional>
#include<list>
using namespace std;
#define ll long long

//https://www.acmicpc.net/problem/2042

ll arr[1 << 20];
ll tree[1 << 22];
int n, m, k, a, b;
ll c;

ll init(int idx, int st, int en) {
	if (st == en) return tree[idx] = arr[st];
	int mid = (st + en) >> 1;
	return tree[idx] = init(idx << 1, st, mid) + init((idx << 1) + 1, mid + 1, en);
}

//st, en : ���� �� �� �ε��� / left, right : ���� �� ���ϰ��� �ϴ� ����
ll sum(int st, int en, int idx, int left, int right) {
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return tree[idx];
	int mid = (st + en) >> 1;
	return sum(st, mid, idx << 1, left, right) + sum(mid + 1, en, (idx << 1) + 1, left, right);
}

void update(int st, int en, int node, int idx, ll tmp) {
	if (idx < st || idx > en) return;
	tree[node] += tmp;
	if (st == en) return;
	int mid = (st + en) >> 1;
	update(st, mid, node << 1, idx, tmp);
	update(mid + 1, en, (node << 1) + 1, idx, tmp);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll tmp = c - arr[b - 1];
			update(0, n - 1, 1, b - 1, tmp);
			arr[b - 1] = c;
		}
		else if (a == 2)
			cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
	}
	return 0;
}
*/