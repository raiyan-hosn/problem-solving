#include<bits/stdc++.h>
using namespace std;
#define MAX 1003
int parent[MAX];
int sz[MAX];
int findParent(int u){
    if(parent[u]==u)return u;

    parent[u]=findParent(parent[u]);
    return parent[u];
}
void unify(int u,int v){
    if(sz[u]<sz[v])swap(u,v);
    u=findParent(u);
    v=findParent(v);
    parent[v]=u;
    sz[u]+=sz[v];
}
bool isSameSet(int u,int v){
    return findParent(u)==findParent(v);
}
int main(){
    for(int i=0;i<MAX;i++){
        parent[i]=i;
        sz[i]=1;
    }
    int m;
    printf("maximum node value is MAX=1000.\nnum of initial edges->");
    scanf("%d",&m);
    while(m--){
        int u,v;
        scanf("%d %d",&u,&v);
        unify(u,v);
    }
    int q;
    printf("num of command-> ");
    scanf("%d",&q);
    while(q--){
        int u,v,type;
        scanf("%d %d %d",&type, &u,&v);
        if(type==1){
            unify(u,v);
        }else{
            if(isSameSet(u,v)){
                printf("same set\n");
            }
            else{
                printf("different set\n");
            }
        }      
    }
}