import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


class Book {
    private String author;
    private String title;
    private String publisher;
    private double cost;
    private int stock;

  
    public Book(String author, String title, String publisher, double cost, int stock) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.cost = cost;
        this.stock = stock;
    }

    
    public String getAuthor() {
        return author;
    }

    public String getTitle() {
        return title;
    }

    public String getPublisher() {
        return publisher;
    }

    public double getCost() {
        return cost;
    }

    public int getStock() {
        return stock;
    }

   
    public void processRequest(int requiredCopies) {
        if (stock >= requiredCopies) {
            double totalCost = cost * requiredCopies;
            System.out.println("Book Details:");
            System.out.println("Author: " + author);
            System.out.println("Title: " + title);
            System.out.println("Publisher: " + publisher);
            System.out.println("Cost per copy: $" + cost);
            System.out.println("Total Cost for " + requiredCopies + " copies: $" + totalCost);
            stock -= requiredCopies; 
        } else {
            System.out.println("Required copies not in stock.");
        }
    }
}


 class BookShop {
    private List<Book> inventory=new ArrayList<>();

   
  public void addBook(Book book) {
        inventory.add(book);
    }

  
    public Book searchBook(String title, String author) {
        for (Book book : inventory) {
            if (book.getTitle().equalsIgnoreCase(title) && book.getAuthor().equalsIgnoreCase(author)) {
                return book;
            }
        }
        return null; 
    }

    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BookShop bookshop = new BookShop();

       
        bookshop.addBook(new Book("J.K. Rowling", "Harry Potter and the Philosopher's Stone", "Bloomsbury", 20.0, 10));
        bookshop.addBook(new Book("George Orwell", "1984", "Secker & Warburg", 15.0, 5));
        bookshop.addBook(new Book("Harper Lee", "To Kill a Mockingbird", "J.B. Lippincott & Co.", 18.0, 7));

       
        System.out.println("Welcome to the Bookshop!");
        System.out.print("Enter the title of the book: ");
        String title = scanner.nextLine();
        System.out.print("Enter the author of the book: ");
        String author = scanner.nextLine();

        Book book = bookshop.searchBook(title, author);
        if (book == null) {
            System.out.println("Sorry, the book is not available in our inventory.");
        } else {
            System.out.print("Enter the number of copies required: ");
            int requiredCopies = scanner.nextInt();
            book.processRequest(requiredCopies);
        }

        scanner.close();
    }
}
