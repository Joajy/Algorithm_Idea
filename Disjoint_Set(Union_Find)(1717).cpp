#include<iostream>
using namespace std;
//https://www.acmicpc.net/problem/1717

int parent[1000001];
/*
	Disjoint Set(Union Find)
	Union �Լ��� Find �Լ��� �����ϰ� �ۼ��Ͽ� �и� ���� ���� �ذ� ����
	(�ʱ�ȭ�� parent[i] = i �ݺ���)

	Union : ���� ���μ� ������ �� ��Ʈ�� Ȯ���ϰ�, �ش� ��Ʈ�� ������ ��Ʈ�� �ƴ� ��� ���Ƿ� �ϳ��� ��Ʈ�� �ٸ� ��Ʈ�� �θ� ��尡 �ȴ�.

	Find : parent[x] == x(x�� ��Ʈ ����� ���)�̸� ��Ʈ ����� x�� ����
		   ��Ʈ ��尡 �ƴ϶�� ��� �Լ��� �ڽ� ��忡�� �θ� ���� �ö󰡸� ��Ʈ ��带 ����
*/

/*
	1 <- 3 <- 4 <- 2�� ���
	parent[1] = 1	parent[2] = 4
	parent[3] = 1	parent[4] = 3

	parent[2] = Find(4) -> parent[4] = Find(3) -> parent[3] = Find(1) -> parent[1] == 1�̹Ƿ� x�� 1 ��ȯ
	�ᱹ parent[1] ~ parent[4]�� Find �Լ������� �������� ��� ��Ʈ ����� 1 ���� ������ ��
*/
int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	//�Ű����� ������ ��Ʈ ��带 a�� b�� ����
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
			//sameParent(int b, int c) -> ���� ���������� ���� ��� �ּ� ����θ� �����ϹǷ� Ȯ��
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