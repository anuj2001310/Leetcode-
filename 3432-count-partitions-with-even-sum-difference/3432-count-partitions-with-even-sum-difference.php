class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function countPartitions($nums) {
        $s = array_sum($nums);
        if ($s % 2 != 0) {
            return 0;
        }

        $left = 0;
        $cnt = 0;

        for ($i = 0; $i < count($nums) - 1; $i++) {
            $left += $nums[$i];
            $temp = $s - 2 * $left;
            if (($temp  & 1) == 0) {
                $cnt++;
            }
        }

        return $cnt;
    }
}