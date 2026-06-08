#include "loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool loadData(const std::string& filename, std::vector<Coord_3D>& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string token;
        Coord_3D point;

        // Leer x
        if (!std::getline(ss, token, ',')) continue;
        point.x = std::stod(token);

        // Leer y
        if (!std::getline(ss, token, ',')) continue;
        point.y = std::stod(token);

        // Leer z
        if (!std::getline(ss, token, ',')) continue;
        point.z = std::stod(token);

        data.push_back(point);
    }

    file.close();
    std::cout << "Datos cargados: " << data.size() << " puntos." << std::endl;
    return true;
}
