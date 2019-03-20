from numpy import interp
def rangeMap(num):
	return int(interp(num,[-32768,32768],[1,10]))


while 1:
	print(rangeMap(int(input())))