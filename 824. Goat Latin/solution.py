class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        sentence = sentence.split()
        ret = []
        for i in range(len(sentence)):
            s = ''
            if sentence[i][0] in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
                s = sentence[i] + 'ma'
            else:
                s = sentence[i][1:] + sentence[i][0] + 'ma'
            ret.append(s + 'a' * (i + 1))
        return ' '.join(ret)
