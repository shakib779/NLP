#include<bits/stdc++.h>
using namespace std;

int ham(string a, string b){
    int i, len, cnt = -1;
    len = a.size();
    if(len != b.size()){
        cout << "String length is not equal" << endl;
    }
    else{
        for(i = 0, cnt = 0; i < len; i++){
            if(a[i] != b[i]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    string a, b;
    while(cin >> a >> b){
        cout << "Hamming distance is = " << ham(a, b) << endl;
    }
    return 0;
}
