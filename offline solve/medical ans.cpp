#include<bits/stdc++.h>
using namespace std;
int n=10;
string ans="0123456789";
vector<string> perticipants;
void fill(int idx){
    if(idx==n){
        perticipants.push_back(ans);
        return;
    }
    for(char c='A';c<='D';c++){
        ans[idx]=c;
        fill(idx+1);
    }
}
int calMark(string ans, string khata){
    int mark=0;
    for(int i=0;i<ans.length();i++){
        if(ans[i]==khata[i])mark++;
        else mark+=(-0.25);
    }
    return mark;
}
int main(){
    fill(0);
    string originalAns="ACBDBDDAAD";
    map<int,int>result;
    for(int i=0;i<perticipants.size();i++){
        int mark=calMark(originalAns,perticipants[i]);
        result[mark]++;
    }
    printf("Total students = %d\n\n",(int)perticipants.size());
    for(auto it=result.begin();it!=result.end();it++){
        printf("%d = %d\n",it->first,it->second);
    }
}
