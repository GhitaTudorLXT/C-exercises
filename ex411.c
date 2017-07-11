/* Just solved the exercise, code not working, missing dependencies */

int getop(char s[]) 
{ 
  static char unget = 0;
   int i, c;
   if (unget == 0)
    while ((s[0] = c = getch()) == ' ' || c == '\t') 
       ; 
    else 
    {
      s[0] = c = unget;
      unget = 0;
    }
   s[1] = '\0'; 
   if (!isdigit(c) && c != '.') 
       return c;      /* not a number */ 
   i = 0; 
   if (isdigit(c))    /* collect integer part */ 
       while (isdigit(s[++i] = c = getch())) 
          ; 
   if (c == '.')      /* collect fraction part */ 

  while (isdigit(s[++i] = c = getch())) 
          ; 
   s[i] = '\0'; 
   if (c != EOF)
   {
       unget = c;
    } 
   return NUMBER; 
} 