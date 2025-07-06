1- x % (2^i) = x & (2^i - 1) 		-> (you mask the remainder, all bits to left of i are already multiples of 2^i).


2- ( A + B ) = ( A | B ) + ( A & B )


3- ( A + B ) = ( A ^ B ) + 2*( A & B )


4- ( A ^ B ) = ( A  + B ) - 2 & ( A & B) 


5-let f(n) = xor(1 .... n)
	if n%4 == 0: f(n) = n
	if n%4 == 1: f(n) = 1
	if n%4 == 2: f(n) = n+1
	if n%4 == 3: f(n) = 0
