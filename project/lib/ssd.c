#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print_hex(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Не вдалося відкрити файл");
        return;
    }

    unsigned char buffer[16]; 
    size_t bytesRead;
    int buf = 0;
    printf("unsigned char %s[] = {\n",filename);
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        printf("\t");
        for (size_t i = 0; i < bytesRead; i++) {
            printf("0x%02x", buffer[i]);
            if (i < bytesRead - 1) {
                printf(", ");
            }
            buf++;
        }
        printf("\n");
    }
    printf("};\nunsigned int %s_len = %d;\n",filename,buf);
    fclose(file);
}
void print_hex_o(const char* filename, const char* outfile) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Не вдалося відкрити файл");
        return;
    }
    FILE *outFile = fopen(outfile, "w");
    if (!outFile) {
        perror("Не вдалося відкрити вихідний файл для запису");
        fclose(file);
        return;
    }

    unsigned char buffer[16];
    size_t bytesRead;
    int buf = 0;
    fprintf(outFile,"unsigned char %s[] = {\n",filename);


    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fprintf(outFile,"\t");
        for (size_t i = 0; i < bytesRead; i++) {
            fprintf(outFile, "0x%02x", buffer[i]);
            if (i < bytesRead - 1) {
                fprintf(outFile, ", ");
            }
            buf++;
        }
        fprintf(outFile, "\n");
    }
    fprintf(outFile, "};\nunsigned int %s_len = %d;\n", filename, buf);
    fclose(file);
    fclose(outFile);
}
int main(int args, char* argv[]){
  char *arg = NULL;
  char name[128];
  char outfile[128];
  arg = (char *)malloc(128 * sizeof(char));
  strcpy(arg, "");

  for(int i = 1; i< args;i++){
    if (strcmp(argv[i], "-h") == 0) {
      strcat(arg,"h");
    }
    else if(strcmp(argv[i],"-o") == 0){
      strcat(arg,"o");
      strcpy(outfile,argv[i+1]);
    }
    else{
      strcpy(name,argv[i]);
    }
  }
  if(strcmp(arg,"h") == 0){
    print_hex(name);
  }
  else if(strcmp(arg,"o") == 0){
    print_hex_o(name,outfile);
  }
  else if(strcmp(arg,"oh") == 0||strcmp(arg,"ho") == 0){
    print_hex(name);
    print_hex_o(name,outfile);
  }
  free(arg);
}
