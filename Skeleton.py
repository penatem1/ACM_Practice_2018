# Basic skeleton

def processCase():
	pass

def processAll():
	data_descriptor = sys.stdin.readline()
	while data_descriptor:
		parsed = data_descriptor.split(" ")
		print processCase(int(parsed[0]), int(parsed[1]), int(parsed[2]))

		# get next data set 
		data_descriptor = sys.stdin.readline()

processAll()
