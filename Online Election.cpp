// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Online Election (LeetCode)
//  ============================
//  -->

class TopVotedCandidate {
public:
    
    vector<int> result, time;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), maxi = 0, winner = -1;
        vector<int> votes(n), res(n);
        
        for(int i = 0; i < n; i++)
        {
            votes[persons[i]]++;
            if(maxi <= votes[persons[i]])
            {
                maxi = votes[persons[i]];
                winner = persons[i];
            }
            res[i] = winner;
        }
        result = res;
        time = times;
    }
    
    int q(int t) {
        int idx = lower_bound(time.begin(), time.end(), t) - time.begin();
        if(idx == time.size())
            return result.back();
        if(time[idx] == t)
            return result[idx];
        return result[idx - 1];
    }
};
