#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>

int main (int argc, char*argv[])
{
    if (argc < 2){
        perror("Not enough actual parametrs");
        perror("./{FileName} {Dest}\nFileName - Name of exec file\nDest - Name of File to write in");
        return 1;
    };
    const int SmbStop = 6;
    int Fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (Fd < 0){
        printf("Cannot open file \"%s\"\n", argv[1]);
        return 2;
    }
    else{
        FILE *Fp = fdopen(Fd, "w");
        int c = 42;
        while ((c = getc(stdin)) != SmbStop){
            if (putc(c, Fp) == EOF){
                perror("Cannot write charachter to file\n");
                return 3;
            };
        };
        if (fclose(Fp) != 0){ 
            perror("Cannot close file\n");
            return 4;
        };
    };
    return 0;
};