#include<iostream>
#include<set>
#include<string>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

/*
    multiset�̳� multimap STL ����
    find�� ���� ���� iter�� �����ͷ� ��ȯ�ȴ�.
    multiset<T> s

    auto iter = s.find(str) -> return tree class
    s.erase(it) -> �ش� �κи� ����(���� ���� �ִ��� �ش� �����͸� �����ϹǷ� �� �ϳ��� ������)
    
    ����, s[0] = 7, s[1] = 7�� ��� iter�� s[0]�� ����Ų�ٰ� �غ���.
    �� �� s.erase(iter)�� ���� s[0]�� ���� erase�ϴ��� s[1] = 7 �̶�� ������ �ڷᱸ���� �����ְ� �ȴ�.
*/

/*
    prev�� ���� end�Լ��� ���� ������ ���� ������ �� ����(rbegin���� ����)
    cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
*/

int main() {
    fast;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        multiset<int> s;
        int k;
        cin >> k; cin.get();
        while (k--) {
            string cmd;
            getline(cin, cmd);
            if (cmd[0] == 'I')
                s.insert(stoi(cmd.substr(2, cmd.length() - 2)));
            else if (cmd == "D 1") {
                if (!s.empty()) {
                    auto it = s.find(*s.rbegin());
                    s.erase(it);
                }
            }
            else if (cmd == "D -1") {
                if (!s.empty())
                    s.erase(s.begin());
            }
        }
        if (s.empty())
            cout << "EMPTY\n";
        else
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
          //cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
    return 0;
}