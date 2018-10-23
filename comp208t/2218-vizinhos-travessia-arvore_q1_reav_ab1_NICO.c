#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void preorder(int tree[][2], int n, int i, int* pos, int* result) {
    if(i == -1)
        return;
        
    result[*pos] =  i;
    *pos += 1;
    
    preorder(tree, n, tree[i][0], pos, result);
    preorder(tree, n, tree[i][1], pos, result);
}

void inorder(int tree[][2], int n, int i, int* pos, int* result) {
    if(i == -1)
        return;
        
    inorder(tree, n, tree[i][0], pos, result);
    
    result[*pos] =  i;
    *pos += 1;
    
    inorder(tree, n, tree[i][1], pos, result);
}

void postorder(int tree[][2], int n, int i, int* pos, int* result) {
    if(i == -1)
        return;
        
    postorder(tree, n, tree[i][0], pos, result);
    postorder(tree, n, tree[i][1], pos, result);
    
    result[*pos] =  i;
    *pos += 1;
    
}

int main() {
    int n, i, j, root_position;
    scanf("%d", &n);
    int tree[n][2];
    for(i = 0; i < n; i++) {
        scanf("%d %d", &tree[i][0], &tree[i][1]);
    }
    scanf("%d", &root_position);




    //Print preorder
    int pos = 1;
    int* pre_array = malloc((n+2) * sizeof(int));
    pre_array[0] = -1;
    pre_array[n+1] = -1;
    preorder(tree, n, root_position, &pos, pre_array);
    printf("Pre Order:\n");
    for(i = 0; i < n; i++) {
        for(j = 1; j < n+1; j++) {
            if(pre_array[j] == i)
                break;
        }
        printf("Node %d: previous = %d next = %d\n", i, pre_array[j-1], pre_array[j+1]);
    }





    //Print inorder
    pos = 1;
    int* in_array = malloc((n+2) * sizeof(int));
    in_array[0] = -1;
    in_array[n+1] = -1;
    inorder(tree, n, root_position, &pos, in_array);
    printf("In Order\n");
    for(i = 0; i < n; i++) {
        for(j = 1; j < n+1; j++) {
            if(in_array[j] == i)
                break;
        }
        printf("Node %d: previous = %d next = %d\n", i, in_array[j-1], in_array[j+1]);
    }





    
    //Print postorder
    pos = 1;
    int* post_array = malloc((n+2) * sizeof(int));
    post_array[0] = -1;
    post_array[n+1] = -1;
    postorder(tree, n, root_position, &pos, post_array);
    printf("Post Order\n");
    for(i = 0; i < n; i++) {
        for(j = 1; j < n+1; j++) {
            if(post_array[j] == i)
                break;
        }
        printf("Node %d: previous = %d next = %d\n", i, post_array[j-1], post_array[j+1]);
    }
	return 0;
}