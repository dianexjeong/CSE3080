#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VERTEX 10001
#define MAX_EDGE 50000001

typedef struct {
  int weight;
  int v1;
  int v2;
} edge;

int vertex_num = 0;
long long int edge_num = 0;
int mst_count = 0;
long long int mst_weight = 0;
long long int heap_num = 0;

edge min_heap[MAX_EDGE];
int parent[MAX_VERTEX] = {0};
FILE *inputfile, *outfile;

void read(FILE *);
edge delete_heap();
int find(int);
void simpleunion(int, int);
void kruskal();
void connection();

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: ./fp1 input_filename\n");
    return 1;
  }

  inputfile = fopen(argv[1], "r");
  outfile = fopen("fp1_result.txt", "w");

  if (inputfile == NULL) {
    printf("The input file does not exist.\n");
    return 2;
  }
  clock_t start, end;
  start = clock();
  printf("started\n");
  read(inputfile);  // inputfile의 내용을 min_heap에 담기
  for (int i = 0; i < vertex_num; i++) {
    parent[i] = -1;
  }
  heap_num = edge_num;
  printf("read\n");
  kruskal();
  printf("kruskaled\n");
  // connection();
  fclose(inputfile);
  fclose(outfile);
  printf("output written to fp1_result.txt.\n");
  end = clock();
  double duration = ((double)end - (double)start) / CLOCKS_PER_SEC;

  printf("running time: %lf seconds\n", duration);

  return 0;
}

void read(FILE *input) {
  fscanf(input, "%d", &vertex_num);
  fscanf(input, "%lld", &edge_num);
  // int meanheapcount = 0;
  for (long long int i = 0; i < edge_num; i++) {
    int index = i + 1;
    edge new_edge;
    fscanf(input, "%d %d %d", &new_edge.v1, &new_edge.v2, &new_edge.weight);
    while ((new_edge.weight < min_heap[index / 2].weight) && (index != 1)) {
      min_heap[index] = min_heap[index / 2];
      index /= 2;
    }
    // meanheapcount++;
    min_heap[index] = new_edge;
  }
  // printf("%d", meanheapcount);
  return;
}

int find(int x) {
  while (1) {
    if (parent[x] < 0) break;
    x = parent[x];
  }
  return x;
}

void simpleunion(int x, int y) {
  parent[y] = x;
  return;
}

edge delete_heap() {
  edge min, temp;
  long long int par = 1;
  long long int child = 2;
  min = min_heap[1];
  temp = min_heap[heap_num--];
  while (child <= heap_num) {
    if ((child < heap_num) &&
        (min_heap[child].weight > min_heap[child + 1].weight))
      child++;
    if (temp.weight <= min_heap[child].weight) break;
    min_heap[par] = min_heap[child];
    par = child;
    child *= 2;
  }
  min_heap[par] = temp;
  return min;
}

void kruskal() {
  for (long long int i = 0; i < edge_num; i++) {
    if (mst_count == vertex_num - 1) break;
    edge min_edge = delete_heap();
    // printf("count: %d min: %d %d\n", mst_count, min_edge.v1, min_edge.v2);
    if (find(min_edge.v1) == find(min_edge.v2))
      continue;
    else {
      // printf("but selected: %d %d\n", min_edge.v1, min_edge.v2);

      if ((parent[min_edge.v1] >= 0) && (parent[min_edge.v2] >= 0)) {
        parent[parent[min_edge.v2]] = parent[min_edge.v1];
      }

      simpleunion(find(min_edge.v1), find(min_edge.v2));
      mst_weight += min_edge.weight;
      mst_count++;
      fprintf(outfile, "%d %d %d\n", min_edge.v1, min_edge.v2, min_edge.weight);
    }
  }
  fprintf(outfile, "%lld\n", mst_weight);
  return;
}
/*
void connection() {
  FILE *out;
  out = fopen("fp1_result.txt", "a");
  int flag = 0;
  for (int i = 0; i < vertex_num - 1; i++) {
    if (flag(parent[mst[i].v1])) }
  fclose(out);
  return;
}
*/