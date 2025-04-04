FLAGS=-lSDL2 -lpthread `pkg-config --libs --cflags gtkmm-3.0 glibmm-2.4`
INCLUDES=-I. -Isrc/imgui -Isrc/imgui/backends -I/usr/include/SDL2
all:
	g++ src/*.cpp src/imgui/imgui.cpp src/imgui/imgui_draw.cpp src/imgui/imgui_widgets.cpp src/imgui/imgui_demo.cpp src/imgui/imgui_tables.cpp \
	src/imgui/backends/imgui_impl_sdlrenderer2.cpp \
  src/imgui/backends/imgui_impl_sdl2.cpp \
	-o bin/main $(FLAGS) $(INCLUDES)
	./bin/main
