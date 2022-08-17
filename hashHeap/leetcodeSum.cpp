#include<bits/stdc++.h>
using namespace std;

// 2 sum

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if(um.find(num) != um.end())
                return {um[num], i};
            
            um.insert({target - num, i});
        }
        return {-1, -1};
    }

// 3 sum

// 4 sum




int main()
{

    

    return 0;
}