l = int(input())
ans = 1
for i in range(11):
    ans = ans * (l-1-i)
for i in range(11):
    ans = ans // (11-i)

print (ans)