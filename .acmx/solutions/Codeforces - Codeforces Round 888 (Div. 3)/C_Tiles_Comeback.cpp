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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>vec(n+1),cnt;
        int fast = -1, last = -1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(i==0)
            {
                fast = a;
            }
            else if(i==n-1)
            {
                last = a;
            }
            vec[a]++;
            cnt.pb(a);
        }
        if(n==1)
        {
            if(k==1) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        int one[n+3]={0}, two[n+3]={0};
        if(cnt[0]==fast) one[0]=1;
        for(int i=1;i<n;i++)
        {
            one[i]+=one[i-1];
            if(cnt[i]==fast) one[i]++;
            //cout<<one[i]<<" ";
        }
        for(int i=n-1;i>-1;i--)
        {
            two[i]+=two[i+1];
            if(cnt[i]==last) two[i]++;
        }
        bool ans =(fast==last)&&(vec[fast]>=k);
        for(int i=0;i<n;i++)
        {
            if(one[i]>=k&&two[i]>=k) ans = true;
            //cout<<one[i]<<" "<<two[i]<<" "<<i<<endl;
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
