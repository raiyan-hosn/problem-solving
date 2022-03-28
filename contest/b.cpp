#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int valueOfB(int a){
	return (a*a-1)>>1;
}
bool isValid(int a,int b,int n){
	return (a*a-b)== sqrt(a*a + b*b)&& max(a,max(b,a*a-b))<=n&& 0<min(a,min(b,(a*a-b)));
}
int main()
{
    int n=5734;

    for(int a=1;a<=n;a++){
        int b=valueOfB(a);
        printf("a= %d, b= %d  ",a,b);
        if(isValid(a,b,n)){
            printf("valid\n");
        }else{
            printf("not valid....\n");
        }
    }

}
