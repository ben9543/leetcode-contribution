class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        count = 0
        i = 0
        l = len(intervals)-1
        intervals.sort()
        while count < l:
            # If the two intervals are overlapping,
            if intervals[i][1] >= intervals[i+1][0]: 
                maxY = max(intervals[i][1], intervals[i+1][1])
                intervals[i][1] = maxY
                intervals.pop(i+1)
            else:
                i+=1
            count+=1
        return intervals