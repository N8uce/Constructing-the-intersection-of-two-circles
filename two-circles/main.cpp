#include "graphics.h"
#include "control.h"
#include "task.h"

int main()
{
   int left = 0, top = 0, width = 600, height = 400;
   
   initwindow(width, height+50);
   create_control(CREATE,   0, height, "create.bmp");
   create_control(SOLUTION,  151, height, "solution.bmp");
   create_control(SAVE,   301, height, "save.bmp");
   create_control(EXIT,   451, height, "exit.bmp");
   
   
   while (1)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
         case NONE: break;
         case CREATE: create(left,top,width, height); break;
         case SOLUTION: solution(); break;
         case SAVE: save(); break;
         case EXIT: closegraph(); return 0;
      }
   }
}