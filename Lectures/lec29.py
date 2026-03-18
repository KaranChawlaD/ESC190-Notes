class PQ:
    def __init__(self):
        self.data = []
    
    def push(self, elem):
        self.data.append(elem)
        self.data.sort(reverse=True)
    
    def pop(self):
        return self.data.pop()[1]

pq = PQ()
pq.push((0, "ESC180"))
pq.push((-100, "ESC195"))
pq.push((185, "MAT185"))

print(pq.pop()) #ESC195
print(pq.pop()) #ESC180
print(pq.pop()) #MAT185


# Pseudocode for Djikstra's Algorithm    