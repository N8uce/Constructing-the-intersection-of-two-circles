#include <math.h>
#include "task.h"
#include "time.h"
#include "control.h"
#include "graphics.h"
#define count_cir 2


point dots[count_cir];
int r[2];


void create(int left, int top ,int width, int height)
{
   srand(time(0));
   setfillstyle (SOLID_FILL, BLACK);
   bar(left,top,width,height);
  
   setcolor(YELLOW);
  for (int i=0; i<count_cir; i++) 
   {
      dots[i].x=((rand()) % (width/2)) + width/4;
      dots[i].y=((rand()) % (height/2))+height/6;
      r[i] =(rand())%(height/4)+20;
      circle(dots[i].x,dots[i].y,r[i]);
   }

}




void solution() 
{
   setfillstyle (SOLID_FILL, YELLOW);
   int x1,x2,y1,y2,r1,r2,a,d;
   point c;
   x1 = dots[0].x;
   y1 = dots[0].y;
   x2 = dots[1].x;
   y2 = dots[1].y;
   r1 = r[0];
   r2 = r[1];
   d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
   a = (r1*r1 - r2*r2 + d*d ) / (2*d); 
    
      if ((r1+ r2 > d) &&(r1 + d > r2) && (r2 + d > r1) )
      {
       c.x = x1 + a*( x2 - x1 ) / d;
       c.y= y1 + a*( y2 - y1 ) / d;
       floodfill(c.x,c.y,YELLOW);
      }
      if (d < abs(r1-r2) && r2<r1 )
      {
       floodfill(x2,y2,YELLOW);
      }
      if (d < abs(r1-r2)&& r1<r2 )
     {
       floodfill(x1,y1,YELLOW);
      }
      
}




void save()
{

   int width, height;
   IMAGE *output;


   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);


   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);

}

