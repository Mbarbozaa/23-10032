#include <iostream>
#include <vector>
#include <string>
#include "types.h"
#include "loader.h"
#include "kmeans.h"
#include "output.h"

int main(int argc, char* argv[]) {
    // Validar argumentos: cluster <k> <datos>
    if (argc != 3) {
        std::cerr << "Uso: cluster <k> <archivo_datos>" << std::endl;
        std::cerr << "  k: numero de clusters (1-6)" << std::endl;
        std::cerr << "  archivo_datos: ruta al archivo CSV" << std::endl;
        return 1;
    }

    int k = std::stoi(argv[1]);
    std::string dataFile = argv[2];

    if (k < 1 || k > 6) {
        std::cerr << "Error: k debe estar entre 1 y 6" << std::endl;
        return 1;
    }

    // Cargar datos (el vector no se modifica después)
    std::vector<Coord_3D> data;
    if (!loadData(dataFile, data)) return 1;

    // Ejecutar k-means
    std::vector<char> labels;
    std::vector<Coord_3D> centroids;
    kMeans(data, k, labels, centroids);

    // Mostrar resumen en pantalla
    std::cout << "\n=== Resultado con k=" << k << " ===" << std::endl;
    for (int c = 0; c < k; c++) {
        char label = 'A' + c;
        int count = 0;
        for (char l : labels) if (l == label) count++;
        double md = clusterDispersion(data, labels, centroids[c], label);
        std::cout << label << ": " << count << " puntos, centroide=("
                  << centroids[c].x << ", " << centroids[c].y << ", " << centroids[c].z
                  << "), dispersion=" << md << std::endl;
    }

    // Generar archivos de salida
    writeClasificados(data, labels);
    writeSummary(data, labels, centroids, k);

    return 0;
}
