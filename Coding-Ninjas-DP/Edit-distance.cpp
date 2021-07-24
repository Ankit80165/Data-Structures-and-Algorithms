#include <bits/stdc++.h>
using namespace std;
int editDistanceRec(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();
    if (s.size() == 0) {
        return t.size();
    }
    if (t.size() == 0) {
        return s.size();
    }
    if (s[0] == t[0]) {
        return 1 + editDistanceRec(s.substr(1, n1 - 1), t.substr(1, n2 - 1));
    } else {
        // insert
        int o1 = editDistanceRec(s, t.substr(1, n2 - 1));
        // remove
        int o2 = editDistanceRec(s.substr(1, n1 - 1), t);
        // replace
        int o3 = editDistanceRec(s.substr(1, n1 - 1), t.substr(1, n2 - 1));

        return min(o1, min(o2, o3));
    }
}
int editDistance(string str1, string str2) {
    //write you code here
    int n = str1.size();
    int m = str2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0) {
                dp[i][j] = j;
                continue;
            }
            else if (j == 0) {
                dp[i][j] = i;
                continue;
            }
            else {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
    }
    return dp[n][m];
}
int main(int argc, char const *argv[])
{
    /* code */
    string s, t;
    cin >> s >> t;
    int res = editDistance(s, t);
    cout << res << endl;
    return 0;
}