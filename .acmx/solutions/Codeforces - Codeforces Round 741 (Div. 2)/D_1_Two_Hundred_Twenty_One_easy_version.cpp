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
vector<vector<int>>ara,bra;

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
        string s;
        cin>>s;
        s = "#"+s;
        n++;
        ara.assign(n+1,vector<int>(2));
        bra.assign(n+1,vector<int>(2));
        for(int i=1;i<n;i++)
        {
            if(i%2)
            {
                if(s[i]=='+')
                {
                    ara[i][0]++;
                    bra[i][1]++;
                }
                else
                {
                    ara[i][1]++;
                    bra[i][0]++;
                }
            }
            else
            {
                if(s[i]=='+')
                {
                    ara[i][1]++;
                    bra[i][0]++;
                }
                else
                {
                    ara[i][0]++;
                    bra[i][1]++;
                }
            }
            ara[i][0]+=ara[i-1][0];
            ara[i][1]+=ara[i-1][1];
            bra[i][0]+=bra[i-1][0];
            bra[i][1]+=bra[i-1][1];
        }
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            if(a%2)
            {
                int pos = ara[b][0]-ara[a-1][0];
                int neg = ara[b][1]-ara[a-1][1];
                cout<<labs(pos-neg)<<endl;
            }
            else
            {
                int pos = bra[b][0]-bra[a-1][0];
                int neg = bra[b][1]-bra[a-1][1];
                cout<<labs(pos-neg)<<endl;
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
