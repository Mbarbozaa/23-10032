#pragma once
#include <vector>
#include <string>
#include "types.h"

// Carga puntos 3D desde un archivo CSV en un vector
// El archivo debe tener el formato: x,y,z por línea
// Retorna true si la carga fue exitosa, false si hubo error
bool loadData(const std::string& filename, std::vector<Coord_3D>& data);
