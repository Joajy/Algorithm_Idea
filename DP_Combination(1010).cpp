#include<iostream>
#include<cstring>
using namespace std;

int dp[30][30];
/*
	Combination with Dynamic Programming
	DP를 이용한 조합문제 풀기

	Memoization 방식
	피보나치와 비슷한 방식으로 재귀를 작성하되, 부분 문제의 값을 배열로 받아들여 중복 계산을 최소화한다.
	-1로 초기화한 후 조건에 따라 값을 반환한다.

	nCr 기준
	1. 만약 n == r 이거나 r == 0이면 1값을 반환
	2. 이외에 -1(초기 값)이 아닐 경우 해당 배열 위치에서의 값 반환
	3. 파스칼의 삼각형 공식으로 n, r 위치의 배열에 값 대입
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