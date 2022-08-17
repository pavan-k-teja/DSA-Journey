#include<bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) 
{
    string ans="";
    k--;
    vector<int> nums(n);
    unsigned long fact = 1;
    for(int i=1;i<n;i++)
    {
        nums[i] = i+1;
        fact *= (unsigned long)i;
        
    }
    nums[0]=1;
    
    while(true)
    {
        int pos = (unsigned long )k/fact;
        if(pos >= nums.size())
            break;
        ans += to_string(nums[pos]);
        nums.erase(nums.begin()+pos);
        
        if(nums.empty())
            break;
        k %= fact;
        fact /= (unsigned long)nums.size();
    }
    
    return ans;
}


int main()
{

    

    return 0;
}