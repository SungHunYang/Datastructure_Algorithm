#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListQueue.h"

// 큐 초기화
void queue_init(Queue* pq) {
	pq->pFront = NULL;
	pq->pBack = NULL;
}

// 큐 제거
void queue_destroy(Queue* pq) {

	// 큐가 다 비어질때까지 dequeue
	while (!queue_is_empty(pq)) {
		queue_deq(pq, NULL);
	}

}

// 큐가 비어있는지?
int queue_is_empty(Queue* pq) {
	if (pq->pFront == NULL) return SUCCESS;

	return FAIL;
}

// enqueue 데이터 추가(back에 추가)
int queue_enq(Queue* pq, Data data) {
	node* pNewNode = (node*)malloc(sizeof(node));
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	
	// 큐가 비어있을때와 그렇지 않을 때 구분
	if (queue_is_empty(pq)) {
		pq->pFront = pNewNode;
		pq->pBack = pNewNode;
	}
	else {
		pq->pBack->pNext = pNewNode;
		pq->pBack = pNewNode;
	}
	return SUCCESS;
	// ※ LinkedList.c 의 list_add() 함수와 비교해보자
	//    dummy node 를 사용한것(LinkedList)와
	//    그렇지 않은것(ListBaseQueue)도 비교
	//   dummy node  를 사용하면 코드가 더욱 간결해진다. (분기가 적어진다)

}

// dequeue 데이터 꺼내기 (front 에서 추출)
int queue_deq(Queue* pq, Data* pData) {
	if (queue_is_empty(pq)) {
		printf("[ QUEUE EMPTY ]\n");
		return FAIL;
	}
	if (pData != NULL) *pData = pq->pFront->data; // front 데이터 추출
	
	node* deleteNode = pq->pFront; //삭제할 노드 기억
	pq->pFront = pq->pFront->pNext; // front는 다음 노드로 이동
	free(deleteNode);
	return SUCCESS;
}

// peek 데이터 보기 (front 에서 봄)
int queue_peek(Queue* pq, Data* pData) {
	if (queue_is_empty(pq)) {
		printf("[ QUEUE EMPTY ]\n");
		return FAIL;
	}
	if (pData != NULL) *pData = pq->pFront->data; // front 데이터 추출

	return SUCCESS;
}
