import networkx as nx
import matplotlib.pyplot as plt

g = nx.Graph()
g.add_edge(0, 1, weight=4)
g.add_edge(0, 7, weight=8)
g.add_edge(1, 2, weight=8)
g.add_edge(1, 7, weight=11)
g.add_edge(2, 3, weight=7)
g.add_edge(2, 8, weight=2)
g.add_edge(2, 5, weight=4)
g.add_edge(3, 4, weight=9)
g.add_edge(3, 5, weight=14)
g.add_edge(4, 5, weight=10)
g.add_edge(5, 6, weight=2)
g.add_edge(6, 7, weight=1)
g.add_edge(6, 8, weight=6)
g.add_edge(7, 8, weight=7)

print(nx.info(g))
nx.draw(g, with_labels=True)

plt.savefig('C://Users//Aditya//Desktop//al//gplot.png')
plt.show()

mst = nx.Graph()
mst = nx.minimum_spanning_tree(g, weight='weight')
print(nx.info(mst))

nx.draw(mst, with_labels=True)
plt.savefig('C://Users//Aditya//Desktop//al//mstplot.png')

plt.show()