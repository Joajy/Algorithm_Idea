#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXNAME 20000

bool cmp(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}
/*
    vector 원소들을 중복 없이 정렬하는 방법
    
    우선 정렬을 한 후에 중복된 값을 확인하여 해당 중복값들을 제거

    vector<T> v
    sort(v.begin(), v.end())
    v.erase(  unique(v.begin(), v.end()) ,v.end()  )

    ex) 벡터 원소가  {1, 1, 2, 2, 3, 3, 4, 5} 일 때,
        sort 후에는  {1, 1, 2, 2, 3, 3, 4, 5} 가 되며 -> 중복값 관계없이 정렬
        unique 뒤엔  {1, 2, 3, 4, 5, 1, 2, 3} 이 되어 중복값이 뒤쪽으로 나열된다.
        즉, unique는 중복없이 나열된 마지막 원소 바로 다음의 iterator
*/
int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int t, n;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        cin >> n;
        string name;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            cin >> name;
            v.push_back(name);
        }
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << "#" << z << '\n';
        for (auto i : v)
            cout << i << '\n';
    }
    return 0;
}