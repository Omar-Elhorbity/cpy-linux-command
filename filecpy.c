#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main (int argc, char **argv) {
    int fdSrc, fdDes;
    ssize_t readByte;
    char buffer[100] = {0}; 

    if (argc != 3)  {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }
    else {
        fdSrc = open(argv[1], O_RDWR); 
        fdDes = open(argv[2], O_RDWR | O_CREAT, S_IRWXU | S_IRWXO);
    }


    if ( fdSrc == -1 || fdDes == -1) {
        printf("Error opening files!\n");
        return 1;
    }
    

    do {
        readByte = read(fdSrc, buffer, sizeof(buffer));
        write(fdDes, buffer, readByte);
    } while ( readByte > 0);


    close(fdSrc);
    close(fdDes);
    
    printf("File(s) Coppied.\n");

    return 0;
}	
