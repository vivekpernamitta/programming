/* this is required with "lock-1" file with sybchronisng with/
   For each group of five bytes in the file, lock4 sets up a region structure to test for locks on the file, which it
   then uses to determine whether the region can be either write or read locked. The returned information
   shows the region bytes, offset from byte zero, that would cause the lock request to fail. Since the l_pid part
   of the returned structure contains the process identifier of the program that currently has the file locked,
   the program sets it to -1 (an invalid value) and then checks whether it has been changed when the fcntl
   call returns. If the region isn’t currently locked, l_pid will be unchanged.
   To understand the output, you need to look in the include file fcntl.h (normally /usr/include/
   fcntl.h) to find that an l_type of 1 is from the definition of F_WRLCK as 1, and an l_type of 0 is from
   the definition of F_RDLCK as 0. Thus, an l_type of 1 tells you that the lock would fail because of an existing
   write lock, and an l_type of 0 is caused by an existing read lock. On the regions of the file that
   lock3 has not locked, both shared and exclusive locks will succeed.
   From bytes 10 to 30, you can see that it would be possible to have a shared lock, because the existing lock
   from the lock3 program is a shared, not an exclusive, lock. On the region from bytes 40 to 50, both types
   of lock will fail because lock3 has an exclusive (F_WRLCK) lock on this region.
   Once the program lock4 has completed, you need to wait for a short period for lock3 to complete its
   sleep call and exit.

   here lock4 = lock2
   here lock3= lock-1
 */
// EXECUTED
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
const char *test_file = "test_lock";
#define SIZE_TO_TRY 5
void show_lock_info(struct flock *to_show);
int main()
{
	int file_desc;
	int res;
	struct flock region_to_test;
	int start_byte;
	// open a file descriptor
	file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
	if (!file_desc) {
		fprintf(stderr, "Unable to open %s for read/write", test_file);
		exit(EXIT_FAILURE);
	}
	for (start_byte = 0; start_byte < 99; start_byte += SIZE_TO_TRY) {
		//Set up the region you wish to test:
		region_to_test.l_type = F_WRLCK;
		region_to_test.l_whence = SEEK_SET;
		region_to_test.l_start = start_byte;
		region_to_test.l_len = SIZE_TO_TRY;
		region_to_test.l_pid = -1;
		printf("Testing F_WRLCK on region from %d to %d\n",
				start_byte, start_byte + SIZE_TO_TRY);
		//Now test the lock on the file:
		res = fcntl(file_desc, F_GETLK, &region_to_test);
		if (res == -1) {
			fprintf(stderr, "F_GETLK failed\n");
			exit(EXIT_FAILURE);
		}
		if (region_to_test.l_pid != -1) {
			printf("Lock would fail. F_GETLK returned:\n");
			show_lock_info(&region_to_test);
		}
		else {
			printf("F_WRLCK - Lock would succeed\n");
		}
		//Now repeat the test with a shared (read) lock. Set up the region you wish to test again:
		region_to_test.l_type = F_RDLCK;
		region_to_test.l_whence = SEEK_SET;
		region_to_test.l_start = start_byte;
		region_to_test.l_len = SIZE_TO_TRY;
		region_to_test.l_pid = -1;
		printf("Testing F_RDLCK on region from %d to %d\n",
				start_byte, start_byte + SIZE_TO_TRY);
		//Test the lock on the file again:
		res = fcntl(file_desc, F_GETLK, &region_to_test);
		if (res == -1) {
			fprintf(stderr, "F_GETLK failed\n");
			exit(EXIT_FAILURE);
		}
		if (region_to_test.l_pid != -1) {
			printf("Lock would fail. F_GETLK returned:\n");
			show_lock_info(&region_to_test);
		}
		else {
			printf("F_RDLCK - Lock would succeed\n");
		}
	}
	close(file_desc);
	exit(EXIT_SUCCESS);
}
void show_lock_info(struct flock *to_show) {
	printf("\tl_type %d, ", to_show->l_type);
	printf("l_whence %d, ", to_show->l_whence);
	printf("l_start %d, ", (int)to_show->l_start);
	printf("l_len %d, ", (int)to_show->l_len);
	printf("l_pid %d\n", to_show->l_pid);
}
