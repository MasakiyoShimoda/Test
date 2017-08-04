//
//  main.c
//  test
//
//  Created by Masakiyo on 2017/08/04.
//  Copyright © 2017年 Masakiyo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>

#define XMIN -70  //x定義域
#define XMAX 130

#define A 0.01  //微小区間
#define K 0.01     //定数
#define E 1e-6   //eps

double f2(double x);

double func(double x){
    double y;
    y = 20 - pow(x - 10, 2);
    return y;
}

int main(int argc, const char * argv[]) {
    unsigned int i = 0;
    double dx, before_x, x;
    FILE *fp;

    fp = fopen("data2.txt","w");

    srand((unsigned int)time(NULL));
    x = (rand() % (XMAX-XMIN)) + XMIN + 1; //探索開始位置セット


    printf("初期x:\t%f\n", x);

    while(1){
        if(i % 10000 == 0)fprintf(fp, "%lf %lf\n", x, f2(x));

        dx = (f2(x + A) - f2(x - A)) / (2 * A);
        before_x = x;
        x = x + K * dx;

        if(fabs(x - before_x) <= E)
            break;
        else
            i++;
    }

    printf("x:\t%f", before_x);
    printf("y:\t%f", f2(before_x));
    printf("探索回数:\t%i\n", i);
}
