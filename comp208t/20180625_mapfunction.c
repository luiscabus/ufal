
void map(int (*f)(int), int array[], int i) {
	if (i == 0) {
		return;
	}

	array[i] = (*f)(array[i]);

	map((*f), array, i - 1);
}

int square(int x) {
	return x * x;
}

int main() {

	int array[4];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;

	map(square, array, 4);

	for (int i = 0; i < 4; ++i)
	{
		printf("Pos %d Val %d\n", i, array[i]);
	}

	return 0;
}