# https://codeforces.com/problemset/problem/1519/A

# Solution

for s in [*open(0)][1:]: *a, d = map(int, s.split());r, b = sorted(a);print('YNEOS'[b - r > d * r::2])
