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
    vector ���ҵ��� �ߺ� ���� �����ϴ� ���
    
    �켱 ������ �� �Ŀ� �ߺ��� ���� Ȯ���Ͽ� �ش� �ߺ������� ����

    vector<T> v
    sort(v.begin(), v.end())
    v.erase(  unique(v.begin(), v.end()) ,v.end()  )

    ex) ���� ���Ұ�  {1, 1, 2, 2, 3, 3, 4, 5} �� ��,
        sort �Ŀ���  {1, 1, 2, 2, 3, 3, 4, 5} �� �Ǹ� -> �ߺ��� ������� ����
        unique �ڿ�  {1, 2, 3, 4, 5, 1, 2, 3} �� �Ǿ� �ߺ����� �������� �����ȴ�.
        ��, unique�� �ߺ����� ������ ������ ���� �ٷ� ������ iterator
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