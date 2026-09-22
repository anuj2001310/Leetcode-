class Solution:
    def resultArray(
        self, nums: List[int], k: int, queries: List[List[int]]
    ) -> List[int]:
        n = len(nums)

        tree = [(0, [0] * k) for _ in range(4 * n)]

        def make_leaf(value):
            r = value % k
            pref = [0] * k
            pref[r] = 1
            return r, pref

        def merge(left, right):
            left_prod, left_pref = left
            right_prod, right_pref = right

            total_prod = (left_prod * right_prod) % k
            pref = left_pref[:]

            for r in range(k):
                new_r = (left_prod * r) % k
                pref[new_r] += right_pref[r]

            return total_prod, pref

        def build(node, l, r):
            if l == r:
                tree[node] = make_leaf(nums[l])
                return

            mid = l + ((r - l) >> 1)

            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def update(node, l, r, idx, value):
            if l == r:
                tree[node] = make_leaf(value)
                return

            mid = l + ((r - l) >> 1)

            if idx <= mid:
                update(node * 2, l, mid, idx, value)
            else:
                update(node * 2 + 1, mid + 1, r, idx, value)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def query(node, l, r, ql, qr):
            if ql <= l and r <= qr:
                return tree[node]

            mid = l + ((r - l) >> 1)

            if qr <= mid:
                return query(node * 2, l, mid, ql, qr)

            if ql > mid:
                return query(node * 2 + 1, mid + 1, r, ql, qr)

            left = query(node * 2, l, mid, ql, qr)
            right = query(node * 2 + 1, mid + 1, r, ql, qr)

            return merge(left, right)

        build(1, 0, n - 1)

        result = []

        for index, value, start, x in queries:
            update(1, 0, n - 1, index, value)

            _, pref = query(1, 0, n - 1, start, n - 1)

            result.append(pref[x])

        return result