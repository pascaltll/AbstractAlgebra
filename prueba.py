import networkx

graph = {
    '1': ['2', '3', '4'],
    '2': ['5','11','12','13','14','15'],
    '3': ['6','7','66','77'],
    '5': ['6', '8','66','77'],
    '4': ['7','66','77'],
    '7': ['9', '10']
}

g = networkx.Graph()

for k, vs in graph.items():
    server_id = 'server_%s' % k

    for v in vs:
        g.add_edge(server_id,v)

networkx.draw_spring(g)