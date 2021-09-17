#include<bits/stdc++.h>
using namespace std;
int vampires,lykans;
void bicolor(vector<int>G[],vector<int>&color,int source){
	queue<int>q;
	q.push(source);
	color[source]=1;
	vampires++;
	while(!q.empty()){
		source=q.front();
		q.pop();
		for(int i=0;i<G[source].size();i++){
			if(G[source][i]==source){
				if(color[source])
					lykans++;
				else
					vampires++;
			}
			else if(color[G[source][i]]==-1){
				color[G[source][i]]=1 - color[source];
                if(color[G[source][i]])vampires++;
                else lykans++;
				q.push(G[source][i]);
			}
		}
	}

}
void prnt(vector<int>G[]){
    for(int i=1;i<=100;i++){
        printf("for %d:  ",i);
        for(int j=0;j<G[i].size();j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{

	freopen("i.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int t=1;t<=tc;t++){
		vampires=lykans=0;
		int n;
		scanf("%d",&n);
		vector<int>G[20001];
		vector<int>color(20001,-1);
		while(n--){
            int u,v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);

		}
//		prnt(G);
		for(int i=1;i<=20000;i++){
			if(color[i]==-1)
				bicolor(G,color,i);
            if(i==2)break;
		}
		printf("Case %d: %d\n",t,max(vampires,lykans));
	}
	return 0;
}
