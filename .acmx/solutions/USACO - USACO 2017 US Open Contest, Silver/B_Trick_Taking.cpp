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
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>vec1(n),vec2(n);
        for(int i=0;i<n;i++) cin>>vec1[i];
        for(int i=0;i<n;i++) cin>>vec2[i];
        int mx1=INT_MIN,pl1,cd1,cd2,mx2=INT_MIN,pl2;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                mx2 = vec2[i];
                cd2 = vec1[i];
                pl2 = i+1;
            }
            else if(cd2==vec1[i])
            {
                if(vec2[i]>mx2)
                {
                    mx2 = vec2[i];
                    pl2 = i+1;
                }
            }
            if(vec1[i]==k)
            {
                if(vec2[i]>mx1)
                {
                    mx1=vec2[i];
                    pl1 = i+1;
                }
            }

        }
        if(mx1!=INT_MIN) cout<<pl1<<endl;
        else cout<<pl2<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
