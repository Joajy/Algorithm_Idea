#include<iostream>
#include<set>
#include<string>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

/*
    multiset이나 multimap STL 기준
    find를 통해 얻어온 iter는 포인터로 반환된다.
    multiset<T> s

    auto iter = s.find(str) -> return tree class
    s.erase(it) -> 해당 부분만 삭제(같은 값이 있더라도 해당 포인터만 삭제하므로 값 하나만 삭제됨)
    
    가령, s[0] = 7, s[1] = 7일 경우 iter가 s[0]을 가리킨다고 해보자.
    이 때 s.erase(iter)를 통해 s[0]의 값을 erase하더라도 s[1] = 7 이라는 정보는 자료구조에 남아있게 된다.
*/

/*
    prev를 통해 end함수를 쓰고도 마지막 값을 추출할 수 있음(rbegin사용과 유사)
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