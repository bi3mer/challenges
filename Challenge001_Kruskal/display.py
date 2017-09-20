#!/usr/bin/python
# @author: Colan Biemer

import matplotlib.pyplot as plt

def plot_maze(nodes, should_save):
	x = []
	y = []

	for node in nodes:
		x.append(node.x)
		y.append(node.y)

		for connection in node.connections:
			x_end = nodes[connection].x
			y_end = nodes[connection].y

			plt.plot([node.x, x_end], [node.y, y_end], 'k-')
	
	plt.scatter(x, y)
	plt.title('Kruskal Minimum Spanning Tree')
	plt.xlabel('x')
	plt.ylabel('y')
	plt.grid(True)

	if should_save:
		print "saved image to plot.png"
		plt.savefig("plot.png")
	else:
		plt.show()