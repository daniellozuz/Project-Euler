from functools import lru_cache


@lru_cache(maxsize=None)
def solution(length):
    if length < 0:
        return 0
    if length == 0:
        return 1
    return sum(solution(length - decrement - 1) for decrement in range(4))


if __name__ == '__main__':
    print(solution(50))
