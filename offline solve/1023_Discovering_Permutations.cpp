//alhamdulillah.
#include<bits/stdc++.h>
using namespace std;
bool nextPermutation(string &s){
    int n=s.length();
    int i=n-1;
    if(n==1)return false;
    while (s[i-1]>=s[i])
    {
        if(--i==0)
            return false;
    }
    int j=n-1;
    while(j>i && s[i-1]>=s[j]){
        j--;
    }
    swap(s[i-1],s[j]);
    reverse(s.begin()+i,s.end());
    return true; 
    
}

int main(void)
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,k;
        scanf("%d %d",&n,&k);
        string s="A";
        for(int i=1;i<n;i++){
            s+=('A'+i);
        }
        printf("Case %d:\n",t);
        int i=0;
        do
        {   
            cout<<s<<endl;
            i++;
        } while (i<k&&nextPermutation(s));
        
    }
}