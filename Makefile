
all: p1 p2 p3 p4 q1 q2 q3 q4 q5 q6 q7

clean:
	rm -f p1 p2 p3 p4

p1: p1.c
	gcc -o p1 p1.c -Wall

p2: p2.c
	gcc -o p2 p2.c -Wall

p3: p3.c
	gcc -o p3 p3.c -Wall

p4: p4.c
	gcc -o p4 p4.c -Wall

q1: q1.c
	gcc -o q1 q1.c -Wall

q2: q2.c
	gcc -o q2 q2.c -Wall

q3: q3.c
	gcc -o q3 q3.c -Wall

q4: q4.c
	gcc -o q4 q4.c -Wall

q5: q5.c
	gcc -o q5 q5.c -Wall

q6: q6.c
	gcc -o q6 q6.c -Wall

q7: q7.c
	gcc -o q7 q7.c -Wall


