//Problema I (Repechaje 2019)
#include<algorithm>
#include<iostream>
#define N 1010
#define oo (1LL<<60)
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<string,ll> psi;

psi A[N];
ll F[N];

ll dp[2][N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x,n;
	ll a,k;
	string s;
	cin>>n;
	for(x=0;x<n;x++) {
		cin>>s>>a>>a;
		A[x]=mp(s,a);
	}
	sort(A,A+n);
	for(x=0;x<n;x++) 
		F[x]=A[x].second;
	int i,j;
	for(k=n;k>0;k--) {
		for(i=0;i<n;i++) {
			for(j=i;j<n && j-i <= n-k;j++) {
				dp[k&1][i][j]=oo;
				for(x=i;x<=j;x++) {	
					ll tmp=F[x]*k;
					if(x>i)
						tmp+=dp[(k+1)&1][i][x-1];
					if(x<j)
						tmp+=dp[(k+1)&1][x+1][j];
					dp[k&1][i][j]=min(dp[k&1][i][j],tmp);
				}
			}
		}
	}
	cout<<dp[1][0][n-1]<<endl;
	return 0;
}