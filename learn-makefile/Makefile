run: exec
	./exec.exe
exec: main.o fun.o
	gcc main.o fun.o -o exec

fun.o: fun.c
	gcc -c fun.c -o fun.o

main.o: main.c
	gcc -c main.c -o main.o

a: b
	@echo "hello world"

b:
	@echo "hello b"
# 不想回显的话加@  抑制回显，只输出结果

clean:
#rm -rf *.o
	echo "clean all .o file"