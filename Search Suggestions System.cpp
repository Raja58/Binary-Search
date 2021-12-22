// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Dec 2021
//  @Detail  :        Search Suggestions System (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getLeft(int low, int high, int idx, string &searchWord, vector<string> &products)
    {
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(idx >= products[mid].size() || products[mid][idx] < searchWord[idx])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
    
    int getRight(int low, int high, int idx, string &searchWord, vector<string> &products)
    {
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(idx >= products[mid].size() || products[mid][idx] > searchWord[idx])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        int start = 0, end = products.size() - 1;
        
        for(int i = 0; i < searchWord.size(); i++)
        {
            start = getLeft(start, end, i, searchWord, products);
            if(start <= end)
                end = getRight(start, end, i, searchWord, products);
            if(start > end)
            {
                for(; i < searchWord.size(); i++)
                    result.push_back({});
                return result;
            }
            vector<string> temp;
            for(int j = start; j - start < 3 && j <= end; j++)
                temp.push_back(products[j]);
            result.push_back(temp);
        }
        return result;
    }
};
