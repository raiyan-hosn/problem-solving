#include<bits/stdc++.h>
using namespace std;
bool isSaparator(char c){
    return c=='+'||c=='-'||c=='*'||c=='('||c==')';
}
vector<string> saparate(string s){
    vector<string>v;
    string part="";
    for(int i=0;i<s.length();i++){
        if(isSaparator(s[i])){
            if(!part.empty())
                v.push_back(part);
            part="";
            part.push_back(s[i]);
            if(!part.empty())
                v.push_back(part);
            part="";
        }
        else{
            part.push_back(s[i]);
        }
    }
    if(!part.empty())
        v.push_back(part);
    return v;
}
void print(vector<string>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
int main(void)
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        string s;
        cin>>s;
        cin.ignore();
        int pos=s.find("=");
        vector<string>LHS,RHS;
        LHS=saparate(s.substr(0,pos));
        RHS=saparate(s.substr(pos+1,s.length()-pos-1));
        print(LHS);
        print(RHS);
    }
   
    
    return 0;
}