#define Package(name, body, size)\
void name (void){\
    body\
    imp = fun[*(int*)(buffer + (ptr += size))];\
}
