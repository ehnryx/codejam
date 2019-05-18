#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	return os << '(' << v.first << ',' << v.second << ')';
}
template <class T> 
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}
template <class T> 
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; 
	return os << '}';
}
template <class T, class U> 
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ "; for (const pair<T,U>& it : v) os << it << " ";
	return os << '}';
}

////////////////////////////////////////////////////////////////////////

void solve();
void init() {
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
	init();

	int T;
	cin >> T;
	for (int cc = 1; cc <= T; cc++) {
		cout << "Case #" << cc << ": ";
		solve();
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////

struct Frac {
	ll n, d;
	Frac(ll a=0, ll b=1) {
		ll g = __gcd(a,b);
		n = a/g; d = b/g;
	}
	bool operator < (const Frac& o) const {
		return n*o.d < d*o.n;
	}
};

const int N = 17;
int a[N], b[N];

bool smaller(int i, int j) {
	return a[i]<=a[j] && b[i]<=b[j];
}

void caseinit() {
}

void solve() {
	caseinit();

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	Frac minv(0,1);
	Frac maxv(INF,1);
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (smaller(i,j)) {
				cout << "IMPOSSIBLE" << nl;
				return;
			}
			if (!smaller(j,i)) {
				if (a[i] < a[j]) {
					maxv = min(maxv, Frac(b[i]-b[j], a[j]-a[i]));
				} else {
					minv = max(minv, Frac(b[j]-b[i], a[i]-a[j]));
				}
			}
		}
	}

	if (!(minv < maxv)) {
		cout << "IMPOSSIBLE" << nl;
		return;
	}

	for (int n=1; n<=1000; n++) {
		for (int d=1; d<=1000; d++) {
			Frac x(n,d);
			if (minv < x && x < maxv) {
				cout << n << " " << d << nl;
				return;
			}
		}
	}
	assert(false);

	return;
}

