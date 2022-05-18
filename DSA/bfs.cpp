#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
void bfs(vvi &g,int source){

    vector<int>level((int)g.size(),-1);
    queue<int>q;
    q.push(source);
    level[source]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        printf("%d lev=%d\n",u,level[u]);
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(level[v]==-1){
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
}
int main(){

    freopen("i.txt","r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    vvi g(n+1,vector<int>());
    while(m--){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(g,1);
}