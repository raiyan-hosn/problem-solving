#include<bits/stdc++.h>
using namespace std;
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int w,h,n;
    while(scanf("%d %d %d",&w,&h,&n)&&w!=0){
        int x1,x2,y1,y2;
        bool ara[w+2][h+2];
        for(int i=1;i<=w;i++)
            for(int j=1;j<=h;j++)
                ara[i][j]=0;
        int cnt=0;
        while(n--){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x2<x1)
                swap(x1,x2);
            if(y2<y1)
                swap(y1,y2);
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    if(ara[i][j]==0){
                        ara[i][j]=1;
                        cnt++;
                    }
                }
            }
        }
        if(cnt==w*h)
            printf("There is no empty spots.\n");
        else if(w*h-cnt==1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n",w*h-cnt);
    }
    return 0;
}
