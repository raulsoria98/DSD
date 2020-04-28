import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Donaciones_I extends Remote{
    boolean intentoRegistrar(String usuario, String pass) throws RemoteException;

    void donar(String nombreUsuario, float cantidad) throws RemoteException;

    float getTotalUsuario(String usuario) throws RemoteException;

    boolean existeUsuario(String nombre) throws RemoteException;

    int getNumUsuarios() throws RemoteException;

    String getNombre() throws RemoteException;

    void registrar(String nombre, String password) throws RemoteException;

    boolean identificarUsuario(String nombre, String password) throws RemoteException;

    String getServidorUsuario(String usuario) throws RemoteException;

    Donaciones_I getReplica(String nombre) throws RemoteException;

    Usuario getUsuario(String nombreUsuario) throws RemoteException;

    int getNumDonaciones(String usuario) throws RemoteException;

    float getSubtotal() throws RemoteException;

    float getTotalDonado() throws RemoteException;

    boolean existeUsuarioTotal(String nombre) throws RemoteException;

    Usuario getUsuarioTotal(String nombreUsuario) throws RemoteException;
}
