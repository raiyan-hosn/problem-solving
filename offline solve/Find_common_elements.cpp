#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void findCommonElements(vi &a, vi &b, vi &c)
{
    vi v;
    int i, j, k;
    i = j = k = 0;
  
    for (i = 0; i < a.size(); i++)
    {

        while (i+1 < a.size() && a[i] == a[i + 1])
            i++;

        while(j<b.size()&& b[j]<=a[i])
            j++;
        while(k<c.size() && c[k]<=a[i])
            k++;
        if(j>0&&k>0&&a[i]==b[j-1]&&a[i]==c[k-1]){
            printf("%d ",a[i]);
        }
    }
    printf("\n");
}
int main()
{
    vi a = {1, 5, 10, 20, 40, 80};
    vi b = {6, 7, 20, 80, 100};
    vi c = {20,80};
    findCommonElements(a, b, c);
}