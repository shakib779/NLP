#include<bits/stdc++.h>
using namespace std;

string ans1, ans2;

int dp[1009][1009];

void ff(int n){
    if(n < 0 && n > -10){
        cout << " " << n;
    }
    else if(n < -9){
        cout << n;
    }
    else if(n >= 0 && n < 10)
        cout << "  " << n;
    else if(n > 9){
        cout << " " << n;
    }
    return;
}

int score(char c, char d){
    if(c != d)
        return -1;
    else
        return 5;
}

int solve(string a, string b){
    int i, j, len1, len2;

    len1 = a.size();
    len2 = b.size();

    for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++){
            if(min(i, j) == 0){
                dp[i][j] = -2*max(i, j);
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1] + score(a[i - 1], b[j - 1]), max(dp[i][j - 1], dp[i - 1][j]) - 2);
            }
        }
    }

    for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++){
                ff(dp[i][j]);
                cout << " ";
        }
        cout << endl;
    }

    return dp[len1][len2];
}

void solve_string(string a, string b, int i, int j){
    if(min(i, j) < 1)
        return;
    else if(dp[i][j] == dp[i - 1][j - 1] + 5 && a[i - 1] == b[j - 1]){
        ans1 += a[i - 1];
        ans2 += b[j - 1];
        solve_string(a, b, i - 1, j - 1);
    }
    else if(dp[i][j] == dp[i][j - 1] - 2){
        ans1 += a[i - 1];
        ans2 += "-";
        solve_string(a, b, i, j - 1);
    }
    else if(dp[i][j] == dp[i - 1][j] - 2){
        ans1 += "-";
        ans2 += b[j - 1];
        solve_string(a, b, i - 1, j);
    }
}

/**

AGTCG
ATCCG


*/
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string a, b;

    while(getline(cin, a)){
        getline(cin, b);
        ans1 = "", ans2 = "";
        cout << "LCS of "<< a << " and " << b <<" is = " << solve(a, b) << endl;
        //cout << LCS(a, b) << endl;
        solve_string(a, b, a.size(), b.size());
        reverse(ans1.begin(), ans1.end());
        reverse(ans2.begin(), ans2.end());
        cout << ans1 << endl;
        cout << ans2 << endl;
    }
    return 0;
}
