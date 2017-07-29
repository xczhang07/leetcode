class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.elem_stack = list()
        self.min_stack = list()
        
    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.elem_stack.append(x)
        if len(self.min_stack) == 0:
            self.min_stack.append(x)
        elif self.min_stack[len(self.min_stack)-1] >= x:
            self.min_stack.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if len(self.elem_stack) == 0:
            return
        top_val = self.elem_stack[len(self.elem_stack)-1]
        if top_val == self.min_stack[len(self.min_stack)-1]:
            self.min_stack.pop()
        self.elem_stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.elem_stack[len(self.elem_stack)-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[len(self.min_stack)-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
