#include "output.h"
#include "kmeans.h"
#include <fstream>
#include <iostream>
#include <iomanip>

bool writeClasificados(const std::vector<Coord_3D>& data,
                       const std::vector<char>& labels,
                       const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo crear " << filename << std::endl;
        return false;
    }

    file << std::fixed << std::setprecision(6);
    for (size_t i = 0; i < data.size(); i++) {
        file << data[i].x << ","
             << data[i].y << ","
             << data[i].z << ","
             << labels[i] << "\n";
    }

    file.close();
    std::cout << "Generado: " << filename << std::endl;
    return true;
}

bool writeSummary(const std::vector<Coord_3D>& data,
                  const std::vector<char>& labels,
                  const std::vector<Coord_3D>& centroids,
                  int k,
                  const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo crear " << filename << std::endl;
        return false;
    }

    file << std::fixed << std::setprecision(4);
    for (int c = 0; c < k; c++) {
        char label = 'A' + c;
        int count = 0;
        for (char l : labels) if (l == label) count++;

        double md = clusterDispersion(data, labels, centroids[c], label);

        file << label << ": "
             << count << ", ("
             << centroids[c].x << ", "
             << centroids[c].y << ", "
             << centroids[c].z << "), "
             << md << "\n";
    }

    file.close();
    std::cout << "Generado: " << filename << std::endl;
    return true;
}
