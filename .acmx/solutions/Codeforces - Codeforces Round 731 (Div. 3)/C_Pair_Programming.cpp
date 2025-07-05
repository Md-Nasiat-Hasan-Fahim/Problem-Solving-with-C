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
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int k,n,m;
        cin>>k>>n>>m;
        vector<int>vec1(n),vec2(m);
        int ara1[301]={0},ara2[301]={0},cum[301]={0};
        for(int i=0;i<n;i++){
            cin>>vec1[i];
            ara1[vec1[i]]++;
        }
        for(int j=0;j<m;j++)
        {
            cin>>vec2[j];
            ara2[vec1[j]]++;
        }
        bool ans = true;
        vector<int>print;
        int i,j;
        for(i=0,j=0;;)
        {
            bool change = false;
            while(i<n&&vec1[i]<=k){print.pb(vec1[i]);if(vec1[i]==0)k++;change=true;i++;}
            while(j<m&&vec2[j]<=k){print.pb(vec2[j]);if(vec2[j]==0)k++;change=true;j++;}
            if(!change) break;
        }
        if(i==n&&j==m)
        {
            for(auto x:print) cout<<x<<" ";
            cout<<endl;
        }
        else cout<<"-1"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
