from functools import lru_cache


@lru_cache(maxsize=None)
def digital_root(number):
    result = sum(int(digit) for digit in str(number))
    return result if result < 10 else digital_root(result)


@lru_cache(maxsize=None)
def max_digital_root_sum(number):
    result = digital_root(number)
    divisor = 2
    sqrt_number = number ** 0.5
    while divisor <= sqrt_number:
        if number % divisor == 0:
            result = max([result,
                          digital_root(number // divisor) + max_digital_root_sum(divisor),
                          digital_root(divisor) + max_digital_root_sum(number // divisor)])
        divisor += 1
    return result


def solution(limit):
    return sum(max_digital_root_sum(n) for n in range(2, limit))


if __name__ == '__main__':
    print(solution(10 ** 6))
