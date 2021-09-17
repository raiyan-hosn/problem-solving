#include<bits/stdc++.h>
using namespace std;
struct arr{
    string name;
    int base,index_size,dimension;
    vector<pair<int,int>>v;
    arr(string n,int b,int ind,int dimen)
    {
        name = n;
        base=b;
        index_size=ind;
        dimension=dimen;
    }
};
vector<arr>arais;
int f(string name)
{
    for(int i=0;i<arais.size();i++){
        if(arais[i].name==name){
            return i;
        }
    }
    return -1;
}
void p()
{
    for(int i=0;i<arais.size();i++){
        cout<<arais[i].name<<"     "<<arais[i].base<<' '<<arais[i].index_size<<' '<<arais[i].dimension;
        for(int j=0;j<arais[i].v.size();j++)
            printf(" %d %d",arais[i].v[j].first,arais[i].v[j].second);
        printf("\n\n");
    }
    printf("arais size= %d\n\n",(int)arais.size());
}
int main(void)
{
//    freopen("i.txt","r",stdin);
    int n,r;
    scanf("%d %d",&n,&r);
    while(n--){
        string name;
        int base,bitsize,dimension;
        cin>>name>>base>>bitsize>>dimension;
        arr ara(name,base,bitsize,dimension);
        while(dimension--){
            int f,s;
            scanf("%d %d",&f,&s);
            ara.v.push_back(make_pair(f,s));
        }
        arais.push_back(ara);
    }
    while(r--){
        string name;
        cin>>name;
        int i=f(name);
        vector<int>dim;
        for(int j=1;j<=arais[i].dimension;j++){
            int d;
            scanf("%d",&d);
            dim.push_back(d);
        }
        int address=0;
        for(int j=0;j<dim.size();j++){
            int add=dim[j]-arais[i].v[j].first;

            for(int k=j+1;k<arais[i].v.size();k++)
                add*=(arais[i].v[k].second-arais[i].v[k].first+1);
            address+=add;
//            printf("add=%d j=%d\n",add,j);
        }
        address*=arais[i].index_size;
        address+=arais[i].base;

//        p();
        cout<<name<<'['<<dim[0];
        for(int j=1;j<dim.size();j++){
            printf(", %d",dim[j]);
        }
        printf("] = %d\n",address);
    }
    return 0;
}
