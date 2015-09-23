#include<stdio.h>

void printList(int list[200000], int length)
{
	for (int i = 0; i < length; i ++)
	{
		printf("List[%d]=%d\n", i, list[i]);
	}
}

int main(int argc, char *argv[])
{
	FILE* f = fopen ("Test.txt" , "r");
	int i = 0;
	int iter = 0;
	int list[200000];
	//fscanf (f, "%d", &i); // Fjerner det første (i filen 1.txt er det 42)
	while (!feof (f)) // while not EndOfFile
	{
/* scanf leser inn en int (tar vel den første den finner???) 
* Også gir den tallet til parameter 3
* Her er det skrevet med & som betyr at i er en referanse og i blir da overskrevet
*/
		fscanf (f, "%d", &i);
		//printf("%d", i);
		list[iter] = i;
		iter ++;
	}
	fclose (f);

	i = 0;
	while(i < iter)
	{
		int j = 0;
		while (j < iter)
		{
			if (list[j] > list[j + 1])
			{
				int a = list[j];
				int b = list[j + 1];
				list[j] = b;
				list[j + 1] = a;
			}
			j ++;
		}
		i++;
	}
	printList(list, iter);
}
