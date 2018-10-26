from sys import stdin

def processCase(list):
	if len(list) is 0:
		return "no"

	time_list = {
		10: 5,
		5: 2,
		1: 1,
		0: 0,
		-5: 3
	}

	candy = 0
	time = 0

	for num in list:
		val = int(num)
		candy += val
		time += time_list.get(val)

	return (str(candy) + " " + str(time))

def processAll():
	line = stdin.readline()
	while line:
		parsed = line.split(" ")
		out = processCase(parsed[1:])
		if out != "no":
			print(out)

		# get next data set 
		line = stdin.readline()

processAll()