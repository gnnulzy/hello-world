
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <limits.h>
#include <asm/ioctls.h>
#include <time.h>
#include <pthread.h>
#include <string.h>



#define   CMD_LCD_BK          1
#define   CMD_LCD_CLEAR_SCREEN              2
#define   CMD_LCD_DISPLAY_CHAR    		3


#define   CMD_LCD_DISPAY_MESSAGE         4
#define   CMD_LCD_DISPLAY_INT                 5
#define   CMD_LCD_DISPLAY_HEX                6
#define   CMD_LCD_SET_CURSOR                  7

#define   CMD_LCD_DSPLAY_STR    8




int main(void)
{
	int fd;
	int data=0;

	char buff[10];

	fd = open("/dev/lcm_test",O_WRONLY);
	if (fd < 0) {
		perror("open /dev/lcm_test");
	}


	ioctl(fd, CMD_LCD_BK,0);
	sleep(1);
	ioctl(fd, CMD_LCD_BK,1);
	sleep(1);
	ioctl(fd, CMD_LCD_BK,0);
	sleep(1);
	ioctl(fd, CMD_LCD_BK,1);
	sleep(1);
	ioctl(fd, CMD_LCD_BK,0);
	sleep(1);
	ioctl(fd, CMD_LCD_BK,1);

	sleep(1);

       ioctl(fd, CMD_LCD_CLEAR_SCREEN, 0);

	sleep(1);
	ioctl(fd, CMD_LCD_SET_CURSOR,0x0007 );
	ioctl(fd, CMD_LCD_DISPLAY_CHAR,0x01 );

       sleep(1);
	ioctl(fd, CMD_LCD_SET_CURSOR,0x0006);
	ioctl(fd, CMD_LCD_DISPLAY_INT,0x06);


	ioctl(fd, CMD_LCD_SET_CURSOR,0x0102);
	ioctl(fd, CMD_LCD_DISPLAY_HEX,0x12);

       ioctl(fd, CMD_LCD_SET_CURSOR,0x0100);
	sleep(1);



	/*buf[0]  raw buf[1.......n] message  */
       buff[0]=1;

	buff[1]='e';
	buff[2]='f';
	buff[3]='g';
       write(fd,buff,4);
	sleep(1);
	ioctl(fd, CMD_LCD_SET_CURSOR,0x0101);
	memcpy(&buff[1],"萬hjk",5);
	if(write(fd,buff,6)<0)
	{
	   printf("write  erro \n");
	}
	




}

