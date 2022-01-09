// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Jan 2022
//  @Detail  :        N-th Fibonacci Number (CodeStudio)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define mod (int)(1e9+7)

vector<vector<int>> multiply(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    vector<vector<int>> mat(2, vector<int>(2));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                mat[i][j] = (mat[i][j] + ((long long)mat1[i][k] * mat2[k][j]) % mod) % mod;
    return mat;
}

int fibonacciNumber(int n){
    if(n <= 2)
        return 1;
  
    int pow = n - 1;
    vector<vector<int>> mat{{1, 1}, {1, 0}}, result{{1, 0}, {0, 1}};
    
    while(pow)
    {
        if(pow & 1)
        {
            result = multiply(result, mat);
            pow--;
        }
        else
        {
            mat = multiply(mat, mat);
            pow /= 2;
        }
    }
    return result[0][0];
}
