#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

void spiralOrder(vector<vector<int>> &matrix)
{
    
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
