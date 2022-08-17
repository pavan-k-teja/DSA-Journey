// Q: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans ;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-3;i++)
        {
            if(i!=0 && nums[i-1]==nums[i])
                continue;
            for(int j=i+1; j<n-2;j++)
            {
                if(j!=(i+1) && nums[j-1]==nums[j])
                    continue;
                int low = j+1, high = n-1;
                
                while(low<high)
                {
                    long lhs = (long long)nums[i] + (long long)nums[j] + (long long)nums[low] + (long long)nums[high];
                    if(lhs == (long long)target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        
                        while(low<high && nums[low] == nums[low+1]) low++;
                        while(low<high && nums[high] == nums[high-1]) high--;
                        low++; high--;
                    }
                    else if (lhs < (long long)target) low++;
                    else high--;
                }
            }
        }
        return ans;
    }
};