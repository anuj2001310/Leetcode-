class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long currentmass = mass;
        int n = asteroids.length;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > currentmass)
                return false;
            currentmass += asteroids[i];
        }
        return true;
    }
}