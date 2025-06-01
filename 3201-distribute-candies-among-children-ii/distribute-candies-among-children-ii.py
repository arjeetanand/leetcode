class Solution(object):
    def distributeCandies(self, n, limit):
        c=0
        for i in range(min(n+1, limit+1)):
            if n-i<=limit:
                c+= n-i+1
            elif 2*limit>=n-i>limit:
                t= n-i-limit
                c+= limit-t+1
        return c