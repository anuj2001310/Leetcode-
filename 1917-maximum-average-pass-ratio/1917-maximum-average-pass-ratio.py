class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n = len(classes)
        impacts = [0] * n

        # Calculate and store impacts for each class in form of tuples
        for i in range(n):
            pass_count = classes[i][0]
            total_count = classes[i][1]

            # Calculate the impact for class i
            current_ratio = pass_count / total_count
            expected_ratio_after_update = (pass_count + 1) / (total_count + 1)
            impact = expected_ratio_after_update - current_ratio

            impacts[i] = (-impact, pass_count, total_count) # '-' sign to make mimic max_heap using python's heapq module
        
        heapq.heapify(impacts)

        while extraStudents > 0:
            # pick the next class with greatest impact
            _, pass_count, total_count = heapq.heappop(impacts)

            # assign a student to the class
            pass_count += 1
            total_count += 1

            # Calculate the updated impact for current class
            current_ratio = pass_count / total_count
            expected_ratio_after_update = (pass_count + 1) / (total_count + 1)
            impact = expected_ratio_after_update - current_ratio

            # Insert updated impact back into the heap
            heapq.heappush(impacts, (-impact, pass_count, total_count))
            extraStudents -= 1

        result = 0

        for _, pass_count, total_count in  impacts:
            result += pass_count / total_count
        
        # return the avearage pass ratio
        return result / n