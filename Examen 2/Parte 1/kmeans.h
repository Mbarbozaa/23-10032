#pragma once
#include <vector>
#include "types.h"

// Calcula la distancia Euclidiana entre dos puntos 3D
double euclideanDistance(const Coord_3D& a, const Coord_3D& b);

// Condición de parada del algoritmo k-means
// Parámetros:
//   oldCentroids: centroides de la iteración anterior
//   newCentroids: centroides de la iteración actual
//   tolerance: umbral mínimo de movimiento para considerar convergencia
// Retorna true si el algoritmo debe detenerse (convergió)
// Es una buena condición de parada porque mide el cambio real de los centroides:
// si ningún centroide se movió más que 'tolerance', el algoritmo ya no mejora
// significativamente y continuar sería un desperdicio de cómputo.
bool hasConverged(const std::vector<Coord_3D>& oldCentroids,
                  const std::vector<Coord_3D>& newCentroids,
                  double tolerance = 1e-6);

// Ejecuta el algoritmo k-means
// Parámetros:
//   data: vector con todos los puntos (no se modifica)
//   k: número de clusters deseado
//   labels: vector de salida con la etiqueta ('A'..'F') de cada punto
//   centroids: vector de salida con los centroides finales
void kMeans(const std::vector<Coord_3D>& data,
            int k,
            std::vector<char>& labels,
            std::vector<Coord_3D>& centroids);

// Calcula la dispersión media de un cluster:
// promedio de distancias de cada punto a su centroide.
// Mide qué tan "apretado" es el cluster.
double clusterDispersion(const std::vector<Coord_3D>& data,
                         const std::vector<char>& labels,
                         const Coord_3D& centroid,
                         char clusterLabel);
