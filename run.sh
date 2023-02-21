# gcc to_screen.c libmlx.a so_long.a -Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o to_screen

gcc so_long.c so_long.a  -lmlx -framework OpenGL -framework AppKit -o so_long