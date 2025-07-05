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

int abc(int x)
{
    int cnt = 0;
    while(x)
    {
        cnt++;
        x=(x>>1);
    }
    return cnt;
}

int cde(int x)
{
    int k = 32768;
    int cnt = INT_MAX;
    for(int i=0;i<45;i++)
            {
                int p = (1LL<<i);
                int y = ceill((p*x*1.0)/k)*k;
                if(y==p*x)
                {
                    cnt=min(cnt,i);
                    break;
                }
                if(abc(y-p*x)<=i) cnt = min(cnt,i);
            }
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            int cnt = 0;
            cin>>x;
            int k = 32768;
            while(k>x)
            {
                cnt++;
                if((k%2==0)&&(k/2)>x) k/=2;
                else k--;
            }
            cnt = min({cde(x),cde(x+1)+1,cnt,cde(2*x)+1});
            cout<<cnt<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
