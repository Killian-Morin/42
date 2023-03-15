#include "../includes/fract_ol.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ft_putstr("List of avalaible parameters: \n", 1);
        ft_putstr("Mandelbrot\nJulia\n");
        return (0);
    }
    if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
        ft_mandelbrot;
    if ((ft_strncmp(argv[1], "Julia", 6) == 0))
        ft_julia;
}