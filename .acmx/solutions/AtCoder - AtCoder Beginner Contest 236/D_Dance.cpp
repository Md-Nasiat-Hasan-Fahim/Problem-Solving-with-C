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

int vec[18][18];
int n;
int ans;

void abc(int mark, int val)
{
    //cout<<mark<<" "<<val<<endl;
    if(__builtin_popcountll(mark)==2*n)
    {
        ans = max(ans,val);
        return;
    }
    for(int i=0;i<2*n;i++)
    {
        if(((1LL<<i)&mark)) continue;
        int x = (mark|(1LL<<i));
        for(int j=0;j<2*n;j++)
        {
            if((i==j)||((1LL<<j)&mark)) continue;
            // cout<<i<<" "<<j<<" ";
            x = (x|(1LL<<j));
            //cout<<x<<" "<<val<<" "<<vec[i][j]<<" ";
            abc(x,(val^vec[i][j]));
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        ans = -1;
        cin>>n;
        for(int i=0;i<2*n;i++)
        {
            for(int j=i+1;j<2*n;j++)
            {
                int a;
                cin>>a;
                vec[i][j]=a;
                vec[j][i]=a;
            }
        }
        abc(0,0);
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
