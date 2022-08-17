#include<bits/stdc++.h>
using namespace std;



bool patStr(string str, string pat, unordered_map<char, string> &umap)
{
    if(pat=="" && str=="")
        return true;
    
    if(pat=="" || str=="")
        return false;

    char currChar = pat[0];
    string remPat = (pat.size()<=1) ? "" : pat.substr(1);

    if(umap[currChar]!="")
    {
        string temp_str = umap[currChar];

        string left = str.substr(0, temp_str.size());
        string right = (str.size()<=temp_str.size()) ? "" : str.substr(temp_str.size());

        if(temp_str != left)
            return 0;

        return patStr(right, remPat, umap);
    }
    else
    {
        for(int i=0;i<str.size();i++)
        {
            string left = str.substr(0, i+1);
            string right = (str.size()<=i+1) ? "" : str.substr(i+1);
            umap[currChar] = left;
            if(patStr(right, remPat, umap))
                return true;
            umap[currChar] = "";
        }
    }

    return false;
}


int main()
{
    string str;
    string pat;
    cin>>str>>pat;

    unordered_map<char, string>  umap;
    for(char& c : pat)
        umap[c]="";
    
    patStr(str, pat, umap);

    for(char& c : pat)
        if(umap[c]=="")
        {
            cout<<"No Solution\n";
            return 0;
        }

    for(auto& ele: umap)
    {
        cout<<ele.first<<" -> "<<ele.second<<"\n";
    }


    return 0;
}