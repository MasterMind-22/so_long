gcc to_screen.c libmlx.a so_long.a -Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o to_screen

# gcc to_screen.c so_long.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o to_screen