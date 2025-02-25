import java.util.ArrayList;
import java.util.List;

class Account {
    private String accountNumber;
    private String holderName;
    private double balance;

    public Account(String accountNumber, String holderName, double balance) {
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getHolderName() {
        return holderName;
    }

    public void setHolderName(String holderName) {
        this.holderName = holderName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    @Override
    public String toString() {
        return "Account Number: " + accountNumber + ", Holder Name: " + holderName + ", Balance: " + balance;
    }
}

class SavingsAccount extends Account {
    private double interestRate;

    public SavingsAccount(String accountNumber, String holderName, double balance, double interestRate) {
        super(accountNumber, holderName, balance);
        this.interestRate = interestRate;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    public double calculateYearlyInterest() {
        return getBalance() * interestRate;
    }

    @Override
    public String toString() {
        return "Savings Account: " + super.toString() + ", Interest Rate: " + interestRate;
    }
}

class CurrentAccount extends Account {
    public CurrentAccount(String accountNumber, String holderName, double balance) {
        super(accountNumber, holderName, balance);
    }

    @Override
    public String toString() {
        return "Current Account: " + super.toString();
    }
}

class Manager {
    private List<Account> accounts;

    public Manager() {
        accounts = new ArrayList<>();
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public List<Account> getAccounts() {
        return accounts;
    }
}

 class Main {
    public static void main(String[] args) {
        Manager manager = new Manager();

        SavingsAccount sa1 = new SavingsAccount("SA001", "Alice", 1000.0, 0.05);
        SavingsAccount sa2 = new SavingsAccount("SA002", "Bob", 2000.0, 0.06);
        manager.addAccount(sa1);
        manager.addAccount(sa2);

        CurrentAccount ca1 = new CurrentAccount("CA001", "Charlie", 3000.0);
        CurrentAccount ca2 = new CurrentAccount("CA002", "Dave", 4000.0);
        CurrentAccount ca3 = new CurrentAccount("CA003", "Eve", 5000.0);
        manager.addAccount(ca1);
        manager.addAccount(ca2);
        manager.addAccount(ca3);

        System.out.println("Calculating yearly interest for Savings Accounts:");
        for (Account acc : manager.getAccounts()) {
            if (acc instanceof SavingsAccount) {
                SavingsAccount savingsAcc = (SavingsAccount) acc;
                double interest = savingsAcc.calculateYearlyInterest();
                System.out.println("Account " + savingsAcc.getAccountNumber() + ": $" + interest);
            }
        }

        System.out.println("\nDetails of all accounts:");
        for (Account acc : manager.getAccounts()) {
            System.out.println(acc);
        }
    }
}