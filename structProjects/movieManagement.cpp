#include <iostream>
#include <string>

using namespace std;

struct Movie 
{
    string title;
    char genre [25];
    double rating;
    char timings[20];
    char hall;
    int seatsAvailable;
};

int inputFunction (int numMovies, Movie (&movies)[100], int totalMovies);
void displayMovies(int numMovies, Movie (&movies)[100]);
void bookTickets(int movieNum, Movie (&movies)[100], int seats);
void searchMovie(string title, Movie (&movies)[100], int totalMovies);

int main()
{
    const int maxMovies = 100;
    Movie movies [maxMovies];
    int totalMovies = 0;
    int numMovies = 0;
    int movieNum;
    int seats;
    string movieTitle;

    cout << "Enter number of movies" << endl;
    cin >> numMovies;
    cin.ignore();
    totalMovies = inputFunction(numMovies, movies, totalMovies);
    displayMovies(totalMovies, movies);

    cout << "Enter movie num whose tickets are to be booked" << endl;
    cin >> movieNum;

    cout << "Enter Number of seats to be booked" << endl;
    cin >> seats;

    bookTickets(movieNum, movies, seats);
    displayMovies(totalMovies, movies);

    cout << "Enter Movie title to get details: " << endl;
    cin.ignore();
    getline(cin, movieTitle);

    searchMovie(movieTitle, movies, numMovies);


    cout << "Enter number of movies" << endl;
    cin >> numMovies;
    cin.ignore();
    totalMovies = inputFunction(numMovies, movies, totalMovies);
    displayMovies(totalMovies, movies);
    
    return 0;
    
}

int inputFunction (int numMovies, Movie (&movies)[100], int totalMovies)
{

    for(int i = totalMovies; i < totalMovies + numMovies; i++)
    {
        cout << "Enter name of the movie" << endl;
        getline(cin, movies[i].title); // For strings which might have space chars use these.

        cout << "Enter genre of the movie" << endl;
        cin.getline(movies[i].genre, 25);

        cout << "Enter timings of the movie" << endl;
        cin >> movies[i].timings; //No space in timings so use cin for char arrays.

        cout << "Enter rating of the movie" << endl;
        cin >> movies[i].rating;

        cout << "Enter hall of the movie" << endl;
        cin >> movies[i].hall;

        cout << "Enter number of seats available" << endl;
        cin >> movies[i].seatsAvailable;
        cin.ignore();
    }

    return totalMovies + numMovies;
}

void displayMovies(int numMovies, Movie (&movies)[100])
{
    cout << "=========================List of movies===========================" << endl;
    
    for(int i = 0; i < numMovies; i++)
    {
        cout << "Movie " << i + 1 << " Details" << endl;
        cout << "title: " << movies[i].title << endl;
        cout << "genre: " << movies[i].genre << endl;
        cout << "timings: " << movies[i].timings << endl;
        cout << "rating: " << movies[i].rating << endl;
        cout << "hall: " << movies[i].hall << endl;
        cout << "seats available: " << movies[i].seatsAvailable << endl;
        cout << "====================================================================" << endl;
    }
}

void bookTickets(int movieNum, Movie (&movies)[100], int seats)
{
    
    if(movies[movieNum - 1].seatsAvailable < seats)
    {
        cout << "Not enough seats left ,please enter a lower number" << endl;
        return; 
    }

    movies[movieNum - 1].seatsAvailable -= seats;
    cout << "Tickets booked successfully" << endl;

}

void searchMovie(string title, Movie (&movies)[100], int totalMovies)
{
    for(int i = 0; i < totalMovies; i++)
    {
        if(movies[i].title == title)
        {
            cout << "====================================================================" << endl;
            cout << "Movie No of Movie is: " << i << endl;
            cout << "HALL No of Movie is: " << movies[i].hall << endl;
            cout << "Timing of Movie is: " << movies[i].timings << endl;
            cout << "====================================================================" << endl;

            return;
        }
    }
   
    cout << "Movie not found please enter valid movie title" << endl;
}

