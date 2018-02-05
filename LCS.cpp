#include<bits/stdc++.h>
using namespace std;

string ans;

int dp[1009][1009];

int LCS(string a, string b){
    int i, j, len1, len2;

    len1 = a.size();
    len2 = b.size();

    for(i = 1; i <= len1; i++){
        for(j = 1; j <= len2; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    /*for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return dp[len1][len2];
}

void LCS_String(string a, string b, int i, int j){
    if(min(i, j) < 1)
        return;
    else if(a[i - 1] == b[j - 1]){
        ans += a[i - 1];
        LCS_String(a, b, i - 1, j - 1);
    }
    else{
        if(dp[i - 1][j] > dp[i][j - 1])
            LCS_String(a, b, i - 1, j);
        else
            LCS_String(a, b, i, j - 1);
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string a, b;

    while(getline(cin, a)){
        getline(cin, b);
        ans = "";
        cout << "LCS of "<< a << " and " << b <<" is = " << LCS(a, b) << endl;
        //cout << LCS(a, b) << endl;
        LCS_String(a, b, a.size(), b.size());
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
