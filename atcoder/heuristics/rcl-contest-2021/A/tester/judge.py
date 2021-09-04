from sys import argv
from testcase import TestCase
import math
import sys


debug = False


def usage():
    print("python judge.py [testdata_file_path] [output_file_path]")


def judge(tc, output):
    if len(output) > tc.M:
        raise RuntimeError("[ERROR] 出力が%d行を超えています" % (tc.M,))

    for i, row in enumerate(output, start=1):
        if len(row) != 2 or not(0 <= row[0] < tc.N) or not(0 <= row[1] < tc.N):
            raise RuntimeError("[ERROR] %d行目 出力が不正です : %s" % (i, ' '.join(map(str, row))))
        tc.A[row[0]] = (tc.A[row[0]] + tc.A[row[1]]) % tc.K

    score = 0.0
    for i, v in enumerate(tc.A):
        s = math.log2(tc.K) - math.log2(v + 1)
        score += s
        if debug:
            print('%3d: %8d %6.3f' % (i, v, s), file=sys.stderr)
    if len(list(v for v in tc.A if v != 0)) <= 1:
        if debug:
            print('bonus: %d' % (tc.M - len(output),), file=sys.stderr)
        score += tc.M - len(output)
    return math.ceil(score)


if __name__ == '__main__':
    if len(argv) < 3:
        usage()
        exit(1)
    with open(argv[1]) as in_file:
        tc = TestCase(input=in_file)
    with open(argv[2]) as out_file:
        output = []
        for i, row in enumerate(out_file, start=1):
            try:
                output.append(list(map(int, row.split())))
            except Exception:
                raise RuntimeError("[ERROR] %d行目 出力が不正です : %s" % (i, row))
    score = judge(tc, output)
    print("score:%d" % score)
