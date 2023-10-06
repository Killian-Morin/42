typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

/*
Fills the zone defined by some parameters with ‘F’ / replace all ‘1’ characters in the zone by ‘F’.
*/

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)//check if the point is valid (in the coordinates and the size of the tab) / needs to be filled
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);//fill the point up
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);//fill the point down
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);//fill the point left
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);//fill the point right
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
//when calling tab, always the .y first then the .x
//when declaring the t_point, always the .x first then the .y (since its in this order in the struct)
