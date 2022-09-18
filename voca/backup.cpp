int match_1(uint16 sym){
    //定义正则表达式
    std::regex regexStr("^[a-zA-Z_]\\w{0,1000}$");
    std::smatch matchResult;
    std::string p = sub_str;
    switch(sym){
        case WHILE:
            return(!strcmp(getSym(),"while"));
            break;
        case IDENTIFIER:
            if(std::regex_match(p,matchResult,regexStr)){
                return 1;
            }
            break;
        case NUMBER:

        case '>':
            return str[cnt]=='>';
            break;
        case '<':
            return str[cnt]=='<';
            break;

    }
    return 0;
}

char* getSym_1(){
    char breakPoint[] = {'{','}','(',')','\n','\b','\t'};
    int i;
    int j;
    for(i=0;;i++){
        for(j=0;str[cnt+i]!=breakPoint[j]&&j<sizeof(breakPoint);j++);
        if(j!=sizeof(breakPoint)-1){
            sub_str[++i]='\0';
            return sub_str;
        }
        else{
            sub_str[i]=str[cnt+i];
        }
    }    
}