#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int INF = 1e8;
int a[105], pa[105], rot[105], prot[105], dp[105][105], sdp[105][105], ans, n, k;

int sum(int l, int r) {
	if(l <= r)
		return pa[r] - pa[l - 1];
	return pa[n] - (pa[l - 1] - pa[r]);
}

int rsum(int l, int r) {
	if(l > r)
		return -1;
	return prot[r] - prot[l - 1];
}

bool check(int l, int r, int bnd) {
	int S = sum(l, r);
	for(int i = 1; i <= n; i++) {
		rot[i] = a[(l + i - 2)%n + 1];
		prot[i] = prot[i - 1] + rot[i];
	}
	r -= (l - 1);
	l = 1;
	if(r < 1)
		r += n;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = sdp[i][j] = 0;
	int bl = 1, br = 1;
	dp[r][1] = 1;
	sdp[r][1] = 1;
	for(int p = r + 1; p <= n; p++) {
		while(rsum(bl, p) > S + bnd)
			bl++;
		while(rsum(br + 1, p) >= S)
			br++;
		for(int cnt = k; cnt >= 2; cnt--) {
			if(sdp[br - 1][cnt - 1] > (bl > 1 ? sdp[bl - 2][cnt - 1] : 0)) {
				dp[p][cnt] = 1;
			}
			sdp[p][cnt] = sdp[p - 1][cnt] + dp[p][cnt];
		}
		sdp[p][1] = sdp[p - 1][1] + dp[p][1];
	}
	return dp[n][k] > 0;
}

void solve(ii s) {
	if(ans == 0)
		return;
	int S = sum(s.first, s.second);
	int lo = 0, hi = INF;
	while(lo < hi) {
		int mi = (lo + hi)/2;
		if(check(s.first, s.second, mi))
			hi = mi;
		else
			lo = mi + 1;
	}
	ans = min(lo, ans);
}

int main() {
	cin >> k >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pa[i] = pa[i - 1] + a[i];
	}
	vector<ii> segs;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			segs.push_back({i, j});
	ans = INF;
	for(auto s : segs)
		solve(s);
	cout << ans << '\n';
}