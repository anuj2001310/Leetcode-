class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int len1 = version1.length(), len2 = version2.length();
        int num1 = 0, num2 = 0;
        while (i < len1 or j < len2) {
            while (i < len1 and version1.at(i) != '.')
                num1 = num1 * 10 + (version1.at(i++) - '0');
            while (j < len2 and version2.at(j) != '.')
                num2 = num2 * 10 + (version2.at(j++) - '0');

            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            num1 = 0, num2 = 0;
            if (i < len1)
                i++;
            if (j < len2)
                j++;
        }
        return 0;
    }
};