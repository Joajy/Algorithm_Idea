#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

string v[500001];

/*
    set�̳� map STL ����
    find�� ���� ���� iter�� �����ͷ� ��ȯ�ȴ�.
    set<T> s

    auto iter = s.find(str) -> return tree class

    **** s.end() -> EOF�� �����ϵ�, �ǵ���� �� �Ǵ� ������ ****

    1.���� ã�� ���ڰ� ���� ���, .end()�� �������� �����Ƿ� ��� ȹ��
    iter != s.end()

    2.���� ã�� ���ڸ� �߰� ���� ���, .end()�� ����
    * ������ �ൿ�� ������ ���� *
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