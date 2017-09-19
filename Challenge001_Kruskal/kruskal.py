#!/usr/bin/python

import argparse

SIZE = 20

# weights for matrix initializations
MIN_WEIGHT = 5
MAX_WEIGHT = 100

# Matrix identifiers
WALL  = 1
EMPTY = 0

def generateKruskalMaze():
	return [[EMPTY for j in range(SIZE)] for i in range(SIZE)]

def turnMazeIntoImage(maze):
	print "I'm going tot turn this maze into an image at some point"

def plotMaze(maze):
	print "i'm going to plot this maze at some point"

def main():
	parser = argparse.ArgumentParser(description='Generate Kruskal maze')
	parser.add_argument('--image', help='generate png \'kruskal.png\' of a generated kruskal maze', action="store_true")
	parser.add_argument('--console', help='print out generated kruskal maze', action="store_true")
	parser.add_argument('--plot',  help='plot a representation of a kruskal maze', action="store_true")

	args = parser.parse_args()
	
	maze = generateKruskalMaze()

	if args.image:
		turnMazeIntoImage(maze)
	elif args.plot:
		plotMaze(maze)
	else:
		for y in range(SIZE):
			row = ""
			for x in range(SIZE):
				row += str(maze[y][x])
			print row


if __name__ == '__main__':
	main()
