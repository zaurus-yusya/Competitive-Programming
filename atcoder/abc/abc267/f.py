import sys
sys.setrecursionlimit(10**6)
n=int(input())
tree=[set([]) for _ in range(n)]
for _ in range(n-1):
    a,b=map(int,input().split())
    a-=1
    b-=1
    tree[a].add(b)
    tree[b].add(a)
q=int(input())
query=[tuple(list(map(int,input().split()))) for _ in range(q)]

# N: 木Tの頂点数
# G[u] = [(w, c), ...]:
#   頂点uに隣接する頂点wとそれを繋ぐ辺の長さc

from collections import deque
def bfs(s):
    global n,tree
    dist = [None]*n
    que = deque([s])
    dist[s] = 0
    while que:
        v = que.popleft()
        d = dist[v]
        for w in tree[v]:
            if dist[w] is not None:
                continue
            dist[w] = d + 1
            que.append(w)
    d = max(dist)
    return dist.index(d), d
startnode, _ = bfs(0)
endnode, d = bfs(startnode)

query_sakiyomi=[set([]) for _ in range(n)]
ans=[-1]*q
for i,(u,k) in enumerate(query):
    u-=1
    query_sakiyomi[u].add((k,i))


visited = set()
def saiki(node):
    global query_sakiyomi,ans,tree,ary, visited
    #print(ary)
    ary.append(node)
    visited.add(node)

    for (fukasa,i) in query_sakiyomi[node]:
        if fukasa <len(ary):
            ans[i]=ary[len(ary)-1-fukasa]+1
    
    for nextNode in tree[node]:
        if nextNode not in visited:
            saiki(nextNode)
        # if len(ary)==1:
        #     ary.append(nextNode)
        #     saiki(nextNode)
        # elif ary[-2]!=nextNode:
        #     ary.append(nextNode)
        #     saiki(nextNode)

    ary.pop()

ary=deque()
visited.clear()
saiki(startnode)
visited.clear()
ary=deque()
saiki(endnode)

# ary=deque([startnode])
# saiki(startnode)
# ary=deque([endnode])
# saiki(endnode)

for item in ans:
    print(item)




