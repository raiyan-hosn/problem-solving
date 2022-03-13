#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vv;
typedef pair<int,int> pii;
#define mk make_pair

int dijkstra(vv &G,int n){

    pii source= mk(0,0);
    map<pii,int>distance;

    priority_queue< pair<int,pii> , vector<pair<int,pii>> >q;

    distance[mk(0,0)]=0;
    q.push(mk(0,mk(0,0))); //weight and then vertex

//    int loop=0;
    while(!q.empty()){
        source=q.top().second;
        q.pop();

//        loop++;
//        if(loop==20)break;

        pii neighbor= mk(source.first+1,source.second);

        if(distance[source]+G[neighbor.first][neighbor.second]
        >distance[neighbor] && G[neighbor.first][neighbor.second]!=0){

            distance[neighbor]=distance[source]+ G[neighbor.first][neighbor.second];
            q.push(mk(distance[neighbor],neighbor));

        }

        neighbor=mk(source.first+1,source.second+1);
         if(distance[source]+G[neighbor.first][neighbor.second]
        >distance[neighbor] && G[neighbor.first][neighbor.second]!=0){

            distance[neighbor]=distance[source]+ G[neighbor.first][neighbor.second];
            q.push(mk(distance[neighbor],neighbor));

        }


    }
    return distance[mk(n+(n-1)-1,n-1)] +G[0][0];

}
void prnt(vv &G){
    for(int i=0;i<G.size();i++){
        for(int j=0;j<G[i].size();j++){
            printf("%2d ",G[i][j]);
        }
        printf("\n");

    }
    printf("\n");
}
void prnt(vector<int> &v){
    for(int i=0;i<v.size();i++){
        printf("i=%d\n",i,v[i]);
    }
}
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        vector<int>temp(n+2,0);
        vv G(n*2,temp);

        for(int i=0;i<n;i++){

            for(int j=0;j<=i;j++){
                scanf("%d",&G[i][j]);
            }
        }
        for(int i=n,k=1;i<G.size();i++,k++){
            for(int j=k;j<n;j++){
                scanf("%d",&G[i][j]);
            }
        }

    printf("Case %d: %d\n",t,dijkstra(G,n));

    }
}
