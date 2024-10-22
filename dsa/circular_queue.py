from typing import Any

class Queue:
    def __init__(self, maxlen:int):
        self.front = 0
        self.rear = -1
        self.counts = 0
        self.maxlen = maxlen

        self.que:list[Any] = [0 for _ in range(maxlen)]

    def push(self, el:Any):
        if self.counts == self.maxlen:
            raise RuntimeError("Queue is full")
        self.rear = (self.rear + 1) % self.maxlen
        self.counts += 1
        self.que[self.rear] = el

    def pop(self):
        if self.counts <= 0:
            raise RuntimeError("Queue is empty")
        el = self.que[self.front]
        self.front = (self.front + 1) % self.maxlen
        self.counts -= 1
        return el
    
    def __repr__(self) -> str:
        # disp_ls = []
        # i = self.front
        # c = self.counts
        # while True:
        #     i = (i+1)%self.maxlen; c-=1
        #     disp_ls.append(self.que[i])
        #     if c<=0:
        #         break
        return f"Queue({self.que}, front={self.front}, rear={self.rear})"

if __name__ == "__main__":
    que = Queue(maxlen=4)
    que.push(10); que.push(20); que.push(30); que.push(40)
    print(que)
    try: que.push(50)
    except Exception as e: print(e)
    print(que)
    que.pop()
    print(que)
    que.push(50)
    print(que)
    