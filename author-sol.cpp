#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll accurate_floor(ll a, ll b) {
    ll val = a / b;
    while (val * b > a) {
        val--;
    }
    return val;
}

void test_case(int& tc) {
    int n;
    ll k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll pref[n+1];
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + a[i];
    }
    ll ans = 1e18;
    for (int y = 0; y < n; y++) {
        ll x = a[0] - accurate_floor(k - pref[n-y] + a[0], y + 1);
        ans = min(ans, y + max(0LL, x));
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}

