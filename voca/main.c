#include <stdio.h>
#define uint16 unsigned short
#define MAX_CHARACTER 1000
char* str;  //全局程序字符串
int cnt;   //全局计数器
char* sub_str; //子串

enum TOKEN{
    WHILE=256,
    IDENTIFIER

};

void advance(){
    cnt++;
    while(str[cnt]==' '||str[cnt]=='\t'||str[cnt]=='\n'){
        cnt++;
    }
}

char nextToken(){
    return str[cnt+1];
}

void initSubString(){
    sub_str = (char*)malloc(MAX_CHARACTER*sizeof(char)+1);
}

copyStr(int digit){
    int i;
    for(i = 0;i<digit;i++){
        sub_str[i]=str[cnt+i];
    }
    sub_str[++i]='\0';
}

match(uint16 sym){
    switch(sym){
        case WHILE:
            return(!strcmp(copyStr(5),"while"));
            break;
        case IDENTIFIER:
        case '>':
            return str[cnt]=='>';
            break;
        case '<':
            return str[cnt]=='<';
            break;

    }
}

void analyse_primary_expr(){
    if(match())
}

void analyse_expr(){
    analyse_primary_expr();
}
void analyse_program(){
    analyse_stmt(); //分析语句
    while(nextToken()!=EOF){
        analyse_stmt();
    }
}

void analyse_stmt();

void analyse_bool_expr(){
    analyse_expr(){

    }
}

void analyse_while_stmt(){
    if(match("while")){

    }
}