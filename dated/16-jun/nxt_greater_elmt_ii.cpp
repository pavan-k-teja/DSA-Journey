// 496. Next Greater Element I
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int> s;
        int len = nums.size();
        
        for(int i=len-2;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            
            s.push(nums[i]);
        }
        
        vector<int> ans(len, -1);
        for(int i=len-1; i>=0; i--)
        {
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            
            ans[i] = s.empty()? -1: s.top();
            
            s.push(nums[i]);
        }
        return ans;
        
    }
};

int main()
{
    vector<int> nums{3,8,4,1,2};
    Solution obj;
    vector<int> ans = obj.nextGreaterElements(nums);
    for(auto i : nums)
        cout<< i<<" ";
}