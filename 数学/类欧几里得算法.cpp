#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int P = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void  chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct info {
	int a[MAXN][MAXN];
};
int sum[MAXN][MAXN];
int binom[MAXN][MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
info func(int n, int a, int b, int c) {
	assert(n >= 0 && a >= 0 && b >= 0 && c >= 0);
	info ans;
	memset(ans.a, 0, sizeof(ans.a));
	if (a == 0 || (1ll * a * n + b) / c == 0) {
		for (int k1 = 0; k1 <= 10; k1++) {
			int mul = 0, now = 1;
			for (int i = 0; i <= k1 + 1; i++) {
				update(mul, 1ll * now * sum[k1][i] % P);
				now = 1ll * now * n % P;
			}
			int base = (1ll * a * n + b) / c % P; now = 1;
			for (int k2 = 0; k1 + k2 <= 10; k2++) {
				ans.a[k1][k2] = 1ll * now * mul % P;
				now = 1ll * now * base % P;
			}
		}
		return ans;
	}
	if (a >= c) {
		info tmp = func(n, a % c, b, c);
		for (int k1 = 0; k1 <= 10; k1++)
		for (int k2 = 0; k1 + k2 <= 10; k2++) {
			int now = 1, base = a / c;
			for (int i = 0; i <= k2; i++) {
				update(ans.a[k1][k2], 1ll * binom[k2][i] * now % P * tmp.a[k1 + i][k2 - i] % P);
				now = 1ll * now * base % P;
			}
		}
		return ans;
	}
	if (b >= c) {
		info tmp = func(n, a, b % c, c);
		for (int k1 = 0; k1 <= 10; k1++)
		for (int k2 = 0; k1 + k2 <= 10; k2++) {
			int now = 1, base = b / c;
			for (int i = 0; i <= k2; i++) {
				update(ans.a[k1][k2], 1ll * binom[k2][i] * now % P * tmp.a[k1][k2 - i] % P);
				now = 1ll * now * base % P;
			}
		}
		return ans;
	}
	int m = (1ll * a * n + b) / c;
	info tmp = func(m - 1, c, c - b - 1, a);
	for (int k1 = 0; k1 <= 10; k1++) {
		int all = 0, now = 1;
		for (int i = 0; i <= k1 + 1; i++) {
			update(all, 1ll * now * sum[k1][i] % P);
			now = 1ll * now * n % P;
		}
		for (int k2 = 0; k1 + k2 <= 10; k2++) {
			ans.a[k1][k2] = 1ll * power(m, k2) * all % P;
			for (int i = 0; i <= k2 - 1; i++)
			for (int j = 0; j <= k1 + 1; j++) {
				int coef = 1ll * binom[k2][i] * sum[k1][j] % P;
				update(ans.a[k1][k2], P - 1ll * coef * tmp.a[i][j] % P);
			}
		}
	}
	return ans;
}
void Lagrange(int n, int *x, int *y, int *a) {
	static int p[MAXN], q[MAXN];
	memset(p, 0, sizeof(p)); p[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			p[j + 1] = (p[j + 1] + p[j]) % P;
			p[j] = (P - 1ll * p[j] * x[i] % P) % P;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(q, 0, sizeof(q));
		for (int j = n - 1; j >= 0; j--)
			q[j] = (p[j + 1] + 1ll * q[j + 1] * x[i]) % P;
		int now = 1;
		for (int j = 1; j <= n; j++)
			if (j != i) now = 1ll * now * (x[i] - x[j]) % P;
		now = power((P + now) % P, P - 2);
		for (int j = 0; j <= n; j++)
			q[j] = 1ll * q[j] * now % P;
		for (int j = 0; j <= n; j++)
			a[j] = (a[j] + 1ll * q[j] * y[i]) % P;
	}
}
int main() {
	for (int i = 0; i <= 10; i++) {
		static int pos[MAXN], now[MAXN];
		now[0] = power(0, i);
		for (int j = 1; j <= i + 2; j++) {
			now[j] = (now[j - 1] + power(j, i)) % P;
			pos[j] = j;
		}
		Lagrange(i + 2, pos, now, sum[i]);
	}
	for (int i = 0; i <= 10; i++) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; j++)
			binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
	}
	int T; read(T);
	while (T--) {
		int n, a, b, c, k1, k2;
		read(n), read(a), read(b), read(c), read(k1), read(k2);
		writeln(func(n, a, b, c).a[k1][k2]);
	}
	return 0;
}
