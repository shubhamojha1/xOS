// #include <cstdio>
/*
    cant include header files, as we are outside of the operating system
    so writing our own printf

    0xb8000 --> memory location that will display words written there
*/
void printf(char* str){
    
    unsigned short* VideoMemory = (unsigned short*)0xb8000;
    for(int i=0;str[i]!='\0';i++){
        VideoMemory[i]= (VideoMemory[i] & 0xFF00) | str[i];
    }
}


extern "C" void kernelMain(void* multiboot_structure, unsigned int magic_number){
    printf("HELLO WORLD! \n\tThis is xOS!!");
    while(1);
}