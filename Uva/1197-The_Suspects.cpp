/// Alhamdulillah AC.......

#include<bits/stdc++.h>
using namespace std;
#define MAX 30004
int par[MAX],sz[MAX];
int  findParent(int u){
    if(par[u]==u)return u;
    par[u]=findParent(par[u]);
    return par[u];
}
void unify(int u,int v){
    if(sz[u]<sz[v])swap(u,v);
    u=findParent(u);
    v=findParent(v);
    par[v]=u;
    sz[u]+=sz[v];

}
bool isSameGroup(int u,int v){
    return findParent(u)==findParent(v);
}
int main(){
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m;
    while(scanf("%d %d",&n,&m)&&(n||m)){
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        while(m--){
            int members, firstMember;
            scanf("%d %d",&members,&firstMember);
            members--;
            while(members--){
                int otherMember;
                scanf("%d",&otherMember);
                unify(firstMember,otherMember);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(findParent(i)==findParent(0))cnt++;
        }
        printf("%d\n",cnt);
    }
}