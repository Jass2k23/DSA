#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, nt = 0, n;
	cin >> n;
	vector<int> a;

	a.push_back(1);
	x = 0;
	y = 1;

	for (int i = 0; i <= n; i++)
	{
		nt = x + y;
		a.push_back(nt);
		x = y;
		y = nt;
	}
	if (n == 1 || n == 2)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << a[n - 1] << endl;
	}
}