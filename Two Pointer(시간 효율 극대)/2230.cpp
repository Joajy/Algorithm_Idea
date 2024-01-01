#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[100001];

int main() {
	fast;
	int n, m, ans = 2000000000;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
    int s = 0, e = 0;
    while(e < n){
        int val = a[e] - a[s];
        if(val < m){
            ++e;
            continue;
        }
        if(val == m){
            cout << m;
            return 0;
        }
        if(ans > val){
            ans = val;
        }
        ++s;
    }
	cout << ans;
}
