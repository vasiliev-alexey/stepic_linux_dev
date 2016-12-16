all:
	gcc solution.c -fPIC -ldl -o solution  

lib:
	gcc -o libShared.so -shared -fPIC Shared.c

clean:
	-rm libSolution.so 2>>/dev/null
