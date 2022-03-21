#include<bits/stdc++.h>
using namespace std;
int cal_gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return cal_gcd(b,a%b);
}
void print(int a,int b,int c,bool isPossitive)
{
    int spaces=0;
    if(a>0){
        spaces=(int)log10(a)+1;
    }
//    printf("\n\n spaces %d\n\n",spaces);
    if(!isPossitive)
        spaces+=2;

    int extra=((int)log10(c)+1)-((int)log10(b)+1);
//    printf("\n\n extra %d\n",extra);
    int hypen=(int)log10(c)+1;
    for(int i=1;i<=spaces+extra;i++)
        printf(" ");

    printf("%d\n",b);
    if(!isPossitive)
        printf("- ");
    if(a>0)
        printf("%d",a);
    for(int i=1;i<=hypen;i++)
        printf("-");
    printf("\n");
    for(int i=1;i<=spaces;i++)
        printf(" ");
    printf("%d\n",c);

}
int main(void)
{
//    freopen("i.txt","r",stdin);
    int n,tc=1;
    while(cin>>n&&n!=0){
        int num;
        int a,b=0,c=n,gcd;
        for(int i=0;i<n;i++){
            scanf("%d",&num);
            b+=num;
        }
        printf("Case %d:\n",tc);
        bool isPossitive=true;
        if(b<0){
            b*=(-1);
            isPossitive=false;
        }
        gcd=cal_gcd(b,c);
        if(gcd==c){
            if(!isPossitive)
                printf("- ");
            printf("%d\n",b/c);
        }
        else{
            b/=gcd;
            c/=gcd;
            if(b<c){
                print(-1,b,c,isPossitive);
            }
            else{
                a=b/c;
                b%=c;
                print(a,b,c,isPossitive);
            }
        }
        tc++;
    }
    return 0;
}

