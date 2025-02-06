#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
typedef struct Node {
    int val;
    struct Node* next;
    struct Node* random;
} Node;

// �����½ڵ�
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// ��������
Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    struct Node* cur = head;

    // **��һ������ÿ���ڵ������½ڵ�**
    while (cur) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        newnode->random = NULL;
        cur->next = newnode;
        cur = newnode->next;
    }

    // **�ڶ��������� random ָ��**
    cur = head;
    while (cur) {
        struct Node* ncur = cur->next; // ȡ���½ڵ�
        if (cur->random != NULL) {
            ncur->random = cur->random->next;  // ���½ڵ�� random ָ�򿽱� random
        }
        cur = cur->next->next;  // ������һ��ԭ�ڵ�
    }

    // **���������������**
    struct Node* newHead = head->next;
    struct Node* oldNode = head;
    struct Node* newNode = newHead;

    while (oldNode) {
        oldNode->next = oldNode->next->next;
        newNode->next = (newNode->next) ? newNode->next->next : NULL;
        oldNode = oldNode->next;
        newNode = newNode->next;
    }

    return newHead;
}

// **���Դ���**
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        printf("Node val: %d, Random points to: %d\n",
            cur->val, cur->random ? cur->random->val : -1);
        cur = cur->next;
    }
}

// �ͷ�����
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// **������**
int main() {
    // ������������
    Node* head = createNode(7);
    head->next = createNode(13);
    head->next->next = createNode(11);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(1);

    // ���� random ָ��
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    // ���ԭ����
    printf("Original list:\n");
    printList(head);

    // ��������
    Node* copiedList = copyRandomList(head);

    // ���������
    printf("\nCopied list:\n");
    printList(copiedList);

    // �ͷ�����
    freeList(head);
    freeList(copiedList);

    return 0;
}
