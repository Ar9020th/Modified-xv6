#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[])
{
	int pid;
	// int stats = 0;
	int wtime = 1;
	int rtime = 2;
	char* arr[100];
	for (int i = 1; i < argc; i++)
	{
		arr[i - 1] = argv[i];
	}
	arr[argc - 1] = '\0';
	pid = fork();
	if (pid < 0)
	{
		printf(1, "Failed to fork\n");
	}
	if (pid == 0)
	{
		int c = exec(arr[0], arr);
		printf(1, "%s\n", arr[0]);
		if (c == -1)
			printf(1, "Failed to execute command\n");
	}
	else
	{
		waitx(&wtime, &rtime);
	}
	printf(1, "Waiting time = %d\n", wtime);
	printf(1, "Run time = %d\n", rtime);
	exit();
}