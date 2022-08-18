class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = dict()
        sol = 0
        for i, c in enumerate(s):
            if c in d:
                curr_c_idx = d[c]
                elems_to_remove = []
                for k, v in d.items():
                    if v <= curr_c_idx:
                        elems_to_remove.append(k)
                for k in elems_to_remove:
                    d.pop(k)
                d[c] = i
            else:
                d[c] = i
                sol = max(sol, len(d))
        return sol
