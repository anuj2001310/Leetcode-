class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        left = 0
        one = 0
        ans = ""

        for right in range(n):
            if s[right] == '1':
                one += 1

            while one > k:
                if s[left] == '1':
                    one -= 1
                left += 1

            while one == k and s[left] == '0':
                left += 1

            if one == k:
                curr = s[left:right + 1]

                if not ans or len(curr) < len(ans) or \
                   (len(curr) == len(ans) and curr < ans):
                    ans = curr

        return ans