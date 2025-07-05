#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=0;
        vector<int>a;

            /*while(n!=1)
            {
                if(n%2==0){a.clear();break;}
                if((n+1/2)%2==1)
                {
                    n=n+1/2;
                    a.push_back(1);

                }
                else
                {
                    n=n-1/2;
                    a.push_back(2);

                }
            }*/
        if(a.empty() or a.size()>40){
         cout<<-1<<endl;}
         else
         {
        reverse(a.begin(), a.end());
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    }
}