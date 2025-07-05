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
int k;

long long POW(long long n, long long r)
{
    if(r==0) return 1LL;
    long long res = POW(n,r/2);
    res = 1LL*res*res;
    if(r%2LL==1LL) res = 1LL*n*res;
    return res;
}

void pqr(int x, vector<int>&vec)
{
    stack<int>q;
    while(x)
    {
        q.push(x%k);
        x/=k;
    }
    while(!q.empty())
    {
        vec[33-q.size()] = q.top();
        q.pop();
    }
}

int def(vector<int>vec)
{
    int cnt = 0;
    for(int i=0;i<33;i++)
    {
        if(vec[33-i-1])
        {
            cnt+=vec[33-i-1]*POW(k,i);
        }
    }
    return cnt;
}


int abc(int x)
{
    vector<int>vec1(33,0),vec2(33,0),vec(33,0);
    pqr(x,vec1);pqr(x-1,vec2);
    int carry = 0;
    for(int i=0;i<33;i++)
    {
        int x = (vec1[i]-vec2[i])%k;
        if(x<0) x+=k;
        x%=k;
        vec[i]=x;
    }
    return def(vec);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                cout<<abc(i)<<endl;
            }
            else
            {
                cout<<i<<endl;
            }
            int x;
            cin>>x;
            if(x==1)
            break;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
