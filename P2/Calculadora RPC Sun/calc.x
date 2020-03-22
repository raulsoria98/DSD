typedef struct vect_2D *vect2D;
typedef struct vect_3D *vect3D;

struct vect_2D
{
    double x;
    double y;
};

struct vect_3D
{
    double x;
    double y;
    double z;
};

program CALCPROG
{
    version CALCVER
    {
        double sumar(double, double) = 1;
        double restar(double, double) = 2;
        double multiplicar(double, double) = 3;
        double dividir(double, double) = 4;
        double escalar2D(vect2D, vect2D) = 5;
        vect2D vectorial2D(vect2D, vect2D) = 6;
        double escalar3D(vect3D, vect3D) = 7;
        vect3D vectorial3D(vect3D, vect3D) = 8;
    } = 1;
} = 0x20000000;