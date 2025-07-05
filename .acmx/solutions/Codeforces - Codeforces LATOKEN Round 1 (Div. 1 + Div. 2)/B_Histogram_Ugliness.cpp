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
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(n>1&&vec[i]>vec[i+1])
                {
                    cnt += vec[0]-vec[1];
                    vec[0]=vec[1];
                }
            }
            else if(i==n-1)
            {
                if(n>1&&vec[n-1]>vec[n-2])
                {
                    cnt +=vec[n-1]-vec[n-2];
                    vec[n-1]=vec[n-2];
                }
            }
            else
            {
                int x = max(vec[i-1],vec[i+1]);
                if(vec[i]>x)
                {
                    cnt+=vec[i]-x;
                    vec[i]=x;
                }
            }
        }
        cnt+=vec[0];
        if(n>1) cnt+=vec[n-1];
        for(int i=1;i<n;i++)
        {
            cnt+=abs(vec[i]-vec[i-1]);
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
