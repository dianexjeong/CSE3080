#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 10001
#define MAX_EDGE 50000001

typedef struct {
  int weight;
  int v1;
  int v2;
} edge;

FILE *inputfile, *outfile;
int vertex_num = 0;
long long int edge_num = 0;
int mst_cnt = 0;
long long int mst_weight = 0;
edge min_heap[MAX_EDGE];
int parent[MAX_VERTEX] = {0};

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

  fscanf(inputfile, "%d", &vertex_num);
  fscanf(inputfile, "%lld", &edge_num);
  for (long long int i = 0; i < edge_num; i++) {
    int index = i + 1;
    edge new_edge;
    fscanf(inputfile, "%d %d %d", &new_edge.v1, &new_edge.v2, &new_edge.weight);
    while ((new_edge.weight < min_heap[index / 2].weight) && (index != 1)) {
      min_heap[index] = min_heap[index / 2];
      index /= 2;
    }
    min_heap[index] = new_edge;
  }

  for (int i = 0; i < vertex_num; i++) {
    parent[i] = -1;
  }

  kruskal();
  connection();

  end = clock();
  double duration = ((double)end - (double)start) / CLOCKS_PER_SEC;

  printf("running time: %lf seconds\n", duration);
  fclose(inputfile);
  return 0;
}

edge delete_heap() {
  long long int heap_num = edge_num;
  edge min, temp;
  min = min_heap[1];
  temp = min_heap[heap_num--];

  long long int par = 1;
  long long int child = 2;
  while (child <= heap_num) {
    if ((child < heap_num) &&
        (min_heap[child].weight > min_heap[child + 1].weight))
      child++;
    if (min_heap[child].weight >= temp.weight) break;

    min_heap[par] = min_heap[child];
    par = child;
    child *= 2;
  }
  min_heap[par] = temp;

  return min;
}

int find(int x) {
  while (1) {
    if (parent[x] < 0) break;
    x = parent[x];
  }
  return x;
}

void simpleunion(int v1, int v2) {
  parent[v2] = v1;
  return;
}

void kruskal() {
  for (long long int i = 0; i < edge_num; i++) {
    if (mst_cnt == vertex_num - 1) break;
    edge min_edge = delete_heap();

    if (find(min_edge.v1) == find(min_edge.v2))
      continue;
    else {
      simpleunion(find(min_edge.v1), find(min_edge.v2));
      mst_cnt++;
      mst_weight += min_edge.weight;
      fprintf(outfile, "%d %d %d\n", min_edge.v1, min_edge.v2, min_edge.weight);
    }
  }
  fprintf(outfile, "%lld\n", mst_weight);
  fclose(outfile);
  printf("output written to fp1_result.txt.\n");
}

void connection() {
  outfile = fopen("fp1_result.txt", "a");
  int connection = 0;
  for (int i = 0; i < vertex_num; i++) {
    if (parent[i] == -1) {
      connection = ((connection == 0) ? 1 : 0);
      if (connection == 0) {
        fprintf(outfile, "DISCONNECTED\n");
        break;
      }
    }
  }
  if (connection) fprintf(outfile, "CONNECTED\n");
  fclose(outfile);
  return;
}