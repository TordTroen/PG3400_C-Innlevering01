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

	i = 0;
	while(i < size)
	{
		int j = 0;
		while (j < size)
		{
			if (list[j] > list[j + 1])
			{
				int temp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp;
				/*int a = list[j];
				int b = list[j + 1];
				list[j] = b;
				list[j + 1] = a;*/
			}
			j ++;
		}
		i++;
	}
	printList(list, size);
}
