#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        int cnt = 0;
        if(n%2)
        {
            int x = (n+1)/2;
            for(int i=x;i<n;i++) cnt+=i+1,cout<<i+1<<" ";
            for(int i=n+2;i<=n+x+1;i++)cnt+=i+1,cout<<i+1<<" ";
        }
        else
        {
            int x = n/2;
            for(int i=x;i<n;i++) cnt+=i,cout<<i<<" ";
            for(int i=n+1;i<=n+x;i++) cnt+=i,cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
