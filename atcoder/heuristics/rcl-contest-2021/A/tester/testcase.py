import random

N = 300
M = 1000
K = 100_000_000


class TestCase:

    def __init__(self, seed=None, input=None):
        if seed is not None:
            self.N = N
            self.M = M
            self.K = K
            self.A = []
            random.seed(seed)
            for i in range(self.N):
                self.A.append(random.randint(1, K - 1))
        else:
            itr = iter(input)
            self.N, self.M, self.K = list(map(int, next(itr).split()))
            self.A = list(map(int, next(itr).split()))

    def __str__(self):
        ret = "%d %d %d\n" % (self.N, self.M, self.K)
        return ret + " ".join(str(v) for v in self.A)
