from functools import lru_cache


@lru_cache(maxsize=None)
def f(sheets):
    return (len(sheets) == 1) + sum((1 / len(sheets)) * f(left(sheets, sheet)) for sheet in sheets)


def left(sheets, sheet):
    new_sheets = list(sheets)
    new_sheets.remove(sheet)
    new_sheets.extend(range(sheet + 1, 6))
    return tuple(new_sheets)


if __name__ == '__main__':
    print(round(f(tuple([1])), 6))
