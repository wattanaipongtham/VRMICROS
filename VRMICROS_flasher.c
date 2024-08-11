#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t buf[64];
    FILE *file;

    file = fopen("C:/Users/WATTANAI/Desktop/64byte.txt", "rb");
    fread(&buf, 64, 1, file);
    fclose(file);

    printf("%c\n", buf[61]);
    
    return 0;
}
