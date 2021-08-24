import sys
sys.setrecursionlimit(10 ** 7)

##入出力
#1行入力
input = sys.stdin.readline
#変数
N, M = [int(x) for x in input().rstrip().split()]
#リスト
A = [int(x) for x in input().rstrip().split()]
#行列
S = [input().rstrip() for _ in range(N)]
#行列入れ替え
transpose = [x for x in zip(*S)]




def main():
    N, M = [int(x) for x in input().rstrip().split()]
    A = [int(x) for x in input().rstrip().split()]
    for a in A:
        print(a)

if __name__ == '__main__':
    main()

