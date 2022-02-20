/*
 * @Description: show_bytes
 * @Author: dive668
 * @Date: 2021-08-16 16:17:08
 * @LastEditTime: 2021-08-16 16:19:40
 */
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for(i=0;i<len;i++)
    {
        printf("%.2x",start[i]);
    }
    printf("\n");
}