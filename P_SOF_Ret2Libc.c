#include <Windows.h>

typedef unsigned int uint;

unsigned char msg[20] = "cmd.exe";


/*
stack:
0xbfffffff
......++++......
->	-1		(-1)				<-((uint*)p)[6]
->	ADDRESS	(msg)					<-((uint*)p)[5]
->	ADDRESS	(&exit)					<-((uint*)p)[4]
->	eip		(&system)			<-((uint*)p)[3]
->	ebp
->	ecx		(Checking cookie)
->	10		(int a)				<-(uint*)p = ((uint*)p)[0]
->	&a		(void *p)
......++++......
0x00000000
*/
int main(void)
{
	int a = 0;

	void *p = &a;

	((uint*)p)[3] = &system;
	((uint*)p)[4] = &exit;
	((uint*)p)[5] = msg;
	((uint*)p)[6] = -1;

	return 0;
}
