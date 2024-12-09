#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 100;
int n, ans, p, u, c, u_;
char s[N];
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	u = 1; c = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i + 1] == s[i - u + 1]) {
			u_++; if (u_ == u) {c++; u_ = 0;}
		}
		else if (s[i + 1] > s[i - u + 1]) {
			u = i - p + 1; c = 1; u_ = 0;
		}
		else {
			while (c--) {p += u; ans ^= p;}
			u = 1; c = 1; u_ = 0;
			i = p;
		}
	}
	printf("%d", ans); 
	return 0;
}
