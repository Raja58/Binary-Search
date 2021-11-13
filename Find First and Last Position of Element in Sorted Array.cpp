// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        13 Nov 2021
//  @Detail  :        Find First and Last Position of Element in Sorted Array (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getRight(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
                
        }
        return high >=0 && high < nums.size() && nums[high] == target ? high : -1;
    }
    
    int getLeft(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low >=0 && low < nums.size() && nums[low] == target ? low : -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> {getLeft(nums, target), getRight(nums, target)};
    }
};
