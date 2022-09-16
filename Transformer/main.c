#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//专有名词
//integer 整数
//decimal 小数
//quotient 商
//remainder 余数
//exponent 阶码
//mantissa 尾数

#define IEEE_754_32BIT_EXPONENT 8
#define UINT_32 32
#define IEEE_754_32BIT_MANTISSA 23
#define uint32 unsigned int
#define uint8 unsigned char
#define uint64 unsigned long

enum{
    X32,
    X64
};



void print_10_2_2(int num,uint8 sign){
    //将整数以二进制形式输出
    uint8 temp[32+1];
    int i = 0;
    while(num){
        temp[i] = num % 2;
        num = (uint32)num / 2;
        i++;
    }
    //为第一位添上0
    temp[i]=sign;


    for(;i>=0;i--)
    {
        printf("%d",temp[i]);
    }
    printf("\n");
}

void float_754_binary_code(double num,int bitType){
    int e = 0;  //定义阶码
    double m;  //定义尾数
    uint8 sign=0;  //定义符号
    short remainder; //整数/2的余数
    int integer_part = (int)num;  //获取整数部分
    double decimal_part = num - integer_part;  //获取小数部分


    uint32 code=0; //浮点数码

    //我们在确定底数以后再将小数部分转化为整型
    //整数>>1后一定会把0位的1给噶掉
    //小数的精度较高不会被噶

    //正负号判断
    if(integer_part<0){
        integer_part = 0- integer_part;
        decimal_part = 0- decimal_part;
        sign=1;
    }

    while(integer_part/2){
        //整数每右移一位，阶码+1，浮点数除2，相当于尾数部分代码右移1位，给尾数添入整数/2的余数
        remainder = integer_part % 2;
        integer_part >>= 1;
        e++;

        decimal_part /= 2;
        decimal_part += (double)remainder/2;
    }

    m = decimal_part;
    

    switch(bitType){
        case X32:
            //阶码补127
            e+=pow(2,7)-1;
            //尾数变为整数
            m *= pow(2,IEEE_754_32BIT_MANTISSA);

            //IEEE 754 32位 浮点数代码
            code = (e << IEEE_754_32BIT_MANTISSA) + m;
            print_10_2_2(code,sign);
            break;
        case X64:

    }
    

}





int main(int argc, char* argv[]){
     if(argc == 3){
         if(!strcmp(argv[1],"-754x32")){
             float_754_binary_code(atof(argv[2]),X32);
         }
     }
}