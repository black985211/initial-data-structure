#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int val;
    struct Node* next;
    struct Node* random;
} Node;

// 创建新节点
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// 复制链表
Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    struct Node* cur = head;

    // **第一步：在每个节点后插入新节点**
    while (cur) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        newnode->random = NULL;
        cur->next = newnode;
        cur = newnode->next;
    }

    // **第二步：复制 random 指针**
    cur = head;
    while (cur) {
        struct Node* ncur = cur->next; // 取出新节点
        if (cur->random != NULL) {
            ncur->random = cur->random->next;  // 让新节点的 random 指向拷贝 random
        }
        cur = cur->next->next;  // 跳到下一个原节点
    }

    // **第三步：拆分链表**
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

// **测试代码**
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        printf("Node val: %d, Random points to: %d\n",
            cur->val, cur->random ? cur->random->val : -1);
        cur = cur->next;
    }
}

// 释放链表
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// **主函数**
int main() {
    // 创建测试链表
    Node* head = createNode(7);
    head->next = createNode(13);
    head->next->next = createNode(11);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(1);

    // 设置 random 指针
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    // 输出原链表
    printf("Original list:\n");
    printList(head);

    // 复制链表
    Node* copiedList = copyRandomList(head);

    // 输出新链表
    printf("\nCopied list:\n");
    printList(copiedList);

    // 释放链表
    freeList(head);
    freeList(copiedList);

    return 0;
}
