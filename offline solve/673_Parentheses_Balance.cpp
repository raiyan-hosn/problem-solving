//Alhamdulillah
#include<bits/stdc++.h>
using namespace std;
bool isCorrect(string &s){
    stack<char>openingBracket;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['){
            openingBracket.push(s[i]);
        }
        else{
            if(openingBracket.empty())
                return false;
            if(s[i]==')'&&openingBracket.top()!='(')
                return false;
            if(s[i]==']'&&openingBracket.top()!='[')
                return false;

            openingBracket.pop();
        }
    }
    if(!openingBracket.empty())
        return false;
    return true;
}
int main(void)
{
    int tc;
    scanf("%d",&tc);
    cin.ignore();
    while(tc--){
        string s;
        getline(cin,s);
        
        if(isCorrect(s)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}