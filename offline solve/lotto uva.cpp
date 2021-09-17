#include<bits/stdc++.h>
using namespace std;
int ara[15],k;
int p[6];

void prnt()
{
    printf("%d",p[0]);
    for(int i=1;i<6;i++)
        printf(" %d",p[i]);
    printf("\n");
}
void f(int idx,int i)
{
    if(idx==6){
        prnt();
        return;
    }
    for(int j=i;j<k;j++){
        p[idx]=ara[j];
        f(idx+1,j+1);
    }
}

int main(void)
{
//    freopen("i.txt","r",stdin);
    int tc=1;
    while(scanf("%d",&k)&&k){
        if(tc!=1)
            printf("\n");
        for(int i=0;i<k;i++)
            scanf("%d",&ara[i]);
        f(0,0);
        tc++;
    }
    return 0;
}
