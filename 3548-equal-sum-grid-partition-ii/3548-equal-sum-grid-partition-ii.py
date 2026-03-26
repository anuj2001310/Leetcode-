class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m = len(grid)
        n = len(grid[0])
        num_map = Counter(chain.from_iterable(grid))

        
        def partition(m, n):
            seen_map = Counter(grid[0])
            rows_sum = [sum(row) for row in grid]
            total_sum = sum(rows_sum)
            current_sum = rows_sum[0]
            remain_sum = total_sum-current_sum
            if current_sum == remain_sum:
                return True
            num_ignore = abs(current_sum-remain_sum)
            if current_sum<remain_sum and num_map[num_ignore] - seen_map[num_ignore] > 0 and m>2:
                if n>1:
                    return True
                elif grid[1][0] == num_ignore or grid[m-1][0] == num_ignore:
                    return True
            elif current_sum>remain_sum and seen_map[num_ignore] > 0 and (grid[0][0]==num_ignore or grid[0][n-1]==num_ignore):
                return True

            for row in range(1, m-2):
                seen_map.update(grid[row])
                current_sum += rows_sum[row]
                remain_sum = total_sum-current_sum
                if current_sum == remain_sum:
                    return True
                num_ignore = abs(current_sum-remain_sum)
                if current_sum<remain_sum and num_map[num_ignore] - seen_map[num_ignore] > 0:
                    if n>1:
                        return True
                    elif grid[row+1][0] == num_ignore or grid[m-1][0] == num_ignore:
                        return True
                elif current_sum>remain_sum and seen_map[num_ignore] > 0:
                    if n>1:
                        return True
                    elif grid[0][0] == num_ignore or grid[row][0] == num_ignore:
                        return True

            if m>2:
                seen_map.update(grid[m-2])
                current_sum += rows_sum[m-2]
                remain_sum = rows_sum[m-1]
            if current_sum == remain_sum:
                return True
            num_ignore = abs(current_sum-remain_sum)
            if current_sum<remain_sum and num_map[num_ignore] - seen_map[num_ignore] > 0 and (grid[m-1][0]==num_ignore or grid[m-1][n-1]==num_ignore):
                return True
            elif current_sum>remain_sum and seen_map[num_ignore] > 0 and m>2:
                if n>1:
                    return True
                elif grid[0][0] == num_ignore or grid[m-2][0] == num_ignore:
                    return True

            return False
        
        result = partition(m, n)   
        if result:
            return True
        grid = list(zip(*grid))
        return partition(n, m) 
