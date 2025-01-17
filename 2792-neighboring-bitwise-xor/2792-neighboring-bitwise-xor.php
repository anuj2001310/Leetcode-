class Solution {

    /**
     * @param Integer[] $derived
     * @return Boolean
     */
    function doesValidArrayExist($derived) {
        $ans = 0;
        foreach ($derived as $num)
            $ans ^= $num;
        
        return $ans == 0;
    }
}