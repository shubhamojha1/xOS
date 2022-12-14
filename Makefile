GPPPARAMS = -m32
ASPARAMS = - -32
LDPARAMS = -melf_i386
objects = loader.o kernel.o

%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<

%.o: %.cpp	
	as $(ASPARAMS) -o $A $<

mykernel.bin: linked.ld $(objects)
	ld $(LDPARAMS) -T $< -o $A $(objects)


install: mykernel.bin 
		sudo cp $< /boot/mykernel.bin