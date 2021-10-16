#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r;
    scanf("%d %d",&l,&r);
    int mod=0;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            mod= max(mod, j%i);
            printf("%d mod %d = %d\n",j,i,mod);
        }
    }
    cout<<mod<<endl;
}