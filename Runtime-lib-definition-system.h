#include <stdlib.h>
#include <string.h>

void loader (void){
    static int runonece = 1;
    static int content_size = sizeof(int);
    static int content_edge = 0;
    if (runonece) {
        InitWindow(800, 600, "Runtime-lib-loader");
        buffer = realloc(buffer, 2048); // Solve the problem of insufficient memory
        runonece = 0; 
    }

    FilePathList files = LoadDirectoryFiles(".");
    int bincount = 0;
    for (int i = 0; i < files.count; i++) {
        if (IsFileExtension(files.paths[i], ".bin")) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), (Rectangle){30, 40 + bincount * 30, MeasureText(GetFileName(files.paths[i]),20), 20})) {

                FILE *file = fopen(GetFileName(files.paths[i]), "rb");
                fseek(file, 0, SEEK_END);
                int tmp = ftell(file);
                void *tmp2 = buffer + content_edge;
                void *tmp3 = tmp2 + tmp;
                void *tmp4 = tmp3 + content_size;
                memcpy(tmp3, tmp2, content_size);
                fseek(file, 0, SEEK_SET);
                fread(tmp2, tmp, 1, file);
                memcpy(tmp4 + sizeof(int), tmp4 - sizeof(int), sizeof(int));
                *(int*)(tmp4 - sizeof(int)) = 0;
                *(int*)(tmp4 ) = content_edge;
                content_edge += tmp;
                content_size += (sizeof(int) + sizeof(int));

            }
            DrawText(GetFileName(files.paths[i]), 30, 40 + (bincount++) * 30, 20, BLACK);
        }
    }

    imp = fun[*(int*)(buffer + (ptr = content_edge))];

    EndDrawing();
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

//imp = fun[];

void exit_ (void){
    imp = fun[*(int*)(buffer + (ptr = stack[--stackPtr] + sizeof(int) + sizeof(int)))];
}

void return_ (void){
    int return_size = *(int*)(buffer + ptr + sizeof(int));
    memcpy(buffer + stack[stackPtr - 1] + sizeof(int) + sizeof(int), buffer + ptr + sizeof(int) + sizeof(int), return_size);
    imp = fun[*(int*)(buffer + (ptr = stack[--stackPtr] + sizeof(int) + sizeof(int) + return_size))];
}

// Package( MOV, 
//     void *tmp = buffer + ptr + sizeof(int);
//     memmove(buffer + ptr + *(int*)(tmp), buffer + ptr + *(int*)(tmp + sizeof(int)), *(int*)(tmp + sizeof(int) + sizeof(int)));,
//     sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)
// )

void MOV (void){
    void *tmp = buffer + ptr + sizeof(int);
    memmove(buffer + ptr + *(int*)(tmp), buffer + ptr + *(int*)(tmp + sizeof(int)), *(int*)(tmp + sizeof(int) + sizeof(int)));
    imp = fun[*(int*)(buffer + (ptr += sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)))];
}

void JMP (void){
    void *tmp = buffer + ptr + sizeof(int);
    if (*(char*)(tmp))
    {
        imp = fun[*(int*)(buffer + (ptr = *(int*)(buffer + *(int*)(tmp + sizeof(char)))))];
    }else
    {
        imp = fun[*(int*)(buffer + (ptr += sizeof(int) + sizeof(char) + sizeof(int)))];
    }
}

// Package( get_relative_ptr, 
//     void *tmp = buffer + ptr + sizeof(int);
//     *(void**)(tmp) = buffer + ptr + *(int*)(tmp + sizeof(void*));,
//     sizeof(int) + sizeof(void*) + sizeof(int)
// )

Package( get_relative_ptr, 
    void *tmp = buffer + ptr + sizeof(int);
    *(void**)(tmp) = buffer + ptr + *(int*)(tmp + sizeof(void*));,
    sizeof(int) + sizeof(void*) + sizeof(int)
)

Package( get_buffer, 
    *(void**)(buffer + ptr + sizeof(int)) = buffer;,
    sizeof(int) + sizeof(void*)
)

Package( add_ptr_int, 
    void *tmp = buffer + ptr + sizeof(int);
    *(void**)tmp = *(void**)(tmp + sizeof(int)) + *(int*)(tmp + sizeof(int) + sizeof(int));,
    sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)
)

// The following functions are replaced by a simple function segmentation (function_segmentation_list) list
// Package( get_buffer, 
//     *(void**)(buffer + ptr + sizeof(int)) = buffer;,
//     sizeof(int) + sizeof(void*)
// )
// Package( add_ptr_int, 
//     void *tmp = buffer + ptr + sizeof(int);
//     *(void**)tmp = *(void**)(tmp + sizeof(int)) + *(int*)(tmp + sizeof(int) + sizeof(int));,
//     sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)
// )
// Package( add_int_int, 
//     void *tmp = buffer + ptr + sizeof(int);
//     *(int*)tmp = *(int*)(tmp + sizeof(int)) + *(int*)(tmp + sizeof(int) + sizeof(int));,
//     sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)
// )
