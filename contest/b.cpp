#include<iostream>

using namespace std;
#define MAX 1000
int a[MAX][MAX];
void print_arr(int n,int m)
{
    cout << "Output" << endl;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;++j){
            cout << "a[" << i << "][" << j << "] : " << a[i][j] << endl;
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;


    int i,j;
    cout << "Enter the elements: ";
    for(i=0;i<n;i++){
        for(j=0;j<m;++j){
            cin >> a[i][j];
        }
    }

    print_arr(n,m);

    return 0;
}
