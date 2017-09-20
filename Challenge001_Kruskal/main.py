#!/usr/bin/python
# @author: Colan Biemer

from kruskal import generate_kruskal_nodes
from display import *
import argparse

def main():
	parser = argparse.ArgumentParser(description='Generate Kruskal maze')
	parser.add_argument('--save', help='generate png \'kruskal.png\' of a generated kruskal maze', action="store_true")
	parser.add_argument('--node_count', help="set number of nodes to be plotted")
	parser.add_argument('--dimension', help="set size of dimensions for x and y")
	parser.add_argument('--seed', help="seed for random generation")
	args = parser.parse_args()

	node_count = 20
	if args.node_count:
		node_count = args.node_count

	size = 10
	if args.dimension:
		size = args.dimension

	seed = ""
	if args.seed:
		seed = int(args.seed);

	maze = generate_kruskal_nodes(node_count, size, seed)

	save = False
	if args.save:
		save = True

	plotMaze(maze, save)

if __name__ == '__main__':
	main()
