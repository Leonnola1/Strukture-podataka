#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person* Position;
typedef struct Person {
    char name[30];
    char lname[30];
    int birthyear;
    Position next;
    
}Person;

int insertAfter(Position head, char* name , char* lname, int birthyear){
    Position NPer=(Position)malloc(sizeof(Person));
    if(NPer==NULL){
        printf("memorijska alokacija nema uspjeha \n");
        return -1;

    }
    strcpy(NPer->name, name);
    strcpy(NPer->lname, lname);
    NPer->birthyear = birthyear;
    NPer->next = head->next;
    head->next = NPer;
    return 0;
}

int insertBegin(Position head, char* name , char* lname, int birthyear){
    Position NPer=(Position)malloc(sizeof(Person));
    if(NPer==NULL){
        printf("greska pri memorijskoj alokaciji! \n");
        return -1;
    }
    strcpy(NPer->name, name);
    strcpy(NPer->lname, lname);
    NPer->birthyear = birthyear;
    NPer->next = head->next;
    head->next = NPer;
    return 0;
}
int Ispis(Position head){
    Position temp=head;
         while(temp!=NULL){
            printf("%s %s %d\n", temp->name , temp-> lname , temp->birthyear);
                temp=temp->next;
    }
return 0;
}
int InsertEnd(Position head, char*name,char* lname, int birthyear){
        Position last = head;
        while(last->next!=NULL){
            last=last->next;

        }


    return insertAfter(last, name, lname, birthyear) ;
}



Position findbylastname(Position first, char* lname){
    Position temp=first;
    while (temp!=NULL && strcmp(lname,temp->lname)!=0){
        temp=temp->next;
        
    }
    if(temp!=NULL){
        printf("Osoba s tim prezimenom je: %s %s %d\n", temp->name, temp->lname, temp->birthyear);
    }else{
        printf("Osoba s tim prezimenom nije pronadjena!\n");
    }
return temp;

}

int deletebylastname(Position head, char* lname){
    Position temp=head;
    while(temp->next!=NULL && strcmp(lname,temp->next->lname)!=0){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Osoba s tim prezimenom nije pronadjena!\n");
        return -1;
    }
    Position toDelete=temp->next;
    temp->next=toDelete->next;
    free(toDelete);

    return 0;
}
int insertAfterlname(Position head, char* targetlname, char* name, char* lname,int birthyear){
    Position temp=findbylastname(head->next, targetlname);
    if (temp==NULL){
        printf("osoba s tim prezimenom nije nadena !");
        return EXIT_FAILURE;
    }
    return insertAfter(temp, name, lname, birthyear);

}
int insertBeforelname(Position head,char* targetlname, char*name, char* lname, int birthyear){
    Position prev=head;
    while(prev->next!=NULL && strcmp(targetlname, prev->next->lname)!=0){
        prev=prev->next;
    }
    if (prev->next==NULL){
        return EXIT_FAILURE;
    }
    return insertAfter(prev, name, lname, birthyear);



}
int writetofile(Position first,char* filename){
    FILE* file=fopen(filename, "w");
    if(file==NULL){
        printf("greska pri otvaranju datoteke!\n");
        return -1;
    }
    
    
    Position temp=first;
    while(temp!=NULL){
        fprintf(file,"%s %s %d \n", temp->name, temp->lname, temp->birthyear);
        temp=temp->next;



    }
    
    fclose(file);
    return 0;



}
int Readfromfile(Position head, char* filename){
    FILE* file=fopen(filename, "r");
    if(file==NULL){
        printf("greska pri otvaranju datoteke!\n");
        return -1;
    }
    char name[30], lname[30];
    int birthyear;
    while(fscanf(file,"%29s %29s %d \n", name, lname, &birthyear)==3){
        InsertEnd(head, name, lname, birthyear);
    }
    fclose(file);
    return 0;

}

void sortlist(Position head){
Person sorted={"","",0,NULL};
Position cur=head->next;
while(cur!=NULL){
    Position next=cur->next;
    Position prev=&sorted;
    while(prev->next!=NULL && strcmp(prev->next->lname, cur->lname)<0){
        prev=prev->next;
    }
    cur->next=prev->next;
    prev->next=cur;
    cur=next;
}
  head->next=sorted.next;
}




int main(){
Person Head = {"", "", 0, NULL};
   insertBegin(&Head, "Ivan", "Zorvat", 1990);
   insertBegin(&Head, "Marko", "Covac", 1995);
     insertBegin(&Head,"Leon","Eola", 2006);
   insertBegin(&Head, "Ana", "Bola", 1992);
   insertBegin(&Head,"Leon","Eola", 2006);
   sortlist(&Head);
   Ispis(Head.next);
   writetofile(Head.next, "datoteka.txt");
   

    return 0;
}