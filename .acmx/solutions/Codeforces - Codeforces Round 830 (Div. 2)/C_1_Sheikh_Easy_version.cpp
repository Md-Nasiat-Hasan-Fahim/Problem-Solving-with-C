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

int abc(int l, int r, vector<int> &cnt, vector<int> &xr)
{
    if(l>r) return INT_MIN;
    return (cnt[r]-cnt[l-1]-(xr[r]^xr[l-1]));
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
        int n,q;
        cin>>n>>q;
        vector<int>vec(n+2);
        vector<int>bit[33];
        vector<int>xorf(n+2);
        vector<int>cntf(n+2);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            vec[i]=a;
            for(int j=0;j<33;j++)
            {
                if(a&(1LL<<j)) bit[j].pb(i);
            }
            cntf[i]=cntf[i-1]+vec[i];
            xorf[i]=xorf[i-1]^vec[i];
        }
        //cout<<n<<" "<<q<<endl;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int ara[33]={0};
            //cout<<bit[3][0]<<endl;
            for(int i=32;i>-1;i--)
            {
                if((bit[i].size()+ara[i])%2)
                {
                    auto teit = lower_bound(all(bit[i]),l);
                    if(teit==bit[i].end()||*teit>r) continue;
                    int pos1 = *teit;
                    auto it = upper_bound(all(bit[i]),r);
                    it--;
                    int pos2 = *it;
                    //cout<<i<<" "<<l<<" "<<r<<" "<<pos1<<" "<<pos2<<endl;
                    if(pos1>pos2) continue;
                    //else if(pos1==pos2) cout<<i<<" "<<l<<" "<<r<<" "<<pos1<<" "<<pos2<<endl;
                    if((abc(pos1+1,r,cntf,xorf)>abc(l,pos2-1,cntf,xorf)))
                    {
                        if(abc(pos1+1,r,cntf,xorf)>=abc(l,r,cntf,xorf))
                        {
                            l = pos1+1;
                            for(int j=32;j>-1;j--)
                            {
                                if(vec[pos1]&(1LL<<j)) ara[j]--;
                            }
                        }
                    }
                    else
                    {
                        if(abc(l,pos2-1,cntf,xorf)>=abc(l,r,cntf,xorf))
                        {
                            r = pos2-1;
                            for(int j=32;j>-1;j--)
                            {
                                if(vec[pos2]&(1LL<<j)) ara[j]--;
                            }
                        }
                    }
                }
            }
            while(l<r&&vec[l]==0) l++;
            while(r>l&&vec[r]==0) r--;
            cout<<l<<" "<<r<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
