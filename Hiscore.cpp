
#include <posix/stdlib.h>
#include <posix/string.h>
#include <posix/stdio.h>
#include <Interface/Font.h>
#include "Hiscore.h"

Hiscore::Hiscore(class View *v) : MovieScroller(v){
//printf("aa\n");
	font = new Font("Fonts/swed");//Humnst777_BT_40");
//printf("bb\n");
	font->SetSize(.65f);
//printf("cc\n");
	Apply(font);
//printf("dd\n");
	#ifdef OPENGL
	#else
	Print(
		"1.  Ledig 0\n"
		"2.  Ledig 0\n"
		"3.  Ledig 0\n"
		"4.  Ledig 0\n"
		"5.  Ledig 0\n"
		"6.  Ledig 0\n"
		"7.  Ledig 0\n"
		"8.  Ledig 0\n"
		"9.  Ledig 0\n"
		"10. Ledig 0\n"
		"11. Ledig 0\n"
		"12. Ledig 0\n"
		"13. Ledig 0\n"
		"14. Ledig 0\n"
		"15. Ledig 0\n"
		"16. Ledig 0\n"
		"17. Ledig 0\n"
		"18. Ledig 0\n"
		"19. Ledig 0\n"
		"20. Ledig 0\n"
		"21. Ledig 0\n"
		"22. Ledig 0\n"
		"23. Ledig 0\n"
		"24. Ledig 0\n"
		"25. Ledig 0\n"
		"26. Ledig 0\n"
		"27. Ledig 0\n"
		"28. Ledig 0\n"
		"29. Ledig 0\n"
		"30. Ledig 0");
	#endif
//printf("ee\n");
	for(int n=0; n<30; n++){
		sprintf(names[n],"Free");
		scores[n]=0;
	}
//printf("ff\n");
}

Hiscore::~Hiscore(){
	delete font;
}

void Hiscore::Add(const char *name, const int score){
//printf("Add %s %d\n",name,score);
	for(int n=0; n<30; n++){
		if(scores[n]<score){
			for(int i=29; i>n; i--){
//printf("%d: %s %d = %d: %s %d => ",i,names[i],scores[i],i-1,names[i-1],scores[i-1]);
				sprintf(names[i],"%s",names[i-1]);
				scores[i]=scores[i-1];
//printf("%d: %s %d\n",i,names[i],scores[i]);
			}
			scores[n]=score;
			sprintf(names[n],"%s",name);

			// remove spaces
			int l=strlen(names[n])-1;
			while(names[n][l]==' ') names[n][l--]='\0';

//printf("New hiscore:\n");
			ConsoleStream::Clear();
			for(n=0; n<30; n++){
				char str[1024];
				sprintf(str,"%d. %s %d\n",n+1,names[n],scores[n]);
//printf(str);
				Print(str);
			}
			return;
		}
	}
}

