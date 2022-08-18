class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        sol = ""
        j = 0
        word = strs[0]
        for i in range(0, len(word)):
            for j in range(1, len(strs)):
                other = strs[j]
                if i >= len(other):
                    return sol
                if word[i] != other[i]:
                    return sol
            sol += word[i]
        return sol
