#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vv;
int white,black;

vv bicoloring(vv G[],int n){

    int source=1;
    vv color(n+1,-1); // no color= -1, white= 0, black= 1;
    color[source]=1;
    black++;
    queue<int>q;
    q.push(source);

    while(!q.empty()){
        source=q.front();
        q.pop();
//        printf("source = %d color %d\n",source,color[source]);
        for(int i=0;i<G[source].size();i++){

            if(color[G[source][i]]== -1){
                if(color[source]== 0){
                    color[G[source][i]]= 1;
                    black++;
                }
                else{
                    color[G[source][i]]=0;
                    white++;
                }

                q.push(G[source][i]);
            }

            if(color[source]== color[G[source][i]]){
//                printf("for node %d color %d\n",G[source][i],color[G[source][i]]);
                if(color[G[source][i]]== 1)
                    black--;
                else
                    white--;
                color[G[source][i]]= -1;
            }
        }
//        printf("source color %d\n",color[source]);
    }

    return color;
}

void prnt(vv &color, int name){
    for(int i=1;i<color.size();i++){
        if(color[i]==1)
            printf("%d ",i);
    }
    printf("\n");
}

int main(void)
{
    freopen("i.txt","r",stdin);
    int m;
    scanf("%d",&m);
    while(m--){
        white=black=0;
        int n,k;
        scanf("%d %d",&n,&k);
        vv G[n+1];

        while(k--){
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
//            G[b].push_back(a);
        }
//        k == 0 hole function call koro na
        vv color;
        color=bicoloring(G,n);
        printf("%d\n",black);
        if(black>white)
            prnt(color,1);
        else
            prnt(color,0);
    }
}
