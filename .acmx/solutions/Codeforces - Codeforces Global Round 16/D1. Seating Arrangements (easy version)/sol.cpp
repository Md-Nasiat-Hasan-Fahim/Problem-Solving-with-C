#include<iostream>
using namespace std;
int t,s,n,m,a[1001];
int main(){
cin>>t;
while(t--){
cin>>n>>m;
s=0;
for(int i=0;i<m;i++)
cin>>a[i];
for(int i=0;i<m;i++)
for(int j=0;j<i;j++)
if(a[i]>a[j])
s++;
cout<<s<<endl;
}
}