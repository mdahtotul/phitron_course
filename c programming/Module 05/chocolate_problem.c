#include <stdio.h>

int main()
{
    int choco, pack, n;
    printf("Total given chocolate : ");
    scanf("%d", &n);

    choco = n;
    pack = n;

    while(pack>=4)
    {
        choco += pack / 4;
        pack = (pack / 4) + (pack % 4);

    }
    printf("Total chocolate eaten : %d", choco);

    return 0;
}
