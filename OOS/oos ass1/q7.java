import java.util.*;


abstract class Publication {
    protected int noOfPages;
    protected double price;
    protected String publisherName;

    public Publication(int pages, double cost, String publisher) {
        this.noOfPages = pages;
        this.price = cost;
        this.publisherName = publisher;
    }
    
    public abstract void printDetails();
}


class Book extends Publication {
    private String title;
    private String author;

    public Book(String bookTitle, String bookAuthor, int pages, double cost, String publisher) {
        super(pages, cost, publisher);
        this.title = bookTitle;
        this.author = bookAuthor;
    }
    
    @Override
    public void printDetails() {
        System.out.println("Book: " + title + "\nAuthor: " + author + "\nPages: " + noOfPages + "\nPrice: Rs." + price + "\nPublisher: " + publisherName + "\n");
    }
}


class Journal extends Publication {
    private String journalName;
    private int issueNumber;

    public Journal(String name, int issue, int pages, double cost, String publisher) {
        super(pages, cost, publisher);
        this.journalName = name;
        this.issueNumber = issue;
    }
    
    @Override
    public void printDetails() {
        System.out.println("Journal: " + journalName + "\nIssue No: " + issueNumber + "\nPages: " + noOfPages + "\nPrice: Rs." + price + "\nPublisher: " + publisherName + "\n");
    }
}


class Library {
    private List<Publication> publications = new ArrayList<>();

    public void addPublication(Publication pub) {
        publications.add(pub);
    }
    
    public void printAllPublications() {
        for (Publication pub : publications) {
            pub.printDetails();
        }
    }
}

 class Main {
    public static void main(String[] args) {
        Library lib = new Library();
        
        
        lib.addPublication(new Book("C++ Primer", "Stanley B. Lippman", 970, 899.99, "Pearson"));
        lib.addPublication(new Book("Introduction to Algorithms", "Cormen", 1292, 999.99, "MIT Press"));
        lib.addPublication(new Book("Clean Code", "Robert C. Martin", 464, 650.50, "Prentice Hall"));
        
        
        lib.addPublication(new Journal("IEEE Transactions on Computers", 125, 150, 350.75, "IEEE"));
        lib.addPublication(new Journal("Nature Communications", 84, 120, 499.99, "Nature Publishing"));
        
        
        lib.printAllPublications();
    }
}

