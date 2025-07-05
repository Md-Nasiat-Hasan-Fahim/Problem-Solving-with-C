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

struct node
{
    int x1,y1,x2,y2;
};

int area(node a, node b)
{
    int length = max(0LL,min(a.x2,b.x2)-max(a.x1,b.x1));
    int width = max(0LL,min(a.y2,b.y2)-max(a.y1,b.y1));
    return length*width;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        node a,b,c;
        cin>>a.x1>>a.y1>>a.x2>>a.y2;
        cin>>b.x1>>b.y1>>b.x2>>b.y2;
        cin>>c.x1>>c.y1>>c.x2>>c.y2;
        int ar = (a.x2-a.x1)*(a.y2-a.y1);
        node d;
        d.x1 = max(b.x1,c.x1);
        d.x2 = min(b.x2,c.x2);
        d.y1 = max(b.y1,c.y1);
        d.y2 = min(b.y2,c.y2);
        //cout<<ar<<" "<<area(a,b)<<" "<<area(a,c)<<" "<<area(a,d)<<endl; 
        if(ar-area(a,b)-area(a,c)+area(a,d)>0) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
