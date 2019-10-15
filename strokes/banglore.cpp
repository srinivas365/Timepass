#include<iostream>
#include<stdlib.h>
#include<strings.h>
using namespace std;
int count=0,len;//globally declared for easy access
void change(string wall[],int n,char cmp,int ni,int nj){
        int current=count;
        wall[ni][nj]=count+48;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                if(ni+i<0 || nj+j<0 ||ni+i>len|| nj+j>len||(ni+i==ni&&nj+j==nj) || count==wall[ni+i][nj+j]-48|| isdigit(wall[ni+i][nj+j]))
                    continue;
                if(isalpha(wall[ni+i][nj+j]) && wall[ni+i][nj+j]==cmp){
                        change(wall,n,cmp,ni+i,nj+j);
                }
            }
        }
}
int main(){
    int n,i,j;
    cin>>n;
    string wall[n];
    for(i=0;i<n;i++)
        cin>>wall[i];
    len=wall[0].length();
    for(i=0;i<n;i++)
        for(j=0;j<len;j++)
            if(isalpha(wall[i][j])){
                count++;
                change(wall,n,wall[i][j],i,j);
        }
    cout<<"[+]Total Stroke required is >> "<<count<<endl;
    cout<<"[+]final wall is >> \n";
    for(i=0;i<n;i++){
        for(j=0;j<len;j++)
            cout<<wall[i][j];
        cout<<"\n";
    }
    return 0;
}
