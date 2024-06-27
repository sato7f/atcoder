#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *prev;
    struct Node *next;
}typedef Node;

// nd1とnd2をnd1→nd2の順番でつなぐ
void conectNodes(Node *nd1, Node *nd2){
    nd1->next = nd2;
    nd2->prev = nd1;
}

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    // 連結リスト
    Node *num_ary;
    num_ary = (Node*)malloc(sizeof(Node) * N);
    
    // ポインタの配列
    Node **ptr_ary;
    ptr_ary = (Node**)malloc(sizeof(Node*) * N);

    // 門番
    Node head = {-1, NULL, &num_ary[0]};
    Node tail = {-2, &num_ary[N - 1], NULL};

    for(int i = 0; i < N; i++){
        // ノードの値の初期化
        num_ary[i].num = i + 1;
        // ノードの連結
        if(i == 0){
            num_ary[i].prev = &head;
            num_ary[i].next = &num_ary[i + 1];
        }
        else if(i == N - 1){
            num_ary[i].prev = &num_ary[i - 1];
            num_ary[i].next = &tail;
        }
        else{
            num_ary[i].prev = &num_ary[i - 1];
            num_ary[i].next = &num_ary[i + 1];
        }

        // ポインタの配列の初期化
        ptr_ary[i] = &num_ary[i];
    }

    int q, flag_a, flag_b;
    Node *focus_nd, *L_le, *L_ri, *R_le, *R_ri;
    for(int i = 0; i < M; i++){
        scanf("%d", &q);
        // printf("q : %d\n", q);

        // ポインタの配列から実体を持ってくる
        // num=qのノードがまずほしい
        // ptr_ary[i]にnum=i+1のノードのポインタが入っている
        
        // [L_le] --- [L_ri] - [focus_nd] - [R_le] --- [R_ri]

        focus_nd = ptr_ary[q - 1];
        L_le = head.next;
        L_ri = ptr_ary[q - 1]->prev;
        R_le = ptr_ary[q - 1]->next;
        R_ri = tail.prev;

        flag_a = focus_nd->num == tail.prev->num;
        flag_b = head.next->num == focus_nd->num;
        // printf("flag_a : %d, focus_nd->num : %d, tail.prev->num : %d\n", flag_a, focus_nd->num, tail.prev->num);
        // printf("flag_b : %d, head.next->num : %d, focus_nd->num : %d\n", flag_b, head.next->num, focus_nd->num);
        
        if(flag_a){
            conectNodes(&head, focus_nd);
        }
        else{
            conectNodes(&head, R_le);
            conectNodes(R_ri, focus_nd);
        }

        if(flag_b){
            conectNodes(focus_nd, &tail);
        }
        else{
            conectNodes(focus_nd, L_le);
            conectNodes(L_ri, &tail);
        }

        // 表示
        // for(Node nd = *head.next; nd.next != NULL;){
        //     printf("%d ", nd.num);
        //     nd = *nd.next;
        // }
        // printf("\n");
    }

    // 表示
    for(Node nd = *head.next; nd.next != NULL;){
        printf("%d ", nd.num);
        nd = *nd.next;
    }
}