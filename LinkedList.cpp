#include<stdio.h>
#include<stdlib.h>

#include "LinkedList.h"

//Initialize the list and return the pointer to it.
List *ListInit() {
	List *pNewList = (List*)malloc(sizeof(List));
	if (pNewList == NULL)
		return NULL;
	pNewList->count = 0;
	pNewList->head = NULL;
	pNewList->tail = NULL;
	return pNewList;
}

//Destroy list and free all allocated memory.
void ListDestroy(List *pList) {
	ListNode *pDel = NULL, *pNext = NULL;
	for (pDel = pList->head; pDel != NULL; pDel = pNext) {
		pNext = pDel->next;
		free(pDel);
	}
	free(pList);
}

//Inserts an item at the beginning of the list.
void ListInsertAtHead(List *pList, int item) {
	ListNode *pNewNode = (ListNode*)malloc(sizeof(ListNode));
	pNewNode->data = item;
	pNewNode->next = NULL;
	pNewNode->prev = NULL;

	if (pList->head == NULL) {
		pList->head = pNewNode;
		pList->tail = pNewNode;
	}
	else {
		pNewNode->next = pList->head;
		pList->head = pNewNode;
		(pNewNode->next)->prev = pNewNode;
	}
	pList->count++;
}

//Inserts an item at the end of the list.
void ListInsertAtTail(List *pList, int item) {
	ListNode *pNewNode = (ListNode*)malloc(sizeof(ListNode));
	pNewNode->data = item;
	pNewNode->next = NULL;
	pNewNode->prev = NULL;

	if (pList->head == NULL) {
		pList->head = pNewNode;
		pList->tail = pNewNode;
	}
	else {
		pNewNode->prev = pList->tail;
		pList->tail = pNewNode;
		(pNewNode->prev)->next = pNewNode;
	}
	pList->count++;
}


//Delete and return the first item.
int ListDeleteFirst(List *pList) {
	ListNode *delNode = pList->head;
	if (pList->head == NULL)
		return NULL;
	if (pList->head->next == NULL) {
		pList->head = NULL;
		return delNode->data;
		free(delNode);
	}
	else {
		pList->head->next->prev = NULL;
		pList->head = pList->head->next;
		return delNode->data;
		free(delNode);
	}
		pList->count--;
}

//Delete and return the last item.
int ListDeleteLast(List *pList) {
	ListNode *delNode = pList->tail;
	if (pList->tail == NULL)
		return NULL;
	if (pList->tail->prev == NULL) {
		pList->tail = NULL;
		return delNode->data;
		free(delNode);
	}
	else {
		pList->tail->prev->next = NULL;
		pList->tail = pList->tail->prev;
		return delNode->data;
		free(delNode);
	}
	pList->count--;
}

//Get the item at given index.
int ListGetAt(List *pList, int index) {
	ListNode *pNode = pList->head;
	for (int i = 0; i < index; i++) { 
		if (pNode == NULL) {
			printf("error\n");
			return NULL;
		}
		if (i == index)
			return pNode->data;
		pNode = pNode->next;
	}
}

//Prints all elements in linked list in forward traversal order.
void ListPrint(List *pList) {
	ListNode *pNode = pList->head;
	printf(" Forward : ");
	if (pNode == NULL)
		return;
	while (pNode != NULL) {
		printf("%d ", pNode->data);
		pNode = pNode->next; 
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void ListReversePrint(List *pList) {
	ListNode *pNode = pList->tail;
	printf(" Reverse : ");
	if (pNode == NULL)
		return;
	while (pNode != NULL) {
		printf("%d ", pNode->data);
		pNode = pNode->prev;
	}
	printf("\n");
}
