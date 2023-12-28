# include<stdio.h>
# include<stdlib.h>
# include<conio.h>
# include<unistd.h>
# include<string.h>
# include<time.h>
# include<ctype.h>

void addNew();
void viewAll();
void search();
void searchByBN();
void searchByAN();
void searchByPrice();
void searchByPG();
void issueBook();
void viewIssueDB();
void checkAv();
void restockBook();
void bookReturn();

struct book{
    char bookName[50];
    char authorName[50];
    char priGenre[20];
    char secGenre[20];
    char subGenre[20];
    unsigned int price;
    unsigned int inStock;
} bookInfo;

struct issueList{
    char bookName[50];
    char iHName[50];
    unsigned int numOfDays;
    char dateOfIssue[12];
} iL;

FILE *fp;
long size = sizeof(bookInfo);

FILE *fptr;
long sz = sizeof(iL);

FILE *fp0;

int main(){

    int choice;

    while(1){
        system("cls");
        printf("\t\t***** Library Management System *****\n\tProject by Tejas Parmar - BSc IT (Hons.) Div-I\n\n");
        printf("Select the task you want to accomplish:");
        printf("\n1. Add a New Book\n");
        printf("2. View all books\n");
        printf("3. Search book(s)\n");
        printf("4. Issue a Book\n");
        printf("5. View Aquirer Database\n");
        printf("6. Restock a Book\n");
        printf("7. Issued Book Return\n");
        printf("0. Exit the program\n");

        printf("Choose the task: ");
        scanf("%d", &choice);

        switch(choice){
            case 0:
            exit(0);
            
            case 1:
            addNew();
            break;

            case 2:
            viewAll();
            break;

            case 3:
            search();
            break;

            case 4:
            issueBook();
            break;

            case 5:
            viewIssueDB();
            break;

            case 6:
            restockBook();
            break;

            case 7:
            bookReturn();
            break;

            default:
            printf("Please select a valid option!");
        }
        printf(" Press any key to continue...");
        getch();
    }

    return 0;
}

void addNew(){
    system("cls");
    printf("\t\t*** Add A New Book ***\n\n");
    
    fp = fopen("bookRecords.txt", "ab");

    printf("Book name: "); fflush(stdin); gets(bookInfo.bookName);
    printf("Author name: "); fflush(stdin); gets(bookInfo.authorName);
    printf("Book's primary genre: "); fflush(stdin); gets(bookInfo.priGenre);
    printf("Book's secondry genre: "); fflush(stdin); gets(bookInfo.secGenre);
    printf("Book's sub genre genre: "); fflush(stdin); gets(bookInfo.subGenre);
    printf("Price of Book: "); scanf("%d", &bookInfo.price);
    printf("Copies currently in stock: "); scanf("%d", &bookInfo.inStock);

    fwrite(&bookInfo, size, 1, fp);
    printf("Saving Info");
    for(int i = 0; i < 3; i++){
        printf(".");
        sleep(1);
    }
    printf("Information Saved Successfully!");

    fclose(fp);

    memset(&bookInfo, 0, size);
}

void viewAll(){
    system("cls");
    printf("\t\t*** View All Books ***\n\n");

    printf("%-50s %-40s %-10s %-10s %-30s %-30s\n\n", "Book Name", "Author Name", "Price", "In Stock", "S-Genre", "Sub");
    fp = fopen("bookRecords.txt", "rb");
    while(fread(&bookInfo, size, 1, fp) == 1){
        printf("%-50s %-40s %-10d %-10d %-30s %-30s\n\n", bookInfo.bookName, bookInfo.authorName, bookInfo.price, bookInfo.inStock, bookInfo.secGenre, bookInfo.subGenre);
    }
    fclose(fp);
}

void search(){
    int choice;

    while(1){
        system("cls");
        printf("\t\t*** Search Book(s) ***\n\n");
        printf("Search book(s) by:\n1. Book Name\n2. Author Name\n3. Price\n4. P-Genre\n0. Back to main menu\n");
        printf("Choose the task: ");
        scanf("%d", &choice);

        switch(choice){
            case 0:
            main();
            break;

            case 1:
            searchByBN();
            break;

            case 2:
            searchByAN();
            break;

            case 3:
            searchByPrice();
            break;

            case 4:
            searchByPG();
            break;
            
            default:
            printf("Please choose a valid option!");
        }
        printf(" Press any key to continue...");
        getch();
    }
}

