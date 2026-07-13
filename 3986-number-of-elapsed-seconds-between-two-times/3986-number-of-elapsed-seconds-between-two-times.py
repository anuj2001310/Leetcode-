class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        s = startTime.split(':')
        e = endTime.split(':')
        hours = int(e[0]) - int(s[0])
        mins = int(e[1]) - int(s[1])
        seconds = int(e[2]) - int(s[2])

        return seconds + 60 * mins + 60 * 60 * hours