#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    scanf("%d",&n);
    int ara[n];
    int sum=0;
    int minimul=INT_MAX;
    for(int i=0;i<n;i++){
        scanf("%d",&ara[i]);
        sum+=ara[i];
    }
    for(int mask=0;mask<1<<n;mask++){
        int pile1=0,pile2;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                pile1+=ara[i];
            }
        }
        pile2=sum-pile1;
        minimul=min(minimul,abs(pile1-pile2));
    }
    printf("%d\n",minimul);
}