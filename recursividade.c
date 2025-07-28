 #include <stdio.h>
 
long long fatorial(int n){
    if(n==0)
        return 1;
    else
        return n * fatorial(n -1);
}



 int main() {
     int x;
     long long z;

     scanf("%d", &x);
     z = fatorial(x);
     printf("%lld\n", z);
     return 0;
 }