void searchByBN(){
    char bName[50]; int flag=0;

    printf("\n\nEnter book name: "); fflush(stdin); gets(bName);

    printf("%-40s %-40s %-10s %-10s %-30s %-30s\n\n", "Book Name", "Author Name", "Price", "In Stock", "S-Genre", "Sub");
    fp = fopen("bookRecords.txt", "rb");
    while(fread(&bookInfo, size, 1, fp) == 1){
        if(strcmpi(bName, bookInfo.bookName) == 0){
            flag=1;
            printf("%-40s %-40s %-10d %-10d %-30s %-30s\n\n", bookInfo.bookName, bookInfo.authorName, bookInfo.price, bookInfo.inStock, bookInfo.secGenre, bookInfo.subGenre);
        }
    }

    fclose(fp);

    if(flag == 0){
        printf("Book Not Found!");
    } else{
        printf("Book Found Successfully!");
    }
}

void searchByAN(){
    char aName[50]; int flag=0;

    printf("\n\nEnter author's name: "); fflush(stdin); gets(aName);

    printf("%-40s %-40s %-10s %-10s %-30s %-30s\n\n", "Book Name", "Author Name", "Price", "In Stock", "S-Genre", "Sub");
    fp = fopen("bookRecords.txt", "rb");
    while(fread(&bookInfo, size, 1, fp) == 1){
        if(strcmpi(aName, bookInfo.authorName) == 0){
            flag=1;
            printf("%-40s %-40s %-10d %-10d %-30s %-30s\n\n", bookInfo.bookName, bookInfo.authorName, bookInfo.price, bookInfo.inStock, bookInfo.secGenre, bookInfo.subGenre);
        }
    }

    fclose(fp);

    if(flag == 0){
        printf("Author Not Found!");
    } else{
        printf("Author Found Successfully!");
    }
}

void searchByPrice(){
    unsigned int bPrice; int flag=0;

    printf("\n\nEnter your affordable price: "); scanf("%d", &bPrice);

    printf("%-40s %-40s %-10s %-10s %-30s %-30s\n\n", "Book Name", "Author Name", "Price", "In Stock", "S-Genre", "Sub");
    fp = fopen("bookRecords.txt", "rb");
    while(fread(&bookInfo, size, 1, fp) == 1){
        if(bPrice == bookInfo.price){
            flag=1;
            printf("%-40s %-40s %-10d %-10d %-30s %-30s\n\n", bookInfo.bookName, bookInfo.authorName, bookInfo.price, bookInfo.inStock, bookInfo.secGenre, bookInfo.subGenre);
        }
    }

    fclose(fp);

    if(flag == 0){
        printf("Book Not Found!");
    } else{
        printf("Book Found Successfully!");
    }
}

void searchByPG(){
    char pG[20]; int flag=0;

    printf("\n\nPrimary Genre (Fiction/NonFiction)? :  "); fflush(stdin); gets(pG);

    printf("%-40s %-40s %-10s %-10s %-30s %-30s\n\n", "Book Name", "Author Name", "Price", "In Stock", "S-Genre", "Sub");
    fp = fopen("bookRecords.txt", "rb");
    while(fread(&bookInfo, size, 1, fp) == 1){
        if(strcmpi(pG, bookInfo.priGenre) == 0){
            flag=1;
            printf("%-40s %-40s %-10d %-10d %-30s %-30s\n\n", bookInfo.bookName, bookInfo.authorName, bookInfo.price, bookInfo.inStock, bookInfo.secGenre, bookInfo.subGenre);
        }
    }

    fclose(fp);

    if(flag == 0){
        printf("Book Not Found!");
    } else{
        printf("Book Found Successfully!");
    }
}

void issueBook(){
    system("cls");
    printf("\t\t*** Issue Books ***\n\n");

    printf("*** Check book availability ***\n");
    checkAv();
}

