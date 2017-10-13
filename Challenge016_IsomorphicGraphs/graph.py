# @note: current recursive implementation isn't ideal for python
#        but was used because iteration breaks when added a new
#        index to the dictionary. This could be resolved by having
#        second dictionary initialized and adding to it when keys
#        don't exists instead of the nodes dictionary. After the 
#        loop you can merge the two dictionaries fairly easily.
def connect_nodes(nodes):
	restart = False

	for key in nodes:
		for node_id in nodes[key]:
			if node_id not in nodes:
				nodes[node_id] = []
				restart = True
				break

			if key not in nodes[node_id]:
				nodes[node_id].append(key)

		if restart:
			break

	if restart:
		connect_nodes(nodes)

def string_to_nodes(string):
	nodes = {}

	rows = string.split('\n')
	for row in rows:
		row = row.split(':')
		nodes[row[0]] = row[1].split(',')

	connect_nodes(nodes)
	return nodes

def get_vertices_degrees(graph):
	degrees = {}

	for key in graph:
		degrees[key] = len(graph[key])

	return degrees

# get surroudnign edge counts and self
def key_to_surrounding_edge_counts(key, graph, degree_counts, sort=True):
	surrounding_edge_counts = [degree_counts[key]]
	for connection in graph[key]:
		surrounding_edge_counts.append(degree_counts[connection])

	if sort:
		surrounding_edge_counts.sort()

	return surrounding_edge_counts

def graph_to_edge_counts(graph, degree_counts, sort=True):
	edge_counts = []

	for key in graph:
		edge_counts.append(key_to_surrounding_edge_counts(key, graph, degree_counts, sort=sort))

	return edge_counts

'''
Tests for isomorphism:
1. vertice counts are the same
2. number of edges are the same
3. adjoining edges match
'''
def graphs_are_isomorphic(graph1, graph2, verbose=True):
	degrees1 = get_vertices_degrees(graph1)
	degrees2 = get_vertices_degrees(graph2)

	# vertice count
	if len(degrees1) != len(degrees2):
		if verbose == True:
			print "Number of vertices do not match between the two graphs."

		return False

	# edge counts
	degree_arr1 = [degrees1[key] for key in degrees1]
	degree_arr2 = [degrees2[key] for key in degrees2]
	degree_arr1.sort()
	degree_arr2.sort()
	for i in range(len(degree_arr1)):
		if degree_arr1[i] != degree_arr2[i]:
			if verbose == True:
				print "Degree counts do not match."
				print "Graph1: " + str(degree_arr1)
				print "Graph2: " + str(degree_arr2)

			return False

	# adjacency
	cnts_1 = graph_to_edge_counts(graph1, degrees1)
	cnts_2 = graph_to_edge_counts(graph2, degrees2)

	for cnt in cnts_1:
		popped = False
		for i in range(len(cnts_2)):
			if cnt == cnts_2[i]:
				popped = True
				cnts_2.pop(i)
				break

		if popped == False:
			if verbose == True:
				print "no matching vertice with adjoing edges found for " + str(cnt)
			break

	# if the length is 0 then we have found adjacent edges
	return len(cnts_2) == 0