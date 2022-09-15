一键生成可执行文件
gcc <C file> -o <Program Name>

生成拥有字节表  Symbol Table的可调式文件，才能交给gdb调试器
没有-g程序的名字全部用内存地址替代了
gcc -g <file> -o <prog>

只进行到编译，不进行链接
gcc -c <file> -o <file.o>


gdb program

b number
b func

gdb sheet
https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf

