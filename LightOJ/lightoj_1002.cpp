#include<bits/stdc++.h>
using namespace std;
int assign_lowest_weight(int val,int  pre_val){
    if(pre_val==0)return val;
    return min(val,pre_val);
}

vector<int> bfs(vector<vector<int>>&G, int source){
    int n=(int)G.size();
    vector<int> level(n,-1);
    level[source]=0;

     priority_queue<     pair<int,int>,   vector<   pair<int,int> >  ,greater<pair<int,int> >  >q;

    q.push(make_pair(0,source));


    while(!q.empty()){

        pair<int,int>new_source=q.top();
        q.pop();

        for(int i=0;i<n;i++){

                if(G[new_source.second][i]!=0){
                    if(level[i]==-1){
                        level[i]= max(level[new_source.second],G[new_source.second][i])  ;

                        q.push(make_pair(level[i],i));
                    }
                    else if(max(level[new_source.second],G[new_source.second][i])<level[i]){
                        level[i]= max(level[new_source.second],G[new_source.second][i])  ;
                        q.push(make_pair(level[i],i));
                    }
                }
        }
    }
    return level;
}

int main(void){

//	freopen("i.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int t=1;t<=tc;t++){
        int n,m;
        scanf("%d %d",&n,&m);

        vector<int>temp(n,0);
        vector<vector<int>>G(n,temp);
        int tm=m;
        while(m--){
                      int u,v,w;
                      scanf("%d %d %d",&u,&v,&w);

                      G[u][v]=assign_lowest_weight(w,G[u][v]);
                       G[v][u]=assign_lowest_weight(w,G[u][v]);
        }


        int source;
        scanf("%d",&source);
        printf("Case %d:\n",t);
         if(tm==0){
            for(int i=0;i<n;i++){
                if(i==source){
                    printf("0\n");
                    continue;
                }
                printf("Impossible\n");
            }
            continue;
        }

         vector<int>level;
         level=bfs(G,source);

         for(int i=0;i<n;i++){
            if(level[i]==-1){
                printf("Impossible\n");
                continue;
            }
            printf("%d\n",level[i]);
         }
	}

}
