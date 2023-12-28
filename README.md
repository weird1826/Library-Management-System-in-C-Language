# Library-Management-System-in-C-Language
Efficient C Language based Library Management System. <br>
📚Streamline book tracker and borrower management. <br>
Simple, sleek and all about organized shelves. 💫💫

# Features:
### >> Add a new book by specifying the following information:
1. Book Name <br>
2. Author Name <br>
3. Primary Genre <br>
4. Secondary Genre (if any, optional) <br>
5. Sub Genre <br>
6. Price <br>
7. Number of books in stock. <br>

- This book information will get saved in a bookInfo.txt file.
- Only use <code>Add a new book</code> feature when you (librarian) receive a brand new book which was never available previously in the library.

### >> View complete book database
You can view the whole book database (unsorted and unfiltered) by just selecting the <code>View All Books</code> option

### >> Book sorting and searching
You can search and filter books based on these parameters:<br>
1. Book Name<br>
2. Author Name<br>
3. Price<br> (NOT PRICE RANGE! FILTER ONLY BY A SPECIFIC PRICE!)<br>
4. Primary Genre

### >> Issue/Borrowing Management
You (librarian) can issue a book to an individual by specifying the following information:
1. Book Name<br>
2. Borrower's Name<br>
3. Number of days the book is being borrowed<br>
4. Date of Issue<br>

- Only one book can be issued per entry.
- The Date of Issue is fetched automatically by the program.
- This borrower's information is stored in an issueHolderDBS.txt file.
- When the book is issued, 1 is deducted from the amount of its stock in the bookInfo.txt file.

**Additional Features in Borrow Management**<br>
Before issuing a book, the program will check whether the book actually exists or not. If it exists, it will then check whether the book is in sufficient stock. I've set a limit, that if a book's stock is <=20 then the program will not allow the librarian to issue the book.

### >> View complete borrower's database
You can view the whole borrower's database by (unfiltered and unsorted) by just selecting the <code>View Aquirer Database</code> option

### >> Returning of the borrowed book by a reader
When a borrower returns a book, the book can be added back to the shelf by specifying the following information:
1. Borrower's Name
2. Book Name

- The program will check the issueHolderDBS.txt for such entry, and if it exists, it will proceed to delete that entry by file swapping and rewriting methods.