void checkAv(){
    char bName[50]; int bPrice, bookAvail = 0, stockAmt = 0, pVar;

    printf("\n\nEnter book name: "); fflush(stdin); gets(bName);

    fp = fopen("bookRecords.txt", "rb+");

    printf("Checking book availablilty");
    for(int i=0; i<3; i++){
        printf(".");
        sleep(1);
    }

    while(fread(&bookInfo, size, 1, fp) == 1){
        if(strcmpi(bName, bookInfo.bookName) == 0){
            bookAvail=1;

            strcpy(iL.bookName, bookInfo.bookName);
            pVar = bookInfo.price;

            //WORKS -> fseek(fp, -size, 1);
            printf("\nBook named '%s' is available!", bookInfo.bookName);
            printf("\nChecking Stock");
            for(int i=0; i<3; i++){
                printf(".");
                sleep(1);
            }
            if(bookInfo.inStock > 20){
                stockAmt=1;
                bookInfo.inStock--;
                printf("\nYou can proceed to issue this book! Original Price: %d\n\n", pVar);
                fseek(fp, -size, 1);

                fptr = fopen("issueHolderDBS.txt", "ab");

                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                sprintf(iL.dateOfIssue, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
                printf("Name of the book to be issued: %s\n", bookInfo.bookName);
                printf("Date of issue: %s\n", iL.dateOfIssue);
                printf("Enter the name of the aquirer: "); fflush(stdin); gets(iL.iHName);
                printf("Number of days the book is to be issued: "); scanf("%d", &iL.numOfDays);

                fwrite(&bookInfo, size, 1, fp);
                fwrite(&iL, sz, 1, fptr);
                fclose(fp);
                fclose(fptr);
                memset(&bookInfo, 0, size);
                memset(&iL, 0, sz);
            }
            break;
        }
    }

    if(bookAvail==0){
        printf("\nThere is no book named '%s' in the library.", bName);
    }

    if(stockAmt==0){
        printf("\nSorry, this book is less or out of stock.");
    }

    fclose(fp);
}

void viewIssueDB(){
    system("cls");
    printf("\t\t*** View Aquirer Database ***\n\n");

    printf("%-40s %-40s %-20s %-20s\n\n", "Book Name", "Holder's Name", "Date of Issue", "Number of days");
    fptr = fopen("issueHolderDBS.txt", "rb");
    while(fread(&iL, sz, 1, fptr) == 1){
        printf("%-40s %-40s %-20s %-20d\n\n", iL.bookName, iL.iHName, iL.dateOfIssue, iL.numOfDays);
    }
    fclose(fptr);
}

void restockBook(){
    system("cls");
    printf("\t\t*** Restock Books ***\n\n");

    char bookQ[50]; int flag=0, rQuantity;
    printf("Enter the name of the book you wish to restock: "); fflush(stdin); gets(bookQ);
    
    fp = fopen("bookRecords.txt", "rb+");
    while(fread(&bookInfo, size, 1, fp) == 1){
        if(strcmpi(bookQ, bookInfo.bookName) == 0){
            flag=1;
            printf("\nBook found successfully!\n");
            printf("Enter the number of books you want to restock: "); scanf("%d", &rQuantity);
            bookInfo.inStock+=rQuantity;
            fseek(fp, -size, 1);
            fwrite(&bookInfo, size, 1, fp);
            fclose(fp);
            printf("Restocking book");
            for(int i=0; i < 3; i++){
                printf(".");
                sleep(1);
            }
            printf("\nBook restocked successfully!");
            break;
        }
    }

    if(flag==0){
        printf("Sorry, we do not have any book named %s in our database. ", bookQ);
    }
}

void bookReturn(){
    system("cls");
    printf("\t\t*** Issued Book Returned ***\n\n");

    remove("swapFile.txt");

    char bName[50], aqName[50]; int flag = 0;
    printf("Enter the Aquirer Name: "); fflush(stdin); gets(aqName);
    printf("Enter the Book Name: "); fflush(stdin); gets(bName);

    fptr = fopen("issueHolderDBS.txt", "rb");
    fp0 = fopen("swapFile.txt", "ab");

    printf("%-40s %-40s %-20s %-20s\n\n", "Book Name", "Holder's Name", "Date of Issue", "Number of days");
    while(fread(&iL, sz, 1, fptr) == 1){
        if(strcmpi(aqName, iL.iHName) == 0 && strcmpi(bName, iL.bookName) == 0){
            printf("%-40s %-40s %-20s %-20d\n\n", iL.bookName, iL.iHName, iL.dateOfIssue, iL.numOfDays);
            flag = 1;
        } else{
            fwrite(&iL, sz, 1, fp0);
        }
    }

    fclose(fptr);
    fclose(fp0);

    remove("issueHolderDBS.txt");
    rename("swapFile.txt", "issueHolderDBS.txt");

    if(flag == 1){
        printf("Record found successfully! Deleting Record");
        for(int i = 0; i < 3; i++){
            printf(".");
            sleep(1);
        }
        fp = fopen("bookRecords.txt", "rb+");

        while(fread(&bookInfo, size, 1, fp) == 1){
            if(strcmpi(bName, bookInfo.bookName) == 0){
                bookInfo.inStock+=1;
                fseek(fp, -size, 1);
                fwrite(&bookInfo, size, 1, fp);
                break;
            }
        }
        fclose(fp);
    } else{
        printf("Can't find record of that information.");
    }
}