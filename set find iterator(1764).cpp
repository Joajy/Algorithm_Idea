#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

string v[500001];

/*
    set이나 map STL 기준
    find를 통해 얻어온 iter는 포인터로 반환된다.
    set<T> s

    auto iter = s.find(str) -> return tree class

    **** s.end() -> EOF와 유사하되, 건드려선 안 되는 포인터 ****

    1.만약 찾는 문자가 있을 경우, .end()에 도달하지 않으므로 결과 획득
    iter != s.end()

    2.만약 찾는 문자를 발견 못할 경우, .end()에 도달
    * 별도의 행동을 취하지 않음 *
*/

int main() {
    fast;
    int n, m, cnt = 0;
    cin >> n >> m;
    string tmp;
    set<string> t;
    for (int i = 0; i < max(n, m); i++) {
        cin >> tmp;
        t.insert(tmp);
    }
    for (int i = 0; i < min(n, m); i++) {
        cin >> tmp;
        auto iter = t.find(tmp);
        if (iter != t.end())
            v[cnt++] = *iter;
    }
    sort(v, v + cnt);
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << v[i] << '\n';
    return 0;
}