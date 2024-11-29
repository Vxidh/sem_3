class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn

    def display_details(self):
        return f"{self.title} by {self.author} (ISBN: {self.isbn})"

class BorrowableBook(Book):
    def __init__(self, title, author, isbn):
        super().__init__(title, author, isbn)
        self.is_borrowed = False

    def borrow(self):
        if not self.is_borrowed:
            self.is_borrowed = True
            return f"You have borrowed {self.title}."
        return f"{self.title} is already borrowed."

    def return_book(self):
        if self.is_borrowed:
            self.is_borrowed = False
            return f"You have returned {self.title}."
        return f"{self.title} wasn't borrowed."

def print_book_info(book):
    print(book.display_details())


if __name__ == "__main__":
    book1 = Book("1984", "George Orwell", "1234567890")
    book2 = BorrowableBook("To Kill a Mockingbird", "Harper Lee", "0987654321")
    print(book1.display_details())
    print(book2.display_details())
    print(book2.borrow())
    print(book2.borrow())  
    print(book2.return_book())
    print(book2.return_book())  

    # Polymorphism in action
    print_book_info(book1)
    print_book_info(book2)
