#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};

void aid(int co, int ex, Polynomial* rear) {
	Polynomial now = (Polynomial)malloc(sizeof(struct PolyNode));
	if (now) {
		now->coef = co;
		now->expon = ex;
		now->link = NULL;
		(*rear)->link = now;
		(*rear) = now;
	}
}

Polynomial ReadPoly() {
	int n, co, ex;
	scanf("%d", &n);
	Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
	if (p) {
		p->link = NULL;
		Polynomial rear = p;
		while (n--) {
			scanf("%d%d", &co, &ex);
			aid(co, ex, &rear);
		}
		Polynomial head = p;
		p = p->link;
		free(head);
		return p;
	}
}

void PrintPoly(Polynomial p) {
	int flag = 0;
	while (p) {
		if (p->coef != 0) {
			if (!p->link || p->link->coef == 0 && p->link->expon == 0) {
				printf("%d %d", p->coef, p->expon);
				flag = 1;
			}
			else {
				printf("%d %d ", p->coef, p->expon);
				flag = 1;
			}
		}
		p = p->link;
	}
	if (!flag) {
		printf("0 0");
	}
}

Polynomial Mult(Polynomial p1, Polynomial p2) {
	Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
	if (p) {
		p->link = NULL;
		Polynomial rear = p;
		int flag = 0;

		Polynomial s1 = p1;
		for (s1; s1; s1 = s1->link) {
			Polynomial s2 = p2;
			for (s2; s2; s2 = s2->link) {
				int co = s1->coef * s2->coef;
				int ex = s1->expon + s2->expon;
				if (!flag) {
					aid(co, ex, &rear);
					flag++;
				}
				else {
					Polynomial des = p->link;
					Polynomial mem = NULL;
					while (des->expon > ex) {
						if (!des->link)
							break;
						mem = des;
						des = des->link;
					}
					if (des->expon == ex) {
						des->coef += co;
					}
					else if (des->expon < ex) {
						Polynomial now = (Polynomial)malloc(sizeof(struct PolyNode));
						if (now) {
							now->coef = co;
							now->expon = ex;
							now->link = des;
							mem->link = now;
						}
					}
					else if (!des->link) {
						aid(co, ex, &rear);
					}
					
				}
			}
		}
		Polynomial head = p;
		p = p->link;
		free(head);
		return p;
	}
}

Polynomial Add(Polynomial p1, Polynomial p2) {
	Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
	if (p) {
		p->link = NULL;
		Polynomial rear = p;
		while (p1 && p2) {
			if (p1->expon == p2->expon) {
				aid(p1->coef + p2->coef, p1->expon, &rear);
				p1 = p1->link;
				p2 = p2->link;
			}
			else if (p1->expon > p2->expon) {
				aid(p1->coef, p1->expon, &rear);
				p1 = p1->link;
			}
			else if (p1->expon < p2->expon) {
				aid(p2->coef, p2->expon, &rear);
				p2 = p2->link;
			}
		}
		while (p1) {
			aid(p1->coef, p1->expon, &rear);
			p1 = p1->link;
		}
		while (p2) {
			aid(p2->coef, p2->expon, &rear);
			p2 = p2->link;
		}
		Polynomial head = p;
		p = p->link;
		free(head);
		return p;
	}
}
int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	printf("\n");
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}