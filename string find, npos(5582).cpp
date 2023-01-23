//https://www.acmicpc.net/problem/5582
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/*
    ã�� ���ڿ�(strtmp)�� ���� ��� npos�� ��ȯ�ȴ�.
    string str
    
    str.find(strcmp) -> return string::npos

    1. ���� ã�� ���ڰ� ���� ��� �ٸ�
    str.find(strtmp) != string::npos

    2.���� ã�� ���ڰ� ���� ��� npos �߻�
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