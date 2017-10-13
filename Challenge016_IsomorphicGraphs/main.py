#!/usr/bin/env python
# @author; Colan Biemer

from graph import string_to_nodes, graphs_are_isomorphic
import os

GRAPH_DIRECTORY = 'graphs'

def get_available_files():
	return os.listdir(GRAPH_DIRECTORY)

# @note: doesn't handle cases where there is not
#        enough choices and will cause and infnite
#        loop that the user will have to break out
#        of.
def choose_graph(graphs):
	user_choice = -1

	while user_choice == -1:
		for i in range(len(graphs)):
			print str(i) + ": " + graphs[i]
		print 

		user_attempt = raw_input('Enter corresponding index for the file: ')
		
		try:
			user_choice = int(user_attempt)

			if user_choice < 0 or user_choice >= len(graphs):
				print "Input not in valid range, please try again."
				user_choice = -1
		except ValueError:
			print "Please enter valid integer"

	return user_choice

def user_choose_graphs():
	graphs = get_available_files()

	index = choose_graph(graphs)
	first_choice = graphs[index]
	graphs.pop(index)

	index = choose_graph(graphs)
	return first_choice, graphs[index]

def convert_to_nodes(file_name):
	f = open(os.path.join(GRAPH_DIRECTORY, file_name), 'r')
	nodes = string_to_nodes(f.read())
	f.close()
	return nodes

def main():
	graph1, graph2 = user_choose_graphs()
	graph1         = convert_to_nodes(graph1)
	graph2         = convert_to_nodes(graph2)

	if graphs_are_isomorphic(graph1, graph2):
		print "The two graphs are isomorphic"
	else:
		print "The two graphs are not isomorphic"

if __name__ == '__main__':
	main()