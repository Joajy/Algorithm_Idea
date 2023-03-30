#include<iostream>
#include<cstring>
using namespace std;

int dp[30][30];
/*
	Combination with Dynamic Programming
	DP�� �̿��� ���չ��� Ǯ��

	Memoization ���
	�Ǻ���ġ�� ����� ������� ��͸� �ۼ��ϵ�, �κ� ������ ���� �迭�� �޾Ƶ鿩 �ߺ� ����� �ּ�ȭ�Ѵ�.
	-1�� �ʱ�ȭ�� �� ���ǿ� ���� ���� ��ȯ�Ѵ�.

	nCr ����
	1. ���� n == r �̰ų� r == 0�̸� 1���� ��ȯ
	2. �̿ܿ� -1(�ʱ� ��)�� �ƴ� ��� �ش� �迭 ��ġ������ �� ��ȯ
	3. �Ľ�Į�� �ﰢ�� �������� n, r ��ġ�� �迭�� �� ����
*/
int C(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (dp[n][r] != -1)
		return dp[n][r];
	return dp[n][r] = C(n - 1, r) + C(n - 1, r - 1);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t, a, b;
	cin >> t;
	memset(dp, -1, sizeof(dp));
	while (t--) {
		cin >> a >> b;
		cout << C(b, a) << '\n';
	}
	return 0;
}