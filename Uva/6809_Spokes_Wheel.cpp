//Alhamdulillah
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void rotateRight(long long int &n){
    ll lsb=0;
    lsb=n&1;
    n=n>>1;
    lsb=lsb<<31;
    n=n|lsb;
    
}
int traverseRight(vector<ll>&v,ll n2){
    for(int i=0;i<v.size();i++){
        if(v[i]==n2)
            return i;
    }
    
    return -1;
}
int traverseLeft(vector<ll>&v,ll n2){
    for(int i=v.size()-1;i>0;i--){
        if(v[i]==n2){
            return 32-i;
        }        

    }
    if(v[0]==n2)return 0;
    return -1;
}
int main(void)
{
 //   freopen("i.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        string a1,a2;
        ll n1,n2;
        cin>>a1>>a2;
        n1=stol(a1,nullptr,16);
        n2=stol(a2,nullptr,16);
        vector<ll>allSpokes(32);
        for(int i=0;i<32;i++){
            allSpokes[i]=n1;
     //       printf("i=%d %lld\n",i,n1);
            rotateRight(n1);
            
        }
          int right=traverseRight(allSpokes,n2);
          int left=traverseLeft(allSpokes,n2);
          printf("Case #%d: ",t);
          if(right==-1){
              printf("Not possible\n");
          }
          else if(right==left){
              printf("%d Any\n",right);
          }
          else if(right<left){
              printf("%d Right\n",right);
          }
          else{
              printf("%d Left\n",left);
          }

    }
}