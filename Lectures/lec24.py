class Node:
    def __init__(self, data):
        self.data = data
        self.neighbours = []

class Graph:
    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)

# YYZ -> YUL -> YVR -> HNL -> HND
        # \
        #  v
        # JFK -> EWR

yyz = Node('YYZ')
yul = Node('YUL')
yvr = Node('YVR')
jfk = Node('JFK')
hnl = Node('HNL')
hnd = Node('HND')
ewr = Node("EWR")
yyz.neighbours.append(yul)
yul.neighbours.append(yvr)
yul.neighbours.append(jfk)
yvr.neighbours.append(hnl)
yvr.neighbours.append(hnd)
jfk.neighbours.append(ewr)
g = Graph()
g.nodes = [yyz, yul, yvr, jfk]

# Concept: start iwth a node in the graphm keep visiting node, adding all its unvisited neighbors to queue
# getting the next node to visit from the queue

def bfs(graph):
    visited = set()

    for starting_node in graph.nodes:
        if starting_node in visited:
            continue
        queue = [starting_node]

        while len(queue) > 0:
            node = queue.pop(0)          # dequeue from front
            if node not in visited:
                print(node.data)
                visited.add(node)
                for neighbour in node.neighbours:
                    if neighbour not in visited:
                        queue.append(neighbour)

def dfs(graph):
    visited = set()

    for starting_node in graph.nodes:
        if starting_node in visited:
            continue
        queue = [starting_node]

        while len(queue) > 0:
            node = queue.pop(-1)          # pop from end
            if node not in visited:
                print(node.data)
                visited.add(node)
                for neighbour in node.neighbours:
                    if neighbour not in visited:
                        queue.append(neighbour)

bfs(g)
print("----------")
dfs(g)

def dfs_rec(node, visited = set()):
    visited.add(node)
    print(node.data)

    flag = False
    for n in node.neighbours:
        if n not in visited:
            flag = True
            dfs_rec(n, visited)

print("---------------")
dfs_rec(yyz)