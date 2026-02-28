#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x - x - 3; 
}

int main(){
    double x_bawah, x_atas;
    int n;

    printf("Masukkan Nilai Batas (x_bawah x_atas): ");
    scanf("%lf %lf", &x_bawah, &x_atas);
    printf("Masukkan Nilai N (Jumlah pembagi): ");
    scanf("%d", &n);

    double h = (x_atas - x_bawah) / n;
    double x_eksak = 2.302775; 

    double x_val[n + 1];
    double f_val[n + 1];

    for(int i = 0; i <= n; i++){
        x_val[i] = x_bawah + i * h;
        f_val[i] = f(x_val[i]);
    }

    printf("\n--- HASIL TABULASI ---\n");
    for(int i = 0; i <= n; i++){
        printf("Iterasi %d | x = %.4lf | f(x) = %.4lf", i, x_val[i], f_val[i]);
        
        double et = fabs((x_eksak - x_val[i]) / x_eksak) * 100;
        printf(" | Et = %.2lf%%", et);

        if (i > 0) {
            double ea = fabs((x_val[i] - x_val[i-1]) / x_val[i]) * 100;
            printf(" | Ea = %.2lf%%", ea);
        }
        printf("\n");

        if (i < n) {
            if (f_val[i] == 0) {
                printf("\nAKAR DITEMUKAN tepat di x = %lf\n", x_val[i]);
                break;
            } 
            else if (f_val[i] * f_val[i+1] < 0) {
                double akar;
                if (fabs(f_val[i]) < fabs(f_val[i+1])) {
                    akar = x_val[i];
                } else {
                    akar = x_val[i+1];
                }
                printf("\nPERUBAHAN TANDA antara %lf dan %lf\n", x_val[i], x_val[i+1]);
                printf("Akar Pendekatan Terdekat = %lf\n", akar);
                break; 
            }
        }
    }
    return 0;
}