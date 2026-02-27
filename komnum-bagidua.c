#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x - x - 3;
}

double x(double a, double b){
    return (a+b)/2;
}

int main (){
    double a, b;
    printf("Masukkan Nilai Tebakan Awal:\nA = ");
    scanf("%lf", &a);
    printf("B = "); scanf("%lf", &b);

    double x_current = 0;
    double f_x = f(x_current);
    int maks_iterasi = 100;
    int i = 0;
    
    while(f_x != 0 && i < maks_iterasi){
        x_current = x(a, b);
        f_x = f(x_current);
        if(f_x < 0) a = x_current;
        else if(f_x > 0) b = x_current;

        printf("Iterasi Ke - %d:\n", i+1);
        printf("X Tebakan = %lf\n", x_current);
        printf("F(x) Saat ini = %lf\n", f_x);
        printf("Interval Baru = [%lf,%lf]\n", a, b);
        printf("\n----------------------------\n");
        i++;
    }
}
