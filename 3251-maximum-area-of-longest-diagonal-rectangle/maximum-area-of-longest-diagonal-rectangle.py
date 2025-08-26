from math import sqrt

class Solution:
    def areaOfMaxDiagonal(self, dimensions: list[list[int]]) -> int:
        dia, mx = 0, 0
        for l, w in dimensions:
            d, a = sqrt(l**2 + w**2), l*w
            if d > dia:
                dia, mx = d, a
            elif d == dia:
                mx = max(mx, a)
        return mx