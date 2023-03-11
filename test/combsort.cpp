/*
Bài toán:

Sắp xếp một dãy số theo thứ tự không giảm.

Độ phức tạp:

O(n logn)
*/

#include <stdio.h>

int a[230997];

int n;

void combsort(){

    int g=n, s=0, j;

    while (g>1 or s!=0){

        g=g*77/96;

        if (g<=1) g=1;

        s=0;

       

        for (j=1; j+g<=n; j++)

        if (a[j]>a[j+g]){

            s=a[j]; a[j]=a[j+g]; a[j+g]=s;   // swap a[j], a[j+g]

            s=1;

        }

    }

}

main(){

    int i;

    scanf("%d", &n);

    for (i=1; i<=n; i++) scanf("%d", &a[i]);

    combsort();

    for (i=1; i<=n; i++)

    printf("%d, ", a[i]);

    printf("\n");

}