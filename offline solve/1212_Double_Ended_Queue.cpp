//Alhamdulillah
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,m;
        scanf("%d %d",&n,&m);
        list<int>lst;
        printf("Case %d:\n",t);
        while(m--){
            string cmd;
            int x;
            cin>>cmd;
            if(cmd=="pushRight"){
                scanf("%d",&x);
                if(n==lst.size()){
                    printf("The queue is full\n");
                }
                else{
                    lst.push_back(x);
                    printf("Pushed in right: %d\n",x);
                }
            }
            else if(cmd=="pushLeft"){
                scanf("%d",&x);
                if(n==lst.size()){
                    printf("The queue is full\n");
                }
                else{
                    lst.push_front(x);
                    printf("Pushed in left: %d\n",x);
                }
            }
            else if(cmd=="popRight"){
                if(lst.empty()){
                    printf("The queue is empty\n");
                }
                else{
                    printf("Popped from right: %d\n",lst.back());
                    lst.pop_back();
                }
            }
            else{
                if(lst.empty()){
                    printf("The queue is empty\n");
                }
                else{
                    printf("Popped from left: %d\n",lst.front());
                    lst.pop_front();
                }
            }
        }
    }
}