#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ft_putstr_fd("List of avalaible parameters: \n", 1);
        ft_putstr_fd("Mandelbrot\nJulia\n", 1);
        return (0);
    }
    if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
        ft_putstr_fd("Mandelbrot\n", 1);
    if ((ft_strncmp(argv[1], "Julia", 6) == 0))
        ft_putstr_fd("Julia\n", 1);
}