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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        string sm, fm;
        char c;
        int sd,sy,fd,fy;
        cin>>sm>>sd>>c>>sy;
        cin>>fm>>fd>>c>>fy;
        if(sm!="January"&&sm!="February") sy++;
        if((fm=="January"||(fm=="February"&&fd<29))) fy--;
        int cnt = (fy/4)-((sy-1)/4);
        cnt-=(fy/100)-((sy-1)/100);
        cnt+=(fy/400)-((sy-1)/400);
        cout<<"Case "<<z<<": ";
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
