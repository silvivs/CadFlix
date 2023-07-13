/*
- Functions prototype , pointers type and globally available data.
- Head.h file for Video Library functions module.
- All functios must be implemented regardless of whether they are going to be used or not.
*/ 

//struct for a movie
typedef struct movie Movie;

//struct for informations about the movie
typedef struct info Info;

//struct for movie list
typedef struct list List;

//function that creates a movie and returns a simple pointer to type Movie
Movie* createMovie(char* name, float price, char* director, char* genre, int year, int age);

//function that creates a list and return a simple pointer to type List
List* createList(void);

//function that checks if a list is empty
int isEmpty(List* head);

//to verify malloc error for char
void verify_mallocError_for_Char(char* string);

//function that deletes a movie and frees up memory
void freeMovies(Movie* movie);

//function that prints the information of a movie
void display(Movie* movie);

//function that delete a movie
void delete(List* head, char* name);

/*
Manipulation Functions
*/

//function that insert a movie at beginning
void insertAtBeginning(List* head);

//functions that accesses and modifies the name of a movie
void setName(Movie* movie, char* newName);

//function that accesses and modifies the price of a movie
void setPrice(Movie* movie, float newPrice);

//function that accesses and renames a director of a movie
void setDirector(Movie* movie, char* newDirector);

//function that accesses and renames the genres of a movie
void setGenre(Movie* movie, char* newGenre);

//function that accesses and modifies a year of a movie
void setYear(Movie* movie, int newYear);

//funtion that accesses and modifies the age range of a movie
void setAge(Movie* movie, int newAge);

//function that displays the main menu
void menu(void);

//function that displays the second menu on option 2 (Feature: rename movie name)
void subMenu(void);

//function that prints the label (list of movies)
void printList(Movie** movieList, int size);

//function that looks for the substring "Terror" in the string related to the movie's genre
int searchSubString(char* subString);