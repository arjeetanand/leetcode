class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def remove_substring(s, a, b, value):
            stack = []
            score = 0
            for ch in s:
                if stack and stack[-1] == a and ch == b:
                    stack.pop()
                    score += value
                else:
                    stack.append(ch)
            return "".join(stack), score

        # Step 1: Decide which pattern to remove first
        if x > y:
            s, score1 = remove_substring(s, 'a', 'b', x)
            _, score2 = remove_substring(s, 'b', 'a', y)
        else:
            s, score1 = remove_substring(s, 'b', 'a', y)
            _, score2 = remove_substring(s, 'a', 'b', x)
        
        return score1 + score2