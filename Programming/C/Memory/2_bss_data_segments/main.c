// BSS сегмент - переменные будут заполнены нулями
int global_var1;
int global_var2 = 0;

// DATA сегмент - явно заданные значения
int global_var3 = 33; // 0x00000021
int global_var4 = 0x12153467;
char global_var5[6] = "ABCDE";

int main(int argc, char **argv)
{
    return 0;
}
