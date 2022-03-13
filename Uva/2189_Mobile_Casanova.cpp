//Alhamdulillah.
#include<bits/stdc++.h>
using namespace std;
int matchedPossition(vector<string>&v,int currentPossition){
    int endsAt=currentPossition+1;
    while (endsAt<v.size())
    {
        if(stoi(v[endsAt]) - stoi(v[currentPossition]) !=1){
            return endsAt;
        }
        endsAt++;
        currentPossition=endsAt-1;
    }
    return endsAt;
    
}
string returnRange(string first, string last){
    int endsAt=0;
    while (endsAt<first.length())
    {
        if(first[endsAt]!=last[endsAt])
            break;
        endsAt++;
    }
   // printf("endsat= %d\n",endsAt);
    string range=first+"-";


    for (int i = endsAt; i < first.length(); i++)
    {
        range+=last[i];
    }
    return range;
    
}
int main(void)
{
    int n,t=0;
    while(scanf("%d",&n)&&n!=0&&++t){
        vector<string>v(n);
        vector<string>solution;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int endsAt=0;
        for(int i=0;i<n;i=endsAt){//update i with currentpossition
            endsAt=matchedPossition(v,i);
            if(endsAt-i==1){
                solution.push_back(v[i]);
            }
            else{
                solution.push_back(returnRange(v[i],v[endsAt-1]));
            }
        }
        printf("Case %d:\n",t);
        for(int i=0;i<solution.size();i++){
            cout<<solution[i]<<endl;
        }
        printf("\n");
    }
}