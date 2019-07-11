#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define test() int t;scanf("%d",&t);for(int tno=1;tno<=t;tno++)
#define mp make_pair
#define pb push_back
#define wl(n) while(n--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii ;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define sz(a) int((a).size())
#define ini(a,v) memset(a,v,sizeof(a))
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scs(s) scanf("%s",s);
#define debug() printf("here\n") 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define inf ((1<<29)-1)
#define linf ((1LL<<60)-1)
const double eps = 1e-9;
const int MAX = 300009;
const ll MOD = 1000000007;
//-----------------------------------------------------------------------------------------------
ll pw(ll base ,ll expo,ll c)
{
	if(expo == 0 )
	return  1 ; 
	ll f = pw(base , expo /2,c) ; 
	if(expo&1)
	return (((f*f)%c)*base)%c ; 
	return (f*f)%c;
}
 
int n;
string s;
ll A[MAX];
string p = "hard";
ll dp[MAX][5];
ll func(int i, int j){
    if(i>=n){
        if(j>=4)return linf;
        return 0;
    }
    if(j>=4)return linf;
    ll &ans = dp[i][j];
    if(ans!=-1)return ans;
    ans = linf;
    if(s[i]==p[j]){
        ans = min(ans,A[i]+func(i+1,j));
        ans = min(ans,A[i]+func(i+1,j+1));
        ans = min(ans,func(i+1,j+1));
    }else{
        ans = min(ans,func(i+1,j));
    }
    return ans;
}
int main() {
    sc(n);cin>>s;
    for(int i=0;i<n;i++){
        scl(A[i]);
    }
    ini(dp,-1);
    ll ans = func(0,0);
    printf("%lld\n",ans);
    return 0;
}