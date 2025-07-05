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
int cnt;
bool vis[1<<14];

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        int tc = 0;
        for(int i=0;i<12;i++)
        {
            if((tp&(1<<i)))
            tc++;
        }
        cnt=min(cnt,tc);
        for(int i=0;i<12;i++)
        {
            if((tp&(1<<i)))
            {
                if((i+2)<12&&(tp&(1<<(i+1)))&&!(tp&(1<<(i+2)))&&!vis[(tp^(1<<(i+1)))])
                {
                    vis[(tp^(1<<(i+1)))] = true;
                    int x = (tp^(1<<(i+1)));
                    x=(x^((1<<i)));
                    x = (x|((1<<(i+2))));
                    q.push(x);
                }
                if((i-2)>-1&&(tp&(1<<(i-1)))&&!(tp&(1<<(i-2)))&&!vis[(tp^(1<<(i-1)))])
                {
                    vis[(tp^(1<<(i-1)))] = true;
                    int x = (tp^(1<<(i-1)));
                    x=(x^((1<<i)));
                    x = (x|((1<<(i-2))));
                    q.push(x);
                }
            }
        }
    }
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        cnt = INT_MAX;
        memset(vis,false,sizeof(vis));
        string s;
        cin>>s;
        int val = 0;
        for(int i=0;i<12;i++)
        {
            if(s[i]=='o')
            val|=(1<<i);
        }
        bfs(val);
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
