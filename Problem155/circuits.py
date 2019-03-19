from functools import lru_cache
from fractions import Fraction


c = Fraction(1, 1)


@lru_cache(maxsize=None)
def f(amount):
    if amount <= 1:
        return {c}
    circuits = set()
    for n in range(1, amount // 2 + 1):
        for a in f(n):
            for b in f(amount - n):
                circuits.update({series(a, b), parallel(a, b)})
    return circuits


def series(a, b):
    return a * b / (a + b)


def parallel(a, b):
    return a + b


def solution(amount):
    circuits = set()
    for n in range(1, amount + 1):
        circuits.update(f(n))
    return len(circuits)


if __name__ == '__main__':
    print(solution(18))
