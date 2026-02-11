#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
int key;
struct node* parent;
struct node* left;
struct node* right;
}node;

node* root = NULL;

void insert (int k){
node* z = (node*)malloc(sizeof(node));
z->parent = NULL;
z->left = NULL;
z->right = NULL;
z->key = k;
node* x = root;
node* y = NULL;
while(x != NULL){
    y = x;
    if(x->key > k){
        x = x->left;
    }
    else if(x->key < k){
        x = x->right;
    }
    else {
        printf("重複や\n");
        free(z);
        return;
    }
}
z->parent = y;
if(y == NULL){
    root = z;
}
else if (y->key > k){
    y->left = z;
}
else if(y->key < k){
    y->right = z;
}
}

node* find(int k){
node* u = root;
while(u != NULL && u->key != k){
    u = (u->key > k) ? u->left : u->right;
}
return u;
}

node* treeminimum(node* u){
while(u->left != NULL){
    u = u->left;
}
return u;
}

void transplant(node* u, node* v){
if(u->parent == NULL){
    root = v;
}
else if(u->parent->left == u){
    u->parent->left = v;
}
else{
    u->parent->right = v;
}
if(v != NULL){
    v->parent = u->parent;
}
}

void delete (node* z){
if(z == NULL){
    return;
}
else if(z->right == NULL){
    transplant(z, z->left);
}
else if(z->left == NULL){
    transplant(z, z->right);
}
else{
    node* y = treeminimum(z->right);
    if(z->right != y){
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
    }
    transplant(z, y);
    y->left = z->left;
    y->left->parent = y;
}
free(z);
}

void preorder(node* x){
    if(x == NULL){
        return;
    }
    printf("%d ", x->key);
    preorder(x->left);
    preorder(x->right);
}

void inorder(node* x){
    if(x == NULL){
        return;
    }
    inorder(x->left);
    printf("%d ", x->key);
    inorder(x->right);
}

void postorder(node* x){
    if(x == NULL){
        return;
    }
    postorder(x->left);
    postorder(x->right);
    printf("%d ", x->key);
}

int main (){
int n;
int i;
int k;
char command[20];
printf("The available commands are as follows. ___ means the input.\n[print] Output a binary tree, in order pre, in, post.\n");
printf("[insert ___ ] Insert the input key. If thre is a duplication, this command wiil be ignored.\n[find ___ ] Find the input key. The output is either Yes or No.\n");
printf("[delete ___ ] Delete the input key. If the key can't be found in the binary tree, this command will be ignored.\n");
printf("[command_list] Display the command list.\n");
printf("(CTRL+C to stop)\n");
while (scanf("%s", command) != EOF){
    if(!strcmp("print", command)){
        printf("Preorder\n");
        preorder(root);
        printf("\n");
        printf("Inorder\n");
        inorder(root);
        printf("\n");
        printf("Postorder\n");
        postorder(root);
        printf("\n");
        continue;
    }
    else if(!strcmp("command_list", command)){
    printf("[print] Output a binary tree, in order pre, in, post.\n[insert ___ ] Insert the input key. If thre is a duplication, this command wiil be ignored.\n[find ___ ] Find the input key. The output is either Yes or No.\n[delete ___ ] Delete the input key. If the key can't be found in the binary tree, this command will be ignored.\n[command_list] Display the command list.\n(CTRL+C to stop)\n");
        continue;    
    }
    if(!strcmp("insert", command)){
        scanf("%d", &k);
        insert(k);
    }
    else if(!strcmp("find", command)){
        scanf("%d", &k);
        printf((find(k) != NULL)?"見っけ '_'\n":"どこにいるの？\n");
    }
    else if (!strcmp("delete", command)){
        scanf("%d", &k);
        delete(find(k));
    }
    else {
        printf("あなた コマンドのスペルきっと間違えてるわよ 「%s」!? No such a command.\n", command);
    }
}
return 0;
}