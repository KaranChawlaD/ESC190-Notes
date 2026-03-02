from lec21 import LinkedList

class Stack:
    def __init__(self):
        self.ll = LinkedList()

    def push(self, val):
        self.ll.prepend(val)       # O(1): add to front

    def pop(self):
        return self.ll.pop_head()  # O(1): remove from front

    def is_empty(self):
        return self.ll.size == 0

    def __repr__(self):
        return "Stack(top -> " + repr(self.ll) + ")"
    
class Queue:
    def __init__(self):
        self.ll = LinkedList()

    def enqueue(self, val):
        self.ll.append(val)        # O(1): add to tail

    def dequeue(self):
        return self.ll.pop_head()  # O(1): remove from head

    def is_empty(self):
        return self.ll.size == 0

    def __repr__(self):
        return "Queue(" + repr(self.ll) + ")"

s = Stack()
s.push(6)
s.push(7)
s.push(7)
print(s.pop())      # 7
print(s.pop())      # 7
print(s.pop())      # 6
print(s.is_empty())  # True

q = Queue()
q.enqueue(6)
q.enqueue(7)
q.enqueue(7)
print(q.dequeue())   # 6
print(q.dequeue())   # 7
print(q.dequeue())   # 7