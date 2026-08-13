class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)

        # Each node stores: [left_char, right_char, prefix_len, suffix_len, max_len, length_of_range]
        tree = [None] * (4 * n)

        def merge(a, b):
            if a is None:
                return b
            if b is None:
                return a

            left_char = a[0]
            right_char = b[1]

            prefix = a[2]
            suffix = b[3]
            maximum = max(a[4], b[4])

            # If the adjacent boundary characters match:
            if a[1] == b[0]:
                # If segment 'a' is composed of all identical characters
                if a[2] == a[5]:
                    prefix = a[2] + b[2]

                # If segment 'b' is composed of all identical characters
                if b[3] == b[5]:
                    suffix = a[3] + b[3]

                maximum = max(maximum, a[3] + b[2])

            total_length = a[5] + b[5]
            return [left_char, right_char, prefix, suffix, maximum, total_length]

        def build(node, l, r):
            if l == r:
                # [left_char, right_char, prefix_len, suffix_len, max_len, segment_len]
                tree[node] = [s[l], s[l], 1, 1, 1, 1]
                return

            mid = (l + r) // 2

            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def update(node, l, r, idx, char):
            if l == r:
                tree[node] = [char, char, 1, 1, 1, 1]
                return

            mid = (l + r) // 2

            if idx <= mid:
                update(node * 2, l, mid, idx, char)
            else:
                update(node * 2 + 1, mid + 1, r, idx, char)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        build(1, 0, n - 1)

        res = []

        for char, idx in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, idx, char)
            res.append(tree[1][4])

        return res