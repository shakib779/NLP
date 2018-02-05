#include<bits/stdc++.h>
using namespace std;

int dp[1009][1009];

int dev(string a, string b){
    int i, j, len1, len2;
    len1 = a.size();
    len2 = b.size();
    for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++){
            if(min(i, j) == 0){
                dp[i][j] = (i == 0)?j:i;
            }
            else if(min(i, j) > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]){
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, min(dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]), dp[i - 2][j - 2] + 1)));
            }
            else{
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])));
            }
        }
    }

   /* for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return dp[len1][len2];
}

int main(){
    string a, b;
    while(cin >> a >> b){
        cout << "Damerau–Levenshtein distance is = " << dev(a, b) << endl;
    }
    return 0;
}
