#include<iostream>
#include<algorithm>
using namespace std;

int lcs[1001][1001];

/*
	���� �� ���� �κй��ڿ� ã��
	LCS : Longest Common Sequence

	dp �Է� �κ��� O(NM)���� ��¿ �� ���� �κ��̹Ƿ� ���ڿ� ã�� �ܰ迡�� ����ȭ �ʿ�
	-> dp �� ���� ���� Ȯ�� �� �ڿ������� ���� ���ڿ� �޾ƿͼ� reverse �� �� �Ŀ� ����ϸ� ��

*/

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	string x, y, answer;
	cin >> x >> y;
	int m = x.length(), n = y.length();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}
	int xlen = m, ylen = n;
	while (m > 0 && n > 0) {
		if (lcs[m][n] == lcs[m - 1][n])
			m--;
		else if (lcs[m][n] == lcs[m][n - 1])
			n--;
		else {
			answer += x[m - 1];
			n--;
			m--;
		}
	}
	reverse(answer.begin(), answer.end());
	cout << lcs[xlen][ylen] << '\n' << answer;
	return 0;
}