class FoodRatings {
    
    HashMap<String, TreeSet<String>> map;
    HashMap<String, String> type;
    HashMap<String, Integer> rating;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        map = new HashMap<>();
        type = new HashMap<>();
        rating = new HashMap<>();
        for (int i = 0; i < foods.length; i++) {
            if (!map.containsKey(cuisines[i])) {
                map.put(cuisines[i], new TreeSet<>((a, b) -> (int)rating.get(b) == rating.get(a) ? a.compareTo(b) : (int)rating.get(b) - rating.get(a)));
            }
            rating.put(foods[i], ratings[i]);
            map.get(cuisines[i]).add(foods[i]);
            type.put(foods[i], cuisines[i]);
        }
    }
    
    public void changeRating(String food, int newRating) {
        map.get(type.get(food)).remove(food);
        rating.put(food, newRating);
        map.get(type.get(food)).add(food);
    }
    
    public String highestRated(String cuisine) {
        return map.get(cuisine).first();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */