class Solution {
    public String findShortestWay(int[][] maze, int[] start, int[] destination) {
        int m = maze.length;
        int n = maze[0].length;
        int[][] direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        String[] way = {"r", "l", "d", "u"};        
        Queue<int[]> queue = new LinkedList<>();        
        String[][] instruction = new String[m][n];
        int[][] distance = new int[m][n];

        for (int[] row : distance){
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        for (String[] row : instruction){
            Arrays.fill(row, "z");
        }
        distance[start[0]][start[1]] = 0;
        instruction[start[0]][start[1]] = "";
        queue.offer(start); // x, y, dist, path_hash
        
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int curX = cur[0], curY = cur[1];            
            for (int i = 0; i < 4; i++){
                int[] dir = direction[i];
                int x = curX, y = curY;
                int dist = distance[curX][curY];
                String newInstruction = instruction[curX][curY]+way[i];                
                while (x+dir[0]>=0 && x+dir[0]<m && y+dir[1]>=0 && y+dir[1]<n 
                       && maze[x+dir[0]][y+dir[1]]==0){
                    x += dir[0];
                    y += dir[1];
                    dist++;
                    if (x == destination[0] && y == destination[1]) break;
                }                
                if(dist < distance[x][y] || 
                   (dist == distance[x][y] && newInstruction.compareTo(instruction[x][y]) < 0)) {
                    distance[x][y] = dist;
                    instruction[x][y] = newInstruction;
                    queue.offer(new int[]{x,y});
                }
            } 
        }
        
        if (distance[destination[0]][destination[1]] == Integer.MAX_VALUE) 
            return "impossible";
        return instruction[destination[0]][destination[1]];
    }
}