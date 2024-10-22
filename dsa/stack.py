from typing import Any

class Stack:
    def __init__(self, maxlen):
        self.maxlen = maxlen
        self.stack_top = -1
        self.stack = [0 for _ in range(maxlen)] # initialize stack

    def push(self, el:Any):
        if self.stack_top >= self.maxlen:
            raise RuntimeError("Stack Overflow")
        self.stack[self.stack_top+1] = el
        self.stack_top +=1

    def pop(self):
        if self.stack_top < 0:
            raise RuntimeError("Stack Underflow")
        return_ele = self.stack[self.stack_top]
        self.stack_top -= 1
        return return_ele

    def __repr__(self):
        return str(self.stack[:self.stack_top+1])
    
    def get_stack_top(self):
        assert self.stack_top >= 0
        return self.stack[self.stack_top]
    
if __name__ == "__main__":
    stack = Stack(maxlen=10)
    stack.push(40)
    print(stack)
    stack.push(100)
    print(stack)
    stack.push(329)
    print(stack)
    stack.pop()
    print(stack)
    stack.pop()
    print(stack)
    stack.pop()
    print(stack)
    stack.pop()
    print(stack)
