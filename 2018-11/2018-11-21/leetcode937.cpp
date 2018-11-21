class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        l = filter(lambda l: l[l.find(" ") + 1].isalpha(), logs)
        d = filter(lambda l: l[l.find(" ") + 1].isdigit(), logs)
        return sorted(l, key = lambda x: (x[x.find(" "):], x[:x.find(" ")])) + list(d)