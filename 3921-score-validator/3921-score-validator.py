class Solution:
    def scoreValidator(self, events: list[str]) -> list[int]:
        s = c = 0
        for event in events:
            if c == 10:
                break
            if event == "W":
                c += 1

            elif event == "WD" or event == "NB":
                s += 1
            else:
                s = s + (ord(event) - 48)

        return [s, c]
