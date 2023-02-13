for (i = 1; i <= N; i++)
{
    if (i % 3 == 0 || i % 5 == 0)
        sum += i;
}

for (i = 0; i <= N; i++)
{
    for (j = i + 1; j <= N; j++)
        if (arr[i] + arr[j] == 100)
            return(1);
}

for (i = 0; i * i <= N; i++)
{
    if (i * i == N)
        return (1);
}
return (0);

for (i = 1; i * 2 <= N; i * 2)