#include<bits/stdc++.h>
using namespace std;
int grid[9][9], col[9][9], row[9][9],box[9][9],pos[9][9];
void init(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            grid[i][j]=col[i][j]=row[i][j]=box[i][j]=pos[i][j]=0;
        }
    }
}
void markDigit(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]!=0){
                row[i][grid[i][j]-1] = col[j][grid[i][j]-1] = 1;
                box[ i/3*3 + j/3 ][grid[i][j]-1]=1;
            }
        }
    }
}
void calculatePossibility(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]!=0){

            }
        }
    }
}
bool isGameOver(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0)
                return false;
        }
    }
    return true;
}
void p(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",box[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        init();
        char dummy;
        scanf("%c",&dummy);
        char line[10];
        for(int l=0;l<9;l++){

            scanf("%s",line);
            scanf("%c",&dummy);
            for(int i=0;i<9;i++){
                if(line[i]=='.'){
                    grid[l][i]=0;
                }
                else{
                    grid[l][i]=line[i]-'0';
                }
            }
        }
        while(!isGameOver()){
            markDigit();

        }

    }

}
