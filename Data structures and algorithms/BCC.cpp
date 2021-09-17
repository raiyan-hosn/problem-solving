//print all biconnected components in a graph
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define pii pair<int,int>
vector<int>graph[MAX+5];
int low[MAX+5],dis[MAX+5];
bool vis[MAX+5];
stack<pii> st;
int tim;
vector<vector<pii>> storageOfBCC;
void init(int n){
    for(int i=0;i<n;i++){
        graph[i].clear();
    }
    st= stack<pii>();
    tim=1;
    storageOfBCC.clear();
    memset(low,-1,sizeof(int)*n);
    memset(dis,-1,sizeof(int)*n);
    memset(vis,false,sizeof(bool)*n);
}
void storeBCCEdeges(int u,int v){
    int node1=st.top().first;
    int node2=st.top().second;
    vector<pii>edgeList;
    while (!st.empty())
    {
        edgeList.push_back(make_pair(node1,node2));
        st.pop();
        if(node1==u&&node2==v)break;
        node1=st.top().first;
        node2=st.top().second;
    }
    storageOfBCC.push_back(edgeList);
}
void printBCC(){
    printf("Total number of BCC = %d\n\n",(int)storageOfBCC.size());

    for(int i=0;i<(int)storageOfBCC.size();i++){
        printf("BCC number %d:\n",i+1);
        for(auto j: storageOfBCC[i]){
            printf("%d %d\n",j.first,j.second);
        }
        printf("\n");
    }
}
void dfs(int u,int pr=-1){
    vis[u]=1;
    low[u]=dis[u]=tim++;
    for(auto v:graph[u]){
        if(v==pr)continue;
       
        if(vis[v]){
            low[u]=min(low[u],dis[v]);
            if(dis[u]>dis[v]){       //if definitely it is a back-edge
                st.push(make_pair(u,v)); 
            }
        }
        else{
            st.push(make_pair(u,v));
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dis[u] ){
                storeBCCEdeges(u,v);
            }
        }
    }
}
void generateBCC(int root){
    dfs(root);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init(n+1); 
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){      //if there exists any disconnected vertex, then find BCC of them.
            generateBCC(i);
        }
    }
    printBCC();
}