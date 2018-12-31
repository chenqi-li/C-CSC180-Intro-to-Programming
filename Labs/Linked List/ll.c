//
//  ll.c
//  Lab 9
//
//  Created by Chenqi Li on 2018/11/16.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(void) {
   llnode *head = NULL;
   llnode *head2 = NULL;
   llnode *head3 = NULL;
   int a = 0;
   int b = 0;
   int c = 0;

   a = ll_add_to_tail(&head, 200);
   a = ll_add_to_tail(&head, 100);
   a = ll_add_to_tail(&head, 300);
   a = ll_print(head);
   printf("%d\n", ll_del_from_head(&head));
   a = ll_print(head);
   
   /*
   a = ll_add_to_tail(&head, 1);
   a = ll_add_to_tail(&head, 2);
   a = ll_add_to_tail(&head, 3);
   b = ll_add_to_tail(&head2, 4);
   b = ll_add_to_tail(&head2, 5);
   b = ll_add_to_tail(&head2, 6);
   a = ll_print(head);
   b = ll_print(head2);
   c = ll_concat(&head, &head2);
   */
   
}

int ll_add_to_head( llnode **head, int val) {
   llnode *old_head;
   if (head == NULL) {
      return -1;
   }
   old_head = *head;
   
   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
   (*head) -> next = old_head;
   return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
             which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
      llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}





int ll_find_by_value(llnode *pList, int val) {
   if (pList == NULL){
      return -1;
   }
   
   if (((*pList).val)==val) {
      return 0;
   } else {
   return ll_find_by_value((*pList).next, val);
   }

   return -1;
}


int ll_del_from_tail(llnode **ppList) {
   if (ppList == NULL) {
      return -1;
   }
   if ((**ppList).next==NULL) {
      free(*ppList);
      *ppList = NULL;
      return 0;
   } else {
      return ll_del_from_tail(&(**ppList).next);
   }
}


int ll_del_from_head(llnode **ppList) {
   llnode *pnew = ((*ppList)->next);

   if (ppList == NULL) {
      return -1;
   }
   free(*ppList);
   *ppList = NULL;
   *ppList = pnew;
   return 0;
}


int ll_del_by_value(llnode **ppList, int val) {
   int *skip;
   skip = 0;

   if (ppList == NULL) {
      return -1;
   }
   
   if (skip==0) {
      free(*ppList);
      ppList = (*ppList)->next;
   }
   else if ((*ppList)->val == val) {
      llnode *old = *ppList;
      free(*ppList);
      (*ppList)->next = (*old).next;
      return 0;
   } else {
      *skip = -1;
      return ll_del_by_value(&((**ppList).next), val);
   }
   return -1;
}


int ll_insert_in_order(llnode **ppList, int val){
   if (ppList == NULL) {
      return -1;
   }
   return 0;
}

int ll_concat(llnode **pSrcA, llnode **pSrcB){
   if (pSrcA == NULL) {
      return -1;
   } else if (pSrcB == NULL) {
      return -1;
   }
   
   if ((**pSrcA).next==NULL) {
      (**pSrcA).next=pSrcB;
      return 0;
   } else {
      return ll_concat(&(**pSrcA).next, &(**pSrcB));
   }
}

int ll_sort(llnode **ppList) {
   if (ppList == NULL) {
      return -1;
   }
   return 0;
}
