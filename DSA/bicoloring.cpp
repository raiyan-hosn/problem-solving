#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
bool isBicoloringPossible(vvi &g,int source){
    vector<int>color((int)g.size(),-1);
    queue<int>q;
    q.push(source);
    color[source]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(color[v]==-1){
                color[v]=!color[u];
                q.push(v);
            }else if(color[v]==color[u]){
                // printf("%d %d, %d %d\n",u,color[u],v,color[v]);
                return false;
            }
        }
    }
    return true;
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
    printf("bi coloring %d\n",isBicoloringPossible(g,1));
}