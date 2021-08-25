import sys
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
#stringをreadlineした場合最後に改行が入る

from collections import deque

from collections import defaultdict

def main():
    d = defaultdict(int)
    d[3] = 8
    d[2]+=1
    d[5]+=3
    a = sorted(d)
    for k, v in d.items():
        print(k, v)
    for aa in a:
        print(aa)




if __name__ == '__main__':
    main()