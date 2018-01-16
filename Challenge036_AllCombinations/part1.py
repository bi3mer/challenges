#!/usr/bin/python
# @author: Colan Biemer

TAB  = "  "
TAB2 = TAB + TAB

class Node:
	def __init__(self, value):
		self.children = []
		self.value    = value

# expected output for ([0, 1], 2), (0, 1], 3), and ([0, 1 ,2], 2):
# 0 0 | 0 0 0 | 0 0 
# 1 0 | 1 0 0 | 1 0 
# 0 1 | 0 1 0 | 0 1
# 1 1 | 0 0 1 | 1 1
#     | 1 1 0 | 2 1 
#     | 1 0 1 | 1 2
#     | 0 1 1 | 2 2
#     | 1 1 1 | 2 0
#             | 0 2
#
# Output doesn't have to be in this ordering, but should have the same
# set where both are subsets of the other
def build_tree(input_set, output_size, root=None):
	if output_size <= 0:
		return None

	if root == None:
		root = Node(None)

	for i in range(len(input_set)):
		child = Node(input_set[i])
		build_tree(input_set, output_size - 1, root=child)
		root.children.append(child)

	return root

def build_tree_output(root):
	if root == None or len(root.children) <= 0:
		return None
	
	output = []
	
	for i in range(len(root.children)):
		child_output = build_tree_output_recursive(root.children[i])

		for child_out in child_output:
			output.append(child_out)

	return output

def build_tree_output_recursive(root):
	if root.children == None or len(root.children) <= 0:
		return [[root.value]]

	output = []

	if root.children != None:
		for i in range(len(root.children)):
			child_output = build_tree_output_recursive(root.children[i])

			if child_output == None:
				continue

			for j in range(len(child_output)):
				if child_output[j] == None:
					continue

				if root.value == None:
					output.append(child_output[j])
				else:
					child_output[j].append(root.value)
					output.append(child_output[j])

	return output

def visualize_tree(root, indent_level=""):
	print indent_level + str(root.value)

	if root.children != None:
		for i in range(len(root.children)):
			if root.children[i] != None:
				visualize_tree(root.children[i], indent_level=indent_level+TAB)

def main():
	output_sizes = [2, 3, 2]
	input_sets   = [[0,1], [0,1], [0,1,2]]
	
	for i in range(len(input_sets)):
		node = build_tree(input_sets[i], output_sizes[i])
		print TAB + "Input (" + str(input_sets[i]) + ", " + str(output_sizes[i]) + ")"
		print TAB + "----> " + str(build_tree_output(node))
		print

if __name__ == '__main__':
	main()