# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bryan/Documents/VSCode/Gestion_Empresarial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bryan/Documents/VSCode/Gestion_Empresarial/build

# Include any dependencies generated for this target.
include CMakeFiles/GPS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GPS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GPS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GPS.dir/flags.make

CMakeFiles/GPS.dir/archivos/funciones.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/archivos/funciones.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.cpp
CMakeFiles/GPS.dir/archivos/funciones.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GPS.dir/archivos/funciones.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/archivos/funciones.cpp.o -MF CMakeFiles/GPS.dir/archivos/funciones.cpp.o.d -o CMakeFiles/GPS.dir/archivos/funciones.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.cpp

CMakeFiles/GPS.dir/archivos/funciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/archivos/funciones.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.cpp > CMakeFiles/GPS.dir/archivos/funciones.cpp.i

CMakeFiles/GPS.dir/archivos/funciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/archivos/funciones.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/archivos/funciones.cpp -o CMakeFiles/GPS.dir/archivos/funciones.cpp.s

CMakeFiles/GPS.dir/clases/clientes.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/clases/clientes.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/clientes.cpp
CMakeFiles/GPS.dir/clases/clientes.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GPS.dir/clases/clientes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/clases/clientes.cpp.o -MF CMakeFiles/GPS.dir/clases/clientes.cpp.o.d -o CMakeFiles/GPS.dir/clases/clientes.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/clientes.cpp

CMakeFiles/GPS.dir/clases/clientes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/clases/clientes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/clientes.cpp > CMakeFiles/GPS.dir/clases/clientes.cpp.i

CMakeFiles/GPS.dir/clases/clientes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/clases/clientes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/clientes.cpp -o CMakeFiles/GPS.dir/clases/clientes.cpp.s

CMakeFiles/GPS.dir/clases/empleados.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/clases/empleados.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/empleados.cpp
CMakeFiles/GPS.dir/clases/empleados.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GPS.dir/clases/empleados.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/clases/empleados.cpp.o -MF CMakeFiles/GPS.dir/clases/empleados.cpp.o.d -o CMakeFiles/GPS.dir/clases/empleados.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/empleados.cpp

CMakeFiles/GPS.dir/clases/empleados.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/clases/empleados.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/empleados.cpp > CMakeFiles/GPS.dir/clases/empleados.cpp.i

CMakeFiles/GPS.dir/clases/empleados.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/clases/empleados.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/empleados.cpp -o CMakeFiles/GPS.dir/clases/empleados.cpp.s

CMakeFiles/GPS.dir/clases/inventario.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/clases/inventario.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/inventario.cpp
CMakeFiles/GPS.dir/clases/inventario.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GPS.dir/clases/inventario.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/clases/inventario.cpp.o -MF CMakeFiles/GPS.dir/clases/inventario.cpp.o.d -o CMakeFiles/GPS.dir/clases/inventario.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/inventario.cpp

CMakeFiles/GPS.dir/clases/inventario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/clases/inventario.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/inventario.cpp > CMakeFiles/GPS.dir/clases/inventario.cpp.i

CMakeFiles/GPS.dir/clases/inventario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/clases/inventario.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/inventario.cpp -o CMakeFiles/GPS.dir/clases/inventario.cpp.s

CMakeFiles/GPS.dir/clases/pedidos.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/clases/pedidos.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.cpp
CMakeFiles/GPS.dir/clases/pedidos.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GPS.dir/clases/pedidos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/clases/pedidos.cpp.o -MF CMakeFiles/GPS.dir/clases/pedidos.cpp.o.d -o CMakeFiles/GPS.dir/clases/pedidos.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.cpp

CMakeFiles/GPS.dir/clases/pedidos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/clases/pedidos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.cpp > CMakeFiles/GPS.dir/clases/pedidos.cpp.i

CMakeFiles/GPS.dir/clases/pedidos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/clases/pedidos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.cpp -o CMakeFiles/GPS.dir/clases/pedidos.cpp.s

CMakeFiles/GPS.dir/clases/ventas.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/clases/ventas.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/ventas.cpp
CMakeFiles/GPS.dir/clases/ventas.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GPS.dir/clases/ventas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/clases/ventas.cpp.o -MF CMakeFiles/GPS.dir/clases/ventas.cpp.o.d -o CMakeFiles/GPS.dir/clases/ventas.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/ventas.cpp

CMakeFiles/GPS.dir/clases/ventas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/clases/ventas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/ventas.cpp > CMakeFiles/GPS.dir/clases/ventas.cpp.i

CMakeFiles/GPS.dir/clases/ventas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/clases/ventas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/clases/ventas.cpp -o CMakeFiles/GPS.dir/clases/ventas.cpp.s

CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/Nodo.cpp
CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o -MF CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/Nodo.cpp

CMakeFiles/GPS.dir/estructuras/Nodo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/Nodo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/Nodo.cpp > CMakeFiles/GPS.dir/estructuras/Nodo.cpp.i

