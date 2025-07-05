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
        string s;
        cin>>s;
        int mn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                int cnta = 0;
                int cntb = 0;
                int cntc = 0;
                for(int j=i;j<i+10&&j<n;j++)
                {
                    if(s[j]=='a') cnta++;
                    else if(s[j]=='b') cntb++;
                    else cntc++;
                    if(j-i+1>1&&cnta>cntb&&cnta>cntc) mn = min(mn,j-i+1);
                }
            }
        }
        if(mn==INT_MAX) mn = -1;
        cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
