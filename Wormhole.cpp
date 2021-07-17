// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Jul 2021
//  @Detail  :        wormhole (CodeChef)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;

struct detail{
  int start;
  int finish;
};

int main() {
    int n, x, y;
    cin>>n>>x>>y;
    vector<detail> input(n);
    for(int i = 0; i < n; i++)
    {
        cin>>input[i].start;
        cin>>input[i].finish;
    }
    vector<int> entry(x), ext(y);
    for(int i = 0; i < x; i++)
        cin>>entry[i];
    for(int i =0; i < y; i++)
        cin>>ext[i];
    sort(entry.begin(), entry.end());
    sort(ext.begin(), ext.end());
    sort(input.begin(), input.end(), [](detail &a, detail &b){return (a.finish - a.start) < (b.finish - b.start);});
    
    int min_time = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        detail current = input[i];
        if(current.finish - current.start >= min_time)
            break;
        int entry_time = *(upper_bound(entry.begin(), entry.end(), current.start) - 1);
        int ext_time = *(lower_bound(ext.begin(), ext.end(), current.finish));
        if(ext_time > 0 && ext_time - entry_time + 1 < min_time)
            min_time = ext_time - entry_time + 1;
    }
    cout<<min_time;
	return 0;
}