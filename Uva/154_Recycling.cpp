//alhamdulillah
#include<bits/stdc++.h>
using namespace std;
struct city
{
    int name,score=0;
};

vector<char>v[5];
vector<city>score;
void erse(){
    for(int i=0;i<5;i++){
        v[i].erase(v[i].begin(),v[i].end());

    }
    score.erase(score.begin(),score.end());
}
int calScore(vector<char>&vs,char c){
    int scr=0;
    for(int i=0;i<vs.size();i++){

        if(vs[i]!=c)scr++;
    }
    return scr;
}
bool cmp(city a,city b){
    return a.score<b.score;
}
int choseCity(){
    int scr=0;
    for(int i=0;i<v[0].size();i++){

        scr=0;
        for(int j=0;j<5;j++){
            scr+=calScore(v[j],v[j][i]);

        }
        city n;
        n.name=i+1;
        n.score=scr;
       // printf("score of %d is %d\n",n.name,n.score);
        score.push_back(n);
    }
    sort(score.begin(),score.end(),cmp);

    return score[0].name;

}
void store(string s){

    for(int i=0;i<s.length();i++){
        if(s[i]=='A'){
            v[0].push_back(s[i-2]);
        }
        else if(s[i]=='G'){
            v[1].push_back(s[i-2]);
        }
         else if(s[i]=='N'){
            v[2].push_back(s[i-2]);
        }
         else if(s[i]=='P'){
            v[3].push_back(s[i-2]);
        }
         else if(s[i]=='S'){
            v[4].push_back(s[i-2]);
        }
    }
}
int main(void)
{
    string s;

    while(cin>>s){
        if(s[0]=='#'){
            break;
        }
        else if(s[0]=='e'){
            printf("%d\n",choseCity());
            erse();
        }
        else
        {
            store(s);
        }


    }
}
