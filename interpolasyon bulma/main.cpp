#include <iostream>
#include <cmath>
#include <iomanip>

// Fonksiyon tanimi
double fonksiyon(double x) {
    return 0.77 * x * x - 2.35 * x - 4;
}

// Fonksiyonun turevi
double fonksiyon_turev(double x) {
    return 1.54 * x - 2.35;
}

// Dogrusal Interpolasyon Metodu
double dogrusalInterpolasyon(double x0, double x1, double tol) {
    double x_yeni, f0, f1;
    do {
        f0 = fonksiyon(x0);
        f1 = fonksiyon(x1);
        x_yeni = x0 - f0 * (x1 - x0) / (f1 - f0);
        if (fonksiyon(x_yeni) == 0) break;
        x0 = x1;
        x1 = x_yeni;
    } while (fabs(fonksiyon(x_yeni)) > tol);
    return x_yeni;
}

// Newton-Raphson Metodu
double newtonRaphson(double x0, double tol) {
    double x_yeni;
    do {
        x_yeni = x0 - fonksiyon(x0) / fonksiyon_turev(x0);
        if (fabs(x_yeni - x0) < tol) break;
        x0 = x_yeni;
    } while (fabs(fonksiyon(x_yeni)) > tol);
    return x_yeni;
}

// Ikiye Bolme Metodu
double ikiyeBolme(double a, double b, double tol) {
    double c;
    do {
        c = (a + b) / 2;
        if (fonksiyon(c) == 0 || fabs(b - a) < tol) break;
        if (fonksiyon(a) * fonksiyon(c) < 0)
            b = c;
        else
            a = c;
    } while (fabs(fonksiyon(c)) > tol);
    return c;
}

int main() {
    double tol = 0.015;  // Hata toleransi
    double x0 = 3, x1 = 15;
    
    // Dogrusal Interpolasyon
    double kok_dogrusal = dogrusalInterpolasyon(x0, x1, tol);
    std::cout << "Dogrusal Interpolasyon ile kok: " << std::setprecision(6) << kok_dogrusal << std::endl;
    
    // Newton-Raphson
    double kok_newton = newtonRaphson((x0 + x1) / 2, tol);
    std::cout << "Newton-Raphson ile kok: " << std::setprecision(6) << kok_newton << std::endl;
    
    // Ikiye Bolme
    double kok_ikiyeBolme = ikiyeBolme(x0, x1, tol);
    std::cout << "Ikiye Bolme Metodu ile kok: " << std::setprecision(6) << kok_ikiyeBolme << std::endl;

    return 0;
}

