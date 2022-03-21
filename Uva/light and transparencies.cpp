#include<bits/stdc++.h>
using namespace std;
struct segment
{
    double x1,x2,coef=1;
};
double minx1(vector<segment>&v,double greaterThen)
{
    double mn=2000000000;
    for(int i=0;i<v.size();i++){
        if(v[i].x1<mn&&v[i].x1>greaterThen)
            mn=v[i].x1;
    }
    return mn;
}
double minx2(vector<segment>&v,double greaterThen)
{
    double mn=2000000000;
    for(int i=0;i<v.size();i++){
        if(v[i].x2<mn&&v[i].x2>greaterThen)
            mn=v[i].x2;
    }
    return mn;
}
void mulcoef(vector<segment>&v,segment &s)
{
    s.coef=1;
    for(int i=0;i<v.size();i++){
        if(v[i].x1<=s.x1&&s.x2<=v[i].x2)
            s.coef*=v[i].coef;
    }
}
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        double mx=-2000000000;
        int seg;
        vector<segment>v;
        scanf("%d",&seg);
        while(seg--){
            double useLessY;
            segment s;
            scanf("%lf %lf %lf %lf %lf",&s.x1,&useLessY,&s.x2,&useLessY,&s.coef);
            if(s.x2<s.x1)
                swap(s.x1,s.x2);
            v.push_back(s);
            if(s.x2>mx)
                mx=s.x2;
        }
        vector<segment>ground;
        double greaterThen=-2000000000;
        segment s;
        s.x1=min(minx1(v,greaterThen),minx2(v,greaterThen));// or using min(), it's the smallest value of all points
        while(greaterThen<mx){

            s.x2=min(minx1(v,s.x1),minx2(v,s.x1));
            greaterThen=s.x2;
            mulcoef(v,s);
            ground.push_back(s);
            s.x1=ground.back().x2;
        }
        printf("%d\n",(int)ground.size()+2);
        printf("-inf %.3lf %.3lf\n",ground[0].x1,1.);
        for(int i=0;i<ground.size();i++)
            printf("%.3lf %.3lf %.3lf\n",ground[i].x1,ground[i].x2,ground[i].coef);
        printf("%.3lf +inf %.3lf\n\n",ground.back().x2,1.);
    }
    return 0;
}
