//https://www.acmicpc.net/problem/5582
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/*
    찾는 문자열(strtmp)이 없을 경우 npos가 반환된다.
    string str
    
    str.find(strcmp) -> return string::npos

    1. 만약 찾는 문자가 있을 경우 다름
    str.find(strtmp) != string::npos

    2.만약 찾는 문자가 없을 경우 npos 발생
    str.find(strtmp) == string::npos
    
*/
int main() {
    string a, b, ans = "";
    cin >> a >> b;
    int dp[4001]{ 0 };
    int cnt = 0, answer = 0;
    //a < b
    if (a.length() > b.length()) swap(a, b);
    for (int i = 0; i < a.length(); i++) {
        if (b.find(a[i]) != string::npos) {
            ans += a[i];
            cnt = i;
            break;
        }
    }
    for (int i = cnt + 1; i < a.length(); i++) {
        ans += a[i];
        while (b.find(ans) == string::npos)
            ans = &ans[1];
        answer = max(answer, (int)ans.length());
        dp[i] = max(dp[i - 1], (int)ans.length());
    }
    cout << dp[a.length() - 1];
    return 0;
}