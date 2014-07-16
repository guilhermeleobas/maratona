#http://codeforces.com/problemset/problem/104/C

def dfs (i):
	stack = [i];
	seen[i] = True
	while (stack):
		i = stack[len(stack)-1]
		stack.pop()
		seen[i] = True
		for j in range (len(graph[i])):
			v = graph[i][j]
			if (seen[v]): continue
			stack.append (v)
		

n, m = map (int, raw_input().split(' '))

graph = [[] for i in range (n)]

for i in range (m):
	u, v = map (int, raw_input().split (' '))
	u -= 1;
	v -= 1;
	graph[u].append (v)
	graph[v].append (u)

seen = [False]*n

dfs (0)

if (not seen.count(False) and m == n):
	print "FHTAGN!"
else:
	print "NO"
