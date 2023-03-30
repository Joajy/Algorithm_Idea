#include<iostream>
#include<algorithm>
using namespace std;

int lcs[1001][1001];

/*
	가장 긴 공통 부분문자열 찾기
	LCS : Longest Common Sequence

	dp 입력 부분은 O(NM)으로 어쩔 수 없는 부분이므로 문자열 찾는 단계에서 최적화 필요
	-> dp 값 동등 여부 확인 후 뒤에서부터 공통 문자열 받아와서 reverse 해 준 후에 출력하면 끝

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