import numpy as np

class Graph:
    def __init__(self, sz):
        self.adj_matrix = np.zeros((sz, sz))
        self.name_to_idx = {}
        self.idx_to_name = {}


    def add_vertex(self, name):
        self.name_to_idx[name] = len(self.name_to_idx)
        self.idx_to_name[len(self.name_to_idx)-1] = name
        if len(self.name_to_idx) > len(self.adj_matrix):
            sz = len(self.adj_matrix)
            new_adj_matrix = np.zeros((2*sz, 2*sz))
            new_adj_matrix[:sz, :sz] = self.adj_matrix
            self.adj_matrix = new_adj_matrix

    def add_edge(self, name1, name2):
        self.adj_matrix[self.name_to_idx[name1], self.name_to_idx[name2]] = 1
        self.adj_matrix[self.name_to_idx[name2], self.name_to_idx[name1]] = 1

    def is_edge(self, name1, name2):
        return self.adj_matrix[self.name_to_idx[name1], self.name_to_idx[name2]] == 1

    def remove_edge(self, name1, name2):
        self.adj_matrix[self.name_to_idx[name1], self.name_to_idx[name2]] = 0
        self.adj_matrix[self.name_to_idx[name2], self.name_to_idx[name1]] = 0

def drunk_traveller(g, starting_airport, n_tickets):
    # take a random available flight n_ticket times, starting from starting_airport
    print("We are now at", starting_airport)
    cur_ind = g.name_to_idx[starting_airport]
    for i in range(n_tickets):
        available_flights = np.where(g.adj_matrix[cur_ind, :])[0] #np.where(A) is the locations of non-zeros in A
        cur_ind = np.random.choice(available_flights)
        print("Now at", g.idx_to_name[cur_ind])

g = Graph(5)
g.add_vertex("YYZ")
g.add_vertex("YUL")
g.add_vertex("YVR")
g.add_vertex("JFK")
g.add_vertex("SFO")
g.add_edge("YYZ", "YUL")
g.add_edge("YYZ", "YVR")
g.add_edge("YYZ", "JFK")
g.add_edge("JFK", "SFO")
g.add_vertex("LAX")
print(g.adj_matrix)
drunk_traveller(g, "YYZ", 10)