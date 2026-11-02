#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void slozi(int n[],int velicina){
      int i,j,temp;
      for (i = 0; i < velicina-1; i++) {
            for (j = 0; j < velicina-i-1; j++) {
                  if (n[j] > n[j+1]) {
                        temp = n[j];
                        n[j] = n[j+1];
                        n[j+1] = temp;
                  }
            }
      }
}
int main() {
int n[10];
printf("Unesi deset brojeva \n");
for(int i=0; i<10; i++){
      scanf("%d",&n[i]);

}
slozi(n,10);
printf("Sortirani brojevi su: \n");
for(int i=0; i<10; i++){
      printf("%d\n",n[i]);
}


return 0;
}






