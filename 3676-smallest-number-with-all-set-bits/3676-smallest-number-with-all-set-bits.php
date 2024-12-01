class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function smallestNumber($n) {
        while (($n & ($n + 1)) != 0)
            $n |= ($n >> 1);
        return $n;
    }
}