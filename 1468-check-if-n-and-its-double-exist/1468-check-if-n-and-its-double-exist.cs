public class Solution {
    public bool CheckIfExist(int[] arr) {
        int i, j;
        for (i = 0; i < arr.Length; i++) {
            for (j = i + 1; j < arr.Length; j++) {
                if (arr[i] == 2 * arr[j] ||
                    (arr[j] % 2 == 0 && arr[i] == arr[j] / 2))
                    return true;
            }
        }
        return false;
    }
}