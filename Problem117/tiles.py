from functools import lru_cache


@lru_cache(maxsize=None)
def solution(length):
    if length < 0:
        return 0
    if length in {0, 1}:
        return 1
    return sum([2 * solution(length - 2),
                2 * solution(length - 3),
                2 * solution(length - 4),
                solution(length - 5)])


if __name__ == '__main__':
    print(solution(50))
