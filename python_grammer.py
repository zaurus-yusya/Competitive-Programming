import sys
sys.setrecursionlimit(10 ** 7)
readline = sys.stdin.readline

def main():
    N, M = [int(x) for x in readline().rstrip().split()]
    A = [int(x) for x in readline().rstrip().split()]
    for a in A:
        print(a)

if __name__ == '__main__':
    main()