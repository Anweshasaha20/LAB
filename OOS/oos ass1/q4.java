class BankAccount {
    private int accountNumber;
    private double balance;
    private String ownerName;

    
    public BankAccount(int accountNumber, double balance, String ownerName) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.ownerName = ownerName;
    }

 
    public int getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public String getOwnerName() {
        return ownerName;
    }

   
    public void add(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Amount deposited: " + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

  
    public void subtract(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Amount withdrawn: " + amount);
        } else {
            System.out.println("Invalid withdrawal amount or insufficient balance.");
        }
    }

  
    public void printDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Owner Name: " + ownerName);
        System.out.println("Balance: " + balance);
    }
}

class AccountManager {
    private BankAccount[] accounts;
    private int count;

    public AccountManager(int size) {
        accounts = new BankAccount[size];
        count = 0;
    }

 
    public void create(int accountNumber, double balance, String ownerName) {
        if (count < accounts.length) {
            accounts[count++] = new BankAccount(accountNumber, balance, ownerName);
            System.out.println("Account created successfully.");
        } else {
            System.out.println("No space to create new account.");
        }
    }

    
    public void delete(int accountNumber) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i] = accounts[--count];
                accounts[count] = null;
                System.out.println("Account deleted successfully.");
                return;
            }
        }
        System.out.println("Account not found.");
    }

   
    public void deposit(int accountNumber, double amount) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i].add(amount);
                return;
            }
        }
        System.out.println("Account not found.");
    }


    public void withdraw(int accountNumber, double amount) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i].subtract(amount);
                return;
            }
        }
        System.out.println("Account not found.");
    }


    public void printAllAccounts() {
        for (int i = 0; i < count; i++) {
            accounts[i].printDetails();
            System.out.println("---------------------------");
        }
    }
}

 class Bank {
    public static void main(String[] args) {
        AccountManager manager = new AccountManager(10);

        
        manager.create(101, 5000, "Anwesha");
        manager.create(102, 10000, "Akash");
        manager.create(103, 7500, "Tanish");
        manager.create(104, 12000, "Asmit");
        manager.create(105, 3000, "Arya");

      
        System.out.println("Details of all accounts:");
        manager.printAllAccounts();
    }
}
