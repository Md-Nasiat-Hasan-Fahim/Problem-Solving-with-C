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
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,l,r;
        cin>>n>>l>>r;
        vector<int>left(n+1),right(n+1);
        for(int i=0;i<l;i++)
        {
            int a;
            cin>>a;
            left[a]++;
        }
        for(int i=0;i<r;i++)
        {
            int a;
            cin>>a;
            right[a]++;
        }
        for(int i=0;i<=n;i++)
        {
            int x = min(left[i],right[i]);
            left[i]-=x;
            right[i]-=x;
        }
        multiset<int>lf,rt;
        for(int i=0;i<=n;i++)
        if(left[i]) lf.insert(left[i]);
        for(int i=0;i<=n;i++)
        if(right[i])rt.insert(right[i]);
        //cout<<rt.size()<<" "<<lf.size()<<endl;
        //cout<<right[2]<<" "<<left[1]<<endl;
        int cnt = 0;
        while(!lf.empty()&&!rt.empty())
        {
            int ltp = *lf.begin();
            lf.erase(lf.begin());
            int rtp = *rt.begin();
            rt.erase(rt.begin());
            //cout<<ltp<<" "<<rtp<<endl;
            if(ltp==rtp) cnt+=ltp;
            else if(ltp>rtp)
            {
                cnt+=rtp;
                lf.insert(ltp-rtp);
            }
            else 
            {
                cnt+=ltp;
                rt.insert(rtp-ltp);
            }
        }
        //cout<<cnt<<endl;
        //cout<<rt.size()<<" "<<lf.size()<<endl;
        int rem = 0;
        while(!rt.empty())
        {
            int x = *rt.begin();
            cnt+=(x/2);
            rem+=x%2;
            rt.erase(rt.begin());
        }
        while(!lf.empty())
        {
            int x=*lf.begin();
            cnt+=(x/2);
            rem+=x%2;
            lf.erase(lf.begin());
        }
        //cout<<cnt<<" "<<rem<<endl;
        if(rem) cnt+=(rem/2)+(rem/2);
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
