// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Jul 2021
//  @Detail  :        all palindrome partitions
//  ============================
//  -->
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPalindrome(string &x)
{
    int i = 0, j = x.size() - 1;
    while(i < j)
    {
        if(x[i] != x[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void getPali(string &str, int idx, vector<string> current, vector<vector<string>> &result)
{
    if(idx == str.size())
    {
        result.push_back(current);
        return;
    }
    
    for(int i = idx; i < str.size(); i++)
    {
        string temp = str.substr(idx, i - idx + 1);
        if(isPalindrome(temp))
        {
            current.push_back(temp);
            getPali(str, i + 1, current, result);
            current.pop_back();
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        vector<vector<string>> result;
        vector<string> current;
        getPali(str, 0, current, result);
        for(vector<string> &x : result)
        {
            for(string &y : x)
                cout<<y<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}