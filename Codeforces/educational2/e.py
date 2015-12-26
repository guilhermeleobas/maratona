import sys

sys.setrecursionlimit(50000000)

# don't try to solve this problem with python
# Seriously!!!

def merge (l):
    ans = dict()

    for d in l:
        # print "merging", d
        for key in d:
            if key in ans:
                ans[key] += d[key]
            else:
                ans[key] = d[key]
        # print "ans", ans

    return ans

# v = vertice
# d = dict()
def get_max (v, d):
    m = max(d.values())

    for key in d:
        if d[key] == m:
            sum[v] += key

def dfs (g, v = 0):

    d = dict()
    d[colors[v]] = 1

    if (visited[v]):
        return None

    visited[v] = True

    if (g[v] == []):
        # print "return com v: ", v, " e d: ", d
        sum[v] = colors[v]
        return d

    l = [d]
    for i in g[v]:
        if (visited[i]):
            continue
        aux = dfs (g, i)
        # print "vertice", v, "i:", i, "aux:", aux
        l.append (aux)

    # print "vertice ", v, " lista: ", l
    ret_dict = merge(l)

    # print "after merge: ", ret_dict
    get_max (v, ret_dict)

    return ret_dict


n = map(int, raw_input().split())[0]
colors = map(int, raw_input().split())

g = [[] for i in range(n+100)]
visited = [False for i in range(n+100)]

for i in range (n-1):
    a, b = map(int, raw_input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)


sum = [0 for i in range(n+100)]

for i in range(n):
    if (visited[i] == False):
        dfs(g, i)

for i in range(n):
    print sum[i],
