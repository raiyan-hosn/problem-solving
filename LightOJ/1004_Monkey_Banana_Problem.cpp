//Alhamdulillah
#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vv;
void prnt(vv &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
}
int findBest(vv &v,vv &best,int row,int col,bool mood){//mood=true for upper half and false for lower half
    if(best[row][col]!=-1)
        return best[row][col];
    
    if(v[row][col]==0)
        return 0;

    if(!mood){
        best[row][col]=max(findBest(v,best,row+1,col-1,mood), findBest(v,best,row+1,col,mood))+v[row][col];
    }
    else{
        best[row][col]=max(findBest(v,best,row+1,col,mood), findBest(v,best,row+1,col+1,mood))+v[row][col];
    }
//    printf("row %d col %d val=%d\n",row,col,best[row][col]);
    return best[row][col];
}
int main(void)
{
//    freopen("i.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        vector<int>temp(n+1,0);
        vv v(n*2+1,temp);
        for(int i=1;i<=n;i++){
            for(int j =1;j<=i;j++){
                scanf("%d",&v[i][j]);
            }
        }
        for(int i=n+1,k=n;i<n*2;i++,k--){
            for(int j=1;j<k;j++){
                scanf("%d",&v[i][j]);
            }
        }
        fill(temp.begin(),temp.end(),-1);
        vv best(n*2+1,temp);
        for(int i=1;i<=n;i++){
            findBest(v,best,n,i,false);
        }
        findBest(v,best,1,1,true);
        //prnt(best);
        printf("Case %d: %d\n",t,best[1][1]);
    }
}