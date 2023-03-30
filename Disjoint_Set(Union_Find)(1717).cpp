#include<iostream>
using namespace std;
//https://www.acmicpc.net/problem/1717

int parent[1000001];
/*
	Disjoint Set(Union Find)
	Union 함수와 Find 함수를 적절하게 작성하여 분리 집합 문제 해결 가능
	(초기화는 parent[i] = i 반복문)

	Union : 비교할 서로소 집합의 각 루트를 확인하고, 해당 루트가 동일한 루트가 아닐 경우 임의로 하나의 루트가 다른 루트의 부모 노드가 된다.

	Find : parent[x] == x(x가 루트 노드일 경우)이면 루트 노드인 x를 리턴
		   루트 노드가 아니라면 재귀 함수로 자식 노드에서 부모 노드로 올라가며 루트 노드를 리턴
*/

/*
	1 <- 3 <- 4 <- 2일 경우
	parent[1] = 1	parent[2] = 4
	parent[3] = 1	parent[4] = 3

	parent[2] = Find(4) -> parent[4] = Find(3) -> parent[3] = Find(1) -> parent[1] == 1이므로 x값 1 반환
	결국 parent[1] ~ parent[4]는 Find 함수에서의 대입으로 모두 루트 노드인 1 값을 가지게 됨
*/
int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	//매개변수 각각의 루트 노드를 a와 b에 담음
	a = Find(a);
	b = Find(b);
	if (a != b) parent[b] = a;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0)
			Union(b, c);
		else {
			//sameParent(int b, int c) -> 같은 공통조상을 가질 경우 최소 공통부모가 존재하므로 확인
			//
			b = Find(b);
			c = Find(c);
			if (b == c)
				cout << "YES\n";
			else
				cout << "NO\n";
			//
		}
	}
	return 0;
}