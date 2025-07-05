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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s="#"+s;
        vector<int>use(n+3);
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0')
            use[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(use[i]==1)
            {
                cnt+=i;
                //cout<<i<<" "<<cnt<<endl;
                use[i]++;
                for(int j=2;i*j<=n;j++)
                {
                    if(use[i*j]==1)
                    {
                        cnt+=i;
                        //cout<<i*j<<" "<<cnt<<endl;
                        use[i*j]++;
                    }
                    else break;
                }
            }
            else if(use[i]==2)
            {
                for(int j=2;i*j<=n;j++)
                {
                    if(use[i*j]==1)
                    {
                        //cout<<cnt<<endl;
                        cnt+=i;
                        //cout<<i*j<<" "<<cnt<<endl;
                        use[i*j]++;
                    }
                    else if(use[i*j]==2);
                    else break;
                }
            }
        }
        cout<<cnt<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
