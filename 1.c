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

#define XMIN 5  //x定義域
#define XMAX 15

#define A 0.01  //微小区間
#define K 1e-3 //定数K
#define E 1e-9 //eps

double func(double x){
    double y;
    y = 20 - pow(x - 10, 2);
    return y;
}

int main(int argc, const char * argv[]) {
    unsigned int i = 0;
    double dx, before_x, x;
    FILE *fp;

    fp = fopen("data1.txt","w");

    srand((unsigned int)time(NULL));
    x = (rand() % (XMAX-XMIN)) + XMIN + 1;


    printf("初期x:\t%f\n", x);

    while(1){
        if(i%50 == 0) fprintf(fp, "%lf %lf\n", x, func(x));

        dx = (func(x + A) - func(x - A)) / (2 * A);
        before_x = x;
        x = x + K * dx;

        if(fabs(x - before_x) <= E)
            break;
        else
            i++;

    }

    printf("x:\t%f\n", before_x);
    printf("y:\t%f\n", func(before_x));
    printf("探索回数:\t%i\n", i);
}
