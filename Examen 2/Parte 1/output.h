#pragma once
#include <vector>
#include <string>
#include "types.h"

// Genera el archivo clasificados.csv con todos los puntos etiquetados
// Formato: x,y,z,label
bool writeClasificados(const std::vector<Coord_3D>& data,
                       const std::vector<char>& labels,
                       const std::string& filename = "clasificados.csv");

// Genera el archivo summary.txt con el resumen de cada cluster
// Formato por línea: X: N, (x, y, z), MD
bool writeSummary(const std::vector<Coord_3D>& data,
                  const std::vector<char>& labels,
                  const std::vector<Coord_3D>& centroids,
                  int k,
                  const std::string& filename = "summary.txt");
