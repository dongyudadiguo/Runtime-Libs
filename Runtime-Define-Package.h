#define Package(name, body, size)\
void name (void){\
    body\
    int tmp2 = *(int*)(buffer + (ptr += size));\
    if(tmp2 > 0){\
        imp = fun[tmp2];\
    }else{\
        stack[stackPtr++] = ptr;\
        imp = fun[*(int*)(buffer + (ptr = - tmp2))];\
    }\
}
