// Q: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int n = nums.size();
        for(int i=0;i<(n-2);i++)
        {
            if(i!=0 && nums[i-1]==nums[i])
                continue;
            int low=i+1, high=nums.size()-1;
            
            while(low < high)
            {
                if(nums[i] + nums[low] + nums[high] == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);
                    
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;
                    
                    low++; high--;
                }
                else if(nums[i] + nums[low] + nums[high] < 0) low++;
                else high--;
                
            }
            
        }
        return ans;
    }
};