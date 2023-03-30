#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	LIS(Longest Increasing Sequence)
	���� ���� �κ� ����

	LCS���� ������ :
	LCS : ���� "����" �κ� ����
	LIS : ���� "����" �κ� ���� -> ���ӵ��� ���� �κм����̶� ����� ����.

	O(N^2)�� �ð����⵵�� ������ ���� �⺻���̸�,
	�̺� Ž���� ��� �� O(N*lgN)���� ���̴� ���� �����ϴ�.(���Ϳ� lower_bound ���)
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
		if (a > v.back())				//v.end���� v.back�� ���� ���� ã�� ���� ���� �߻� ����
			v.push_back(a);
		else {
			//*lower_bound(v.begin(), v.end(), a) = a;
		//�Է� ������ ���ų� ū ���� �ε����� ã��, �ش� �ε����� ���� �� ���� ��(a)�� ��ȯ
		int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
		v[idx] = a;
		}
	}
	cout << v.size() - 1;
	return 0;
}
*/