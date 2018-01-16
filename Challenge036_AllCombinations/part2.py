#!/usr/bin/python
# @author: Colan Biemer

from part1 import build_tree, build_tree_output

TAB  = "  "
TAB2 = TAB + TAB

def all_combinations(input_set, output_size):
	combinations = build_tree_output(build_tree(input_set, output_size))

	if combinations == None or len(combinations) <= 0:
		yield None
	else:
		for combination in combinations:
			yield combination

def main():
	output_sizes = [2, 3, 2]
	input_sets   = [[0,1], [0,1], [0,1,2]]

	for i in range(len(output_sizes)):
		print TAB + "Input (" + str(input_sets[i]) + ", " + str(output_sizes[i]) + ")"

		for combination in all_combinations(input_sets[i], output_sizes[i]):
			print TAB + "----> " + str(combination)
		
		print

if __name__ == '__main__':
	main()