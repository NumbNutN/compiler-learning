#include <iostream>
#include <regex>
#include <string>

#define uint16 unsigned short
#define MAX_CHARACTER 1000

using namespace std;
char* str;  //全局程序字符串
int cnt;   //全局计数器
char* sub_str; //子串

enum TOKEN{
    WHILE=256,
    IDENTIFIER,
    NUMBER

};

void skip_backspace(){
    /*
    跳过空格字段，光标会挪到非空格的第一个字符上
    */
    while(str[cnt]==' '||str[cnt]=='\t'||str[cnt]=='\n'){
        cnt++;
    }
}

void advance(){
    /*
    一直往前挪，当光标落到特殊字符上停止
    */
   while(!match_spe(str[cnt])){
        cnt++;
   }
}

void advance_once(){
    /*
    光标只往前挪动一步
    没有任何判定条件，绕过单字符的特殊字符
    */
   cnt++;
}

int match_spe(char ch){
    /*
    判断单一字符是否匹配
    */
    int i;
    char breakPoint[] = {'{','}','(',')','\n','\b','\t',' '};
    for(i=0;ch!=breakPoint[i]&&i<sizeof(breakPoint);i++);
        if(i!=sizeof(breakPoint)-1){
            return 1;
        }
        else{
            return 0;
        }
}

char nextToken(){
    return str[cnt+1];
}

void initSubString(){
    sub_str = (char*)malloc(MAX_CHARACTER*sizeof(char)+1);
}

char* copyStr(int digit){
    int i;
    for(i = 0;i<digit;i++){
        sub_str[i]=str[cnt+i];
    }
    sub_str[++i]='\0';
    return sub_str;
}


char* getSym(){
    char breakPoint[] = {'{','}','(',')','\n','\b','\t'};
    int i;
    int j;
    for(i=0;;i++){
        if(match_spe(str[cnt+i])){
            sub_str[++i]='\0';
            return sub_str;
        }
        else{
            sub_str[i]=str[cnt+i];
        }
    }
    //i会自增1
    //cnt+=i;
}

int match(uint16 sym){
    //定义正则表达式
    std::string p = sub_str;
    switch(sym){
        case WHILE:
            return(!strcmp(getSym(),"while"));
            break;
        case IDENTIFIER:
            if(std::regex_match(p,regex("^[a-zA-Z_]\\w{0,1000}$"))){
                return 1;
            }
            break;
        case NUMBER:
            if(std::regex_match(p,regex("^[0-9]{0,1000}$"))){
                return 1;
            }
            break;
              
        case '>':
            return str[cnt]=='>';
            break;
        case '<':
            return str[cnt]=='<';
            break;
        case '+':
            return str[cnt]=='+';
            break;
        case '-':
            return str[cnt]=='-';
            break;

    }
    return 0;
}

int analyse_primary_expr(){
    if(match(IDENTIFIER)||match(NUMBER)){
        advance();
        skip_backspace();
        return 1;
    }
    return 0;
    
}

int analyse_expr(){
    int p;
    if(!analyse_primary_expr()){
        return 0;
    }
    if(match('+') || match('-')){
        advance_once();
        p = analyse_expr();
    }
    else{
        return 1;
    }
    
}
void analyse_program(){
    analyse_stmt(); //分析语句
    while(!match('\0')){
        analyse_stmt();
    }
}

void analyse_stmt();

int analyse_bool_expr(){
    analyse_expr();
    skip_backspace();
    if(!(match('>') || match('<'))){
        return 0;
    }
    advance_once();
    skip_backspace();
    analyse_expr();
}

int analyse_while_stmt(){
    if(!match(WHILE)){
        return 0;
    }
    advance();
    skip_backspace();
    if(!match('(')){
        return 0;
    }
    advance_once();
    skip_backspace();
    analyse_bool_expr();
    
    if(!match(')')){
        return 0;
    }
    advance_once();
}

int main(){
    str = "while ( a+b+c>b+c+d )";
    analyse_while_stmt();
}