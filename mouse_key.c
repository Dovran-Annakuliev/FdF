#include "fdf.h"

void	cam_fix(t_mlx *data)
{
	if (data->cam.mouse == 0)
		data->cam.mouse = 1;
	else
		data->cam.mouse = 0;
}

int 	mouse_key(int key, int x, int y, t_mlx *data)
{
	if (key == 1)
		cam_fix(data);
}

int 	mouse_move(int x, int y, t_mlx *data)
{
	if (data->cam.mouse == 1)

}
