#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v;
    int rs = 0, cs = 0, re = m, ce = n;
    int k = 0;
    int direction = 0;
    while (rs<re&&cs<ce)
    {

        if (direction == 0)
        {
            for (int i = cs; i < ce  ; i++)
            {
                v.push_back(matrix[rs][i]);
            }
            rs++;
        }
        else if (direction == 1)
        {

            for (int i = rs; i < re ; i++)
            {
                v.push_back(matrix[i][ce - 1]);
            }
            ce--;
        }
        else if (direction == 2)
        {

            for (int i = ce - 1; i >= cs; i--)
            {
                v.push_back(matrix[re - 1][i]);
            }
            re--;
        }
        else
        {
            for (int i = re - 1; i >= rs; i--)
            {
                v.push_back(matrix[i][cs]);
            }
            cs++;
        }
        direction++;
        direction=direction%4;
        
    }
    // v.push_back(k);
    return v;
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
