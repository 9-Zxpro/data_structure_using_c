//Champions

//Q2
int main() {
    int *p;
    p = (int*)malloc(sizeof(int));
    if(!p)
        printf("Failed to allocate space for _ bytes\n");
    *p = 15;
    printf("Value with in heap memory = %d\n", *p);
    free(p);
    return 0;
}

//Q3
void read(int *p, int n){
    printf("Enter %d elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", p+i);
    }
}
void bubbleSort(int *p, int n){
    int tmp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(*(p+j) > *(p+j+1)){
                tmp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = tmp;
            }
        }
    }
}
void display(int *p, int n){
    for(int i=0; i<n; i++){
        printf("%d ", *(p+i));
    }
    printf("\n");
}
int binarySearch(int *p, int n, int key){
    int beg=0, end=n, mid;
    while (beg<=end)
    {
        mid = (beg+end)/2;
        if(key==*(p+mid)){
            return mid;
        }
        else if(*(p+mid)<key)
            beg = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

//Q4
void read(int *p, int m, int n){
    printf("Enter %d elements : ", m*n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", p+(i*n)+j);
        }
    }
}
void display(int *p, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", *(p+(i*n)+j));
        }
        printf("\n");
    }
}
void multiplicationOfTwoMatrices(int *a, int *b, int m, int n, int q){
    int sum=0;
    printf("The Multiplication Matrix is\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<q; j++){
            sum=0;
            for(int k; k<n; k++){
                sum += (*(a+(i*n)+k)) * (*(b+(k*q)+j));
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
}