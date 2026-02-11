#include<stdio.h>
#include<string.h>
#include<unistd.h>
#define MAX 2000000001
//優先度付きキュー：再帰を使わずにループを使って（up_heapとdown_heapの実装）書いたもの
int size = 0;
int a[MAX];

void smiley (int n){
for(int i = 0; i < n; i++){
    printf("\\^∇^/\n");
}
return;
}

void swap (int *a, int *b){
int tmp = *a;
*a = *b;
*b = tmp;
}

void up_heap(int j){
while(j > 1 && a[j/2] < a[j]){
    swap(&a[j/2], &a[j]);
    j /= 2;
}
}

void down_heap(int j){
    while(2*j <= size){
        int k = 2*j;
        if (k + 1 <= size && a[k + 1] > a[k]){
            k += 1;
        }
        if(a[j] < a[k]){
            swap(&a[j], &a[k]);
            j = k;
        }
        else{
            break;
        }
    }
}

void insert(int key) {
a[++size] = key;
up_heap(size);
}

int extract(void){
if (size < 1){
    return -1;
}
int maxv = a[1];    
a[1] = a[size--];
down_heap(1);
return maxv;
}

int main (){
int i;
int key;
char command[20];
sleep(1);
printf("にゅぅん\n");
sleep(1);
printf("へっ\n");
sleep(1);
printf("ぬっ\n");
sleep(1);
printf("はっ\n\n");
sleep(1);
printf("Practice of priority queue.The available commands are as follows.\nend\ninsert ___\nextract\nsmiley\n\n");
while(1){
    scanf("%s", command);
    if(!strcmp("end", command)){
        break;
    }
    else if(!strcmp("extract", command)){
        printf("%d\n", extract());
    }
    else if(!strcmp("insert", command)){
        scanf("%d", &key);
        insert(key);
    }
    else if(!strcmp("smiley", command)){
        printf("How many smiley do you want? ");
        scanf("%d", &key);
        smiley(key);
    }
    else{
        printf("あなた コマンドのスペルきっと間違えてるわよ 「%s」!? No such a command.\n", command);
    }
}
return 0;
}