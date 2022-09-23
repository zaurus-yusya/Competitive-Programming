n,m,e=map(int,input().split())
uv=[]
for _ in range(e):
    u,v=map(int,input().split())
    u-=1
    v-=1
    if u>n:
        u=n
    if v>n:
        v=n
    uv.append((u,v))

query=[]
q=int(input())
for _ in range(q):
    query.append(int(input())-1)

ans=[]

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

uf = UnionFind(n+1)
size=[1]*(n+1)
for i,(u,v) in enumerate(uv):
    if i not in query:
        if u>n:
            u=n
        if v>n:
            v=n
        if uf.same(u, v):
            continue
        else:
            tmp1=uf.find(u)
            tmp2=uf.find(v)
            uf.union(u, v)
            size[uf.find(u)]=size[tmp1]+size[tmp2]
ans.append(size[uf.find(n)]-1)
#print(size)
#print(uf)
for tmp in query[::-1]:
    (u,v)=uv[tmp]
    #print(u,v)
    if u>n:
        u=n
    if v>n:
        v=n
    #print(u,v)
    if uf.same(u, v):
        ans.append(ans[-1])
    else:
        tmp1=size[uf.find(u)]
        tmp2=size[uf.find(v)]
        uf.union(u, v)
        #print("##",tmp1,tmp2)
        size[uf.find(u)]=tmp1+tmp2
        ans.append(size[uf.find(n)]-1)
    #print(">>",size)
    #print(uf)
#print(">>")

for i,item in enumerate(ans[::-1]):
    if i!=0:
        print(item)