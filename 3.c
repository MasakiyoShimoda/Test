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

#define XMIN -10  //x定義域
#define XMAX 10
#define YMIN -10
#define YMAX 10

#define A 1e-2  //微小区間
#define K 1e-4     //定数
#define E 1e-8   //eps

double func(double x, double y){
    double z;
    z = exp(-pow(x-3, 2)/30) * exp(-pow(y-4, 2)/30);
    return z;
}

int main(int argc, const char * argv[]) {
    unsigned int i = 0;
    double dx, before_x, x;
    double dy, before_y, y;
    FILE *fp;
    
    fp = fopen("/Users/shimoda/Desktop/test/test/data3.txt", "w");
    
    srand((unsigned int)time(NULL));
    x = (rand() % abs(XMAX-XMIN)) + XMIN + 1; //探索開始位置セット
    y = (rand() % abs(YMAX-YMIN)) + YMIN + 1;
    
    printf("初期x:\t%f\n", x);
    printf("初期y:\t%f\n", y);
    
    while(1){
        if(i%10000==0)fprintf(fp, "%f\t%f\t%f\n", x, y, func(x, y));
        
        dx = (func(x + A, y) - func(x - A, y)) / (2 * A);
        dy = (func(x, y + A) - func(x, y - A)) / (2 * A);
        
        before_x = x;
        before_y = y;
        
        x = x + K * dx;
        y = y + K * dy;
        
        if(sqrt(pow(x - before_x, 2) + pow(y - before_y, 2)) <= E){
            break;
        }
        else{
            i++;
        }
    }
    
    printf("最適解x:\t%f\n", before_x);
    printf("最適解y:\t%f\n", before_y);
    printf("最適解f(x,y):\t%f\n", func(before_x, before_y));
    printf("探索回数:\t%d\n", i);
    
    return 0;
}
