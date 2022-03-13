// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int lHare,lTortois,m,i,z,tc=1;
   while(scanf("%d %d %d %d",&z,&i,&m,&lTortois)&&(z||i||m||lTortois)){
       lHare=lTortois;
       int lHare2=lHare;
       do{
           lHare= (z*((z*lHare+i)%m)+i)%m;
           lTortois=(z*lTortois+i)%m;

       }while(lHare!=lTortois);
     
       while(lHare!=lHare2){
           
           lHare=(z*lHare+i)%m;
           lHare2=(z*lHare2+i)%m;
       }
      
       int step=1;
       
       int lTortois2=(z*lHare+i)%m;
       while(lTortois2!=lHare){
           lTortois2=(z*lTortois2+i)%m;
           step++;
       }
       printf("Case %d: %d\n",tc++,step);


   }
}