#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//专有名词
//integer 整数
//decimal 小数
//quotient 商
//remainder 余数
//exponent 阶码

#define IEEE_754_32BIT_EXPONENT 8
#define UINT_32 32

int push(char* lst,char ch){
    int i;
    for(i=0;lst[i]!=0;i++);
    lst[i]=ch;
}

void transform_10_2_2(double num){
    int integer_part = (int)num;  //获取整数部分
    double decimal_part = num - integer_part;  //获取小数部分
    printf("%d  %lf",integer_part,decimal_part);

    //char interger_binary[IEEE_754_32BIT_EXPONENT];
    int quotient = integer_part;
    int remainder;
    int e;  //阶码
    while(quotient>>1){
        //整数每右移一位，阶码+1，浮点数除2，加入整数的余数
        remainder = quotient % 2;
        quotient >> 1;
        e++;

        decimal_part /= 2;
        decimal_part += (double)remainder/2;
    }
    printf("%lf",quotient+decimal_part);





}

long float2754(char* num){
    int e; //定义了阶数


    //寻找小数点
    int i,j;
    for(i=0;num[i]=='.';i++);
    for(j=0;num[i]!='0';j++); //计算无效数字
    e = i - 1 - j; 
    double m = 0;
    
    
}

int main(int argc, char* argv[]){
    // if(argc == 3){
    //     if(!strcmp(argv[1],"-754")){
    //         float2754(argv[2]);
    //     }
    // }
    double test;
    scanf("%lf",&test);
    transform_10_2_2(test);


    
}