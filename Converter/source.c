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
#define IEEE_754_64BIT_MANTISSA 52
#define uint32 unsigned int
#define uint8 unsigned char
#define uint16 unsigned short
#define uint64 unsigned long long

enum{
    X32,
    X64
};



void print_10_2_2_32(uint32 num,uint8 sign){
    /*
        将IEEE754 32位浮点数的二进制编码打印出来
        num:以整型存储的二进制编码的值
        sign:定义正负数
    */
    uint8 temp[32];
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

void print_10_2_2_64(uint64 num,uint8 sign){
    /*
        将IEEE754 64位浮点数的二进制编码打印出来
        num:以整型存储的二进制编码的值
        sign:定义正负数
    */
    uint8 temp[64];
    int i = 0;
    while(num){
        temp[i] = num % 2;
        num = (uint64)num / 2;
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
    /*
        定义一个uint64的变量(unsigned long long Windows11 x64系统 编译器gcc 版本8.1.0)用来存储最多64位的IEEE754定义的浮点数二进制编码，变量名为code

        以下以32位浮点数二进制编码的转换为例
        当用户指定一个小数并要求转化为32位浮点数二进制编码时，
        
        1.小数交给c的double类型浮点数对数值进行储存，在后面的处理中保证精度的损失在IEEE754 64位的要求之内
        2.对小数不断/2，记录余数存到小数点右边，转化为N = (1.xxxxx)(二进制)  x 2^E 的形式
        3.尾数x2^23位变成一个整数部分有23位的浮点数并+入code ,如果该数仍有小数部分，会因为强制类型转换抹去，这部分小数以IEEE754 32位的精度也表示不出来
        4.阶数E+127(8位，如果用户定义的整数过大使阶数最后大于8位，这个转化程序只会存储阶数的低9位，且只会打印出低8位，还没有分析IEEE754怎么处理超过范围的整数部分，不确定这个处理对不对)，左移23位+入code
        5.依据小数的正负打印0或1
        5.将code以二进制形式打印前31位输出到命令行窗口
    */
    uint64 e = 0;  //定义阶码
    double m;  //定义尾数
    uint8 sign=0;  //定义符号
    uint8 remainder; //整数/2的余数
    long long integer_part = (int)num;  //获取整数部分
    double decimal_part = num - integer_part;  //获取小数部分

    //理论上integer_part 应该用uint64声明，但是我在强制类型转化会出现乱码，因为定义了uint32为unsigned long long的原因，这里使用long long (-2^63 ~ 2^63-1)来定义
    //但 事实上IEEE 754 定义的64位浮点数的最大真值应该为 2^(2^11 - 1 - 2^10 + 1)x(1-2^(-52)) 约为2^1024，这个量级是long long远远不能表示的
    //如果用户传入的小数 整数部分过大，我暂时没有做处理，只能保留用户的整数的低63位
    //而e在64位浮点数中最多只有11位，用uint16表示即可,但是因为在拼凑代码中会最多左移52位，需要有63位容量


    uint64 code=0; //浮点数码

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
            e+=(pow(2,7)-1);
            //尾数变为整数
            m *= pow(2,IEEE_754_32BIT_MANTISSA);

            //IEEE 754 32位 浮点数代码
            code = (e << IEEE_754_32BIT_MANTISSA) + m;
            print_10_2_2_32(code,sign);
            break;
        case X64:
            //阶码补2^10-1
            e+=(pow(2,10)-1);
            //尾数变整数
            m *= pow(2,IEEE_754_64BIT_MANTISSA);

            //IEEE 754 64位 浮点数代码
            code =(e << IEEE_754_64BIT_MANTISSA) + m;
            print_10_2_2_64(code,sign);
            break;

    }
    

}





int main(int argc, char* argv[]){
     if(argc == 3){
         if(!strcmp(argv[1],"-754x32")){
             float_754_binary_code(atof(argv[2]),X32);
         }
         else if(!strcmp(argv[1],"-754x64")){
            float_754_binary_code(atof(argv[2]),X64);
         }
         else{
            printf("error:Could not find argv \"%s\"",argv[1]);
         }
     }
}