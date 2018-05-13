#include	<stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <math.h>

int primo(int numerador, int denominador)
{
    int divisor;
    if(denominador > 9)
    {
        return 1;
    }
    divisor = numerador % denominador;
    
    if(divisor == 0)
    {
        return 1 + primo(numerador, denominador + 1);
    }
    else
    {
        return primo(numerador, denominador + 1);
    }
}

int check(int num, int count, int eh_igual)
{
    if(num <= 0)
    {
        return eh_igual;
    }

    int digito, next_n;
    digito = num % 10;
    next_n = num / 10;
    
    if(digito == count)
    {
        check(next_n, count, eh_igual);
    }
    else
    {
        check(next_n, count, eh_igual + 1 );
    }
}

long int multiplica(long int num)
{
    int digito, next_n;
    digito = num % 10;
    next_n = num / 10;

    if(num <= 0)
    {
        return 1;
    }
    else
    {
        return digito * multiplica(next_n);
    }
}

int compare(int init, int compara)
{
    long int produto = multiplica(compara);
    if(produto == init)
    {
        printf("%li\n", compara);
        return 0;
    }
    else
    {
        compare(init, compara + 1);
    }
}

int main()
{
    int num, cond1, cond2;
    scanf ( "%d", &num );
    
    cond1 = check(num / 10, num % 10, 1);
    cond2 = primo(num, 1); 
    
    if(cond1 == 1 || cond2 == 2)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        compare(num, 10);
        return 0;
    }

    return 0;
}				
