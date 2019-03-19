from functools import lru_cache


@lru_cache(maxsize=None)
def f(length, size):
    return 1 + sum(f(shorter, size) for shorter in range(length - size + 1))


def solution(length):
    return f(length, 4) + f(length, 3) + f(length, 2) - 3


if __name__ == '__main__':
    print(solution(50))
