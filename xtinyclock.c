

int main(void) {
   Display *d;
   Window w;
   XEvent e;
   char *msg = "Hello, World!";
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 0, 0, WINWIDTH , 20, 1, BlackPixel(d, s), WhitePixel(d, s));

   XStoreName( d , w , "xtinyclock");

   XSelectInput(d, w, ExposureMask | KeyPressMask);
   XMapWindow(d, w);



   XMoveResizeWindow(d, w , 2 , 2 ,  WINWIDTH  , 20 );
   XRaiseWindow(d , w );
 
   while (1) 
   {
      XNextEvent(d, &e);
      if (e.type == Expose) 
      {
	 while ( 1 )
	 {

           XClearWindow(d, w);
           XDrawString(d, w, DefaultGC(d, s), 5, 10, strtimenow() , strlen( strtimenow() ));
           XFlush( d );
	   usleep( 10000 );
	 }
      }
   }


   XCloseDisplay(d);
   return 0;
}
