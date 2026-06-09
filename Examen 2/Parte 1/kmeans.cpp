#include "kmeans.h"
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iostream>

// Distancia Euclidiana entre dos puntos en 3D
// Formula: sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
double euclideanDistance(const Coord_3D& a, const Coord_3D& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

// Condición de parada:
// El algoritmo converge cuando todos los centroides se mueven menos que 'tolerance'.
// Esto garantiza estabilidad sin iterar de más.
bool hasConverged(const std::vector<Coord_3D>& oldC,
                  const std::vector<Coord_3D>& newC,
                  double tolerance) {
    for (size_t i = 0; i < oldC.size(); i++) {
        if (euclideanDistance(oldC[i], newC[i]) > tolerance)
            return false;
    }
    return true;
}

void kMeans(const std::vector<Coord_3D>& data,
            int k,
            std::vector<char>& labels,
            std::vector<Coord_3D>& centroids) {

    int n = (int)data.size();
    labels.resize(n);
    centroids.resize(k);

    // Inicializar centroides eligiendo k puntos al azar del dataset
    std::srand(42); // semilla fija para reproducibilidad
    std::vector<int> chosen;
    while ((int)chosen.size() < k) {
        int idx = std::rand() % n;
        bool already = false;
        for (int c : chosen) if (c == idx) { already = true; break; }
        if (!already) chosen.push_back(idx);
    }
    for (int i = 0; i < k; i++) centroids[i] = data[chosen[i]];

    const int MAX_ITER = 1000;
    for (int iter = 0; iter < MAX_ITER; iter++) {

        // Paso 1: Asignar cada punto al centroide más cercano
        for (int i = 0; i < n; i++) {
            double minDist = std::numeric_limits<double>::max();
            int bestCluster = 0;
            for (int c = 0; c < k; c++) {
                double d = euclideanDistance(data[i], centroids[c]);
                if (d < minDist) {
                    minDist = d;
                    bestCluster = c;
                }
            }
            labels[i] = 'A' + bestCluster;
        }

        // Paso 2: Recalcular centroides como promedio de puntos asignados
        std::vector<Coord_3D> newCentroids(k, {0.0, 0.0, 0.0});
        std::vector<int> counts(k, 0);

        for (int i = 0; i < n; i++) {
            int c = labels[i] - 'A';
            newCentroids[c].x += data[i].x;
            newCentroids[c].y += data[i].y;
            newCentroids[c].z += data[i].z;
            counts[c]++;
        }

        for (int c = 0; c < k; c++) {
            if (counts[c] > 0) {
                newCentroids[c].x /= counts[c];
                newCentroids[c].y /= counts[c];
                newCentroids[c].z /= counts[c];
            }
        }

        // Paso 3: Verificar convergencia
        if (hasConverged(centroids, newCentroids)) {
            std::cout << "Convergio en iteracion " << iter+1 << std::endl;
            centroids = newCentroids;
            break;
        }
        centroids = newCentroids;
    }
}

double clusterDispersion(const std::vector<Coord_3D>& data,
                         const std::vector<char>& labels,
                         const Coord_3D& centroid,
                         char clusterLabel) {
    double sum = 0.0;
    int count = 0;
    for (size_t i = 0; i < data.size(); i++) {
        if (labels[i] == clusterLabel) {
            sum += euclideanDistance(data[i], centroid);
            count++;
        }
    }
    return (count > 0) ? sum / count : 0.0;
}
