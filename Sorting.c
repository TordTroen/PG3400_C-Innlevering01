#include<stdio.h>
#include<stdlib.h>

// Function declarations
void printList(int list[], int length);
void readFileContent(char *fileName, int *length, int *list);
void bubbleSort(int *list, int length);
void searchList(int list[], int length);

int main(int argc, char *argv[])
{
	int length = 0; // Length of the list
	int list[200000]; // The list to be sorted

	// Read numbers from file to list
	readFileContent("TestFile.txt", &length, list);
	
	// TODO: take input and chose sorting algorithm

	// Sort the list
	bubbleSort(list, length);

	// Print the list
	printList(list, length);

	// Searching for int
	searchList(list, length);
}

void readFileContent(char *fileName, int *length, int *list)
{
	
	FILE* f = fopen (fileName , "r");
	int i = 0;
	int size = 0;
	while (!feof (f)) // while not EndOfFile
	{
		fscanf (f, "%d", &i);
		list[size] = i;
		if (feof(f)) break;
		//printf("Read[%d]=%d\n", size, i);
		size ++;
	}
	fclose (f);
	*length = size;
}

void bubbleSort(int *list, int length)
{
	int keepSorting = 1;
	int i = 0;
	int j = 0;

	while(keepSorting != 0)
	{
		keepSorting = 0;
		i = 0;
		while (i < length - 1)
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
}

// Debug only, remove
void printList(int list[], int length)
{
	for (int i = 0; i < length; i ++)
	{
		printf("List[%d]=%d\n", i, list[i]);
	}
}

void searchList(int list[], int length)
{
	int search;
	int low = 0;
	int high = length - 1;
	int mid = (low+high)/2;

	printf("Please input an integer for search\n");
	scanf("%d", &search);

	if (search == 0)
                        exit(0);

	while (low <= high) {
		if (list[mid] < search)
			low = mid + 1;
		else if (list[mid] == search) {
			printf("The integer(%d) is at location: %d\n", search, mid+1);
			break;
		}
		else
			high = mid - 1;
			mid = (low + high)/2;
		}
		if (low > high)
			printf("Integer not found\n");
}
