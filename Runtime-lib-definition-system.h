void MOV(void){
    memmove(buffer + *(int*)(buffer + ptr + sizeof(int)), buffer + *(int*)(buffer + ptr + sizeof(int) + sizeof(int)), *(int*)(buffer + ptr + sizeof(int) + sizeof(int) + sizeof(int)));
    int tmp2 = *(int*)(buffer + (ptr += sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)));
    if(tmp2 > 0){
        imp = fun[tmp2];
    }else{
        stack[stackPtr++] = ptr;
        imp = fun[*(int*)(buffer + (ptr = - tmp2))];
    }
}