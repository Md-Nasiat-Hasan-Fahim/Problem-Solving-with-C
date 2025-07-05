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
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int x1,p1,x2,p2;
        cin>>x1>>p1>>x2>>p2;
        if(abs(p1-p2)<10)
        {
            while(p1>p2)x1*=10,p1--;
            while(p1<p2)x2*=10,p2--;
        }
        int y1 = x1,y2 = x2;
        while(y1)
        {
            p1++;
            y1/=10;
        }
        while(y2)
        {
            p2++;
            y2/=10;
        }
        if(p1==p2)
        {
            if(x1>x2) cout<<">"<<endl;
            else if(x1<x2) cout<<"<"<<endl;
            else cout<<"="<<endl;
        }
        else if(p1>p2) cout<<">"<<endl;
        else cout<<"<"<<endl;
        //cout<<p1<<" "<<p2<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
