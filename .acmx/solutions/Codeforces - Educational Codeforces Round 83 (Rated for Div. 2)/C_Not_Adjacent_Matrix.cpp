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

bool is_valid(int x, int y,int n)
{
    return x>-1&&x<n&&y>-1&&y<n;
}

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
        cin>>n;
        int vec[n][n];
        if(n==2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int cnt = 1;
        for(int j=n-1;j>-1;j-=2)
        {
            for(int k=n-1,l = j;k>-1&&l<n;k--,l++)
            {
                vec[k][l]=cnt++;
            }
        }
        int i = n-3;
        if(n%2==0) i=n-2;
        for(;i>=0;i-=2)
        {
            for(int j=0,k=i;j<n&&k>-1;j++,k--)
            {
                vec[k][j]=cnt++;
            }
        }
        int l = -1;
        if(n%2==1) l=0;
        for(int j=n-2;j>l;j-=2)
        {
            for(int k=n-1,l=j;k>-1,l<n;k--,l++)
            {
                vec[k][l]=cnt++;
            }
        }
        cnt=n*n;
        for(int i=1;i<n-1;i+=2)
        {
            for(int j=0,k=i;j<n&&k>-1;j++,k--)
            {
                vec[k][j]=cnt--;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
