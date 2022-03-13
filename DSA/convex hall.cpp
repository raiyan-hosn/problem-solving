#include<bits/stdc++.h>
using namespace std;

struct  point
{
    int x,y;
};

int orierntation(point p,point q, point r){
    return (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);//returns 0 if colinear, positive if clockwise, negative if counter-clockwise.  
}

void giftWrapping_convexHall(vector<point>&v,vector<point>&convexHall){
    int n=v.size();
    
    if(n<3)return;

    int leftMost=0;

    for(int i=1;i<n;i++){
        if(v[i].x<v[leftMost].x){
            leftMost=i;
        }
    }
    int p=leftMost,q;
    
    do
    {
        convexHall.push_back(v[p]);

        q=(p+1)%n; 

        for(int i=0;i<n;i++){
            if(orierntation(v[p],v[q],v[i])<0){
                q=i;
            }
        }
        p=q;
       
    } while (p!=leftMost);
    
}

int main(void){
    vector<point>v={ {-3,0}, {0,6},{3,0}, {0,3}
    };
    vector<point> convexHall;

    giftWrapping_convexHall(v,convexHall);
    
    for(int i=0;i<convexHall.size();i++){
        printf("(%d, %d)\n",convexHall[i].x,convexHall[i].y);
    }
}