CMakeFiles/GPS.dir/estructuras/Nodo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/Nodo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/Nodo.cpp -o CMakeFiles/GPS.dir/estructuras/Nodo.cpp.s

CMakeFiles/GPS.dir/estructuras/arbol.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/arbol.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbol.cpp
CMakeFiles/GPS.dir/estructuras/arbol.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GPS.dir/estructuras/arbol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/arbol.cpp.o -MF CMakeFiles/GPS.dir/estructuras/arbol.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/arbol.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbol.cpp

CMakeFiles/GPS.dir/estructuras/arbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/arbol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbol.cpp > CMakeFiles/GPS.dir/estructuras/arbol.cpp.i

CMakeFiles/GPS.dir/estructuras/arbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/arbol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbol.cpp -o CMakeFiles/GPS.dir/estructuras/arbol.cpp.s

CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.cpp
CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o -MF CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.cpp

CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.cpp > CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.i

CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.cpp -o CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.s

CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.cpp
CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o -MF CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.cpp

CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.cpp > CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.i

CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.cpp -o CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.s

CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.cpp
CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o -MF CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.cpp

CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.cpp > CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.i

CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.cpp -o CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.s

CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.cpp
CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o -MF CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.cpp

CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.cpp > CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.i

CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.cpp -o CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.s

CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.cpp
CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o -MF CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o.d -o CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.cpp

CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.cpp > CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.i

CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.cpp -o CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.s

CMakeFiles/GPS.dir/prueba.cpp.o: CMakeFiles/GPS.dir/flags.make
CMakeFiles/GPS.dir/prueba.cpp.o: /home/bryan/Documents/VSCode/Gestion_Empresarial/prueba.cpp
CMakeFiles/GPS.dir/prueba.cpp.o: CMakeFiles/GPS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/GPS.dir/prueba.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPS.dir/prueba.cpp.o -MF CMakeFiles/GPS.dir/prueba.cpp.o.d -o CMakeFiles/GPS.dir/prueba.cpp.o -c /home/bryan/Documents/VSCode/Gestion_Empresarial/prueba.cpp

CMakeFiles/GPS.dir/prueba.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GPS.dir/prueba.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryan/Documents/VSCode/Gestion_Empresarial/prueba.cpp > CMakeFiles/GPS.dir/prueba.cpp.i

CMakeFiles/GPS.dir/prueba.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GPS.dir/prueba.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryan/Documents/VSCode/Gestion_Empresarial/prueba.cpp -o CMakeFiles/GPS.dir/prueba.cpp.s

# Object files for target GPS
GPS_OBJECTS = \
"CMakeFiles/GPS.dir/archivos/funciones.cpp.o" \
"CMakeFiles/GPS.dir/clases/clientes.cpp.o" \
"CMakeFiles/GPS.dir/clases/empleados.cpp.o" \
"CMakeFiles/GPS.dir/clases/inventario.cpp.o" \
"CMakeFiles/GPS.dir/clases/pedidos.cpp.o" \
"CMakeFiles/GPS.dir/clases/ventas.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/arbol.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o" \
"CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o" \
"CMakeFiles/GPS.dir/prueba.cpp.o"

# External object files for target GPS
GPS_EXTERNAL_OBJECTS =

GPS: CMakeFiles/GPS.dir/archivos/funciones.cpp.o
GPS: CMakeFiles/GPS.dir/clases/clientes.cpp.o
GPS: CMakeFiles/GPS.dir/clases/empleados.cpp.o
GPS: CMakeFiles/GPS.dir/clases/inventario.cpp.o
GPS: CMakeFiles/GPS.dir/clases/pedidos.cpp.o
GPS: CMakeFiles/GPS.dir/clases/ventas.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/Nodo.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/arbol.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/arbolClientes.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/arbolEmpleados.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/arbolInventario.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/arbolPedidos.cpp.o
GPS: CMakeFiles/GPS.dir/estructuras/arbolVentas.cpp.o
GPS: CMakeFiles/GPS.dir/prueba.cpp.o
GPS: CMakeFiles/GPS.dir/build.make
GPS: CMakeFiles/GPS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable GPS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GPS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GPS.dir/build: GPS
.PHONY : CMakeFiles/GPS.dir/build

CMakeFiles/GPS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GPS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GPS.dir/clean

CMakeFiles/GPS.dir/depend:
	cd /home/bryan/Documents/VSCode/Gestion_Empresarial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bryan/Documents/VSCode/Gestion_Empresarial /home/bryan/Documents/VSCode/Gestion_Empresarial /home/bryan/Documents/VSCode/Gestion_Empresarial/build /home/bryan/Documents/VSCode/Gestion_Empresarial/build /home/bryan/Documents/VSCode/Gestion_Empresarial/build/CMakeFiles/GPS.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GPS.dir/depend

