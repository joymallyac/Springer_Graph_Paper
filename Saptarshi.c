#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

int *array,counter = 0;

void byte_to_binary(int x,int n)
{
    static char b[20];
    b[0] = '\0';
    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
    int i = 8-n , j = 0;
	while(i<8){
        //bi[j] = b[i];
        printf("%c",b[i]);
    	i++;
    	//j++;
    }

}

int greycode(int n )
{
	int k,i;
	array[counter++]=0;
	array[counter++]=1;
	for(i=1 ; i < n; i++){
		k = counter -1;
		while(k>=0){
			array[counter++] = array[k--] | 1<<i;
		}
	}

}

void main()
{
	int n,i, j = 0 ;
	char * bi;
	printf("\nEnter n\n");
	scanf("%d",&n);
	array = (int*)malloc(pow(2,n)*sizeof(int));
	greycode(n);
	printf("\n------------------------greycode------------------------------\n");
	for(i=0;i<counter;i++){
		byte_to_binary(array[i],n);
		/*while(j != 2)
        {
            printf("%c",bi[j]);
            j++;
        }*/
		printf("\n");
	}
}
