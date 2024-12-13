import typing as tp

class Value:
    def __init__(self, data, link=None):
        self.data:int = data
        self.link:tp.Optional[Value] = link

    def __repr__(self):
        return f"Value(data={self.data}, link={self.link})"

class LinkedList:
    def __init__(self, data:tp.Optional[int]=None):
        self.first:tp.Optional[Value]
        self.count:int
        if data is None:
            self.first = None
            self.count = 0
        else:
            self.first = Value(data, link=None)
            self.count = 1

    def __len__(self):
        return self.count

    def display(self):
        temp = self.first
        print("[", end="")
        if temp is not None:
            while True:
                print(f"{temp.data}", end=", ")
                if temp.link is None:
                    break
                temp = temp.link
        print("]")

    # INSERT OPERATIONS    
    def append(self, el:int): # insert at end
        self.count += 1
        if self.first is None:
            self.first = Value(el, link=None)
        else:
            temp = self.first
            while temp.link is not None:
                temp = temp.link
            insert_node = Value(el, link=None)
            temp.link = insert_node

    def prepend(self, el:int): # insert at beggining
        self.count += 1
        if self.first is None:
            self.first = Value(el, link=None)
        else:
            insert_node = Value(el, link=self.first)
            self.first = insert_node

    def insert_at_idx(self, at:int, el:int): # insert at given index
        if at > self.count:
            self.display()
            raise IndexError(f"index: {at}\nlen: {self.count}\nNot possible to insert at given index")
        
        insert_node = Value(el, link=None)
        temp1, temp2, idx = self.first, None, -1
        while temp1.link is not None and  idx != at-1:
            idx += 1
            temp2 = temp1
            temp1 = temp1.link
        insert_node.link = temp1
        temp2.link = insert_node
        self.count += 1

    # DELETE OPERATIONS
    def popf(self): # delete at front
        el = self.first.data
        self.first = self.first.link
        self.count -= 1
        return el

    def pop(self): # delete at end
        temp1, temp2 = self.first, None
        while temp1.link is not None:
            temp2 = temp1
            temp1 = temp1.link
        temp2.link = None
        self.count -= 1
        return temp1.data

    def delete_at_idx(self, at:int): # delete at index
        temp1, temp2, idx = self.first, None, -1
        while temp1.link is not None and idx != at-1:
            idx += 1
            temp2 = temp1
            temp1 = temp1.link
        temp2.link = temp1.link
        self.count -= 1
        return temp1.data

if __name__ == "__main__":
    llist = LinkedList()
    llist.append(10)
    llist.display()
    llist.append(11)
    llist.display()
    llist.append(212)
    llist.display()
    llist.prepend(323)
    llist.display()
    llist.insert_at_idx(at=3, el=3232)
    llist.display()
    print("popf", llist.popf())
    llist.display()
    print("pop", llist.pop())
    llist.display()
    print("delete_at_idx 1:", llist.delete_at_idx(1))
    llist.display()
    print("len:", len(llist))
    llist.pop()
    llist.display()
    llist.popf()
    llist.display()
