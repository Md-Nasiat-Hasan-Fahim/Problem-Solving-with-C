#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char ara[101];
        scanf("%s",ara);
        int n = strlen(ara);
        if(ara[n-1]%2==0) cout<<"even"<<endl;
        else cout<<"odd"<<endl;
    }
}