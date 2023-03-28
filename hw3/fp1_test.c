#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_E 50000001
#define MAX_V 10001

typedef struct {
  long long int v1;
  long long int v2;
  int cost;
} edge;

edge newedge;
edge min_heap[MAX_E];
int parent[MAX_V] = {0};
void insert_minheap(int, edge);
edge delete ();
void kruskal();
int simplefind(int);
void simpleunion(int, int);
void connection();
long long int vertexnum = 0, edgenum = 0, heapcount = 0;
long long int mstcount = 0, mstcost = 0;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: ./fp1 input_filename");
    return 1;
  }

  FILE *inputfile;
  inputfile = fopen(argv[1], "r");
  if (inputfile == NULL) {
    printf("The input file does not exist.");
    return 2;
  }

  clock_t begin = clock();                //시작
  fscanf(inputfile, "%lld", &vertexnum);  //첫줄
  fscanf(inputfile, "%lld", &edgenum);    //둘째줄
  while (1) {  //셋째줄부터 읽어서 minheap에 넣기
    heapcount++;
    if (heapcount > edgenum) {
      heapcount--;
      break;
    }
    if (feof(inputfile)) break;
    fscanf(inputfile, "%lld %lld %d", &newedge.v1, &newedge.v2, &newedge.cost);
    insert_minheap(heapcount, newedge);
  }
  for (int i = 0; i < vertexnum; i++) {
    parent[i] = -1;
  }

  kruskal();
  connection();
  fclose(inputfile);
  printf("output written to fp1_result.txt.\n");
  clock_t end = clock();  //끝
  double rtime = ((double)end - (double)begin) / CLOCKS_PER_SEC;
  printf("running time: %f seconds\n", rtime);

  return 0;
}

void insert_minheap(int idx, edge e) {
  while ((idx != 1) && (e.cost < min_heap[idx / 2].cost)) {
    min_heap[idx] = min_heap[idx / 2];
    idx /= 2;
  }
  min_heap[idx] = e;
  return;
}

void kruskal() {
  FILE *outfile;
  outfile = fopen("fp1_result.txt", "w");
  for (long long int i = 1; i <= edgenum; i++) {
    if (mstcount == vertexnum - 1) break;

    edge minedge = delete ();  // minheap에서 제일 작은거 가져오기
    if ((simplefind(minedge.v1) == simplefind(minedge.v2)))  // cycle 만드는지
      continue;
    else {
      if ((parent[minedge.v1] >= 0) && (parent[minedge.v2] >= 0)) {
        parent[parent[minedge.v2]] = parent[minedge.v1];
      }
      simpleunion(find(minedge.v1), find(minedge.v2));

      mstcost += minedge.cost;
      fprintf(outfile, "%lld %lld %d\n", minedge.v1, minedge.v2, minedge.cost);
    }
  }
  fprintf(outfile, "%lld\n", mstcost);
  fclose(outfile);
  return;
}

edge delete () {
  edge min, tmp;
  long long int parent, child;
  min = min_heap[1];
  tmp = min_heap[heapcount--];
  parent = 1;
  child = 2;
  while (child <= heapcount) {
    if ((child < heapcount) &&
        (min_heap[child].cost > min_heap[child + 1].cost))
      child++;
    if (tmp.cost <= min_heap[child].cost) break;
    min_heap[parent] = min_heap[child];
    parent = child;
    child *= 2;
  }
  min_heap[parent] = tmp;
  return min;
}

int simplefind(int x) {
  while (1) {
    if (parent[x] < 0) break;
    x = parent[x];
  }
  return x;
}

/*
int simplefind(int vertex) {
  for (; parent[vertex] >= 0; vertex = parent[vertex])
    ;
  return vertex;
}
*/

void simpleunion(int x, int y) {
  parent[y] = x;
  return;
}

void connection() {
  FILE *outfile;
  outfile = fopen("fp1_result.txt", "a");
  int i = 0, flag = 0;  //원래는 이상무
  for (i = 0; i < vertexnum; i++) {
    if (simplefind(i) < 0) {
      if (flag == 0)
        flag = 1;  //이제는 root 하나 있다 표시
      else if (flag == 1) {
        fprintf(outfile, "DISCONNECTED\n");
        flag = 2;
        break;
      }
    }
  }
  if (flag != 2) fprintf(outfile, "CONNECTED\n");
  fclose(outfile);
  return;
}