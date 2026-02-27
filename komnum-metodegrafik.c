#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x - x - 3;
}

double xi(double x_bawah, int i, double h){
    return x_bawah + i*h;
}

int main(){
    double x_bawah, x_atas;
    printf("Masukkan Nilai Batas Awal:\n X_bawah= ");
    scanf("%lf", &x_bawah);
    printf("X_atas = "); scanf("%lf", &x_atas);
    int n; printf("Masukkan Nilai N = "); scanf("%d", &n);

    double h = (x_atas - x_bawah)/n;

    double x_current = 0;
    double f_x;
    for(int i = 0; i < n; i++){
        x_current = xi(x_bawah, i, h);
        f_x = f(x_current);

        if(f_x == 0) {
            printf("X = %lf\n", x_current);
            break;
        }
    }
}
