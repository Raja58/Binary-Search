// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Nov 2021
//  @Detail  :        Most Profit Assigning Work (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getLowerBound(int x, vector<int> &workers)
    {
        int low = 0, high = workers.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(workers[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        int n = profit.size();
        vector<pair<int,int>> input(n);
        for(int i = 0; i < n; i++)
            input[i] = {difficulty[i], profit[i]};
        
        sort(input.begin(), input.end(), [](pair<int, int> &x, pair<int, int> &y) {return x.second < y.second;});
        sort(workers.begin(), workers.end());
        
        int endIdx = workers.size(), result = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            int idx = getLowerBound(input[i].first, workers);
            if(idx >= endIdx)
                continue;
            result += input[i].second * (endIdx - idx);
            endIdx = idx;
          
            if(endIdx == 0)
                return result;
        }
        return result;
    }
};
