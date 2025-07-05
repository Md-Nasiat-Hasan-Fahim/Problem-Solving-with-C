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

int abc(int a,int n)
{
    if(n-a<0) return 0; 
    int tn = (n-a)/4;
    tn++;
    return tn*(a+2*(tn-1));
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int x,n;
        cin>>x>>n;
        if(n==0)
        {
            cout<<x<<endl;
            continue;
        }
        int xy = abc(2,n)+abc(3,n);
        int yz = abc(4,n)+abc(5,n);
        //cout<<xy<<" "<<yz<<endl;
        if(x%2)
        {
            cout<<x+1-xy+yz<<endl;
        }
        else cout<<x-1+xy-yz<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
