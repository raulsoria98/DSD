from calculadora import Calculadora

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from calculadora.ttypes import *

transport = TSocket.TSocket('localhost', 9090)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)

# creamos el cliente
client = Calculadora.Client(protocol)

print("\t1. Suma de numeros")
print("\t2. Resta de numeros")
print("\t3. Multiplicacion de numeros")
print("\t4. Division de numeros")
print("\t5. Escalar de vector 2D")
print("\t6. Vectorial de vector 2D")
print("\t7. Escalar de vector 3D")
print("\t8. Vectorial de vector 3D")

while True:
    opcion = int(input("Seleccione una opcion: "))
    if opcion == 1 or opcion == 2 or opcion == 3 or opcion == 4 or opcion == 5 \
            or opcion == 6 or opcion == 7 or opcion == 8:
        break

transport.open()

print('\nHacemos ping al server\n')
client.ping()

if opcion == 1 or opcion == 2 or opcion == 3 or opcion == 4:  # operaciones basicas
    a = float(input("Introduzca el primer numero: "))
    b = float(input("Introduzca el segundo numero: "))

    if opcion == 1:
        resultado = client.sumar(a, b)
        print(f"\nOperacion: {a} + {b} = {resultado}")
    elif opcion == 2:
        resultado = client.restar(a, b)
        print(f"\nOperacion: {a} - {b} = {resultado}")
    elif opcion == 3:
        resultado = client.multiplicar(a, b)
        print(f"\nOperacion: {a} * {b} = {resultado}")
    else:  # opcion 4
        resultado = client.dividir(a, b)
        print(f"\nOperacion: {a} / {b} = {resultado}")

elif opcion == 5 or opcion == 6:  # operaciones vect2D
    v1 = vect2D()
    v2 = vect2D()
    v1.x = float(input("Introduzca el primer numero del primer vector: "))
    v1.y = float(input("Introduzca el segundo numero del primer vector: "))
    v2.x = float(input("\nIntroduzca el primer numero del segundo vector: "))
    v2.y = float(input("Introduzca el segundo numero del segundo vector: "))

    if opcion == 5:
        resultado = client.escalar2d(v1, v2)
        print(f"\nOperacion: {v1} * {v2} = {resultado}")
    else:  # opcion 6
        resultado = client.vectorial2d(v1, v2)
        print(f"\nOperacion: {v1} x {v2} = {resultado}k")

else:  # operaciones vect3D
    v1 = vect3D()
    v2 = vect3D()
    v1.x = float(input("Introduzca el primer numero del primer vector: "))
    v1.y = float(input("Introduzca el segundo numero del primer vector: "))
    v1.z = float(input("Introduzca el tercer numero del primer vector: "))
    v2.x = float(input("\nIntroduzca el primer numero del segundo vector: "))
    v2.y = float(input("Introduzca el segundo numero del segundo vector: "))
    v2.z = float(input("Introduzca el tercer numero del segundo vector: "))

    if opcion == 7:
        resultado = client.escalar3d(v1, v2)
        print(f"\nOperacion: {v1} * {v2} = {resultado}")
    else:  # opcion 8
        resultado = vect3D()
        resultado = client.vectorial3d(v1, v2)
        print(f"\nOperacion: {v1} x {v2} = {resultado.x}i {resultado.y}j {resultado.z}k")

transport.close()