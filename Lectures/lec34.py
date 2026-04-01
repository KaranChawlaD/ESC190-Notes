import heapq
import math


class Node:
    def __init__(self, data):
        self.data = data
        self.neighbours = []


class Graph:
    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)


class WeightedGraph:
    def __init__(self):
        self.nodes = []
        self.name_to_node = {}

    def add_node(self, node):
        self.nodes.append(node)
        self.name_to_node[node.data] = node

    def add_edge(self, u, v, weight=1):
        u_node = self.name_to_node[u]
        v_node = self.name_to_node[v]
        u_node.neighbours.append((v_node, weight))


def dijkstra(graph, source):
    """Return shortest distances and predecessors from source.

    Uses a min-priority queue (`heapq`) as discussed in Lecture 29.
    """

    dist = {node.data: float("inf") for node in graph.nodes}
    prev = {node.data: None for node in graph.nodes}
    visited = set()

    dist[source] = 0
    pq = [(0, source, graph.name_to_node[source])]

    while pq:
        cur_dist, _, u_node = heapq.heappop(pq)
        u = u_node.data

        if u in visited:
            continue
        visited.add(u)

        for v_node, w in u_node.neighbours:
            v = v_node.data
            if v in visited:
                continue
            new_dist = cur_dist + w
            if new_dist < dist[v]:
                dist[v] = new_dist
                prev[v] = u
                heapq.heappush(pq, (new_dist, v, v_node))

    return dist, prev


def astar(graph, source, goal, heuristic):
    """A* search on a weighted graph.

    `heuristic` is a function with signature heuristic(node_name, goal_name).
    """
    g_score = {node.data: float("inf") for node in graph.nodes}
    prev = {node.data: None for node in graph.nodes}
    closed = set()

    g_score[source] = 0
    f0 = heuristic(source, goal)
    pq = [(f0, source, graph.name_to_node[source])]

    while pq:
        _, _, u_node = heapq.heappop(pq)
        u = u_node.data

        if u in closed:
            continue
        if u == goal:
            break

        closed.add(u)

        for v_node, w in u_node.neighbours:
            v = v_node.data
            if v in closed:
                continue

            tentative_g = g_score[u] + w
            if tentative_g < g_score[v]:
                g_score[v] = tentative_g
                prev[v] = u
                f_score = tentative_g + heuristic(v, goal)
                heapq.heappush(pq, (f_score, v, v_node))

    return g_score, prev


def reconstruct_path(prev, dest):
    """Reconstruct source -> dest path from predecessor map."""
    path = []
    cur = dest
    while cur is not None:
        path.append(cur)
        cur = prev[cur]
    path.reverse()
    return path


def build_lecture23_airport_graph():
    # Build the airport graph shown in Lecture 23
    YYZ = Node("YYZ")
    YUL = Node("YUL")
    YVR = Node("YVR")
    JFK = Node("JFK")
    SFO = Node("SFO")

    YYZ.neighbours = [YUL, YVR, JFK]
    YUL.neighbours = [YVR, JFK]
    JFK.neighbours = [SFO]

    graph = Graph()
    for node in [YYZ, YUL, YVR, JFK, SFO]:
        graph.add_node(node)
    return graph


def build_lecture29_weighted_graph():
    """Build the weighted directed graph from Lecture 29 walkthrough."""
    g = WeightedGraph()

    A = Node("A")
    B = Node("B")
    C = Node("C")
    D = Node("D")
    E = Node("E")
    F = Node("F")
    G = Node("G")
    H = Node("H")

    for node in [A, B, C, D, E, F, G, H]:
        g.add_node(node)

    # A -> {B, C, D}
    g.add_edge("A", "B", 2)
    g.add_edge("A", "C", 1)
    g.add_edge("A", "D", 6)

    # B, C, D -> E
    g.add_edge("B", "E", 1)
    g.add_edge("C", "E", 3)
    g.add_edge("D", "E", 8)

    # E -> {F, G}
    g.add_edge("E", "F", 7)
    g.add_edge("E", "G", 5)

    # F, G -> H
    g.add_edge("F", "H", 5)
    g.add_edge("G", "H", 6)

    return g


def build_airport_weighted_graph():
    """Build a weighted version of the Lecture 23 airport graph."""
    g = WeightedGraph()

    YYZ = Node("YYZ")
    YUL = Node("YUL")
    YVR = Node("YVR")
    JFK = Node("JFK")
    SFO = Node("SFO")

    for node in [YYZ, YUL, YVR, JFK, SFO]:
        g.add_node(node)

    # Same directed edges as Lecture 23.
    # All legs have unit weight (1).
    g.add_edge("YYZ", "YUL")
    g.add_edge("YYZ", "YVR")
    g.add_edge("YYZ", "JFK")
    g.add_edge("YUL", "YVR")
    g.add_edge("YUL", "JFK")
    g.add_edge("JFK", "SFO")

    return g


def get_airport_coordinates(airport_code):
    """Return (latitude, longitude) for airports used in Lecture 23."""
    coordinates = {
        "YYZ": (43.6777, -79.6248),  # Toronto Pearson
        "YUL": (45.4706, -73.7408),  # MontrÃ©alâ€“Trudeau
        "YVR": (49.1947, -123.1792),  # Vancouver Intl
        "JFK": (40.6413, -73.7781),  # John F. Kennedy Intl
        "SFO": (37.6213, -122.3790),  # San Francisco Intl
    }

    return coordinates[airport_code]


def haversine_km(coord1, coord2):
    """Great-circle distance between two (lat, lon) coordinates in km."""
    lat1, lon1 = coord1
    lat2, lon2 = coord2

    lat1 = math.radians(lat1)
    lon1 = math.radians(lon1)
    lat2 = math.radians(lat2)
    lon2 = math.radians(lon2)

    dlat = lat2 - lat1
    dlon = lon2 - lon1

    a = math.sin(dlat / 2) ** 2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2) ** 2
    c = 2 * math.asin(math.sqrt(a))
    earth_radius_km = 6371.0
    return earth_radius_km * c


def query_airport_distance(airport1, airport2):
    """Query geographic distance (km) between two airport codes."""
    coord1 = get_airport_coordinates(airport1)
    coord2 = get_airport_coordinates(airport2)
    return haversine_km(coord1, coord2)


if __name__ == "__main__":
    airport_graph = build_lecture23_airport_graph()
    print("Lecture 23 airport graph (adjacency list):")
    for node in airport_graph.nodes:
        neighbours = [neighbour.data for neighbour in node.neighbours]
        print(f"{node.data}: {neighbours}")

    print("\nLecture 29 Dijkstra example:")
    weighted_graph = build_lecture29_weighted_graph()
    distances, predecessors = dijkstra(weighted_graph, "A")
    path_to_h = reconstruct_path(predecessors, "H")

    print("Distances from A:", distances)
    print("Shortest path A -> H:", " -> ".join(path_to_h))
    print("Cost A -> H:", distances["H"])

    print("\nA* on airport graph (heuristic = straight-line distance):")
    airport_weighted_graph = build_airport_weighted_graph()
    scores, airport_prev = astar(
        airport_weighted_graph,
        "YYZ",
        "SFO",
        # Heuristic is computed on-the-fly by querying distance to the goal.
        heuristic=lambda airport, goal: query_airport_distance(airport, goal),
    )
    airport_path = reconstruct_path(airport_prev, "SFO")

    print("Shortest path YYZ -> SFO:", " -> ".join(airport_path))
    print("Cost YYZ -> SFO (legs):", scores["SFO"])