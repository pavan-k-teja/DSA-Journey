#include<bits/stdc++.h>
using namespace std;

void wordBreak(string ip, int idx, string op, unordered_set<string> &us)
{
    // if()
    // {

    // }
    if(idx == ip.size())
    {
        cout<<op<<"\n";
        return;
    }

    for(int i=idx;i<ip.size();i++)
    {
        string left = ip.substr(idx, i-idx+1);

        if(us.find(left)!=us.end())
        {
            string output = op + left + ' ';
            string right = ip.substr(i+1);
            wordBreak(ip, i+1, output, us);
        }
    }

}

int main()
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    unordered_set<string> us;
    for(string s : dictionary)
        us.insert(s);
    
    string input = "iloveicecreamandmango";
    string res="";
    wordBreak(input, 0, res, us);


    return 0;
}