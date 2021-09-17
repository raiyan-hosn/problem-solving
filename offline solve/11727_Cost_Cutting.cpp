//alhamdulillah

#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int ara[3];
        scanf("%d %d %d",&ara[0],&ara[1],&ara[2]);
        sort(ara,ara+3);
        printf("Case %d: %d\n",t,ara[1]);
    }
}