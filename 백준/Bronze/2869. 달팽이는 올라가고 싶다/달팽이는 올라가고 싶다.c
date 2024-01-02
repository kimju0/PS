#include <stdio.h>
int main() {
	int A, B, V;
	scanf("%d%d%d", &A, &B, &V);
	if ((V - B) % (A - B) != 0) printf("%d", (V - B) / (A - B) + 1);
	else printf("%d", (V - B) / (A - B));
}