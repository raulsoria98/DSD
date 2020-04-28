import java.io.Serializable;

public class Usuario implements Serializable {
    private String nombre;
    private String password;
    private int numDonaciones;
    private int totalDonado;

    Usuario(String nombre, String password) {
        this.nombre = nombre;
        this.password = password;
        this.numDonaciones = 0;
        this.totalDonado = 0;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setNumDonaciones(int nDonaciones) {
        this.numDonaciones = nDonaciones;
    }

    public void setTotalDonado(int totalDonado) {
        this.totalDonado = totalDonado;
    }

    public String getNombre() {
        return nombre;
    }

    public String getPassword() {
        return password;
    }

    public int getNumDonaciones() {
        return numDonaciones;
    }

    public int getTotalDonado() {
        return totalDonado;
    }

    public void haceDonacion(float cantidad) {
        numDonaciones++;
        totalDonado += cantidad;
    }
}
