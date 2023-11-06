#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NODE {
	int arrive_ind, distance;
	struct NODE* link;
}NODE;
int V, E, K, A;
int shortest_dist[20001];
int check[20001];
NODE head[20001];

int main() {
	scanf("%d%d", &V, &E);
	for (int i = 1; i < V+1; i++) {
		shortest_dist[i] = 1000000000;
	}
	for (int i = 0; i < E; i++) {
		int temp[3];
		scanf("%d%d%d", &temp[0], &temp[1], &temp[2]);

		NODE* new = malloc(sizeof(NODE));
		new->arrive_ind = temp[1], new->distance = temp[2], new->link = head[temp[0]].link;
		head[temp[0]].link = new;
	}
	scanf("%d%d", &K, &A);
	shortest_dist[K] = 0;
	check[K] = 1;
	int cur = K;
	for (int i = 1; i < V; i++) {//시적점은 이미 확정되었으니 V-1번 반복
		NODE* cur_node = &head[cur];
		while (cur_node != NULL) {
			if (check[cur_node->arrive_ind]==0 && shortest_dist[cur_node->arrive_ind] > shortest_dist[cur] + cur_node->distance) {
				shortest_dist[cur_node->arrive_ind] = shortest_dist[cur] + cur_node->distance;
			}
			cur_node = cur_node->link;
		}

		int ind,compare_dist=1000000000;
		for (int j = 1; j < V + 1; j++) {
			if (check[j] == 0 && shortest_dist[j] < compare_dist) {
				ind = j, compare_dist = shortest_dist[j];
			}
		}
		check[ind] = 1;
		cur = ind;
	}
	printf("%d\n", shortest_dist[A]);
}