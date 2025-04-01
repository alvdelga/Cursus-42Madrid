
#include <stdio.h>
#include <stddef.h>

int digit_counter(int n)
{
    int count;
    int copy;

    copy = n;
    count = 0;
    if(copy == 0)
        return (1);
    if(copy == -2147483648)
        return (11);
    if(copy < 0)
    {
        copy = -copy;
        count++;
    }
    while(copy > 0)
    {
        copy = copy / 10;
        count++;
    }
    return (count);
}

int exp_counter(int n)
{
    int exp;
    int copy;
    int digit;

    copy = n;
    digit = digit_counter(n);
    if(copy == 0)
        return (1);
    if(copy == -2147483648)
        return (1000000000);
    if(copy < 0)
    {
        copy = -copy;
        digit--;
    }
    exp = 1;
    while(--digit)
    {
        exp = exp * 10;
    }
    return (exp);
}

int main()
{
  int i = -1123456789;

  int res = exp_counter(i);

  printf("%d", res);

  return (0);
}