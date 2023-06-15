import java.util.ArrayList;
import java.util.List;

class Book {
    private String title;
    private boolean isBorrowed;

    public Book(String title) {
        this.title = title;
        this.isBorrowed = false;
    }

    public String getTitle() {
        return this.title;
    }

    public boolean isBorrowed() {
        return this.isBorrowed;
    }

    public void setBorrowed(boolean borrowed) {
        this.isBorrowed = borrowed;
    }
}

class Member {
    private String name;
    private List<Book> borrowedBooks;

    public Member(String name) {
        this.name = name;
        this.borrowedBooks = new ArrayList<>();
    }

    public String getName() {
        return this.name;
    }

    public void borrowBook(Book book) throws BookUnavailableException {
        if (book.isBorrowed()) {
            throw new BookUnavailableException(book.getTitle() + " is already borrowed.");
        } else {
            book.setBorrowed(true);
            borrowedBooks.add(book);
        }
    }
}

class Library {
    private List<Book> books;
    private List<Member> members;

    public Library() {
        this.books = new ArrayList<>();
        this.members = new ArrayList<>();
    }

    public void addBook(Book book) {
        this.books.add(book);
    }

    public void addMember(Member member) {
        this.members.add(member);
    }

    public Book findBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title)) {
                return book;
            }
        }
        return null;
    }
}

class BookUnavailableException extends Exception {
    public BookUnavailableException(String message) {
        super(message);
    }
}

public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        library.addBook(new Book("Book 1"));
        library.addBook(new Book("Book 2"));
        library.addBook(new Book("Book 3"));

        Member member1 = new Member("John");
        Member member2 = new Member("Mary");

        library.addMember(member1);
        library.addMember(member2);

        try {
            member1.borrowBook(library.findBook("Book 1"));
            System.out.println("Book borrowed succesfully");
            member2.borrowBook(library.findBook("Book 1")); // Will throw BookUnavailableException
            System.out.println("Will not reach here!");
        } catch (BookUnavailableException e) {
            System.out.println("This book is currently unavailable");
        }
    }
}