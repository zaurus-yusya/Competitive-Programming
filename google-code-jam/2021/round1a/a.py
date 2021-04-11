t = int(input())

for T in range(t):
    
    n = int(input())
    x = list(map(int,input().split()))

    ans = 0
    for i in range(1, n):

        if (x[i] > x[i-1]):
            continue
        bef = str(x[i-1])
        aft = str(x[i])

        if len(bef) == len(aft):
            x[i] = x[i] * 10
            ans += 1
            continue
        else:
            flag = 0
            for j in range(len(aft)):
                if bef[j] == aft[j]:
                    continue
                elif bef[j] < aft[j]:
                    flag = 1
                    break
                else:
                    flag = 2
                    break
            
            if flag == 0:
                nine = True
                for j in range(len(aft), len(bef)):
                    if bef[j] != '9':
                        nine = False
                        break

                if nine == True:
                    x[i] = x[i] * pow(10, len(bef) - len(aft) + 1)
                    ans += len(bef) - len(aft) + 1
                else:
                    x[i] = x[i-1] + 1
                    ans += len(bef) - len(aft)

            elif flag == 1:
                x[i] = x[i] * pow(10, len(bef) - len(aft))
                ans += len(bef) - len(aft)
            else:
                x[i] = x[i] * pow(10, len(bef) - len(aft) + 1)
                ans += len(bef) - len(aft) + 1




    print("Case #" + str(T+1) + ": " + str(ans))