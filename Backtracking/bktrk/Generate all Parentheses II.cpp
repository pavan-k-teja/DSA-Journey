#include<bits/stdc++.h>
using namespace std;

#define pb push_back
void compute( string str, int low, int high, int n, vector <string> &ans ){
    if( low > n ) return;
    if( low == n && high == n ) ans.pb(str);
    else{
        compute( str + "(", low + 1, high, n, ans );
        if( low > high ) compute( str + ")", low, high + 1, n, ans );
    }
}

vector<string> generateParenthesis(int n) {
    vector <string> ans;
    compute( "", 0, 0, n, ans );
    return ans;
}


int main()
{

    

    return 0;
}