#include<bits/stdc++.h>
using namespace std;
int bfs(int n,vector<int>v[],int source);
void p(vector<int>v[],int n);
int main(void){
    freopen("i.txt","r",stdin);
    int n;

    scanf("%d",&n);
    std::vector<int>v[n+1];
    for(int i=1;i<=n;i++){
        printf("Adjacend nodes of %d:",i);
        int m=1;
        while(m!=0){
            scanf("%d",&m);
            if(m==0)break;
            v[i].push_back(m);

        }

    }
    printf("\n\n");
    bfs(n,v,1);

}

int bfs(int n,vector<int>v[],int source){
    queue<int>q;
    int level[n+1];
    memset(level,-1,sizeof(level));
    level[source]=0;
    q.push(source);
    while(!q.empty()){
        source=q.front();

        q.pop();
        for(int i=0;i<v[source].size();i++){

            if(level[v[source][i]]==-1){
                q.push(v[source][i]);

                level[v[source][i]]=level[source]+1;

            }

        }
    }
    for(int i=1;i<=n;i++){
        printf("level of %d is %d\n",i,level[i]);
    }
}
void p(vector<int>v[],int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            printf("v[%d]=%d\n",i,v[i][j]);
        }
    }
}

