const int values[] = {4, 5, 6};

int real_main(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    int x = arg0;
    int y = arg6;
    y = 7 * x + 32;
    int z = 8 * y + 2;
    return 0;    
}

int main()
{
    real_main(values[2],0,0,0,0,0,0);
}