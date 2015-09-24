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
	FILE* f = fopen ("1.txt" , "r");
	int i = 0;
	int size = 0;
	int list[200000];
	while (!feof (f)) // while not EndOfFile
	{
		fscanf (f, "%d", &i);
		list[size] = i;
		if (feof(f)) break;
		printf("Read[%d]=%d\n", size, i);
		size ++;
	}

	printf("\n");
	printf("Size: %d\n", size);
	fclose (f);
	int keepSorting = 1;
	i = 0;
	int j = 0;
	while(keepSorting != 0)
	{
//		printf("outer_while[%d]\n", j);
		keepSorting = 0;
		i = 0;
		while (i < size - 1)
		{
			if (list[i] > list[i + 1])
			{
				int temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
				keepSorting = 1;
			}
			i ++;
		}
		j++;
	}
	printf("\n");
	printList(list, size);
}
