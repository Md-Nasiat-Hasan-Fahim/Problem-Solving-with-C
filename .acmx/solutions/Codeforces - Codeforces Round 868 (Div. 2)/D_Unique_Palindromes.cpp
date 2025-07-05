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
        bool ans = true;
        int n,k;
        cin>>n>>k;
        vector<int>x(n);
        vector<int>c(n);
        for(int i=0;i<k;i++) cin>>x[i];
        for(int i=0;i<k;i++) cin>>c[i];
        queue<char>q;
        int p = 0, r = 3;
        if(c[0]>x[0])
        {
            NO;
            continue;
        }
        int tem = c[0];
        int y = x[0];
        while(tem>2)
        {
            q.push('a');
            y--;
            tem--;
        }
        p++;
        while(y)
        {
            y--;
            q.push('a'+p);
            p++;
            p%=3;
        }
        for(int i=1;i<k;i++)
        {
            int y = x[i]-x[i-1];
            int z = c[i]-c[i-1];
            if(z<0||z>y)
            {
                ans = false;
                break;
            }
            if(z==0)
            {
                while(y)
                {
                    y--;
                    q.push('a'+p);
                    p++;
                    p%=3;
                }
            }
            else
            {
                while(z)
                {
                    z--;
                    y--;
                    q.push(r+'a');
                }
                r++;
                while(y)
                {
                    y--;
                    q.push('a'+p);
                    p++;
                    p%=3;
                }
            }
        }
        y = n-x[k-1];
        while(y)
        {
            y--;
            q.push('a'+p);
            p++;
            p%=3;
        }
        if(ans)
        {
            YES;
            while(!q.empty())
            {
                cout<<q.front();
                q.pop();
            }
            cout<<endl;
        }
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
