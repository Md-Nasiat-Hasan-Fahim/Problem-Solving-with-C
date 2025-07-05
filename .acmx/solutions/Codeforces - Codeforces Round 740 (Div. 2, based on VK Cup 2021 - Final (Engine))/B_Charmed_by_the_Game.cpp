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


bool abc(int i, int a, int b, int x1 , int y1)
{
    int ta = a, tb = b, tx = x1, ty = y1,ti=i;
    int mn = min(a,i);
    a-=mn;i-=mn;y1-=mn;x1-=a;
    if(x1==i&&b>=i&&y1+i==b) return true;
    a = ta;b = tb;x1=tx;y1=ty;i=ti;
    mn = min(b,i);
    b-=mn;i-=mn;x1-=mn;y1-=b;
    if(y1==i&&a>=i&&x1+i==a) return true;
    return false;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int a,b;
        cin>>a>>b;
        queue<int>q;
        for(int i=0;i<=a+b;i++)
        {
            int x = ceil((a+b)/2.0); int y = a+b-x;
            if(abc(i,a,b,x,y)||abc(i,a,b,y,x)) q.push(i);
        }
        cout<<q.size()<<endl;
        while(q.size())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
