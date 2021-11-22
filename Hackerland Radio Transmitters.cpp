// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Nov 2021
//  @Detail  :        Hackerland Radio Transmitters (HackerRank)
//  ============================
//  -->

int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(), x.end());
    int transPlaced = 0, i = 0;
    while(i < (int)x.size())
    {
        transPlaced++;
        i = upper_bound(x.begin() + i, x.end(), x[i] + k) - x.begin() - 1;
        i = upper_bound(x.begin() + i, x.end(), x[i] + k) - x.begin();
    }
    return transPlaced;
}
