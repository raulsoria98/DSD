import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

public class Donaciones extends UnicastRemoteObject implements Donaciones_I{
    private ArrayList<Usuario> usuarios;
    private String nombre;
    private String replica;
    private float subtotal;
    private String host;

    public Donaciones(String nombre, String replica, String host) throws RemoteException {
        usuarios = new ArrayList<>();
        this.nombre = nombre;
        this.replica = replica;
        this.host = host;
    }

    @Override
    public boolean identificarUsuario(String nombre, String password) throws RemoteException {
        boolean identificado = false;

        Usuario usuario = getUsuarioTotal(nombre);

        if(usuario != null) {
            if(usuario.getPassword().equals(password))
                identificado = true;
        }

        return identificado;
    }

    @Override
    public boolean intentoRegistrar(String usuario, String pass) throws RemoteException {
        boolean exito = false;

        boolean existeUsuario = this.existeUsuarioTotal(usuario);

        if(!existeUsuario) {
            Donaciones_I replica = this.getReplica(this.replica);

            int numUsuarios = this.getNumUsuarios();
            int numUsuariosReplica = replica.getNumUsuarios();

            if(numUsuariosReplica < numUsuarios)
                replica.registrar(usuario, pass);
            else
                this.registrar(usuario, pass);

            exito = true;
        }

        return exito;
    }

    @Override
    public String getServidorUsuario(String usuario) throws RemoteException {
        String servidor = this.nombre;

        boolean existeUsuario = this.existeUsuario(usuario);

        if(!existeUsuario)
            servidor = this.replica;

        return servidor;
    }

    @Override
    public int getNumUsuarios() throws RemoteException {
        return usuarios.size();
    }

    @Override
    public String getNombre() throws RemoteException {
        return nombre;
    }

    @Override
    public void registrar(String nombre, String password) throws RemoteException {
        usuarios.add(new Usuario(nombre, password));
        System.out.println("Nuevo cliente registrado: " + nombre);
    }

    @Override
    public boolean existeUsuario(String nombre) throws RemoteException {
        boolean existe = true;

        Usuario usuario = getUsuario(nombre);

        if(usuario == null)
            existe = false;

        return existe;
    }

    @Override
    public boolean existeUsuarioTotal(String nombre) throws RemoteException {
        Usuario usuario = getUsuarioTotal(nombre);

        return usuario != null;
    }

    @Override
    public void donar(String nombreUsuario, float cantidad) throws RemoteException {
        Usuario usuario = getUsuario(nombreUsuario);

        usuario.haceDonacion(cantidad);
        this.subtotal += cantidad;
    }

    @Override
    public Usuario getUsuario(String nombreUsuario) throws RemoteException {
        Usuario usuario = null;

        for (Usuario usr : usuarios) {
            if(usr.getNombre().equals(nombreUsuario)) {
                usuario = usr;
                break;
            }
        }

        return usuario;
    }

    @Override
    public Usuario getUsuarioTotal(String nombreUsuario) throws RemoteException {
        Usuario usuario = this.getUsuario(nombreUsuario);

        if(usuario == null) {
            Donaciones_I replica = this.getReplica(this.replica);

            usuario = replica.getUsuario(nombreUsuario);
        }

        return usuario;
    }

    @Override
    public float getTotalUsuario(String usuario) throws RemoteException {
        return getUsuario(usuario).getTotalDonado();
    }

    @Override
    public int getNumDonaciones(String usuario) throws RemoteException {
        return getUsuario(usuario).getNumDonaciones();
    }

    @Override
    public float getSubtotal() throws RemoteException {
        return this.subtotal;
    }

    @Override
    public float getTotalDonado() throws RemoteException {
        return this.getSubtotal() + this.getReplica(this.replica).getSubtotal();
    }

    @Override
    public Donaciones_I getReplica(String nombre) throws RemoteException {
        Donaciones_I replica = null;

        try {
            Registry mireg = LocateRegistry.getRegistry(host, 1099);
            replica = (Donaciones_I)mireg.lookup(nombre);
        } catch(NotBoundException | RemoteException e) {
            System.err.println("Exception del sistema: " + e);
        }

        return replica;
    }
}
