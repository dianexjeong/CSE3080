#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int weight;
  int v1;
  int v2;
} edge;

FILE *fp_in, *fp_out;
int vertex_num;
long long int edge_num;
edge min_heap[50000001];
edge MST[50000001];
int parent[100001] = {0};

// min_heap에 element을 삽입하는 함수
void insert_heap(long long int idx, edge insertElement) {
  while (insertElement.weight < min_heap[idx / 2].weight && idx != 1) {
    long long int next_idx = idx / 2;
    min_heap[idx] = min_heap[next_idx];
    idx = next_idx;
  }
  min_heap[idx] = insertElement;
}

// min_heap에서 최소 element을 삭제하고 힙을 정렬하는 함수
edge delete_heap() {
  edge ret;
  ret = min_heap[1];

  edge temp;
  temp = min_heap[edge_num];
  min_heap[edge_num].weight = 0;
  min_heap[edge_num].v1 = 0;
  min_heap[edge_num--].v2 = 0;

  long long int parent = 1;
  long long int child = 2;
  while (child <= edge_num) {
    if ((child < edge_num) &&
        (min_heap[child].weight > min_heap[child + 1].weight))
      child++;
    if (min_heap[child].weight >= temp.weight) break;

    min_heap[parent] = min_heap[child];
    parent = child;
    child *= 2;
  }
  min_heap[parent] = temp;

  return ret;
}

int find(int vertex) {
  for (; parent[vertex] >= 0; vertex = parent[vertex])
    ;
  return vertex;
}

void unionSet(int v1, int v2) {
  if (parent[v1] > parent[v2]) {
    parent[v2] = parent[v1] + parent[v2];
    parent[v1] = v2;
  } else {
    parent[v1] = parent[v1] + parent[v2];
    parent[v2] = v1;
  }
}

// solve() 함수에서 파일 입출력
void solve() {
  fscanf(fp_in, "%d", &vertex_num);
  fscanf(fp_in, "%lld", &edge_num);
  long long int n = edge_num;

  // find함수 사용을 위해 모든 vertex의 parent값 -1로 초기화
  for (int i = 0; i < vertex_num; i++) {
    parent[i] = -1;
  }

  //파일에서 입력받아 heap에 삽입
  for (long long int i = 1; i <= edge_num; i++) {
    edge insert_element;
    fscanf(fp_in, "%d %d %d", &insert_element.v1, &insert_element.v2,
           &insert_element.weight);
    insert_heap(i, insert_element);
  }

  // hw3_result.txt 파일에 출력
  fp_out = fopen("hw3_result.txt", "w");

  // MST 구성 edge 관련 변수
  int MST_cnt = 0;
  long long int MST_weight = 0;
  // Kruskal's algorithm 적용
  for (long long int i = 1; i <= n; i++) {
    // minimum cost의 edge를 선택
    edge min_edge = delete_heap();

    // cycle이 생기는지 판단
    if (find(min_edge.v1) != -1 && find(min_edge.v1) == find(min_edge.v2))
      continue;

    //생기지 않는다면 MST에 추가, MST_cnt 업데이트
    else {
      unionSet(find(min_edge.v1), find(min_edge.v2));
      MST[MST_cnt] = min_edge;
      MST_cnt++;
      MST_weight += min_edge.weight;
    }

    fprintf(fp_out, "%d %d %d\n", min_edge.v1, min_edge.v2, min_edge.weight);
    if (MST_cnt == vertex_num - 1) break;
  }
  fprintf(fp_out, "%lld\n", MST_weight);

  // MST가 connected인지 판단
  int flag = 0;
  for (int i = 0; i < vertex_num; i++) {
    if (parent[i] < 0) {
      if (flag == 0)
        flag = 1;
      else {
        fprintf(fp_out, "DISCONNECTED\n");
        flag = 0;
        break;
      }
    }
  }
  if (flag) fprintf(fp_out, "CONNECTED\n");

  fclose(fp_in);
  fclose(fp_out);
  printf("output written to hw3_result.txt.\n");
}

int main(int argc, char *argv[]) {
  // argument 에러 처리
  if (argc != 2) {
    printf("usage: ./hw3 input_filename\n");
    exit(1);
  }
  //파일 입력 에러 처리
  fp_in = fopen(argv[1], "r");
  if (!fp_in) {
    printf("The input file does not exist.\n");
    exit(1);
  }
  clock_t start, end;
  start = clock();

  // 실행
  solve();

  end = clock();
  double duration = ((double)end - (double)start) / CLOCKS_PER_SEC;

  printf("running time: %lf seconds\n", duration);
  fclose(fp_in);
  return 0;
}