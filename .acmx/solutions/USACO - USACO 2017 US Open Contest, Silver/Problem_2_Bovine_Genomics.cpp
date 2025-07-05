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
    freopen("cownomics.in","r+",stdin);
    freopen("cownomics.out","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<string>vec;
        for(int i=0;i<2*n;i++)
        {
            string s;
            cin>>s;
            vec.pb(s);
        }
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                for(int k=j+1;k<m;k++)
                {
                    bool ans = true;
                    set<int>st;
                    for(int l=0;l<n;l++)
                    {
                        int val = 31*(vec[l][i]-'A'+1)+31*31*(vec[l][j]-'A'+1)+31*31*31*(vec[l][k]);
                        st.insert(val);
                    }
                    for(int l=n;l<2*n;l++)
                    {
                        int val = 31*(vec[l][i]-'A'+1)+31*31*(vec[l][j]-'A'+1)+31*31*31*(vec[l][k]);
                        if(st.count(val)) ans=false;
                    }
                    if(ans) cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
