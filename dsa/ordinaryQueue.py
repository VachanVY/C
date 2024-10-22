from typing import Any

class Queue:
    def __init__(self, maxlen:int, init_val:float|int=0):
        self.que:list[Any] = [init_val for _ in range(maxlen)] # init queue
        self.front, self.rear = 0, -1
        self.maxlen = maxlen

    def pop(self):
        if self.front > self.rear:
            raise RuntimeError("Queue is empty")
        el = self.que[self.front]
        self.front += 1
        return el
    
    def push(self, el:Any):
        if self.rear >= self.maxlen - 1:
            raise RuntimeError("Queue is full")
        self.rear += 1
        self.que[self.rear] = el
