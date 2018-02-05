#include<bits/stdc++.h>
using namespace std;

double jac(string a, string b){
    int i, len1, len2, cnt = -1;
    set <char> s, t;
    len1 = a.size();
    len2 = b.size();
    int m[200];
    memset(m, 0, sizeof(m));

    for(i = 0; i < len1; i++){
        s.insert(a[i]);
        m[a[i]]++;
    }
    for(i = 0; i < len2; i++){
        s.insert(b[i]);
        m[b[i]]++;
    }

    for(i = 0; i < 200; i++){
        if(m[i] == 2){
            t.insert(i);
        }
    }

    double v = (t.size()*1.0)/(s.size()*1.0);

    return 1.0 - v;
}

int main(){
    string a, b;
    while(cin >> a >> b){
        cout << "Jaccard distance is = " << jac(a, b) << endl;
    }
    return 0;
}
