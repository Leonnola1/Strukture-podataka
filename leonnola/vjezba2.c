#include <stdio.h>
typedef struct Osoba*Position;
typedef struct Osoba{
    char ime[30];
    char prezime[30];
    int godine;
    Position next;
}Person;
int insertAfter(Position p, Position newP){

newPerson->next = p->next;
p->next = newP;



}
int insertBegin(char *Ime, char *Prezime,int Godine){
    Position newPerson=NULL;
    newPerson=(Position)malloc(sizeof(Person));
    newPerson->godine = Godine;
    strcpy (newPerson->ime, Ime );
    newPerson->next=NULL;
    





}
int main(){
    Person Head={Person.ime={0}, Person.prezime{0}, Person.next=NULL, Person.godine=0};
    Position p=&Head;





}
int ispis(Position q = p, q->next != NULL, q=q->next){
    printf(".....",q->ime)
    printf("")
}
insertEnd(char *Ime, char *Prezime,int Godine){
    Position newPerson=NULL;
    newPerson=(Position)malloc(sizeof(Person));
    newPerson->godine = Godine;
    strcpy (newPerson->ime, Ime );
    newPerson->next=NULL;
    while (p->next!=NULL){
        p=p->next;
    insertAfter(p , newPerson);

    }
}


