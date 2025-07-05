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
        int n;
        cin>>n;
        vector<int>ara(n);
        for(int i=0;i<n;i++) cin>>ara[i];
        int cnt = 0;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(ara[i]!=i+1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"0\n"<<endl;
            continue;
        }
        //int cnt = 0;
        while(1)
        {
            int x = 0;
            bool abc = false;
            for(int i=1;i<n;i+=2)
            {
                if(ara[i-1]>ara[i])
                {
                    swap(ara[i-1],ara[i]);
                    abc = true;
                }
            }
            x+=abc;
            abc = false;
            for(int i=1;i<n-1;i+=2)
            {
                if(ara[i]<ara[i+1])
                {
                    swap(ara[i],ara[i+1]);
                    abc = true;
                }
            }
            x+=abc;
            if(!x) break;
            cnt+=x;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
