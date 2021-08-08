class Graph(object):
    def __init__(self, v):
        self.vertices = v
        self.edges = []
        self.parent = [i for i in range(v)]
        self.children = [1]*v

    def add_edge(self, v1, v2, w):
        self.edges.append([v1, v2, w])

    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def merge(self, v1, v2):
        v1, v2 = self.find(v1), self.find(v2)
        if v1 == v2:
            return
        if self.children[v1] < self.children[v2]:
            v1, v2 = v2, v1
        self.parent[v2] = v1
        self.children[v1] += self.children[v2]

    def kruskal(self):
        weight_total = 0
        tree_edges = 0
        self.edges.sort(key = lambda x: x[2])
        for e in self.edges:
            if tree_edges >= self.vertices-1:
                break
            if self.find(e[0]) == self.find(e[1]):
                continue
            weight_total += e[2]
            self.merge(e[0], e[1])
            tree_edges += 1
        return weight_total
    

if __name__ == "__main__":
    f = open("../../problem_inputs/p107_network.txt", "r")
    g = Graph(40)
    all_weights = 0
    for i, line in enumerate(f):
        line_split = line.strip().split(",")
        for j in range(i+1):
            if line_split[j] != "-":
                g.add_edge(i, j, int(line_split[j]))
                all_weights += int(line_split[j])
    print(all_weights-g.kruskal())
