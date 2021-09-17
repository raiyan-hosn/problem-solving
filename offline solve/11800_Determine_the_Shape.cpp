//Alhamdulillah.
#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
struct point
{
    int x,y;
};
double straightLineDistance(point a, point b){
    return sqrt(1.0* (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
}
int orientation(point a, point b, point c){
    return (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
}
void convexHallSorting(vector<point>&v,vector<point>&convexHall){
    int n=(int)v.size();
    int leftMost=0;
    for(int i=1;i<n;i++)
        if(v[i].x<v[leftMost].x)
            leftMost=i;

    int p=leftMost,q;
    do
    {
        convexHall.push_back(v[p]);
        q=(p+1)%n;
        for(int i=0;i<n;i++){
            if(orientation(v[p],v[q],v[i])<0)
                q=i;
        }
        p=q;
    } while (p!=leftMost);

}

double slope(point a, point b){
    if(a.x-b.x==0)return 1000000.0;
    return 1.0*(a.y-b.y)/(a.x-b.x);
}
bool isTraizium(vector<point>&convexHall){
    if(abs(slope(convexHall[0],convexHall[1])-slope(convexHall[2],convexHall[3]))<=eps)
        return true;
    if(abs(slope(convexHall[1],convexHall[2])-slope(convexHall[0],convexHall[3]))<=eps)
        return true;
    return false;
}
int main(void)
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        vector<point>v(4);
        for(int i=0;i<4;i++)
            scanf("%d %d",&v[i].x,&v[i].y);

        vector<point>convexHall;
        convexHallSorting(v,convexHall);

        double ab=straightLineDistance(convexHall[0],convexHall[1]);
        double bc=straightLineDistance(convexHall[1],convexHall[2]);
        double cd=straightLineDistance(convexHall[2],convexHall[3]);
        double da=straightLineDistance(convexHall[3],convexHall[0]);
        //two diagonals:
        double ac=straightLineDistance(convexHall[0],convexHall[2]);
        double bd=straightLineDistance(convexHall[1],convexHall[3]);

     

        printf("Case %d: ",t);
        if(convexHall.size()<4){
            printf("Ordinary Quadrilateral\n");
            continue;
        }
        if(abs(ab-bc)<=eps&&abs(bc-cd)<=eps&&abs(cd-da)<=eps){
            if(abs(ac-bd)<=eps){
                printf("Square\n");
            }
            else
            {
                printf("Rhombus\n");
            }
        }
        else if(abs(ab-cd)<=eps&&abs(bc-da)<=eps){
            if(abs(ac-bd)<=eps){
                printf("Rectangle\n");
            }
            else
            {
                printf("Parallelogram\n");
            }

        }
        else if(isTraizium(convexHall)){
            printf("Trapezium\n");
        }
        else
        {
            printf("Ordinary Quadrilateral\n");
        }

    }
}