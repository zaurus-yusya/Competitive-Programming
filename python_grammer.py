import sys
sys.setrecursionlimit(10 ** 7)

##入出力
#1行入力
input = sys.stdin.readline
#変数
N, M = [int(x) for x in input().rstrip().split()]
#リスト
A = [int(x) for x in input().rstrip().split()]
#1行に1つ N行
B = [input() for _ in range(N)]
#行列
S = [input().rstrip().split() for _ in range(N)]
#行列入れ替え
transpose = [x for x in zip(*S)]
#複数行行数分からず
listA=[]
while True:
    try:
        listA.append(input().split())
    except:
        break

#リスト初期化
A = [0] * N

#ソート
A.sort()      #Aをソート
B = sorted(A) #新しいリスト生成
A.sort(reverse=True) #降順

#stack queue deque
from collections import deque
d = deque()
d.append(2)     #右側追加
d.appendleft(3) #左側追加
d.pop()         #右側削除
d.popleft()     #左側削除

len(d) > 0      #emptyかどうかチェック
print(d[0])     #左側取得
print(d[-1])    #右側取得

#辞書
from collections import defaultdict
d = defaultdict(int)
d[3] = 8
d[2]+=1
d[5]+=3
a = sorted(d)          #keyをソートしてlistに入れる
for k, v in d.items(): #ソートされてない
    print(k, v)
for aa in a:           #keyをリストに入れる      
    print(aa)


def main():
    N, M = [int(x) for x in input().rstrip().split()]
    A = [int(x) for x in input().rstrip().split()]
    for a in A:
        print(a)

if __name__ == '__main__':
    main()

