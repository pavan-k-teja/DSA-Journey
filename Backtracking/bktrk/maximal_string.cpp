#include<bits/stdc++.h>
using namespace std;

string ans;
int n;

void check(int i,string &str,int k)
{
    if(ans<str)
    ans=str;
    
    if(!k || i==n)
    return;
    
    check(i+1,str,k);

    for(int j=i+1;j<n;j++)
    {
        if(str[j]>str[i])
        {
            swap(str[j],str[i]); 
            check(i+1,str,k-1);
            swap(str[j],str[i]); 
        }
    }
}
string solve(string str, int k) 
{
    ans=str;
    n=str.length();
    
     check(0,str,k);
     return ans;
}



