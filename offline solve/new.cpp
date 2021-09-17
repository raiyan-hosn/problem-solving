#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    for(int i=1;i<s.length();i++){
        if(s[i]=='/'&&s[i-1]=='*')
            return true;
    }
    return false;
}
int main(void)
{
    string comment;
    getline(cin,comment);

    if(comment.length()<2){
        printf("No comment\n");
    }

    else{
        if(comment[0]=='/'&&comment[1]=='/'){
            printf("Single line comment\n");
        }

        else if(comment[0]=='/'&&comment[1]=='*'){
            int l=comment.length();

            //should be wait for another input.

            if(isValid(comment)){
                printf("multiple line comment\n");
            }
            else{
            string nextLine;
            cin.ignore();
             while (getline(cin,comment),cin)
             {
                nextLine=comment; 
             }
             cout<<"string "<<nextLine<<endl;
             if(nextLine.length()<2){
                 printf("No comment\n");
             }


            else if(nextLine[l-1]=='/'&&nextLine[l-2]=='*'){
                printf("multiple line comment\n");
            }
            else{
                printf("No comment\n");
            }

             

            }
        }
        else{
            printf("No comment\n");
        }
    }
    
}