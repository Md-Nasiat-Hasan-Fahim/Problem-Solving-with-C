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
        int cnt = 0;
        cin>>n;
        queue<pair<int,int>>neg,pos;
        int vec1[n],vec2[n];
        for(int i=0;i<n;i++)cin>>vec1[i];
        for(int i=0;i<n;i++)cin>>vec2[i];
        int ct = 0;
        for(int i=0;i<n;i++)
        {
            int x = vec1[i]-vec2[i];
            cnt+=x;
            if(x<0) neg.push({i,x});
            else if(x>0) {pos.push({i,x});ct+=x;}
        }
        if(cnt!=0)
        {
            cout<<"-1\n";
            continue;
        }
        int cx = 0,cy = 0,x,y;
        cout<<ct<<endl;
        while(1)
        {
            while(cx==0&&pos.size())
            {
                x = pos.front().first;
                cx = pos.front().second;
                pos.pop();
            }
            while(cy==0&&neg.size())
            {
                y = neg.front().first;
                cy = neg.front().second;
                neg.pop();
            }
            if(cx==0||cy==0) break;
            while(cx&&cy)
            {
                cout<<x+1<<" "<<y+1<<endl;
                cx--;cy++;
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
