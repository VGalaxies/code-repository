#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXD 1000000
#define MAXNUMBER 12

//��������ṹ
typedef struct list
{
    int count;
    char telenumber[MAXNUMBER];
    struct list* Next;
} *LNode;

//��ϣ��
typedef struct Map
{
    int size;
    LNode Head;
} *HashMap;

//����������
int NewPrime(int numbers)
{
    int i, j, temp;
    for (i = numbers + 1; i < MAXD; i += 2)
    {
        temp = sqrt(i);
        for (j = 2; j <= temp; j++)
            if (i % j == 0)
                break;
        if (j == temp + 1)
            return i;
    }
}

//����ֵ
int Hash(char* key, int p)
{
    return (atoi(key + MAXNUMBER - 5) % p);
}

//�ڹ�ϣ������λ��
LNode Find(HashMap H, char* str)
{
    int pos = Hash(str, H->size);
    LNode position = H->Head[pos].Next;
    while (position)
    {
        if (!strcmp(str, position->telenumber))
            break;
        else
            position = position->Next;
    }
    return position;
}

//���뺯��
void Insert(char* str, HashMap H)
{
    int pos;
    LNode position;
    position = Find(H, str);
    if (!position)
    {
        position = (LNode)malloc(sizeof(struct list));
        pos = Hash(str, H->size);
        strcpy(position->telenumber, str);
        if (position->telenumber)
        {
            position->count = 1;
            position->Next = H->Head[pos].Next;
            H->Head[pos].Next = position;
        }
    }
    else
        position->count++;
    return;
}

//�����ϣ��
HashMap CreateHashMap(int numbers)
{
    int i;
    HashMap H;
    char str[MAXNUMBER];
    H = (HashMap)malloc(sizeof(struct Map));
    H->size = NewPrime(2 * numbers);
    H->Head = (LNode)malloc(H->size * sizeof(struct list));
    for (i = 0; i < H->size; i++)
    {
        H->Head[i].Next = NULL;
        H->Head[i].count = 0;
        H->Head[i].telenumber[0] = '\0';
    }
    for (i = 0; i < 2 * numbers; i++)
    {
        scanf("%s", &str);
        Insert(str, H);
    }
    return H;
}

//�������
void Print(HashMap H)
{
    LNode position;
    int i, maxcount = 0, friends = 0;
    char minnumber[MAXNUMBER];
    for (i = 0; i < H->size; i++)
    {
        position = H->Head[i].Next;
        while (position)
        {
            if (position->count > maxcount)
            {
                maxcount = position->count;
                strcpy(minnumber, position->telenumber);
                friends = 1;
            }
            else if (position->count == maxcount)
            {
                friends++;
                if (strcmp(position->telenumber, minnumber) < 0)
                    strcpy(minnumber, position->telenumber);
            }
            position = position->Next;
        }
    }
    printf("%s %d", minnumber, maxcount);
    if (friends > 1)
        printf(" %d", friends);
    return;
}

//������
int main()
{
    HashMap H;
    int numbers;
    scanf("%d", &numbers);
    H = CreateHashMap(numbers);
    Print(H);
    return 0;
}