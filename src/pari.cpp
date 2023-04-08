#include<iostream>
#pragma GCC target ("avx2")
#pragma GCC optimization ("OFast")
#pragma GCC optimization ("unroll-loops")

main()
{
    short c; bool l;
    while((c = getchar_unlocked())>'\n') l = c&1;
    if (l)
    {
        putchar_unlocked('d');
        putchar_unlocked('i');
        putchar_unlocked('s');
    }
    putchar_unlocked('p');
    putchar_unlocked('a');
    putchar_unlocked('r');
    putchar_unlocked('i');
}