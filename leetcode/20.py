class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False
        
        from collections import deque
        d = deque()
        
        pairs = (
            ('(', ')'),
            ('[', ']'),
            ('{', '}')
        )
        
        for e in s:
            if e in ('(', '[', '{'):
                d.append(e)
            else:
                if len(d) == 0:
                    return False
                last = d.pop()
                if (last, e) not in pairs:
                    return False
        return len(d) == 0
