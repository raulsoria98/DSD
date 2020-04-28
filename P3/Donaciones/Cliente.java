import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Cliente {
    public static void main(String[] args) {
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }

        String host = "localhost";
        String servidor = "Replica1";
        String opcion, nombreUsuario = "", password;
        float importe, totalDonado, totalUsuario;
        int numDonaciones;

        Scanner in = new Scanner(System.in);

        try {
            Registry mireg = LocateRegistry.getRegistry(host, 1099);
            Donaciones_I gestorDonaciones = (Donaciones_I)mireg.lookup(servidor);

            boolean identificado = false, salir = false;

            while (!salir) {
                if(!identificado) {
                    System.out.println("Seleccione una de las siguientes opciones:\n"
                    + "\tI: Identificarse\n"
                    + "\tR: Registrarse\n"
                    + "\tS: Salir\n");
                    opcion = in.nextLine().toUpperCase();

                    switch (opcion) {
                        case "R":
                            System.out.println("\n*-*-*-*-*-*- REGISTO -*-*-*-*-*-*\n");
                            System.out.print("Introduzca el nombre de usuario: ");
                            nombreUsuario = in.nextLine();
                            System.out.print("Introduzca la contraseña para su cuenta: ");
                            password = in.nextLine();

                            if (gestorDonaciones.intentoRegistrar(nombreUsuario, password))
                                System.out.println("\nUsted se ha registrado correctamente\n");
                            else
                                System.out.println("\nError en el registro: nombre de usuario en uso\n");

                            Thread.sleep(2000);
                            break;

                        case "I":
                            System.out.println("\n*-*-*-*-*-*- IDENTIFICACION -*-*-*-*-*-*\n");
                            System.out.print("Introduzca su nombre de usuario: ");
                            nombreUsuario = in.nextLine();
                            System.out.print("Introduzca su contraseña: ");
                            password = in.nextLine();

                            if (gestorDonaciones.identificarUsuario(nombreUsuario, password)) {
                                identificado = true;
                                servidor = gestorDonaciones.getServidorUsuario(nombreUsuario);
                                gestorDonaciones = (Donaciones_I) mireg.lookup(servidor);
                                System.out.println("\nSe ha iniciado sesión como " + nombreUsuario + " en " + servidor + "\n");
                            } else
                                System.out.println("\nUsuario o contraseña incorrecta\n");

                            Thread.sleep(2000);
                            break;

                        case "S":
                            salir = true;
                            System.out.println("\nGracias por utilizar nuestro servicio!");

                            Thread.sleep(2000);
                            break;

                        default:
                            System.out.println("\nLa opción " + opcion + " no existe\n");

                            Thread.sleep(2000);
                            break;
                    }
                } else { // Usuario identificado
                    System.out.println("Hola " + nombreUsuario + ", selecciona una de las siguientes opciones:\n"
                            + "\tD: Realizar una donación\n"
                            + "\tC: Consultar total donado\n"
                            + "\tP: Consultar total donado personal\n"
                            + "\tN: Consultar numero donaciones personal\n"
                            + "\tS: Cerrar sesión\n");
                    opcion = in.nextLine().toUpperCase();

                    switch (opcion) {
                        case "D":
                            System.out.println("\n*-*-*-*-*-*- DONACION -*-*-*-*-*-*\n");
                            do {
                                System.out.print("Introduzca el importe de su donación: ");
                                importe = Float.parseFloat(in.nextLine());
                            } while (importe <= 0);

                            gestorDonaciones.donar(nombreUsuario, importe);

                            System.out.println("\nGracias " + nombreUsuario + " por contribuir a la causa con " + importe + "€\n");

                            Thread.sleep(2000);
                            break;

                        case "C":
                            numDonaciones = gestorDonaciones.getNumDonaciones(nombreUsuario);

                            if(numDonaciones > 0) {
                                totalDonado = gestorDonaciones.getTotalDonado();

                                System.out.println("\nNuestra causa ha recaudado un total de " + totalDonado + "€. Gracias por su colaboración\n");
                            } else {
                                System.out.println("\nTiene que realizar al menos una donación para poder consultar el total donado\n");
                            }

                            Thread.sleep(2000);
                            break;

                        case "P":
                            totalUsuario = gestorDonaciones.getTotalUsuario(nombreUsuario);

                            if(totalUsuario > 0)
                                System.out.println("\nUsted ha donado un total de " + totalUsuario + "€ a la causa. Gracias por su colaboración\n");
                            else
                                System.out.println("\nAún no ha realizado ninguna donación. Se agradece cualquier participación\n");

                            Thread.sleep(2000);
                            break;

                        case "N":
                            numDonaciones = gestorDonaciones.getNumDonaciones(nombreUsuario);

                            if(numDonaciones > 0)
                                System.out.println("\nUsted ha realizado un total de " + numDonaciones + " donaciones a la causa. Gracias por su colaboración\n");
                            else
                                System.out.println("\nAún no ha realizado ninguna donación. Se agradece cualquier participación\n");

                            Thread.sleep(2000);
                            break;

                        case "S":
                            identificado = false;
                            System.out.println("\nHasta pronto!\n");

                            Thread.sleep(2000);
                            break;

                        default:
                            System.out.println("\nLa opción " + opcion + " no existe\n");

                            Thread.sleep(2000);
                            break;
                    }
                }
            }
        } catch (NotBoundException | RemoteException | InterruptedException e) {
            System.err.println("Exception del sistema: " + e);
        }
    }
}
