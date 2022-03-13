#include<bits/stdc++.h>
using namespace std;
string s="A .- J .--- S ... 1 .---- . .-.-.- : ---... B -... K -.- T - 2 ..--- , --..-- ; -.-.-. C -.-. L .-.. U ..- 3 ...-- ? ..--.. = -...- D -.. M -- V ...- 4 ....- ' .----. + .-.-. E . N -. W .-- 5 ..... ! -.-.-- - -....- F ..-. O --- X -..- 6 -.... / -..-. _ ..--.- G --. P .--. Y -.-- 7 --... ( -.--. H .... Q --.- Z --.. 8 ---.. ) -.--.- @ .--.-. I .. R .-. 0 ----- 9 ----. & .-...";
char c='"';
string u;
string t=".-..-.";
map<string,string>lst;
void p(string w)
{
    cout<<lst[w];
}
int main(void)
{
//    freopen("i.txt","r",stdin);

    stringstream ss(s);
    string word;
    u=c;
    while(ss>>word){
        string word2;
        ss>>word2;
        lst.insert(make_pair(word2,word));
    }
    lst.insert(make_pair(t,u));
//    for(auto it=lst.begin();it!=lst.end();it++)
//    {
//        cout<<it->first<<' '<<it->second<<endl;
//    }

    int tc;
    string st;
    scanf("%d",&tc);
    cin.ignore();
    for(int t=1;t<=tc;t++){
        getline(cin,st);
        printf("Message #%d\n",t);
        int i=0;
        char c;
        word=string();
        for(int i=0;i<st.length();i++){
            if(st[i]==' '&&word.length()!=0){
                p(word);
                word=string();

//                printf("st[i+1]= .%c.\n",st[i+1]);
                if(st[i+1]==' '){
                    printf(" ");
                    i++;
                }
                continue;
            }
            if(st[i]==' ')
                continue;
            word+=st[i];

        }
        if(word.length()!=0)
            p(word);
        if(t==tc){
            printf("\n");
            continue;
        }
        printf("\n\n");
    }
    return 0;
}

