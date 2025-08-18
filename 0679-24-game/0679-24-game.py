class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        if judge(cards, 24):
            return True

        first = [(0, 1), (0, 2), (0, 3)]
        second = [(2, 3), (1, 3), (1, 2)]
        for (i, j), (m, n) in zip(first, second):
            x, y = cards[i], cards[j]
            p, q = cards[m], cards[n]
            if any(
                abs(res - 24.0) < 1e-7
                for a in comb(x, y)
                for b in comb(p, q)
                for res in comb(a, b)
            ):
                return True
        return False


def comb(x, y):
    yield x + y
    yield x - y
    yield y - x
    yield x * y
    if y != 0:
        yield x / y
    if x != 0:
        yield y / x


def judge(cards, target):
    if len(cards) == 1:
        return cards[0] == target
    if len(cards) == 2:
        return any(abs(res - target) < 1e-7 for res in comb(*cards))
    for i in range(len(cards)):
        c = cards[i]
        rest = cards[:i] + cards[(i + 1) :]
        if any(
            (
                judge(rest, target + c),
                judge(rest, target - c),
                judge(rest, c - target),
                judge(rest, target * c),
                judge(rest, target / c) if c != 0 else False,
                judge(rest, c / target) if target != 0 else False,
            )
        ):
            return True
    return False