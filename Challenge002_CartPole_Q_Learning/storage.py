from os import path
from q_learning import build_qnn
import pickle

def store_model(qnn, file_name="model.pkl"):
	if path.isfile(file_name):
		response = raw_input("Overwrite " + file_name + "? (y for yes)")

		if response != "y":
			print "Cancelled save"
			return
		else:
			print "Overwriting file"

	qnn.model.save_weights(file_name)

def load_model(input_dimension, num_actions, file_name="model.pkl"):
	qnn = build_qnn(input_dimension, num_actions)
	qnn.model.load_weights(file_name)
	return qnn