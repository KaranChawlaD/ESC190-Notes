# # Stack: an ordered collection with the operations PUSH, POP, ISEMPTY
# #
# # 6 7 7
# # POP: 7, stack: 6 7
# # POP: 7, stack: 6
# # POP: 6, stack: [EMPTY]
# # last in-first out (LIFO)

# # 
# # 
# # Queue: an ordered collection with the operations ENQUEUE, DEQUEUE, ISEMPTY
# # first in-first out (FIFO)

# class Stack:
#     def __init__(self):
#         self.data = []
    
#     def push(self, elem):
#         self.data.append(elem)
    
#     def pop(self):
#         return self.data.pop()
    
#     def isempty(self):
#         return len(self.data) == 0
    
# class Queue:
#     def __init__(self):
#         self.data = []
    
#     def enqueue(self, elem):
#         self.data.append(elem)
    
#     def dequeue(self):
#         return self.data.pop(0)
    
#     def isempty(self):
#         return len(self.data) == 0

# if __name__ == '__main__':
#     s = Stack()
#     s.push(6)
#     s.push(7)
#     s.push(7)
    
#     print(s.pop()) # 7
#     print(s.pop()) # 7
#     print(s.pop()) # 6
#     print(s.isempty()) # True

#     s = Queue()
#     s.enqueue(6)
#     s.enqueue(7)
#     s.enqueue(7)
    
#     print(s.dequeue()) # 6
#     print(s.dequeue()) # 7
#     print(s.dequeue()) # 7
#     print(s.isempty()) # True

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None # the last node in the linked list
        self.size = 0
    
    def prepend(self, data):
        n = Node(data)
        n.next = self.head
        self.head = n
        self.size += 1

    def append(self, data):
        # cur = self.head
        # while cur.next:
        #     cur = cur.next
        # cur.next = Node(data)
        n = Node(data)
        if self.tail != None:
            self.tail.next = n
        else:
            self.head = n
        self.tail = n
        self.size += 1
    
    def pop_head(self):
        data = self.head.data
        self.head = self.head.next
        self.size -= 1
        return data
    
    def __repr__(self):
        res = ""
        cur = self.head
        while cur != None:
            if cur.next != None:
                res += str(cur.data) + " -> "
            else:
                res += str(cur.data)
            cur = cur.next
        return res

    def __get_item__(self, ind): # or __get_item__
        cur = self.head
        for i in range(ind):
            cur = cur.next
        return cur.data

if __name__ == '__main__':
    LL = LinkedList()
    LL.append(6)
    LL.append(7)
    print(LL)