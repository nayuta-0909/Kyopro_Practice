#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int stack[1000],top=0;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	top--;
	return stack[top+1];
}

int main()
{
	char s[100];
	int x,y;

/*ctrl + D で終了*/
	while(scanf("%s",s) != EOF){
		if(s[0] == '+'){
			x = pop();
			y = pop();
			push(x + y);
		}else if(s[0] == '-'){
			x = pop();
			y = pop();
			push(y - x);
		}else if(s[0] == '*'){
			x = pop();
			y = pop();
			push(x * y);
		}else{
			push(atoi(s));
		}
	}

   

	printf("%d\n",pop()); 
    
    
	return 0;
}
