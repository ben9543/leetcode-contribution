class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        hm = {}
        s = set()
        for n in arr:
            if n in hm:
                hm[n] += 1
            else:
                hm[n] = 1
        for k in hm:
            if hm[k] in s:return False
            i = hm[k]
            s.add(i)
        return True