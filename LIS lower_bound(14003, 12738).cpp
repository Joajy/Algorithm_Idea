#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	LIS(Longest Increasing Sequence)
	최장 증가 부분 수열

	LCS와의 차이점 :
	LCS : 최장 "공통" 부분 수열
	LIS : 최장 "증가" 부분 수열 -> 연속되지 않은 부분수열이라도 상관이 없다.

	O(N^2)의 시간복잡도를 가지는 것이 기본적이며,
	이분 탐색을 사용 시 O(N*lgN)으로 줄이는 것이 가능하다.(벡터와 lower_bound 사용)
*/
//https://www.acmicpc.net/problem/14003
#define MAXSIZE 1'000'001

int a[MAXSIZE], dp[MAXSIZE];
vector<int> v, ans;
int n, cnt = 0;

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    v.push_back(a[1]);

    for (int i = 2; i <= n; i++) {
        if (a[i] > v[cnt]) {
            v.push_back(a[i]);
            dp[i] = ++cnt;
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
            dp[i] = idx;
        }
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] == cnt) {
            ans.push_back(a[i]);
            cnt--;
        }
    }

    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << ans.back() << " ";
        ans.pop_back();
    }
    return 0;
}
/*
int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, a;
	vector<int> v{ -1 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > v.back())				//v.end보다 v.back을 통해 값을 찾는 것이 에러 발생 적음
			v.push_back(a);
		else {
			//*lower_bound(v.begin(), v.end(), a) = a;
		//입력 값보다 같거나 큰 수의 인덱스를 찾아, 해당 인덱스의 값을 더 작은 값(a)로 변환
		int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
		v[idx] = a;
		}
	}
	cout << v.size() - 1;
	return 0;
}
*/