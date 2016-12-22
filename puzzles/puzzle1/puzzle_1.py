
def calculate_distance(input):
	angle = 0
	direction = 'N'
	distance = {'N':0, 'E':0, 'S':0, 'W':0}
	print(distance)
	for d in input:
		movement = d[:1]
		steps = d[1:]

		if(movement == 'L'):
			angle -= 90
		if(movement == 'R'):
			angle += 90

		if(angle < 0):
			angle = 270
		if(angle > 270):
			angle = 0

		if(angle == 0):
			direction = 'N'
		if(angle == 90):
			direction = 'E'
		if(angle == 180):
			direction = 'S'
		if(angle == 270):
			direction = 'W'

		distance[direction] += int(steps)

	distance_vert = abs(distance['N'] - distance['S'])
	distance_horiz = abs(distance['E'] - distance['W'])

	print(distance_vert + distance_horiz)


file = open('puzzle_1_input.txt', 'r')

in_directions = file.readline().split(", ")

calculate_distance(in_directions)