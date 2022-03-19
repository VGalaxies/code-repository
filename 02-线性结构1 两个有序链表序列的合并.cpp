#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    int n, data;
    scanf("%d", &n);
    List head = (List)malloc(sizeof(List)), now = (List)malloc(sizeof(List));
    if (head && now) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &data);
            if (i == 0) {
                head->Data = data;
                head->Next = NULL;
            }
            else {
                for (now = head; now; now = now->Next) {
                    if (!now->Next) {
                        List tmp = (List)malloc(sizeof(List));
                        if (tmp) {
                            tmp->Data = data;
                            now->Next = tmp;
                            tmp->Next = NULL;                           
                        }
                        break;
                    }
                }
            }
        }
    }
    return head;
}

void Print(List L) {
    if (!L) {
        printf("NULL\n");
    }
    else {
        for (L; L; L = L->Next) {
            if (L) {
                printf("%d ", L->Data);
            }
        }
    }
    printf("\n");
}

List Merge(List L1, List L2) {
    if (!L1 && !L2) {
        return NULL;
    }
    List p1 = L1, p2 = L2;
    if (!L1) {
        L2 = NULL;
        return p2;
    }
    if (!L2) {
        L1 = NULL;
        return p1;
    }
    List ans = (List)malloc(sizeof(List)), now = (List)malloc(sizeof(List));
    if (ans && now) {
        ans = now;
        while (L1 && L2) {
            if (L1->Data < L2->Data) {
                now->Data = L1->Data;
                L1 = L1->Next;
            }
            else {
                now->Data = L2->Data;
                L2 = L2->Next;
            }
            List tmp = (List)malloc(sizeof(List));
            if (tmp && L1 && L2) {
                now->Next = tmp;
                now = now->Next;
            }
        }
        if (!L1) {
            now->Next = L2;
        }
        if (!L2) {
            now->Next = L1;
        }
    }
    return ans;
}