#pragma once

// Representa un punto en espacio 3D
struct Coord_3D {
    double x;
    double y;
    double z;
};

// Representa un punto etiquetado (asociado a un cluster)
struct Labeled {
    Coord_3D coord;
    char label;
};
