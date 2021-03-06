#include "../includes/fdf.h"

void	print_point(t_point p)
{
	printf("x = %f\ty = %f\tz = %f\tclr = %x\n", p.x, p.y, p.z, p.clr);
}

int		main(int argc, char **argv)
{
	t_mlx *data;

	data = start(argc, argv);
	draw_image(data);
	mlx_hook(data->window, 2, 1l << 0, deal_key, data);
	mlx_loop(data->mlx);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img.img_data);
	return (0);
}
