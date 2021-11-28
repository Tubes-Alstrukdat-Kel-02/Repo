#include "queueRenamed.h"
#include <stdio.h>

void tulisQueue(Queue q);

int main() {
  Queue  q;
  int n;
  infotype x;
  printf("Masukan panjang max Q: ");
  scanf("%d",&n);
  CreateEmptyQueue(&q,n);
  while(1){
    do {
      printf("\n1. Add\n2. Del\nInput: ");
      scanf("%d",&n);
    } while (n!=1 && n!=2);
    if (n==1) {
      printf("\nAdd: ");
      scanf("%d", &x);
      AddElmtQueue(&q,x);
      tulisQueue(q);
    } else {
      DelElmtQueue(&q,&x);
      printf("\nDel: %d\n",x);
      tulisQueue(q);
    }
    if(IsFullQueue(q)){
    	printf("Q full\n");
 	}
  }
  return 0;
}

void tulisQueue(Queue q){
  if (IsEmptyQueue(q)) printf("Q kosong");
  else {
    printf("Q= |");
    for (int i=1;i<=MaxElQueue(q);i++){
      if (TailQueue(q)<HeadQueue(q)) {
        if (i<=TailQueue(q) || i>=HeadQueue(q)) {
          printf(" %d",q.T[i]);
        } else printf(" ~");
      } else {
        if (i<=TailQueue(q) && i>=HeadQueue(q)) {
          printf(" %d",q.T[i]);
        } else printf(" ~");
      }
      printf(" |");
    }
    // }
  }
  printf("\nHead    : %d\nInfoHead: %d",HeadQueue(q),InfoHeadQueue(q));
  printf("\nTail    : %d\nInfoTail: %d\n",TailQueue(q),InfoTailQueue(q));
}