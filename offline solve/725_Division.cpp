//Alhamdulillah.......
#include<bits/stdc++.h>
using namespace std;
bool isValidNumber(int n){
    int digit=1+ (int)log10(n);
    vector<int>ara(10,0);
    while (n!=0)
    {
        ara[n%10]++;
        n/=10;
    }
    for(int i=0;i<10;i++){
        if(ara[i]>1)
            return false;
    }
    if(digit==4&&ara[0]!=0)
        return false;
    return true;
}
bool isTwoValidNumbers(int a,int b){
    int d_a=1+(int)log10(a);
    int d_b=1+(int)log10(b);
    vector<int>ara(10,0);
    while(a){
        ara[a%10]++;
        a/=10;
    }
    if(d_a==4)ara[0]++;
    while(b){
        ara[b%10]++;
        b/=10;
    }
    if(d_b==4)ara[0]++;
    for(int i=0;i<10;i++){
        if(ara[i]>1)return false;
    }
    return true;
}
int main(void)
{
   // freopen("o.txt","w",stdout);
    vector<int>validNumbers;
    map<int,int>mp;
    for(int i=1000;i<=99999;i++){
        if(isValidNumber(i)){
            validNumbers.push_back(i);
            mp[i]=1;
        }
          
    }
    int n,t=0;
    while(scanf("%d",&n)&&n&&++t){
        if(t!=1)
            printf("\n");
        vector<pair<int,int>>solution;
        for(int i=0;i<validNumbers.size();i++){
            if(mp[n*validNumbers[i]]&&isTwoValidNumbers(validNumbers[i],n*validNumbers[i])){
                solution.push_back(make_pair(n*validNumbers[i],validNumbers[i]));
            }
        }
        if(solution.size()==0){
            printf("There are no solutions for %d.\n",n);
            continue;
        }
        for(int i=0;i<solution.size();i++){
            printf("%d / ",solution[i].first);
            if(1+ (int)log10(solution[i].second)==4)
                printf("0");
            printf("%d = %d\n",solution[i].second,n);
        }
    }

}