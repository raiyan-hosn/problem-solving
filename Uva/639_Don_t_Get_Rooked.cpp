//Alhamdulillah.
#include<bits/stdc++.h>
using namespace std;
bool debug=false;
struct nodes
{
    int row,col;
    vector<pair<int,int>> connectedNodes;
};
void link_edeges(string matrix[],vector<nodes>&G,int row,int col){
    nodes n;
    n.row=row;n.col=col;
    // write a recursion of the bellow code :-)
    for(int i=row,j=col+1;j<matrix[i].length();j++){//going right side
        if(matrix[i][j]=='X')
            break;
        n.connectedNodes.push_back(make_pair(i,j));
    }
        for(int i=row,j=col-1;j>=0;j--){//going left side
        if(matrix[i][j]=='X')
            break;
        n.connectedNodes.push_back(make_pair(i,j));
    }
        for(int i=row-1, j=col;i>=0;i--){//going up
        if(matrix[i][j]=='X')
            break;
        n.connectedNodes.push_back(make_pair(i,j));
    }
        for(int i=row+1,j=col;i<matrix[0].length();i++){//going down
        if(matrix[i][j]=='X')
            break;
        n.connectedNodes.push_back(make_pair(i,j));
    }

    G.push_back(n);

    if(debug){
        printf("node index %d %d\n",n.row,n.col);
        for(int i=0;i<n.connectedNodes.size();i++){
            printf("%d,%d ||  ",n.connectedNodes[i].first,n.connectedNodes[i].second);
        }
        printf("\n");
    }
}
bool cmp(nodes a, nodes b){
    return a.connectedNodes.size()<b.connectedNodes.size();
}
void mark_all_conntected(string matrix[],nodes &n){

    for(int i=0;i<n.connectedNodes.size();i++){
        int row=n.connectedNodes[i].first;
        int col=n.connectedNodes[i].second;
        matrix[row][col]='-';
    }
}
int main(void)
{
    int n;
    while(scanf("%d",&n)&&n!=0){
        string matrix[n];
        for(int i=0;i<n;i++){
            cin>>matrix[i];
        }
        vector<nodes>G;
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].length();j++){
                if(matrix[i][j]=='.'){
                    link_edeges(matrix,G,i,j);
                }
                
            }
        }
        sort(G.begin(),G.end(),cmp);
        int rooks=0;
        for(int i=0;i<G.size();i++){
            if(matrix[G[i].row][G[i].col]=='.'){
                matrix[G[i].row][G[i].col]='r';
                rooks++;
                mark_all_conntected(matrix,G[i]);
            }

        }
        printf("%d\n",rooks);
    }
}