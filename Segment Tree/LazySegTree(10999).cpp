#include<iostream>
using namespace std;
#define ll long long
#define MAX 1'000'001

ll arr[MAX], segTree[MAX << 2], lazy[MAX << 2];
/*
	Propagation Segment Tree
	한 쿼리에서 다구간 변경이 필요한 경우에 사용

	b번째부터 c번째까지 각각 d라는 값을 더하여 update
	이와 같은 경우에 lazy Update 방법 사용
*/
ll init(int node, int st, int en) {
	if (st == en) return segTree[node] = arr[st];
	int mid = (st + en) >> 1;
	return segTree[node] = init(node << 1, st, mid) + init((node << 1) + 1, mid + 1, en);
}

void lazyUpdate(int st, int en, int node) {
	if (lazy[node] == 0) return;
	if (st != en) {
		lazy[node << 1] += lazy[node];
		lazy[(node << 1) + 1] += lazy[node];
	}
        segTree[node] += (en - st + 1) * lazy[node];
	lazy[node] = 0;
}

ll rangeUpdate(int st, int en, int left, int right, int node, ll val) {
	lazyUpdate(st, en, node);
	if (left > en || right < st) return segTree[node];
	if (left <= st && en <= right) {
		if (st != en) {
			lazy[node << 1] += val;
			lazy[(node << 1) + 1] += val;
		}
		return segTree[node] += (en - st + 1) * val;
	}
	int mid = (st + en) >> 1;
	return segTree[node] = rangeUpdate(st, mid, left, right, node << 1, val) + rangeUpdate(mid + 1, en, left, right, (node << 1) + 1, val);
}

ll sum(int st, int en, int node, int left, int right) {
	lazyUpdate(st, en, node);
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return segTree[node];
	int mid = (st + en) >> 1;
	return sum(st, mid, node << 1, left, right) +
		sum(mid + 1, en, (node << 1) + 1, left, right);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll d;
			cin >> d;
			rangeUpdate(1, n, b, c, 1, d);
		}
		else
			cout << sum(1, n, 1, b, c) << '\n';
	}
	return 0;
}
