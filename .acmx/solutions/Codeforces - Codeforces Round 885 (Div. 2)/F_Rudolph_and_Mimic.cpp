#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;
vector<int>prv[11],now[11];

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        for(int i=0;i<11;i++) now[i].clear(),prv[i].clear();
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            now[a].pb(i+1);
        }
        cout<<"-"<<" "<<"0"<<endl;cout.flush();
        bool flag = false;
        int ct = 0;
        int fn = false;
        int run = 5;
        while(run--)
        {
            if(!flag)
            {
                for(int i=0;i<11;i++) prv[i]=now[i];
                for(int i=0;i<11;i++) now[i].clear();
                for(int i=0;i<n;i++)
                {
                    int a;
                    cin>>a;
                    now[a].pb(i+1);
                }
                for(int i=0;i<11;i++)
                {
                    if(prv[i].size()+1==now[i].size())
                    {
                        flag = true;
                        ct = i;
                        break;
                    }
                }
                if(flag)
                {
                    cout<<"-"<<" "<<n-now[ct].size()<<" ";cout.flush();
                    for(int i=0;i<11;i++)
                    {
                        if(i==ct) continue;
                        for(int j=0;j<now[i].size();j++) cout<<now[i][j]<<" ",cout.flush();
                    }
                    cout<<endl;cout.flush();
                    n = now[ct].size();
                }
                else
                {
                    cout<<"-"<<" "<<"0"<<endl;cout.flush();
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    int a;
                    cin>>a;
                    if(a!=ct)
                    {
                        cout<<"! "<<i+1<<endl;cout.flush();
                        fn = true;
                        break;
                    }
                }
                if(!fn) cout<<"- 0"<<endl;
                else break;
                cout.flush();
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
