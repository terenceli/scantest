#include <unistd.h>
#include <stdlib.h> 


int f1()
{
    char *buf;
    int len;
    /* for some file descriptor fd*/
    read(0, &len, sizeof(len));
    /* We forgot to check for input < 0 */

    if (len > 8000) {return 0; }
    buf = malloc(len);
    read(0, buf, len); /* len casted to unsigned and overflows */
    return 0;
}

unsigned int amount(int y){ return y;}

int f2(){
   int amoun;
   int value=-300;
   amoun=amount(value);
   return 0;
}

#define SIZE 16
int f3(){
    char* ptr = (char*)malloc (SIZE);
    if (1) {
        free(ptr);
    }
    free(ptr);
    return 0;
}


int f4(){
    int abrt=0;
    int err=1;
    char* ptr = (char*) malloc(64*sizeof(char));
    strcpy(ptr,"This string is in the heap");
    if (err) {
        abrt = 1;
        free(ptr);
        char* ptr2 = (char*) malloc(2*sizeof(char));
    }
    if (abrt) {
        printf("operation aborted before commit. Pointer value is ptr: %s",ptr);
    }
    return 0;
}


int f5()
{
    int x;
    x=1/0;
    return 0;
}

#define NULL 0
int f6(){
   int *p=NULL;
   if (*p){

   }
   return 0;
}

int f7(){
    int x,y;
    x=y+1;
    return 0;
}

int f8(){
    char last_name[20];
    printf ("Enter your last name: ");
    scanf ("%s", last_name);
    return 0;
}


int main()
{
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
}
