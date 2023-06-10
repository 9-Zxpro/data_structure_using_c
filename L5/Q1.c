// champions

//Q2
int sumRecursion(int n) {
    if(n==1) {
        return 1;
    } else {
        return n+sumRecursion(n-1);
    }
}

//Q3
int sumOfArrayEementsRecursive(int a[], int n){
    if(n<=0)
        return 0;
    else
        return a[n-1]+sumOfArrayEementsRecursive(a, n-1);
}

//Q4
int fibonacciRecursive(int n) {
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}

//Q5
int gcdRecursive(int a, int b){
    if(a%b==0)
        return b;
    else    
        gcdRecursive(b, a%b);
}

//Q6
int sumOfDigitsRecursive(int n){
    if(n<0)
        return sumOfDigitsRecursive(-1*n);
    else if(n<=9)
        return n;
    else
        return n%10+sumOfDigitsRecursive(n/10);
}

//Q7
void hanoi(int n, char a, char b, char c) {
    if(n==1)
        printf("Move disk - %d from pole %c to %c\n", n,a,c);
    else
    {
        hanoi(n-1, a,c,b);
        printf("Move disk - %d from pole %c to %c\n", n,a,c);
        hanoi(n-1, c,b,a);
    }
}