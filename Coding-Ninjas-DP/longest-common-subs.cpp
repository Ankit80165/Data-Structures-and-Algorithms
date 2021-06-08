#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t) {
    //Write your code here
    int m = s.size(), n = t.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
// space efficeinet method
int lcsSpaceEfficeint(string s, string t) {
    // s goes on to the col
    int m = s.size();
    int dp[2][m + 1];
    for (int i = 0; i < m + 1; i++) {
        dp[0][i] = 0;
    }
    dp[1][0] = 0;
    int row = 1;
    for (int i = 0; i < t.size(); i++) {

        for (int j = 0; j < s.size(); j++) {

            if (row == 1) {
                if (t[i] == s[j]) {
                    dp[1][j + 1] = dp[0][j] + 1;
                } else {
                    dp[1][j + 1] = max(dp[1][j], dp[0][j + 1]);
                }
            } else {
                if (t[i] == s[j]) {
                    dp[0][j + 1] = dp[1][j] + 1;
                } else {
                    dp[0][j + 1] = max(dp[1][j + 1], dp[0][j]);
                }
            }
        }
        row = 1 - row;
        // for (int i = 0; i < 2; i++) {
        //     for (int j = 0; j < m + 1; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    int ans;
    if (t.size() % 2 == 1) {
        ans = dp[1][m];
    } else {
        ans = dp[0][m];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s, t;
    cin >> s >> t;
    int ans = lcsSpaceEfficeint(s, t);
    cout << ans << endl;
    return 0;
}