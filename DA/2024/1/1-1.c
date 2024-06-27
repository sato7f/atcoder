#include <stdio.h>
#include <stdlib.h>

// １次元配列を一列に表示
void priary(int *ary, int N){
    for(int i = 0; i < N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");
}

// qを支点に左右を交換
void magicExchage(int *ary, int q, int N){
    int *tmp_ary;
    tmp_ary = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) tmp_ary[i] = ary[i];

    // qがaryで何番目か調べる
    int idx = -1;
    for(int i = 0; i < N; i++){
        if(ary[i] == q) idx = i;
    }

    // printf("q:%d, idx:%d, %d\n",q, idx, N - idx - 1);

    for(int i = 0; i < N; i++){
        if(i < N - idx - 1) tmp_ary[i] = ary[(i + idx + 1) % N];
        else if(i == N - idx - 1) tmp_ary[i] = q;
        else tmp_ary[i] = ary[(i + idx) % N];
    }

    for(int i = 0; i < N; i++) ary[i] = tmp_ary[i];
}

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int *num_ary;
    num_ary = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) num_ary[i] = i + 1;


    int *que_ary;
    que_ary = (int*)malloc(sizeof(int) * M);
    for(int i = 0; i < M; i++) scanf("%d", &que_ary[i]);

    for(int i = 0; i < M; i++){
        // priary(num_ary, N);
        magicExchage(num_ary, que_ary[i], N);
        // priary(num_ary, N);
        // printf("\n");
    }
    priary(num_ary, N);
}

/*
output1-1.txt  -> 正解
output1-2.txt  -> 正解
output1-3.txt  -> 正解
output1-4.txt  -> 正解
output1-5.txt  -> 正解
output1-6.txt  -> 時間がかかりすぎているので改善しましょう
output1-7.txt  -> 時間がかかりすぎているので改善しましょう
output1-8.txt  -> 時間がかかりすぎているので改善しましょう
*/
