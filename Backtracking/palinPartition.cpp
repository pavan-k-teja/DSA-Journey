#include<bits/stdc++.h>
using namespace std;

bool isPalin(string str)
{
    int s=0, e=str.size()-1;
    while(s<e)
    {
        if(str[s]!=str[e])
            return false;
        s++; e--;
    }
    return true;
}

void palinPartition(string ip, int idx, string op)
{
    if(idx == ip.size())
    {
        cout<<op<<"\n";
        return;
    }

    for(int i=idx;i<ip.size();i++)
    {
        string left = ip.substr(idx, i-idx+1);

        if(isPalin(left))
        {
            string output = op + left + ' ';
            string right = ip.substr(i+1);
            palinPartition(ip, i+1, output);
        }
    }

}

int main()
{
    
    string input = "geeks";
    string res="";
    palinPartition(input, 0, res);


    return 0;
}