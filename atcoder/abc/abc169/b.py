a = int(input())
i = list(map(int, input().split()))

ans = 1
flag = 0

if i.count(0) > 0:
    print(0)
    flag = 1

if flag == 0:
    for x in range(len(i)):
        ans = ans * i[x]
        if ans > 1000000000000000000:
            flag = 1
            break

    if flag == 1:
        print(-1)
    elif flag == 2:
        print(0)
    else:
        print(ans)