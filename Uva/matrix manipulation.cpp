#include<bits/stdc++.h>
using namespace std;
struct matrix
{
    int row,col;
    string name;
};
vector<matrix>v;
stack<string>s;
int sum=0;
matrix srch(string c)
{
    for(int i=0;i<v.size();i++){
        if(c==v[i].name)
            return v[i];
    }
    return *v.end();
}
matrix cal(matrix a,matrix b)
{
    int mul=a.row*a.col*b.col;
    sum+=mul;
    matrix c;
    c.row=a.row;
    c.col=b.col;
    c.name=a.name+b.name;
    return c;
}
bool isValid(matrix a,matrix b)
{
    if(a.col==b.row)
        return true;
    return false;
}
bool f(string &str)
{
    for(int i=0;i<str.length();i++){
        if(str[i]!=')'){
            string t(1,str[i]);
            s.push(t);
        }
        else{
            string a,b;
            b=s.top();
            s.pop();
            a=s.top();
            s.pop();
            s.pop();
            if(!isValid(srch(a),srch(b))){
                return false;
            }
            matrix m=cal(srch(a),srch(b));
            v.push_back(m);
            s.push(m.name);
        }
    }
    return true;
}
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--){
        matrix m;
        cin>>m.name>>m.row>>m.col;
        v.push_back(m);
    }
    string str;
    while(cin>>str){
        s= stack<string>();
        sum=0;
        if(f(str)){
            printf("%d\n",sum);
        }
        else{
            printf("error\n");
        }
    }
    return 0;
}
