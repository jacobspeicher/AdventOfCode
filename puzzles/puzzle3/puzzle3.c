#include <stdio.h>

int main()
{
	FILE *file = fopen("input.txt", "r");
	int valid_triangles = 0;
	int side1, side2, side3;

	while(fscanf(file, "%d %d %d", &side1, &side2, &side3) != EOF)
	{
		printf("%d %d %d\n", side1, side2, side3);
		if((side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2)
		{
			valid_triangles++;
		}
	}

	printf("%d\n", valid_triangles);
}