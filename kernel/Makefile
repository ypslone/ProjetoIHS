# Makefile para compilar driver kernel

obj-m := driver.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

install: all
	@echo "Para carregar o módulo, use:"
	@echo "sudo rmmod arduino_buzzer || true"
	@echo "sudo insmod driver.ko"
	@echo "dmesg | tail -20"
