obj-m += test.o simple.o 
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc hello.c -o hello.o
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean