void    ft_mandelbrot()
{
   int *x;//x coordinate of pixel
   int *y;//y coordinate of pixel
   int iteration;
   int max_iteration;

   x = 0;
   y = 0;
   iteration = 0;
   max_iteration = 100;
   while (((x*x + y*y) <= (2*2)) && iteration < max_iteration)
   {
       x[iteration] = x*x - y*y + x[0];
       y = 2*xy*y + y[0];
       x = x[iteration];
       iteration++;
   }
   if (iteration == max_iteration)
       color = black;//assign the right color
   plot(x[0], y[0], color);//apply the color
   if (iteration != max_iteration)
       color = iteration;//apply the color
   plot(x[0], y[0], color);
   /*
   if (iteration == max_iteration)
       color = black;
   else
       color = iteration;
   plot(x[0], y[0], color);
   */
}
