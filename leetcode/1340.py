from collections import defaultdict

class Solution:
    def buildGraph(self, arr, d):
        g = defaultdict(list)
        n = len(arr)
        for i in range(n):
            maxval = 0
            for j in range(i-1, i-d-1, -1):
                if 0 <= j < n and i != j:
                    if arr[i] > arr[j] and arr[i] > maxval:
                        g[i].append(j)
                    maxval = max(maxval, arr[j])

            maxval = 0
            for j in range(i, i+d+1, 1):
                if 0 <= j < n and i != j:
                    if arr[i] > arr[j] and arr[i] > maxval:
                        g[i].append(j)
                    maxval = max(maxval, arr[j])

        return g

    def dfs(self, g, u, dist):
        if dist[u] != 0:
            return dist[u]
        m = 0
        for v in g[u]:
            m = max(m, self.dfs(g, v, dist))
        dist[u] = m + 1
        return dist[u]

    def maxJumps(self, arr, d):
        g = self.buildGraph(arr, d)
        n = len(arr)
        dist = [0] * (n)
        m = 0
        for u in range(n):
            if dist[u] == 0:
                m = max(m, self.dfs(g, u, dist))
        return m
