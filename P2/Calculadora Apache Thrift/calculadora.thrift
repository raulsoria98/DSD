struct vect2D
{
    1: required double x;
    2: required double y;
}

struct vect3D
{
    1: required double x;
    2: required double y;
    3: required double z;
}

service Calculadora
{
    void ping();
    double sumar(1:double num1, 2:double num2),
    double restar(1:double num1, 2:double num2),
    double multiplicar(1:double num1, 2:double num2),
    double dividir(1:double num1, 2:double num2),
    double escalar2d(1:vect2D v1, 2:vect2D v2),
    double vectorial2d(1:vect2D v1, 2:vect2D v2),
    double escalar3d(1:vect3D v1, 2:vect3D v2),
    vect3D vectorial3d(1:vect3D v1, 2:vect3D v2);
}