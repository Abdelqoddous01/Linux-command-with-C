#include <stdio.h>
#include <string.h>

int is_file(char filename[]){
    FILE *file;

    file=fopen(filename,"r");

    if(file == NULL){
        return 0;
    }

    fclose(file);
    return 1;

}

long int file_size(char filename[]){


    if(is_file(filename)){
        
        FILE *file;
        file=fopen(filename,"r");

        fseek(file,0,SEEK_END);
        long int size=ftell(file);
        return size;    
    }

    else{
        return 0;
    }

}


void create_copy(char content[],char filename[]){
    
    FILE *file;
    
    if (is_file(filename))
    {
        printf("file alredy exist");
    }

    else{
        file=fopen(filename,"w");
        fprintf(file, "%s\n",content);
    }

}

int main(int argc,char **argv){


    char help[]="Copy to path > cp path/file1.txt path/file2.txt\n";

    if (argc == 1)
    {
        printf("expected 2 arguments but got 0"); 
    }

    else if (argc == 2)
    {
        printf("required arguments 2 but got 1");
    }

    else if (argc >3)
    {
        printf("expected 2 arguments but got %d",argc);
    }
    
    else{
    

        if (file_size(argv[1]) )
        {
            long int size=file_size(argv[1]);
            char content[size+1];
            
            FILE *file=fopen(argv[1],"r");
            char c=fgetc(file);
            int len=0;
            

            while (c!=EOF && len != size)
            {
                content[len]=c;
                len++;
                c=fgetc(file);
            }
            content[len]='\0';

            create_copy(content,argv[2]);         
        }

        else{
            printf("file dosen't exitst");
        }
        
    }
    

    
    return 0;

}