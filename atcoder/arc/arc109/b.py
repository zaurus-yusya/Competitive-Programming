

def binary_search(N, val):
    left = -1        # 探索する範囲の左端を設定
    right = N        # 探索する範囲の右端を設定
    while (right - left > 1):
        mid = (left + right) // 2            # 探索する範囲の中央を計算
        if (1+mid)*mid // 2 <= val:
            left = mid
        else:
            right = mid
    return left            # 見つからなかった場合

n = int(input()) 
x = n+1
tmp = binary_search(x, x)
#print(binary_search(x, x))
#print(tmp)

print(n - tmp +1)