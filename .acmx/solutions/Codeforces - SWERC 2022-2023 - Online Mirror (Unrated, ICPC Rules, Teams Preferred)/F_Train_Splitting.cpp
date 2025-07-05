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
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        int degree[n+1]={0};
        vector<pair<int,int>>vec;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
            vec.pb({a,b});
        }
        int mn = INT_MAX, mnc = -1;
        for(int i=1;i<=n;i++)
        {
            if(degree[i]<mn)
            {
                mnc = i;
                mn = degree[i];
            }
        }
        if(mn==n-1)
        {
            bool ans = false;
            cout<<"3"<<endl;
            for(int i=0;i<m;i++)
            {
                if(vec[i].first==mnc||vec[i].second==mnc)
                {
                    if(ans) cout<<"2 ";
                    else {cout<<"3 ";ans=true;}
                }
                else cout<<"1 ";
            }
        }
        else
        {
            cout<<"2\n";
            for(int i=0;i<m;i++)
            {
                if(vec[i].first==mnc||vec[i].second==mnc)
                {
                    cout<<"2 ";
                }
                else cout<<"1 ";
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
