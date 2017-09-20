#!/usr/bin/python
# @author: Colan Biemer

import random
from Node import Node

def randomize_node(node, dimension):
	node.x = random.uniform(0, dimension)
	node.y = random.uniform(0, dimension)

def random_nodes(node_count, dimension):
	nodes = []

	for node in range(node_count):
		node = Node()
		randomize_node(node, dimension)

		nodes.append(node)

	return nodes

def sqr_distance(node1, node2):
	return pow(node2.x - node1.x, 2) + pow(node2.y - node1.y, 2)

# @inneficient: we could optimize by setting this up to instead
# set a boolean for both sets found and return on those so we 
# avoid unneeded checking every time if we have found a set 
# already
def in_same_set(node_set, a, b):
	for n_set in node_set:
		if a in n_set and b in n_set:
			return True

	return False

# @inneficient: notice that we find the set indexes already in 
# function "in_same_set", so if we return these indices we could
# speed this program up a tad
def combine_set_by_members(node_set, a, b):
	a_set_index = -1
	b_set_index = -1

	for i in range(len(node_set)):
		if a_set_index == -1:
			if a in node_set[i]:
				a_set_index = i

		if b_set_index == -1:
			if b in node_set[i]:
				b_set_index = i

	node_set[a_set_index] += node_set[b_set_index]
	node_set.pop(b_set_index)

def index_to_set_value(index):
	return "|" + str(index) + "|"

def kruskal(nodes):
	node_sets = [index_to_set_value(i) for i in range(len(nodes))]

	while len(node_sets) > 1:
		shortest_path = float("inf")
		
		# find shortest pair
		node_1 = ""
		node_2 = ""
		index_1 = 0
		index_2 = 0

		for i in range(len(nodes)):
			for j in range(i, len(nodes)):
				n1 = str(index_to_set_value(i))
				n2 = str(index_to_set_value(j))
				distance = sqr_distance(nodes[i], nodes[j])

				if distance < shortest_path and not in_same_set(node_sets, n1, n2):
					node_1 = n1
					node_2 = n2
					index_1 = i
					index_2 = j

					shortest_path = distance

		nodes[index_1].connections.append(index_2)
		nodes[index_2].connections.append(index_1)

		combine_set_by_members(node_sets, node_1, node_2)

def generate_kruskal_nodes(node_count, dimension, seed):
	if type(seed) == int:
		random.seed(seed)

	nodes = random_nodes(node_count, dimension)
	kruskal(nodes)

	return nodes