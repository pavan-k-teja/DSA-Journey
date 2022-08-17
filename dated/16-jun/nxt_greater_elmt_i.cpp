// 496. Next Greater Element I
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& query, vector<int>& nums)
    {
        stack<int> s;
        unordered_map<int, int> umap;
        for(int i=nums.size()-1; i>=0; i--)
        {
            while(!s.empty() && s.top()<= nums[i])
                s.pop();
            // if(s.empty())
            //     umap[nums[i]] = -1;
            // else
            //     umap[nums[i]] = s.top();

            umap[nums[i]] = (s.empty()? -1 : s.top());
            
            s.push(nums[i]);
        } 

        vector<int> ans;
        for(auto i: query)
            ans.push_back(umap[i]);
        
        return ans;
    }
};