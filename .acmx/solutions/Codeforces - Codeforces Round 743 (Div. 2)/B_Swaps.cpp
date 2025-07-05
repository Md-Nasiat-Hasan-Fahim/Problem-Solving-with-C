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
        vector<int>a(n),b(n);
        vector<int>pa(2*n+1,-1),pb(2*n+1,-1);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            pa[a[i]]=i;
        }
        for(int j=0;j<n;j++)
        {
            cin>>b[j];
            pb[b[j]]=j;
        }
        int cnt = INT_MAX;
        int ap = b[0];
        for(int i=0;i<n;i++)
        {
            for(int j=b[i]-1;j>0;j-=2)
            {
                if(pa[j]==-1) break;
                cnt = min(cnt,pa[j]+i);
                pa[j]=-1;
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
