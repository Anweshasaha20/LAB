interface Fruit {
    boolean hasAPeel();
}

interface Vegetable {
    boolean hasARoot();
}

class Tomato implements Fruit, Vegetable {
    private String name;

    public Tomato(String name) {
        this.name = name;
    }

    @Override
    public boolean hasAPeel() {
        return true;
    }

    @Override
    public boolean hasARoot() {
        return false;
    }

    @Override
    public String toString() {
        return "Tomato{" +
                "name='" + name + '\'' +
                ", hasAPeel=" + hasAPeel() +
                ", hasARoot=" + hasARoot() +
                '}';
    }
}

public class q16 {
    public static void main(String[] args) {
        Tomato tomato = new Tomato("Cherry Tomato");
        System.out.println(tomato);
    }
}
