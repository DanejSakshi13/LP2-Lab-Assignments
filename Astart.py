import heapq
class Node:
    def __init__(self, id, heuristic, cost):
        self.id = id
        self.heuristic = heuristic
        self.cost = cost

def astar(graph, start, goal, heuristic):
    pq = []
    heapq.heappush(pq, (heuristic[start], start))
    cost_so_far = {}
    cost_so_far[start] = 0.0
    came_from = {}
    while pq:
        _, current = heapq.heappop(pq)
        if current == goal:
            path = []
            node = goal
            while node != start:
                path.append(node)
                node = came_from[node]
            path.append(start)
            path.reverse()
            return path
        for edge in graph[current]:
            new_cost = cost_so_far[current] + edge[1]
            if edge[0] not in cost_so_far or new_cost < cost_so_far[edge[0]]:
                cost_so_far[edge[0]] = new_cost
                priority = new_cost + heuristic[edge[0]]
                heapq.heappush(pq, (priority, edge[0]))
                came_from[edge[0]] = current
    return []

if __name__ == "__main__":
    num_nodes, num_edges = map(int, input().split())
    graph = [[] for _ in range(num_nodes)]
    for _ in range(num_edges):
        source, destination, cost = map(int, input().split())
        graph[source].append((destination, cost))
    heuristic = [0] * num_nodes
    for i in range(num_nodes):
        heuristic[i] = float(input())
    start, goal = map(int, input().split())
    path = astar(graph, start, goal, heuristic)
    if path:
        print("Path found:", " ".join(map(str, path)))
    else:
        print("Path not found")
