#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	#include<algorithm>
	lower_bound, upper_bound	(이진 탐색)

	lower_bound(v.begin(), v.end(), key) - v.begin()		//vector<int> v
	lower_bound(arr, arr + 6, 6) - arr						//arr[6]
	
	찾으려는 key 값보다
	"같거나 큰 수"에 대한	 "최초의" 인덱스를 찾기 위함

	upper_bound(v.begin(), v.end(), key) - v.begin()		//vector<int> v
	upper_bound(arr, arr + 6, 6) - arr						//arr[6]

	찾으려는 key 값을 
	*"초과하는 최초의"*		 인덱스를 찾기 위함

*/

int x[100001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++)
		cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << ' ';
	return 0;
}