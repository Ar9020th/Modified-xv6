#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf(1, "Failed to execute\n");
		exit();
	}
	int oldpriority = set_priority(atoi(argv[1]), atoi(argv[2]));
	printf(1, "Old priority of pid %d was :- %d now changed to :-%d\n", atoi(argv[2]), oldpriority, atoi(argv[1]));
}