// Define la interfaz remota

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Ejemplo_I extends Remote {
    public void escribir_mensaje (int id_porceso) throws RemoteException;
}