#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 5e-10;

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
	cerr << fixed << setprecision(16);
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

bool incomp(int a1, int b1, int a2, int b2) {
	return (a1<a2 && b1>b2) || (a1>a2 && b1<b2);
}

const int N = 300+1;
int res[N];
int X[N], Y[N];
ld x;

bool cmp(int a, int b) {
	return X[a]*x + Y[a] < X[b]*x + Y[b];
}

const ll CAP = 1e16;
const ll P = 1234567891;
const ll A = 97;
const ll Q = 1e12-11;
const ll B = 101;

pll ha(int n) {
	ll a = 0;
	ll b = 0;
	for (int i=0; i<n; i++) {
		a = a*A + res[i];
		b = b*B + res[i];
		if (a>CAP) a%=P;
		if (b>CAP) b%=Q;
	}
	return pll(a%P, b%Q);
}

ld maxv;
pll solve(int n, int a1, int b1, int a2, int b2, const ld& e) {
	x = (ld)(b2-b1)/(a1-a2);
	maxv = max(maxv, x);
	x += e;
	sort(res, res+n, cmp);
	return ha(n);
}

void caseinit() {
}

void solve() {
	caseinit();

	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> X[i] >> Y[i];
		res[i] = i;
	}

	set<pll> ans;
	maxv = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (incomp(X[i], Y[i], X[j], Y[j])) {
				ans.insert(solve(n, X[i], Y[i], X[j], Y[j], -EPS));
			}
		}
	}
	x = maxv+1;
	sort(res, res+n, cmp);
	ans.insert(ha(n));
	cout << ans.size() << nl;

	return;
}


