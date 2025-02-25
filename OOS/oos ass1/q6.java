import java.util.ArrayList;

class Employee {
    private String name;
    private int id;
    private String address;
    private long salary;

    public Employee(String name, int id, String address, long salary) {
        this.name = name;
        this.id = id;
        this.address = address;
        this.salary = salary;
    }

    public long getSalary() {
        return salary;
    }

    public void setSalary(long salary) {
        this.salary = salary;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getAddress() {
        return address;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

}

class Dept {

    ArrayList<Employee> employees;
    String name;
    String location;

    public Dept(String name, String location) {
        this.name = name;
        this.location = location;
        employees = new ArrayList<>();
    }

    public void addEmployee(Employee e) {
        employees.add(e);
    }

    public void removeEmployee(int id) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees.get(i).getId() == id) {
                employees.remove(i);
                break;
            }
        }
    }

}

public class q6 {
    public static void main(String[] args) {
        Dept dept = new Dept("Information Technology", "Bangalore");
        for (int i = 0; i < 5; i++) {
            dept.addEmployee(new Employee("Employee" + i, i, "Address" + i, 10000 + i * 1000));
        }
        long yearlyExpense = 0;
        for (Employee e : dept.employees) {
            yearlyExpense += e.getSalary() * 12;
        }
        System.out.println("Yearly Expense: " + yearlyExpense);
    }
}
