#include <stdio.h>
#include <stdlib.h>
typedef struct Cvor{
    double v;
    struct Cvor*next;
}Cvor;
void Push(Cvor **vrh,double v){
    Cvor *novi =(Cvor*)malloc(sizeof(Cvor));
    if (novi==NULL){
        printf("Greska");
        exit(1);

    }
novi->v=v;
novi->next=*vrh;
*vrh=novi;





}
int pop(Cvor **vrh, double *v){
if (*vrh==NULL){
    return 1;
}
Cvor*temp=*vrh;
*v=temp->v;
*vrh=temp->next;
free(temp);
return 1;
}



int main(){
    Cvor *stog=NULL;
    FILE*f=fopen("postfix.txt","r");
    char token[50];
    if (f==NULL){
        printf("Greska");

        return 1;

    }
while (fscanf(f,"%49s",token)==1){
        if (token[0]>='0' && token[0]<='9'){
            double v=strtod(token,NULL);
            Push(&stog,v);
        }
        else{
            double op2,op1;
            if (pop(&stog,&op2)==1 && pop(&stog,&op1)==1){
                if (token[0]=='+'){
                    Push(&stog,op1+op2);
                }
                else if (token[0]=='-'){
                    Push(&stog,op1-op2);
                }
                else if (token[0]=='*'){
                    Push(&stog,op1*op2);
                }
                else if (token[0]=='/'){
                    Push(&stog,op1/op2);
                }
            }
            else{
                printf("Greska");
                return 1;
            }
        }
    }
    fclose(f);
    double rezultat;
    if (pop(&stog,&rezultat)==1){
        printf("Rezultat: %g\n",rezultat);

    }
  
    return 0;
}