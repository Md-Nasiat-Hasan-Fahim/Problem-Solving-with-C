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

bool abc(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return true;
    }
    return false;
}

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
        int sum = 0;
        int od = -1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            sum+=a;
            if(a%2) od = i;
        }
        if(abc(sum))
        {
            cout<<n<<endl;
            for(int i=0;i<n;i++) cout<<i+1<<" ";
            cout<<endl;
        }
        else
        {
            cout<<n-1<<endl;
            for(int i=0;i<n;i++)
            {
                if(i==od) continue;
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
