#!/usr/bin/python
# @author: Colan Biemer

import random
from Node import Node

# TOOD: shouldn't pass node_Count and set random connection
def randomize_node(node, dimension, node_count):
	node.x = random.uniform(0, dimension)
	node.y = random.uniform(0, dimension)

	node.connections.append(int(random.uniform(0, node_count)))

def random_nodes(node_count, dimension):
	nodes = []

	for node in range(node_count):
		node = Node()
		randomize_node(node, dimension, node_count) # update to not pass node_count

		nodes.append(node)

	return nodes

def generate_kruskal_nodes(node_count, dimension, seed):
	if type(seed) == int:
		random.seed(seed)

	nodes = random_nodes(node_count, dimension)

	return nodes