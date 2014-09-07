#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *i,*o;
	i=fopen("input42.txt","r");
	o=fopen("in42.txt","w");
	char ch;
	while( ( ch = fgetc(i) ) != EOF ){
    	if(ch==','){
    		fputc('\n',o);
    		continue;
    	}
    	if(ch=='"'){
    		continue;
    	}
    	fputc(ch,o);
  	}
  	fclose(i);
  	fclose(o);
}